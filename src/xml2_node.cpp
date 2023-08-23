#define R_NO_REMAP
#include <Rinternals.h>
#undef R_NO_REMAP

#include <libxml/tree.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <set>

#include "xml2_types.h"
#include "xml2_utils.h"

template<typename T> // for xmlAttr and xmlNode
std::string nodeName(T* node, SEXP nsMap) {
  std::string name = Xml2String(node->name).asStdString();
  if (Rf_xlength(nsMap) == 0) {
    return name;
  }

  xmlNs* ns = node->ns;
  if (ns == NULL)
    return name;

  std::string prefix = NsMap(nsMap).findPrefix(Xml2String(ns->href).asStdString());
  return prefix + ":" + name;
}

// [[export]]
extern "C" SEXP node_name(SEXP node_sxp, SEXP nsMap) {
  BEGIN_CPP
  XPtrNode node(node_sxp);

  std::string name = nodeName(node.checked_get(), nsMap);
  return Rf_ScalarString(Rf_mkCharLenCE(name.c_str(), name.size(), CE_UTF8));
  END_CPP
}

// [[export]]
extern "C" SEXP nodeset_name(SEXP node_sxp, SEXP nsMap) {
  BEGIN_CPP

  int n = Rf_xlength(node_sxp);

  SEXP out = PROTECT(Rf_allocVector(STRSXP, n));

  for (int i = 0; i < n; ++i) {
    SEXP node_sxp_i = VECTOR_ELT(node_sxp, i);

    if (Rf_inherits(node_sxp_i, "xml_node")) {
      SEXP node_field_i = VECTOR_ELT(node_sxp_i, 0);
      XPtrNode node_i(node_field_i);
      std::string name_i = nodeName(node_i.checked_get(), nsMap);
      SET_STRING_ELT(out, i, Rf_mkCharLenCE(name_i.c_str(), name_i.size(), CE_UTF8));
    } else if (Rf_inherits(node_sxp_i, "xml_missing")) {
      SET_STRING_ELT(out, i, NA_STRING);
    } else {
      // xml_nodeset can't appear
      Rf_error("Unexpected node type");
    }
  }

  UNPROTECT(1);
  return out;

  END_CPP
}

// [[export]]
extern "C" SEXP node_set_name(SEXP node_sxp, SEXP value) {
  BEGIN_CPP
  XPtrNode node(node_sxp);

  xmlNodeSetName(node, asXmlChar(value));

  return R_NilValue;
  END_CPP
}

// [[export]]
extern "C" SEXP node_text(SEXP node_sxp) {
  BEGIN_CPP
  XPtrNode node(node_sxp);

  return Rf_ScalarString(Xml2String(xmlNodeGetContent(node.checked_get())).asRString());
  END_CPP
}

// [[export]]
extern "C" SEXP nodeset_text(SEXP node_sxp) {
  BEGIN_CPP

  int n = Rf_xlength(node_sxp);

  SEXP out = PROTECT(Rf_allocVector(STRSXP, n));

  for (int i = 0; i < n; ++i) {
    SEXP node_sxp_i = VECTOR_ELT(node_sxp, i);

    if (Rf_inherits(node_sxp_i, "xml_node")) {
      SEXP node_field_i = VECTOR_ELT(node_sxp_i, 0);
      XPtrNode node_i(node_field_i);
      SEXP text_i = Xml2String(xmlNodeGetContent(node_i.checked_get())).asRString();
      SET_STRING_ELT(out, i, text_i);
    } else if (Rf_inherits(node_sxp_i, "xml_missing")) {
      SET_STRING_ELT(out, i, NA_STRING);
    } else {
      // xml_nodeset can't appear
      Rf_error("Unexpected node type");
    }
  }

  UNPROTECT(1);
  return out;

  END_CPP
}

bool hasPrefix(std::string lhs, std::string rhs) {
  if (lhs.length() > rhs.length()) {
    return false;
  }

  return std::equal(
      lhs.begin(),
      lhs.end(),
      rhs.begin());
}

const xmlChar* xmlNsDefinition(xmlNodePtr node, const xmlChar* lookup) {
  xmlNsPtr next = node->nsDef;

  while(next != NULL) {
    // default namespace
    if (xmlStrEqual(next->prefix, lookup)) {
      return next->href;
    }
    next = next->next;
  }

  return NULL;
}

