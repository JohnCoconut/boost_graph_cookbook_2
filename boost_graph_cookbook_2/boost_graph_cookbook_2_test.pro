include(any_test.pri)

INCLUDEPATH += ../../boost_graph_cookbook_1/boost_graph_cookbook_1
include(../../boost_graph_cookbook_1/boost_graph_cookbook_1/boost_graph_cookbook_1_bundled_edges_and_vertices.pri)
include(../../boost_graph_cookbook_1/boost_graph_cookbook_1/boost_graph_cookbook_1_bundled_vertices.pri)
include(../../boost_graph_cookbook_1/boost_graph_cookbook_1/boost_graph_cookbook_1_helper.pri)
include(../../boost_graph_cookbook_1/boost_graph_cookbook_1/boost_graph_cookbook_1_misc.pri)
include(../../boost_graph_cookbook_1/boost_graph_cookbook_1/boost_graph_cookbook_1_no_properties.pri)

include(boost_graph_cookbook_2.pri)
include(boost_graph_cookbook_2_test.pri)

SOURCES += main_test.cpp
QMAKE_LFLAGS += -fuse-ld=gold

# Use Graphviz
LIBS += -lboost_graph
