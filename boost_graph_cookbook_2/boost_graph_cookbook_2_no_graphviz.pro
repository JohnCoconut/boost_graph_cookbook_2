include(any_normal.pri)

DEFINES += BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
DEFINES += BOOST_GRAPH_COOKBOOK_2_NO_GRAPHVIZ

INCLUDEPATH += ../../boost_graph_cookbook_1/boost_graph_cookbook_1
include(../../boost_graph_cookbook_1/boost_graph_cookbook_1/boost_graph_cookbook_1_no_graphviz.pri)

include(boost_graph_cookbook_2_no_graphviz.pri)

SOURCES += main.cpp