// [[export]]
extern "C" SEXP node_attr(
    SEXP node_sxp,
    SEXP name_sxp,
    SEXP missing_sxp,
    SEXP nsMap_sxp) {
  BEGIN_CPP

  XPtrNode node(node_sxp);
  std::string name(CHAR(STRING_ELT(name_sxp, 0)));

  if (Rf_xlength(missing_sxp) != 1) {
    Rf_error("`missing` should be length 1");
  }

  SEXP missingVal = STRING_ELT(missing_sxp, 0);

  if (name == "xmlns") {
    return Rf_ScalarString(Xml2String(xmlNsDefinition(node, NULL)).asRString(missingVal));
  }

  if (hasPrefix("xmlns:", name)) {
    std::string prefix = name.substr(6);
    return Rf_ScalarString(Xml2String(xmlNsDefinition(node, asXmlChar(prefix))).asRString(missingVal));
  }

  xmlChar* string;
  if (Rf_xlength(nsMap_sxp) == 0) {
    string = xmlGetProp(node.checked_get(), asXmlChar(name));
  } else {
    size_t colon = name.find(':');
    if (colon == std::string::npos) {
      // Has namespace spec, but attribute not qualified, so look for attribute
      // without namespace
      string = xmlGetNoNsProp(node.checked_get(), asXmlChar(name));
    } else {
      // Split name into prefix & attr, then look up full url
      std::string
        prefix = name.substr(0, colon),
               attr = name.substr(colon + 1, name.size() - 1);

      std::string url = NsMap(nsMap_sxp).findUrl(prefix);

      string = xmlGetNsProp(node.checked_get(), asXmlChar(attr), asXmlChar(url));
    }
  }

  return Rf_ScalarString(Xml2String(string).asRString(missingVal));
  END_CPP
}

// [[export]]
extern "C" SEXP node_attrs(SEXP node_sxp, SEXP nsMap_sxp) {
  BEGIN_CPP
  XPtrNode node_(node_sxp);

  int n = 0;
  xmlNodePtr node = node_.checked_get();

  if (node->type == XML_ELEMENT_NODE) {
    // attributes
    for(xmlAttr* cur = node->properties; cur != NULL; cur = cur->next)
      n++;

    // namespace definitions
    for(xmlNsPtr cur = node->nsDef; cur != NULL; cur = cur->next)
      n++;

    SEXP names = PROTECT(Rf_allocVector(STRSXP, n));
    SEXP values = PROTECT(Rf_allocVector(STRSXP, n));

    int i = 0;
    for(xmlAttr* cur = node->properties; cur != NULL; cur = cur->next, ++i) {
      std::string name = nodeName(cur, nsMap_sxp);
      SET_STRING_ELT(names, i, Rf_mkCharLenCE(name.c_str(), name.size(), CE_UTF8));

      xmlNs* ns = cur->ns;
      if (ns == NULL) {
        if (Rf_xlength(nsMap_sxp) > 0) {
          SET_STRING_ELT(values, i, Xml2String(xmlGetNoNsProp(node, cur->name)).asRString());
        } else {
          SET_STRING_ELT(values, i, Xml2String(xmlGetProp(node, cur->name)).asRString());
        }
      } else {
        SET_STRING_ELT(values, i, Xml2String(xmlGetNsProp(node, cur->name, ns->href)).asRString());
      }
    }

    for(xmlNsPtr cur = node->nsDef; cur != NULL; cur = cur->next, ++i) {
      if (cur->prefix == NULL) {
        SET_STRING_ELT(names, i, Rf_mkChar("xmlns"));
      } else {
        std::string name = std::string("xmlns:") + Xml2String(cur->prefix).asStdString();
        SET_STRING_ELT(names,i, Rf_mkCharLenCE(name.c_str(), name.size(), CE_UTF8));
      }
      SET_STRING_ELT(values, i, Xml2String(cur->href).asRString());
    }

    Rf_setAttrib(values, R_NamesSymbol, names);

    UNPROTECT(2);
    return values;
  }

  return Rf_allocVector(STRSXP, 0);
  END_CPP
}


