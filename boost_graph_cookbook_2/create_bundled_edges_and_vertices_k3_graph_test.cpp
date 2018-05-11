#include "create_bundled_edges_and_vertices_k3_graph.h"
#include "create_bundled_edges_and_vertices_k3_graph_demo.impl"

#include <boost/test/unit_test.hpp>

#include "add_bundled_edge.h"
#include "add_bundled_vertex.h"
#include "save_bundled_edges_and_vertices_graph_to_dot.h"
#include "save_custom_edges_and_vertices_graph_to_dot.h"
#include "convert_dot_to_svg.h"
#include "copy_file.h"

BOOST_AUTO_TEST_CASE(create_bundled_edges_and_vertices_k3_graph_thorough)
{
  {
    auto g = create_bundled_edges_and_vertices_k3_graph();
    BOOST_CHECK(boost::num_edges(g) == 3);
    BOOST_CHECK(boost::num_vertices(g) == 3);
  }
  #ifndef BOOST_GRAPH_COOKBOOK_2_NO_GRAPHVIZ
  //Create the .dot and .svg of the 'create_bundled_edges_and_vertices_k3_graph' chapter
  {
    const auto g = create_bundled_edges_and_vertices_k3_graph();
    const std::string base_filename{"create_bundled_edges_and_vertices_k3_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_bundled_edges_and_vertices_graph_to_dot(g, dot_filename);
    convert_dot_to_svg(dot_filename, svg_filename);
    copy_file(
      dot_filename,
      "../boost_graph_cookbook_2/" + dot_filename,
      copy_file_mode::allow_overwrite
    );
    copy_file(
      svg_filename,
      "../boost_graph_cookbook_2/" + svg_filename,
      copy_file_mode::allow_overwrite
    );
    std::remove(dot_filename.c_str());
    std::remove(svg_filename.c_str());
  }
  #endif// BOOST_GRAPH_COOKBOOK_2_NO_GRAPHVIZ
}
