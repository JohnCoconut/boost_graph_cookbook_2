#include "set_my_bundled_edge.h"
#include "set_my_bundled_edge_demo.impl"


#include <boost/test/unit_test.hpp>

#include "get_my_bundled_edge.h"
#include "create_empty_undirected_bundled_edges_and_vertices_graph.h"
#include "add_bundled_edge.h"
#include "find_first_bundled_edge_with_my_edge.h"
#include "add_bundled_vertex.h"

BOOST_AUTO_TEST_CASE(set_my_bundled_edge_thorough)
{
  {
    auto g = create_empty_undirected_bundled_edges_and_vertices_graph();
    const my_bundled_edge old_edge{"Dex"};
    const auto vd_a = add_bundled_vertex(my_bundled_vertex{"A"}, g);
    const auto vd_b = add_bundled_vertex(my_bundled_vertex{"B"}, g);
    add_bundled_edge(vd_a, vd_b, old_edge, g);
    const auto vd = find_first_bundled_edge_with_my_edge(old_edge, g);
    BOOST_CHECK(get_my_bundled_edge(vd, g) == old_edge);
    const my_bundled_edge new_edge{"Diggy"};
    set_my_bundled_edge(new_edge, vd, g);
    BOOST_CHECK(get_my_bundled_edge(vd, g) == new_edge);
  }
  
}
