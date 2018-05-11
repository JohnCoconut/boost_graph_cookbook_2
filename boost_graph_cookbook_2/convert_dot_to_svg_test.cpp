#include "convert_dot_to_svg.h"
#include <boost/test/unit_test.hpp>

#ifndef BOOST_GRAPH_COOKBOOK_2_NO_GRAPHVIZ

BOOST_AUTO_TEST_CASE(test_convert_dot_to_svg)
{
  BOOST_CHECK_THROW(
    convert_dot_to_svg("dont_exists.dot", "dont_exists.svg"),
    std::invalid_argument
  );
}

#endif // BOOST_GRAPH_COOKBOOK_2_NO_GRAPHVIZ
