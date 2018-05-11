include(any_test.pri)

DEFINES += BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
DEFINES += BOOST_GRAPH_COOKBOOK_2_NO_GRAPHVIZ

INCLUDEPATH += ../../boost_graph_cookbook_1/boost_graph_cookbook_1
include(../../boost_graph_cookbook_1/boost_graph_cookbook_1/boost_graph_cookbook_1_no_graphviz.pri)

#include(../../boost_graph_cookbook_1/boost_graph_cookbook_1/boost_graph_cookbook_1_bundled_edges_and_vertices.pri)
#include(../../boost_graph_cookbook_1/boost_graph_cookbook_1/boost_graph_cookbook_1_bundled_vertices.pri)
#include(../../boost_graph_cookbook_1/boost_graph_cookbook_1/boost_graph_cookbook_1_helper.pri)
#include(../../boost_graph_cookbook_1/boost_graph_cookbook_1/boost_graph_cookbook_1_misc.pri)
#include(../../boost_graph_cookbook_1/boost_graph_cookbook_1/boost_graph_cookbook_1_no_properties.pri)

include(boost_graph_cookbook_2_no_graphviz.pri)
include(boost_graph_cookbook_2_test_no_graphviz.pri)

#LIBS += -lboost_regex
QMAKE_LFLAGS += -fuse-ld=gold

SOURCES += main_test.cpp

