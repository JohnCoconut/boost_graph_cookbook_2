include(any_normal.pri)

# Equivalent to:
# include(boost_graph_cookbook_2.pri)
include(../../boost_graph_cookbook_1/boost_graph_cookbook_1/boost_graph_cookbook_1_bundled_edges_and_vertices.pri)
include(../../boost_graph_cookbook_1/boost_graph_cookbook_1/boost_graph_cookbook_1_bundled_vertices.pri)
include(../../boost_graph_cookbook_1/boost_graph_cookbook_1/boost_graph_cookbook_1_helper.pri)
include(../../boost_graph_cookbook_1/boost_graph_cookbook_1/boost_graph_cookbook_1_misc.pri)
include(../../boost_graph_cookbook_1/boost_graph_cookbook_1/boost_graph_cookbook_1_no_properties.pri)
include(../../boost_graph_cookbook_1/boost_graph_cookbook_1/boost_graph_cookbook_1_tutorial.pri)

include(boost_graph_cookbook_2_no_properties.pri)

SOURCES += main.cpp

# USe Graphviz
LIBS += -lboost_graph