// Fix the tree by removing the namespace pointers to the given tree
void xmlRemoveNamespace(xmlNodePtr tree, xmlNsPtr ns) {

  // From https://github.com/GNOME/libxml2/blob/v2.9.2/tree.c#L6440
  //
  xmlNodePtr node = tree;
  /*
   * Browse the full subtree, deep first
   */
  while(node != NULL) {
    if (node->ns != NULL && node->ns == ns) {
      node->ns = NULL;
    }

    // Check for namespaces on the attributes
    if (ns->prefix != NULL && // default namespaces will not exist on attributes
        node->type == XML_ELEMENT_NODE) {
      xmlAttrPtr attr = node->properties;
      while (attr != NULL) {
        if (attr->ns != NULL && attr->ns == ns) {
          attr->ns = NULL;
        }
        attr = attr->next;
      }
    }

    if ((node->children != NULL) && (node->type != XML_ENTITY_REF_NODE)) {
      /* deep first */
      node = node->children;
    } else if ((node != tree) && (node->next != NULL)) {
      /* then siblings */
      node = node->next;
    } else if (node != tree) {
      /* go up to parents->next if needed */
      while (node != tree) {
        if (node->parent != NULL)
          node = node->parent;
        if ((node != tree) && (node->next != NULL)) {
          node = node->next;
          break;
        }
        if (node->parent == NULL) {
          node = NULL;
          break;
        }
      }
      /* exit condition */
      if (node == tree)
        node = NULL;
    } else
      break;
  }
  return;
}

// Fix the tree by adding the namespace pointers to the given tree
void xmlAddNamespace(xmlNodePtr tree, xmlNsPtr ns) {

  // Only needed for default namespaces
  if (ns->prefix != NULL) {
    return;
  }

  // From https://github.com/GNOME/libxml2/blob/v2.9.2/tree.c#L6440
  //
  xmlNodePtr node = tree;
  /*
   * Browse the full subtree, deep first
   */
  while(node != NULL) {
    if (node->ns == NULL) {
      node->ns = ns;
    }

    if ((node->children != NULL) && (node->type != XML_ENTITY_REF_NODE)) {
      /* deep first */
      node = node->children;
    } else if ((node != tree) && (node->next != NULL)) {
      /* then siblings */
      node = node->next;
    } else if (node != tree) {
      /* go up to parents->next if needed */
      while (node != tree) {
        if (node->parent != NULL)
          node = node->parent;
        if ((node != tree) && (node->next != NULL)) {
          node = node->next;
          break;
        }
        if (node->parent == NULL) {
          node = NULL;
          break;
        }
      }
      /* exit condition */
      if (node == tree)
        node = NULL;
    } else
      break;
  }
  return;
}

void removeNs(xmlNodePtr node, const xmlChar* prefix) {
  if (node == NULL) {
    return;
  }

  if (node->nsDef == NULL) {
    return;
  }

  xmlNsPtr prev = node->nsDef;
  if (xmlStrEqual(prev->prefix, prefix)) {
    node->nsDef = prev->next;
    xmlRemoveNamespace(node, prev);
    xmlFreeNs(prev);
    return;
  }

  while(prev->next != NULL) {
    xmlNsPtr cur = prev->next;
    if (xmlStrEqual(cur->prefix, prefix)) {
      prev->next = cur->next;
      xmlRemoveNamespace(node, cur);
      xmlFreeNs(cur);
      return;
    }
    prev = prev->next;
  }
  return;
}

// [[export]]
extern "C" SEXP node_set_attr(SEXP node_sxp, SEXP name_sxp, SEXP value, SEXP nsMap) {
  BEGIN_CPP
  XPtrNode node_(node_sxp);
  std::string name(CHAR(STRING_ELT(name_sxp, 0)));

  const xmlNodePtr node = node_.checked_get();

  if (name == "xmlns") {
    xmlAddNamespace(node, xmlNewNs(node, asXmlChar(value), NULL));
    return R_NilValue;
  }
  if (hasPrefix("xmlns:", name)) {
    std::string prefix = name.substr(6);
    removeNs(node, asXmlChar(prefix));
    xmlAddNamespace(node, xmlNewNs(node, asXmlChar(value), asXmlChar(prefix)));
    return R_NilValue;
  }

  if (Rf_xlength(nsMap) == 0) {
      xmlSetProp(node, asXmlChar(name), asXmlChar(value));
  } else {
    size_t colon = name.find(':');
    if (colon == std::string::npos) {
      // Has namespace spec, but attribute not qualified, so just use that name
      xmlSetProp(node, asXmlChar(name), asXmlChar(value));
    } else {
      // Split name into prefix & attr, then look up full url
      std::string
      prefix = name.substr(0, colon),
        attr = name.substr(colon + 1, name.size() - 1);

      std::string url = NsMap(nsMap).findUrl(prefix);

      xmlNsPtr ns = xmlSearchNsByHref(node_->doc, node, asXmlChar(url));

      xmlSetNsProp(node, ns, asXmlChar(attr), asXmlChar(value));
    }
  }

  return R_NilValue;
  END_CPP
}

