// Generated by cpp11: do not edit by hand
// clang-format off

#include "xml2_types.h"
#include "cpp11/declarations.hpp"
#include <R_ext/Visibility.h>

// connection.cpp
cpp11::sexp read_connection_(SEXP con_sxp, SEXP read_size_sxp);
extern "C" SEXP _xml2_read_connection_(SEXP con_sxp, SEXP read_size_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(read_connection_(cpp11::as_cpp<cpp11::decay_t<SEXP>>(con_sxp), cpp11::as_cpp<cpp11::decay_t<SEXP>>(read_size_sxp)));
  END_CPP11
}
// xml2_doc.cpp
cpp11::sexp  xml_parse_options_();
extern "C" SEXP _xml2_xml_parse_options_() {
  BEGIN_CPP11
    return cpp11::as_sexp(xml_parse_options_());
  END_CPP11
}
// xml2_doc.cpp
cpp11::sexp doc_parse_file(cpp11::strings path_sxp, cpp11::strings encoding_sxp, cpp11::logicals as_html_sxp, cpp11::integers options_sxp);
extern "C" SEXP _xml2_doc_parse_file(SEXP path_sxp, SEXP encoding_sxp, SEXP as_html_sxp, SEXP options_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(doc_parse_file(cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(path_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(encoding_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::logicals>>(as_html_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::integers>>(options_sxp)));
  END_CPP11
}
// xml2_doc.cpp
cpp11::sexp doc_parse_raw(cpp11::raws x, cpp11::strings encoding_sxp, cpp11::strings base_url_sxp, cpp11::logicals as_html_sxp, cpp11::integers options_sxp);
extern "C" SEXP _xml2_doc_parse_raw(SEXP x, SEXP encoding_sxp, SEXP base_url_sxp, SEXP as_html_sxp, SEXP options_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(doc_parse_raw(cpp11::as_cpp<cpp11::decay_t<cpp11::raws>>(x), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(encoding_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(base_url_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::logicals>>(as_html_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::integers>>(options_sxp)));
  END_CPP11
}
// xml2_doc.cpp
cpp11::sexp doc_root(cpp11::sexp x);
extern "C" SEXP _xml2_doc_root(SEXP x) {
  BEGIN_CPP11
    return cpp11::as_sexp(doc_root(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(x)));
  END_CPP11
}
// xml2_doc.cpp
cpp11::logicals doc_has_root(cpp11::sexp x_sxp);
extern "C" SEXP _xml2_doc_has_root(SEXP x_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(doc_has_root(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(x_sxp)));
  END_CPP11
}
// xml2_doc.cpp
cpp11::strings doc_url(cpp11::sexp doc_sxp);
extern "C" SEXP _xml2_doc_url(SEXP doc_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(doc_url(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(doc_sxp)));
  END_CPP11
}
// xml2_doc.cpp
cpp11::sexp doc_new(cpp11::strings version_sxp, cpp11::strings encoding_sxp);
extern "C" SEXP _xml2_doc_new(SEXP version_sxp, SEXP encoding_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(doc_new(cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(version_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(encoding_sxp)));
  END_CPP11
}
// xml2_doc.cpp
cpp11::sexp doc_set_root(cpp11::sexp doc_sxp, cpp11::sexp root_sxp);
extern "C" SEXP _xml2_doc_set_root(SEXP doc_sxp, SEXP root_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(doc_set_root(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(doc_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(root_sxp)));
  END_CPP11
}
// xml2_doc.cpp
cpp11::sexp doc_is_html(cpp11::sexp doc_sxp);
extern "C" SEXP _xml2_doc_is_html(SEXP doc_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(doc_is_html(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(doc_sxp)));
  END_CPP11
}
// xml2_init.cpp
cpp11::sexp init_libxml2();
extern "C" SEXP _xml2_init_libxml2() {
  BEGIN_CPP11
    return cpp11::as_sexp(init_libxml2());
  END_CPP11
}
// xml2_init.cpp
cpp11::strings libxml2_version_();
extern "C" SEXP _xml2_libxml2_version_() {
  BEGIN_CPP11
    return cpp11::as_sexp(libxml2_version_());
  END_CPP11
}
// xml2_namespace.cpp
cpp11::sexp unique_ns(SEXP ns);
extern "C" SEXP _xml2_unique_ns(SEXP ns) {
  BEGIN_CPP11
    return cpp11::as_sexp(unique_ns(cpp11::as_cpp<cpp11::decay_t<SEXP>>(ns)));
  END_CPP11
}
// xml2_namespace.cpp
cpp11::sexp doc_namespaces(SEXP doc_sxp);
extern "C" SEXP _xml2_doc_namespaces(SEXP doc_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(doc_namespaces(cpp11::as_cpp<cpp11::decay_t<SEXP>>(doc_sxp)));
  END_CPP11
}
// xml2_namespace.cpp
cpp11::sexp ns_lookup_uri(SEXP doc_sxp, SEXP node_sxp, SEXP uri_sxp);
extern "C" SEXP _xml2_ns_lookup_uri(SEXP doc_sxp, SEXP node_sxp, SEXP uri_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(ns_lookup_uri(cpp11::as_cpp<cpp11::decay_t<SEXP>>(doc_sxp), cpp11::as_cpp<cpp11::decay_t<SEXP>>(node_sxp), cpp11::as_cpp<cpp11::decay_t<SEXP>>(uri_sxp)));
  END_CPP11
}
// xml2_namespace.cpp
cpp11::sexp ns_lookup(SEXP doc_sxp, SEXP node_sxp, SEXP prefix_sxp);
extern "C" SEXP _xml2_ns_lookup(SEXP doc_sxp, SEXP node_sxp, SEXP prefix_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(ns_lookup(cpp11::as_cpp<cpp11::decay_t<SEXP>>(doc_sxp), cpp11::as_cpp<cpp11::decay_t<SEXP>>(node_sxp), cpp11::as_cpp<cpp11::decay_t<SEXP>>(prefix_sxp)));
  END_CPP11
}
// xml2_node.cpp
cpp11::strings node_name(cpp11::list x, cpp11::strings nsMap);
extern "C" SEXP _xml2_node_name(SEXP x, SEXP nsMap) {
  BEGIN_CPP11
    return cpp11::as_sexp(node_name(cpp11::as_cpp<cpp11::decay_t<cpp11::list>>(x), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(nsMap)));
  END_CPP11
}
// xml2_node.cpp
SEXP node_set_name(node_pointer node_sxp, cpp11::strings value);
extern "C" SEXP _xml2_node_set_name(SEXP node_sxp, SEXP value) {
  BEGIN_CPP11
    return cpp11::as_sexp(node_set_name(cpp11::as_cpp<cpp11::decay_t<node_pointer>>(node_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(value)));
  END_CPP11
}
// xml2_node.cpp
cpp11::strings node_text(cpp11::list x);
extern "C" SEXP _xml2_node_text(SEXP x) {
  BEGIN_CPP11
    return cpp11::as_sexp(node_text(cpp11::as_cpp<cpp11::decay_t<cpp11::list>>(x)));
  END_CPP11
}
// xml2_node.cpp
cpp11::strings node_attr(cpp11::list x, cpp11::strings name_sxp, cpp11::strings missing_sxp, cpp11::strings nsMap_sxp);
extern "C" SEXP _xml2_node_attr(SEXP x, SEXP name_sxp, SEXP missing_sxp, SEXP nsMap_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(node_attr(cpp11::as_cpp<cpp11::decay_t<cpp11::list>>(x), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(name_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(missing_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(nsMap_sxp)));
  END_CPP11
}
// xml2_node.cpp
cpp11::sexp node_attrs(cpp11::list x, cpp11::strings nsMap_sxp);
extern "C" SEXP _xml2_node_attrs(SEXP x, SEXP nsMap_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(node_attrs(cpp11::as_cpp<cpp11::decay_t<cpp11::list>>(x), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(nsMap_sxp)));
  END_CPP11
}
// xml2_node.cpp
cpp11::sexp node_set_attr(node_pointer node_sxp, cpp11::strings name_sxp, cpp11::strings value, cpp11::strings nsMap);
extern "C" SEXP _xml2_node_set_attr(SEXP node_sxp, SEXP name_sxp, SEXP value, SEXP nsMap) {
  BEGIN_CPP11
    return cpp11::as_sexp(node_set_attr(cpp11::as_cpp<cpp11::decay_t<node_pointer>>(node_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(name_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(value), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(nsMap)));
  END_CPP11
}
// xml2_node.cpp
cpp11::sexp node_remove_attr(node_pointer node_sxp, cpp11::strings name_sxp, cpp11::strings nsMap);
extern "C" SEXP _xml2_node_remove_attr(SEXP node_sxp, SEXP name_sxp, SEXP nsMap) {
  BEGIN_CPP11
    return cpp11::as_sexp(node_remove_attr(cpp11::as_cpp<cpp11::decay_t<node_pointer>>(node_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(name_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(nsMap)));
  END_CPP11
}
// xml2_node.cpp
cpp11::list node_children(node_pointer node_sxp, cpp11::logicals only_node_sxp);
extern "C" SEXP _xml2_node_children(SEXP node_sxp, SEXP only_node_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(node_children(cpp11::as_cpp<cpp11::decay_t<node_pointer>>(node_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::logicals>>(only_node_sxp)));
  END_CPP11
}
// xml2_node.cpp
cpp11::integers node_length(cpp11::list x, cpp11::logicals only_node_sxp);
extern "C" SEXP _xml2_node_length(SEXP x, SEXP only_node_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(node_length(cpp11::as_cpp<cpp11::decay_t<cpp11::list>>(x), cpp11::as_cpp<cpp11::decay_t<cpp11::logicals>>(only_node_sxp)));
  END_CPP11
}
// xml2_node.cpp
cpp11::logicals node_has_children(node_pointer node_sxp, cpp11::logicals only_node_sxp);
extern "C" SEXP _xml2_node_has_children(SEXP node_sxp, SEXP only_node_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(node_has_children(cpp11::as_cpp<cpp11::decay_t<node_pointer>>(node_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::logicals>>(only_node_sxp)));
  END_CPP11
}
// xml2_node.cpp
cpp11::list node_parents(node_pointer node_sxp);
extern "C" SEXP _xml2_node_parents(SEXP node_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(node_parents(cpp11::as_cpp<cpp11::decay_t<node_pointer>>(node_sxp)));
  END_CPP11
}
// xml2_node.cpp
cpp11::list node_siblings(node_pointer node_sxp, cpp11::logicals only_node_sxp);
extern "C" SEXP _xml2_node_siblings(SEXP node_sxp, SEXP only_node_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(node_siblings(cpp11::as_cpp<cpp11::decay_t<node_pointer>>(node_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::logicals>>(only_node_sxp)));
  END_CPP11
}
// xml2_node.cpp
node_pointer node_parent(node_pointer node_sxp);
extern "C" SEXP _xml2_node_parent(SEXP node_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(node_parent(cpp11::as_cpp<cpp11::decay_t<node_pointer>>(node_sxp)));
  END_CPP11
}
// xml2_node.cpp
cpp11::strings node_path(cpp11::list x);
extern "C" SEXP _xml2_node_path(SEXP x) {
  BEGIN_CPP11
    return cpp11::as_sexp(node_path(cpp11::as_cpp<cpp11::decay_t<cpp11::list>>(x)));
  END_CPP11
}
// xml2_node.cpp
cpp11::logicals nodes_duplicated(cpp11::list nodes);
extern "C" SEXP _xml2_nodes_duplicated(SEXP nodes) {
  BEGIN_CPP11
    return cpp11::as_sexp(nodes_duplicated(cpp11::as_cpp<cpp11::decay_t<cpp11::list>>(nodes)));
  END_CPP11
}
// xml2_node.cpp
cpp11::integers node_type(cpp11::list x);
extern "C" SEXP _xml2_node_type(SEXP x) {
  BEGIN_CPP11
    return cpp11::as_sexp(node_type(cpp11::as_cpp<cpp11::decay_t<cpp11::list>>(x)));
  END_CPP11
}
// xml2_node.cpp
node_pointer node_copy(node_pointer node_sxp);
extern "C" SEXP _xml2_node_copy(SEXP node_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(node_copy(cpp11::as_cpp<cpp11::decay_t<node_pointer>>(node_sxp)));
  END_CPP11
}
// xml2_node.cpp
cpp11::sexp node_set_content(node_pointer node_sxp, cpp11::strings content);
extern "C" SEXP _xml2_node_set_content(SEXP node_sxp, SEXP content) {
  BEGIN_CPP11
    return cpp11::as_sexp(node_set_content(cpp11::as_cpp<cpp11::decay_t<node_pointer>>(node_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(content)));
  END_CPP11
}
// xml2_node.cpp
cpp11::sexp node_append_content(node_pointer node_sxp, cpp11::strings content);
extern "C" SEXP _xml2_node_append_content(SEXP node_sxp, SEXP content) {
  BEGIN_CPP11
    return cpp11::as_sexp(node_append_content(cpp11::as_cpp<cpp11::decay_t<node_pointer>>(node_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(content)));
  END_CPP11
}
// xml2_node.cpp
cpp11::sexp node_new_text(node_pointer node_sxp, cpp11::strings content);
extern "C" SEXP _xml2_node_new_text(SEXP node_sxp, SEXP content) {
  BEGIN_CPP11
    return cpp11::as_sexp(node_new_text(cpp11::as_cpp<cpp11::decay_t<node_pointer>>(node_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(content)));
  END_CPP11
}
// xml2_node.cpp
node_pointer node_append_child(node_pointer parent_sxp, node_pointer cur_sxp);
extern "C" SEXP _xml2_node_append_child(SEXP parent_sxp, SEXP cur_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(node_append_child(cpp11::as_cpp<cpp11::decay_t<node_pointer>>(parent_sxp), cpp11::as_cpp<cpp11::decay_t<node_pointer>>(cur_sxp)));
  END_CPP11
}
// xml2_node.cpp
node_pointer node_prepend_child(node_pointer parent_sxp, node_pointer cur_sxp);
extern "C" SEXP _xml2_node_prepend_child(SEXP parent_sxp, SEXP cur_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(node_prepend_child(cpp11::as_cpp<cpp11::decay_t<node_pointer>>(parent_sxp), cpp11::as_cpp<cpp11::decay_t<node_pointer>>(cur_sxp)));
  END_CPP11
}
// xml2_node.cpp
node_pointer node_prepend_sibling(node_pointer cur_sxp, node_pointer elem_sxp);
extern "C" SEXP _xml2_node_prepend_sibling(SEXP cur_sxp, SEXP elem_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(node_prepend_sibling(cpp11::as_cpp<cpp11::decay_t<node_pointer>>(cur_sxp), cpp11::as_cpp<cpp11::decay_t<node_pointer>>(elem_sxp)));
  END_CPP11
}
// xml2_node.cpp
node_pointer node_append_sibling(node_pointer cur_sxp, node_pointer elem_sxp);
extern "C" SEXP _xml2_node_append_sibling(SEXP cur_sxp, SEXP elem_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(node_append_sibling(cpp11::as_cpp<cpp11::decay_t<node_pointer>>(cur_sxp), cpp11::as_cpp<cpp11::decay_t<node_pointer>>(elem_sxp)));
  END_CPP11
}
// xml2_node.cpp
node_pointer node_replace(node_pointer old_sxp, node_pointer cur_sxp);
extern "C" SEXP _xml2_node_replace(SEXP old_sxp, SEXP cur_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(node_replace(cpp11::as_cpp<cpp11::decay_t<node_pointer>>(old_sxp), cpp11::as_cpp<cpp11::decay_t<node_pointer>>(cur_sxp)));
  END_CPP11
}
// xml2_node.cpp
cpp11::sexp node_remove(node_pointer node_sxp, cpp11::logicals free_sxp);
extern "C" SEXP _xml2_node_remove(SEXP node_sxp, SEXP free_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(node_remove(cpp11::as_cpp<cpp11::decay_t<node_pointer>>(node_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::logicals>>(free_sxp)));
  END_CPP11
}
// xml2_node.cpp
cpp11::sexp node_new(cpp11::strings name);
extern "C" SEXP _xml2_node_new(SEXP name) {
  BEGIN_CPP11
    return cpp11::as_sexp(node_new(cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(name)));
  END_CPP11
}
// xml2_node.cpp
cpp11::sexp node_cdata_new(cpp11::sexp doc_sxp, cpp11::strings content_sxp);
extern "C" SEXP _xml2_node_cdata_new(SEXP doc_sxp, SEXP content_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(node_cdata_new(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(doc_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(content_sxp)));
  END_CPP11
}
// xml2_node.cpp
node_pointer node_comment_new(cpp11::strings content);
extern "C" SEXP _xml2_node_comment_new(SEXP content) {
  BEGIN_CPP11
    return cpp11::as_sexp(node_comment_new(cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(content)));
  END_CPP11
}
// xml2_node.cpp
node_pointer node_new_ns(cpp11::strings name, cpp11::external_pointer<xmlNs> ns_sxp);
extern "C" SEXP _xml2_node_new_ns(SEXP name, SEXP ns_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(node_new_ns(cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(name), cpp11::as_cpp<cpp11::decay_t<cpp11::external_pointer<xmlNs>>>(ns_sxp)));
  END_CPP11
}
// xml2_node.cpp
cpp11::sexp node_set_namespace_uri(doc_pointer doc_sxp, node_pointer node_sxp, cpp11::strings uri);
extern "C" SEXP _xml2_node_set_namespace_uri(SEXP doc_sxp, SEXP node_sxp, SEXP uri) {
  BEGIN_CPP11
    return cpp11::as_sexp(node_set_namespace_uri(cpp11::as_cpp<cpp11::decay_t<doc_pointer>>(doc_sxp), cpp11::as_cpp<cpp11::decay_t<node_pointer>>(node_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(uri)));
  END_CPP11
}
// xml2_node.cpp
cpp11::sexp node_set_namespace_prefix(doc_pointer doc_sxp, node_pointer node_sxp, cpp11::strings prefix_sxp);
extern "C" SEXP _xml2_node_set_namespace_prefix(SEXP doc_sxp, SEXP node_sxp, SEXP prefix_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(node_set_namespace_prefix(cpp11::as_cpp<cpp11::decay_t<doc_pointer>>(doc_sxp), cpp11::as_cpp<cpp11::decay_t<node_pointer>>(node_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(prefix_sxp)));
  END_CPP11
}
// xml2_node.cpp
cpp11::sexp node_new_dtd(doc_pointer doc_sxp, cpp11::strings name_sxp, cpp11::strings eid_sxp, cpp11::strings sid_sxp);
extern "C" SEXP _xml2_node_new_dtd(SEXP doc_sxp, SEXP name_sxp, SEXP eid_sxp, SEXP sid_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(node_new_dtd(cpp11::as_cpp<cpp11::decay_t<doc_pointer>>(doc_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(name_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(eid_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(sid_sxp)));
  END_CPP11
}
// xml2_output.cpp
cpp11::writable::integers xml_save_options_();
extern "C" SEXP _xml2_xml_save_options_() {
  BEGIN_CPP11
    return cpp11::as_sexp(xml_save_options_());
  END_CPP11
}
// xml2_output.cpp
cpp11::sexp doc_write_file(cpp11::sexp doc_sxp, cpp11::strings path_sxp, cpp11::strings encoding_sxp, cpp11::integers options_sxp);
extern "C" SEXP _xml2_doc_write_file(SEXP doc_sxp, SEXP path_sxp, SEXP encoding_sxp, SEXP options_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(doc_write_file(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(doc_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(path_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(encoding_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::integers>>(options_sxp)));
  END_CPP11
}
// xml2_output.cpp
cpp11::sexp doc_write_connection(cpp11::sexp doc_sxp, cpp11::sexp connection, cpp11::strings encoding_sxp, cpp11::integers options_sxp);
extern "C" SEXP _xml2_doc_write_connection(SEXP doc_sxp, SEXP connection, SEXP encoding_sxp, SEXP options_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(doc_write_connection(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(doc_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(connection), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(encoding_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::integers>>(options_sxp)));
  END_CPP11
}
// xml2_output.cpp
cpp11::writable::strings doc_write_character(cpp11::sexp doc_sxp, cpp11::strings encoding_sxp, cpp11::integers options_sxp);
extern "C" SEXP _xml2_doc_write_character(SEXP doc_sxp, SEXP encoding_sxp, SEXP options_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(doc_write_character(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(doc_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(encoding_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::integers>>(options_sxp)));
  END_CPP11
}
// xml2_output.cpp
cpp11::sexp node_write_file(cpp11::sexp node_sxp, cpp11::strings path_sxp, cpp11::strings encoding_sxp, cpp11::integers options_sxp);
extern "C" SEXP _xml2_node_write_file(SEXP node_sxp, SEXP path_sxp, SEXP encoding_sxp, SEXP options_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(node_write_file(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(node_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(path_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(encoding_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::integers>>(options_sxp)));
  END_CPP11
}
// xml2_output.cpp
cpp11::sexp node_write_connection(cpp11::sexp node_sxp, cpp11::sexp connection, cpp11::strings encoding_sxp, cpp11::integers options_sxp);
extern "C" SEXP _xml2_node_write_connection(SEXP node_sxp, SEXP connection, SEXP encoding_sxp, SEXP options_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(node_write_connection(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(node_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(connection), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(encoding_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::integers>>(options_sxp)));
  END_CPP11
}
// xml2_output.cpp
cpp11::writable::strings node_write_character(cpp11::sexp node_sxp, cpp11::strings encoding_sxp, cpp11::integers options_sxp);
extern "C" SEXP _xml2_node_write_character(SEXP node_sxp, SEXP encoding_sxp, SEXP options_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(node_write_character(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(node_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(encoding_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::integers>>(options_sxp)));
  END_CPP11
}
// xml2_schema.cpp
cpp11::logicals doc_validate(cpp11::sexp doc_sxp, cpp11::sexp schema_sxp);
extern "C" SEXP _xml2_doc_validate(SEXP doc_sxp, SEXP schema_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(doc_validate(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(doc_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(schema_sxp)));
  END_CPP11
}
// xml2_url.cpp
cpp11::strings url_absolute_(cpp11::strings x_sxp, cpp11::strings base_sxp);
extern "C" SEXP _xml2_url_absolute_(SEXP x_sxp, SEXP base_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(url_absolute_(cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(x_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(base_sxp)));
  END_CPP11
}
// xml2_url.cpp
cpp11::strings url_relative_(cpp11::strings x_sxp, cpp11::strings base_sxp);
extern "C" SEXP _xml2_url_relative_(SEXP x_sxp, SEXP base_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(url_relative_(cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(x_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(base_sxp)));
  END_CPP11
}
// xml2_url.cpp
cpp11::data_frame url_parse_(cpp11::strings x_sxp);
extern "C" SEXP _xml2_url_parse_(SEXP x_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(url_parse_(cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(x_sxp)));
  END_CPP11
}
// xml2_url.cpp
cpp11::strings url_escape_(cpp11::strings x_sxp, cpp11::strings reserved_sxp);
extern "C" SEXP _xml2_url_escape_(SEXP x_sxp, SEXP reserved_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(url_escape_(cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(x_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(reserved_sxp)));
  END_CPP11
}
// xml2_url.cpp
cpp11::strings url_unescape_(cpp11::strings x_sxp);
extern "C" SEXP _xml2_url_unescape_(SEXP x_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(url_unescape_(cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(x_sxp)));
  END_CPP11
}
// xml2_xpath.cpp
cpp11::sexp xpath_search(cpp11::sexp node_sxp, cpp11::sexp doc_sxp, cpp11::sexp xpath_sxp, cpp11::strings nsMap_sxp, cpp11::doubles num_results_sxp);
extern "C" SEXP _xml2_xpath_search(SEXP node_sxp, SEXP doc_sxp, SEXP xpath_sxp, SEXP nsMap_sxp, SEXP num_results_sxp) {
  BEGIN_CPP11
    return cpp11::as_sexp(xpath_search(cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(node_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(doc_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(xpath_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(nsMap_sxp), cpp11::as_cpp<cpp11::decay_t<cpp11::doubles>>(num_results_sxp)));
  END_CPP11
}

extern "C" {
static const R_CallMethodDef CallEntries[] = {
    {"_xml2_doc_has_root",              (DL_FUNC) &_xml2_doc_has_root,              1},
    {"_xml2_doc_is_html",               (DL_FUNC) &_xml2_doc_is_html,               1},
    {"_xml2_doc_namespaces",            (DL_FUNC) &_xml2_doc_namespaces,            1},
    {"_xml2_doc_new",                   (DL_FUNC) &_xml2_doc_new,                   2},
    {"_xml2_doc_parse_file",            (DL_FUNC) &_xml2_doc_parse_file,            4},
    {"_xml2_doc_parse_raw",             (DL_FUNC) &_xml2_doc_parse_raw,             5},
    {"_xml2_doc_root",                  (DL_FUNC) &_xml2_doc_root,                  1},
    {"_xml2_doc_set_root",              (DL_FUNC) &_xml2_doc_set_root,              2},
    {"_xml2_doc_url",                   (DL_FUNC) &_xml2_doc_url,                   1},
    {"_xml2_doc_validate",              (DL_FUNC) &_xml2_doc_validate,              2},
    {"_xml2_doc_write_character",       (DL_FUNC) &_xml2_doc_write_character,       3},
    {"_xml2_doc_write_connection",      (DL_FUNC) &_xml2_doc_write_connection,      4},
    {"_xml2_doc_write_file",            (DL_FUNC) &_xml2_doc_write_file,            4},
    {"_xml2_init_libxml2",              (DL_FUNC) &_xml2_init_libxml2,              0},
    {"_xml2_libxml2_version_",          (DL_FUNC) &_xml2_libxml2_version_,          0},
    {"_xml2_node_append_child",         (DL_FUNC) &_xml2_node_append_child,         2},
    {"_xml2_node_append_content",       (DL_FUNC) &_xml2_node_append_content,       2},
    {"_xml2_node_append_sibling",       (DL_FUNC) &_xml2_node_append_sibling,       2},
    {"_xml2_node_attr",                 (DL_FUNC) &_xml2_node_attr,                 4},
    {"_xml2_node_attrs",                (DL_FUNC) &_xml2_node_attrs,                2},
    {"_xml2_node_cdata_new",            (DL_FUNC) &_xml2_node_cdata_new,            2},
    {"_xml2_node_children",             (DL_FUNC) &_xml2_node_children,             2},
    {"_xml2_node_comment_new",          (DL_FUNC) &_xml2_node_comment_new,          1},
    {"_xml2_node_copy",                 (DL_FUNC) &_xml2_node_copy,                 1},
    {"_xml2_node_has_children",         (DL_FUNC) &_xml2_node_has_children,         2},
    {"_xml2_node_length",               (DL_FUNC) &_xml2_node_length,               2},
    {"_xml2_node_name",                 (DL_FUNC) &_xml2_node_name,                 2},
    {"_xml2_node_new",                  (DL_FUNC) &_xml2_node_new,                  1},
    {"_xml2_node_new_dtd",              (DL_FUNC) &_xml2_node_new_dtd,              4},
    {"_xml2_node_new_ns",               (DL_FUNC) &_xml2_node_new_ns,               2},
    {"_xml2_node_new_text",             (DL_FUNC) &_xml2_node_new_text,             2},
    {"_xml2_node_parent",               (DL_FUNC) &_xml2_node_parent,               1},
    {"_xml2_node_parents",              (DL_FUNC) &_xml2_node_parents,              1},
    {"_xml2_node_path",                 (DL_FUNC) &_xml2_node_path,                 1},
    {"_xml2_node_prepend_child",        (DL_FUNC) &_xml2_node_prepend_child,        2},
    {"_xml2_node_prepend_sibling",      (DL_FUNC) &_xml2_node_prepend_sibling,      2},
    {"_xml2_node_remove",               (DL_FUNC) &_xml2_node_remove,               2},
    {"_xml2_node_remove_attr",          (DL_FUNC) &_xml2_node_remove_attr,          3},
    {"_xml2_node_replace",              (DL_FUNC) &_xml2_node_replace,              2},
    {"_xml2_node_set_attr",             (DL_FUNC) &_xml2_node_set_attr,             4},
    {"_xml2_node_set_content",          (DL_FUNC) &_xml2_node_set_content,          2},
    {"_xml2_node_set_name",             (DL_FUNC) &_xml2_node_set_name,             2},
    {"_xml2_node_set_namespace_prefix", (DL_FUNC) &_xml2_node_set_namespace_prefix, 3},
    {"_xml2_node_set_namespace_uri",    (DL_FUNC) &_xml2_node_set_namespace_uri,    3},
    {"_xml2_node_siblings",             (DL_FUNC) &_xml2_node_siblings,             2},
    {"_xml2_node_text",                 (DL_FUNC) &_xml2_node_text,                 1},
    {"_xml2_node_type",                 (DL_FUNC) &_xml2_node_type,                 1},
    {"_xml2_node_write_character",      (DL_FUNC) &_xml2_node_write_character,      3},
    {"_xml2_node_write_connection",     (DL_FUNC) &_xml2_node_write_connection,     4},
    {"_xml2_node_write_file",           (DL_FUNC) &_xml2_node_write_file,           4},
    {"_xml2_nodes_duplicated",          (DL_FUNC) &_xml2_nodes_duplicated,          1},
    {"_xml2_ns_lookup",                 (DL_FUNC) &_xml2_ns_lookup,                 3},
    {"_xml2_ns_lookup_uri",             (DL_FUNC) &_xml2_ns_lookup_uri,             3},
    {"_xml2_read_connection_",          (DL_FUNC) &_xml2_read_connection_,          2},
    {"_xml2_unique_ns",                 (DL_FUNC) &_xml2_unique_ns,                 1},
    {"_xml2_url_absolute_",             (DL_FUNC) &_xml2_url_absolute_,             2},
    {"_xml2_url_escape_",               (DL_FUNC) &_xml2_url_escape_,               2},
    {"_xml2_url_parse_",                (DL_FUNC) &_xml2_url_parse_,                1},
    {"_xml2_url_relative_",             (DL_FUNC) &_xml2_url_relative_,             2},
    {"_xml2_url_unescape_",             (DL_FUNC) &_xml2_url_unescape_,             1},
    {"_xml2_xml_parse_options_",        (DL_FUNC) &_xml2_xml_parse_options_,        0},
    {"_xml2_xml_save_options_",         (DL_FUNC) &_xml2_xml_save_options_,         0},
    {"_xml2_xpath_search",              (DL_FUNC) &_xml2_xpath_search,              5},
    {NULL, NULL, 0}
};
}

extern "C" attribute_visible void R_init_xml2(DllInfo* dll){
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
  R_forceSymbols(dll, TRUE);
}
