include(any_test.pri)

DEFINES += BOOST_GRAPH_COOKBOOK_2_NO_GRAPHVIZ

include(boost_graph_cookbook_2_no_graphviz.pri)
include(boost_graph_cookbook_2_test_no_graphviz.pri)

#LIBS += -lboost_regex
QMAKE_LFLAGS += -fuse-ld=gold

SOURCES += main_test.cpp