// [[export]]
extern "C" SEXP node_remove_attr(SEXP node_sxp, SEXP name_sxp, SEXP nsMap) {
  BEGIN_CPP
  XPtrNode node_(node_sxp);
  std::string name(CHAR(STRING_ELT(name_sxp, 0)));

  const xmlNodePtr node = node_.checked_get();

  if (name == "xmlns") {
    removeNs(node, NULL);
    return R_NilValue;
  }
  if (hasPrefix("xmlns:", name)) {
    std::string prefix = name.substr(6);
    removeNs(node, asXmlChar(prefix));
    return R_NilValue;
  }

  if (Rf_xlength(nsMap) == 0) {
      xmlUnsetProp(node, asXmlChar(name));
  } else {
    size_t colon = name.find(':');
    if (colon == std::string::npos) {
      // Has namespace spec, but attribute not qualified, so just use that name
      xmlUnsetNsProp(node, NULL, asXmlChar(name));
    } else {
      // Split name into prefix & attr, then look up full url
      std::string
      prefix = name.substr(0, colon),
        attr = name.substr(colon + 1, name.size() - 1);

      std::string url = NsMap(nsMap).findUrl(prefix);

      xmlNsPtr ns = xmlSearchNsByHref(node_->doc, node, asXmlChar(url));

      xmlUnsetNsProp(node, ns, asXmlChar(attr));
    }
  }

  return R_NilValue;
  END_CPP
}

SEXP asList(std::vector<xmlNode*> nodes) {
  SEXP out = PROTECT(Rf_allocVector(VECSXP, nodes.size()));
  for (size_t i = 0; i < nodes.size(); ++i) {
    XPtrNode node(nodes[i]);
    SET_VECTOR_ELT(out, i, SEXP(node));
  }

  UNPROTECT(1);

  return out;
}

// [[export]]
extern "C" SEXP node_children(SEXP node_sxp, SEXP only_node_sxp) {
  BEGIN_CPP
  XPtrNode node(node_sxp);
  bool only_node = LOGICAL(only_node_sxp)[0];

  std::vector<xmlNode*> out;

  for(xmlNode* cur = node->xmlChildrenNode; cur != NULL; cur = cur->next) {
    if (only_node && cur->type != XML_ELEMENT_NODE) {
      continue;
    }

    out.push_back(cur);
  }

  return asList(out);
  END_CPP
}

// [[export]]
extern "C" SEXP node_length(SEXP node_sxp, SEXP only_node_sxp) {
  BEGIN_CPP

  XPtrNode node(node_sxp);
  bool only_node = LOGICAL(only_node_sxp)[0];

  int i = 0;
  for(xmlNode* cur = node->xmlChildrenNode; cur != NULL; cur = cur->next) {
    if (only_node && cur->type != XML_ELEMENT_NODE) {
      continue;
    }
    ++i;
  }

  return Rf_ScalarInteger(i);
  END_CPP
}

// [[export]]
extern "C" SEXP node_has_children(SEXP node_sxp, SEXP only_node_sxp) {
  BEGIN_CPP
  XPtrNode node(node_sxp);
  bool only_node = LOGICAL(only_node_sxp)[0];

  for(xmlNode* cur = node->xmlChildrenNode; cur != NULL; cur = cur->next) {
    if (only_node && cur->type != XML_ELEMENT_NODE) {
      continue;
    }
    return Rf_ScalarLogical(true);
  }
  return Rf_ScalarLogical(false);
  END_CPP
}

// [[export]]
extern "C" SEXP node_parents(SEXP node_sxp) {
  BEGIN_CPP
  XPtrNode node(node_sxp);

  std::vector<xmlNode*> out;

  for(xmlNode* cur = node->parent; cur != NULL; cur = cur->parent) {
    if (cur->type != XML_ELEMENT_NODE)
      continue;
    out.push_back(cur);
  }

  return asList(out);
  END_CPP
}

// [[export]]
extern "C" SEXP node_siblings(SEXP node_sxp, SEXP only_node_sxp) {
  BEGIN_CPP
  XPtrNode node(node_sxp);
  bool only_node = LOGICAL(only_node_sxp)[0];

  std::vector<xmlNode*> out;

  xmlNode* parent = node->parent;
  if (parent == NULL)
    return Rf_allocVector(VECSXP, 0);

  for(xmlNode* cur = parent->xmlChildrenNode; cur != NULL; cur = cur->next) {
    if (cur == node) {
      continue;
    }
    if (only_node && cur->type != XML_ELEMENT_NODE) {
      continue;
    }

    out.push_back(cur);
  }

  return asList(out);
  END_CPP
}


