#ifndef BOOST_GRAPH_COOKBOOK_2_NO_GRAPHVIZ
#include "save_bundled_vertices_graph_to_dot.h"
//#include "save_bundled_vertices_graph_to_dot_demo.impl"

#include <boost/test/unit_test.hpp>
#include <sstream>

#include "copy_file.h"
#include "create_bundled_vertices_k2_graph.h"
#include "show_dot.h"
#include "convert_dot_to_svg.h"
#include "is_regular_file.h"
#include "file_to_vector.h"

BOOST_AUTO_TEST_CASE(save_bundled_vertices_graph_to_dot_thorough)
{
  //Show it does store the vertex names
  {
    const auto g = create_bundled_vertices_k2_graph();

    const std::string base_filename{"save_bundled_vertices_graph_to_dot_test_bundled_vertices_k2_graph"};
    const std::string dot_filename{base_filename + ".dot"};

    save_bundled_vertices_graph_to_dot(g,dot_filename);
    BOOST_CHECK(is_regular_file(dot_filename));
    const std::vector<std::string> text{
      file_to_vector(dot_filename)
    };
    BOOST_CHECK(!text.empty());
    const std::vector<std::string> expected_text{
      "digraph G {",
      "}"
    };
    BOOST_CHECK(text != expected_text);
    std::remove(dot_filename.c_str());
  }
  //Show it does not store the edges' names
  {
    const auto g = create_bundled_vertices_k2_graph();
    const std::string base_filename{"save_bundled_vertices_graph_to_dot_test_bundled_vertices_k2_graph"};
    const std::string dot_filename{base_filename + ".dot"};

    save_bundled_vertices_graph_to_dot(g,dot_filename);
    const std::vector<std::string> text{
      file_to_vector(dot_filename)
    };
    BOOST_CHECK(!text.empty());
    const std::vector<std::string> expected_text{
      "graph G {",
      "0[label=top];",
      "1[label=right];",
      "2[label=left];",
      "0--1 ;",
      "1--2 ;",
      "2--0 ;",
      "}"
    };
    BOOST_CHECK(text != expected_text);
    std::remove(dot_filename.c_str());
  }
}

#endif // BOOST_GRAPH_COOKBOOK_2_NO_GRAPHVIZ
