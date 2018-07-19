#include <boost/graph/adjacency_list.hpp>

boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS>
create_graph()
{
  using Graph = boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS>;
  Graph g(7);
  boost::add_edge(0, 1, g);
  boost::add_edge(0, 2, g);
  boost::add_edge(1, 3, g);
  boost::add_edge(1, 4, g);
  boost::add_edge(2, 5, g);
  boost::add_edge(5, 6, g);
  return g;
}