// [[export]]
extern "C" SEXP node_parent(SEXP node_sxp) {
  BEGIN_CPP
  XPtrNode node(node_sxp);

  if (node->parent == NULL) {
    Rf_error("Parent does not exist");
  }
  XPtrNode out(node->parent);
  return SEXP(out);
  END_CPP
}

// [[export]]
extern "C" SEXP node_path(SEXP node_sxp) {
  BEGIN_CPP
  XPtrNode node(node_sxp);

  return Rf_ScalarString(Xml2String(xmlGetNodePath(node.checked_get())).asRString());
  END_CPP
}

// [[export]]
extern "C" SEXP nodes_duplicated(SEXP nodes) {
  BEGIN_CPP

  std::set<xmlNode*> seen;

  int n = Rf_xlength(nodes);

  SEXP out = PROTECT(Rf_allocVector(LGLSXP, n));

  for (int i = 0; i < n; ++i) {
    bool result;
    SEXP cur = VECTOR_ELT(nodes, i);
    if (Rf_inherits(cur, "xml_node")) {
      XPtrNode node(VECTOR_ELT(cur, 0));
      result = !seen.insert(node.checked_get()).second;
    } else if (Rf_inherits(cur, "xml_missing")) {
      result = false;
    } else {
      XPtrNode node(cur);
      result = !seen.insert(node.checked_get()).second;
    }
    LOGICAL(out)[i] = result;
  }

  UNPROTECT(1);
  return out;
  END_CPP
}

// [[export]]
extern "C" SEXP node_type(SEXP node_sxp) {
  BEGIN_CPP
  XPtrNode node(node_sxp);

  return Rf_ScalarInteger(node->type);
  END_CPP
}

// [[export]]
extern "C" SEXP node_copy(SEXP node_sxp) {
  BEGIN_CPP
  XPtrNode node(node_sxp);

  XPtrNode copy(xmlCopyNode(node.checked_get(), 1));

  return SEXP(copy);
  END_CPP
}

// [[export]]
extern "C" SEXP node_set_content(SEXP node_sxp, SEXP content) {
  BEGIN_CPP
  XPtrNode node(node_sxp);

  xmlNodeSetContentLen(node.checked_get(), asXmlChar(content), Rf_xlength(STRING_ELT(content, 0)));

  return R_NilValue;
  END_CPP
}

// [[export]]
extern "C" SEXP node_append_content(SEXP node_sxp, SEXP content) {
  BEGIN_CPP
  XPtrNode node(node_sxp);

  xmlNodeAddContentLen(node.checked_get(), asXmlChar(content), Rf_xlength(STRING_ELT(content, 0)));

  return R_NilValue;
  END_CPP
}

// [[export]]
extern "C" SEXP node_new_text(SEXP node_sxp, SEXP content) {
  BEGIN_CPP
  XPtrNode node(node_sxp);

  xmlAddChild(node.checked_get(), xmlNewTextLen(asXmlChar(content), Rf_xlength(STRING_ELT(content, 0))));

  return R_NilValue;
  END_CPP
}

// [[export]]
extern "C" SEXP node_append_child(SEXP parent_sxp, SEXP cur_sxp) {
  BEGIN_CPP
  XPtrNode parent(parent_sxp);
  XPtrNode cur(cur_sxp);
  XPtrNode out(xmlAddChild(parent.checked_get(), cur.checked_get()));
  return SEXP(out);
  END_CPP
}

// [[export]]
extern "C" SEXP node_prepend_child(SEXP parent_sxp, SEXP cur_sxp) {
  BEGIN_CPP
  XPtrNode parent(parent_sxp);
  XPtrNode cur(cur_sxp);

  XPtrNode out(xmlAddPrevSibling(parent.checked_get()->children, cur.checked_get()));

  return SEXP(out);
  END_CPP
}

// Previous sibling
// [[export]]
extern "C" SEXP node_prepend_sibling(SEXP cur_sxp, SEXP elem_sxp) {
  BEGIN_CPP
  XPtrNode cur(cur_sxp);
  XPtrNode elem(elem_sxp);

  XPtrNode out(xmlAddPrevSibling(cur.checked_get(), elem.checked_get()));

  return SEXP(out);
  END_CPP
}

