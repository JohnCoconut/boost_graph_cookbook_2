#include "seperate_string.h"

#include <boost/test/unit_test.hpp>
#include <sstream>

BOOST_AUTO_TEST_CASE(test_seperate_string)
{
 { //Single input, seperator of type char
    const std::vector<std::string> v = seperate_string("a",',');
    BOOST_CHECK(v[0]=="a");
  }
  { //Two inputs, seperator of type char
    const std::vector<std::string> v = seperate_string("a,b",',');
    BOOST_CHECK(v[0]=="a");
    BOOST_CHECK(v[1]=="b");
  }
  { //Five inputs, seperator of type char
    const std::vector<std::string> v = seperate_string("a,bb,ccc,dddd,eeeee",',');
    BOOST_CHECK(v[0]=="a");
    BOOST_CHECK(v[1]=="bb");
    BOOST_CHECK(v[2]=="ccc");
    BOOST_CHECK(v[3]=="dddd");
    BOOST_CHECK(v[4]=="eeeee");
  }
  { //Three inputs, of which one empty, seperator of type char
    const std::vector<std::string> v = seperate_string("a, ,ccc",',');
    BOOST_CHECK(v[0]=="a");
    BOOST_CHECK(v[1]==" ");
    BOOST_CHECK(v[2]=="ccc");
  }
}
