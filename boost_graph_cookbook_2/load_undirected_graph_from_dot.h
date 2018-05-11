#ifndef LOAD_UNDIRECTED_GRAPH_FROM_DOT_H
#define LOAD_UNDIRECTED_GRAPH_FROM_DOT_H

#ifndef BOOST_GRAPH_COOKBOOK_2_NO_GRAPHVIZ

#include "create_empty_undirected_graph.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS
>
load_undirected_graph_from_dot(
  const std::string& dot_filename
);

#else
#error(Do not include this file when BOOST_GRAPH_COOKBOOK_2_NO_GRAPHVIZ is defined)
#endif // BOOST_GRAPH_COOKBOOK_2_NO_GRAPHVIZ

#endif // LOAD_UNDIRECTED_GRAPH_FROM_DOT_H