// Append sibling
// [[export]]
extern "C" SEXP node_append_sibling(SEXP cur_sxp, SEXP elem_sxp) {
  BEGIN_CPP
  XPtrNode cur(cur_sxp);
  XPtrNode elem(elem_sxp);
  XPtrNode out(xmlAddNextSibling(cur.checked_get(), elem.checked_get()));

  return SEXP(out);
  END_CPP
}

// Replace node
// [[export]]
extern "C" SEXP node_replace(SEXP old_sxp, SEXP cur_sxp) {
  BEGIN_CPP
  XPtrNode old(old_sxp);
  XPtrNode cur(cur_sxp);
  XPtrNode out(xmlReplaceNode(old.checked_get(), cur.checked_get()));

  return SEXP(out);
  END_CPP
}

// [[export]]
extern "C" SEXP node_remove(SEXP node_sxp, SEXP free_sxp) {
  BEGIN_CPP
  XPtrNode node(node_sxp);
  bool free = LOGICAL(free_sxp)[0];

  xmlUnlinkNode(node.checked_get());
  if (free) {
    xmlFreeNode(node.checked_get());
  }

  return R_NilValue;
  END_CPP
}

// [[export]]
extern "C" SEXP node_new(SEXP name) {
  BEGIN_CPP
  XPtrNode node(xmlNewNode(NULL, asXmlChar(name)));
  return SEXP(node);
  END_CPP
}


// [[export]]
extern "C" SEXP node_cdata_new(SEXP doc_sxp, SEXP content_sxp) {
  BEGIN_CPP
  XPtrDoc doc(doc_sxp);
  XPtrNode node(xmlNewCDataBlock(doc.checked_get(), asXmlChar(content_sxp), Rf_xlength(STRING_ELT(content_sxp, 0))));
  return SEXP(node);
  END_CPP
}

// [[export]]
extern "C" SEXP node_comment_new(SEXP content) {
  BEGIN_CPP
  XPtrNode node(xmlNewComment(asXmlChar(content)));
  return SEXP(node);
  END_CPP
}

// [[export]]
extern "C" SEXP node_new_ns(SEXP name, SEXP ns_sxp) {
  BEGIN_CPP
  XPtrNs ns(ns_sxp);
  XPtrNode node(xmlNewNode(ns.checked_get(), asXmlChar(name)));
  return SEXP(node);
  END_CPP
}

// [[export]]
extern "C" SEXP node_set_namespace_uri(SEXP doc_sxp, SEXP node_sxp, SEXP uri) {
  BEGIN_CPP
  XPtrDoc doc(doc_sxp);
  XPtrNode node(node_sxp);

  xmlNsPtr ns = xmlSearchNsByHref(doc.checked_get(), node.checked_get(), asXmlChar(uri));

  xmlSetNs(node.checked_get(), ns);

  return R_NilValue;
  END_CPP
}

// [[export]]
extern "C" SEXP node_set_namespace_prefix(SEXP doc_sxp, SEXP node_sxp, SEXP prefix_sxp) {
  BEGIN_CPP
  XPtrDoc doc(doc_sxp);
  XPtrNode node(node_sxp);

  xmlNsPtr ns = NULL;
  if (Rf_xlength(STRING_ELT(prefix_sxp, 0)) == 0) {
    ns = xmlSearchNs(doc.checked_get(), node.checked_get(), NULL);
  } else {
    ns = xmlSearchNs(doc.checked_get(), node.checked_get(), asXmlChar(prefix_sxp));
  }

  xmlSetNs(node.checked_get(), ns);

  return R_NilValue;
  END_CPP
}

// [[export]]
extern "C" SEXP node_new_dtd(SEXP doc_sxp, SEXP name_sxp, SEXP eid_sxp, SEXP sid_sxp) {
  BEGIN_CPP
  XPtrDoc doc(doc_sxp);
  std::string name(CHAR(STRING_ELT(name_sxp, 0)));
  std::string eid(CHAR(STRING_ELT(eid_sxp, 0)));
  std::string sid(CHAR(STRING_ELT(sid_sxp, 0)));

  xmlDtdPtr dtd = xmlNewDtd(doc, name == "" ? NULL : asXmlChar(name), eid == "" ? NULL : asXmlChar(eid), sid == "" ? NULL : asXmlChar(sid));
  xmlAddChild(reinterpret_cast<xmlNodePtr>(doc.checked_get()), reinterpret_cast<xmlNodePtr>(dtd));

  return R_NilValue;
  END_CPP
}
