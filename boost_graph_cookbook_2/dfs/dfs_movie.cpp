#include "counter.hpp"
#include "create_graph.hpp"
#include <boost/format.hpp>
#include <boost/graph/depth_first_search.hpp>
#include <boost/graph/graphviz.hpp>

using Graph
  = boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS>;

struct ColorFontSettings {
  // Style.first = color to fill the node, Style.second = font color
  using Style = std::pair<std::string, std::string>;
  Style style;
  ColorFontSettings(boost::default_color_type color)
  {
    switch (color) {
    case boost::white_color:
      style = { "white", "black" };
      break;
    case boost::gray_color:
      style = { "gray", "black" };
      break;
    case boost::black_color:
      style = { "black", "white" };
      break;
    default:;
    }
  }
};

template <typename ColorMap>
class ColorWriter
{
public:
  ColorWriter(ColorMap colorMap)
    : colorMap_(colorMap)
  {
  }
  template <typename Vertex>
  void operator()(std::ostream& os, Vertex v) const
  {
    ColorFontSettings cf(colorMap_[v]);
    os << boost::format(
            "[style=\"filled\" fillcolor=\"%1%\" fontcolor=\"%2%\"]")
        % cf.style.first % cf.style.second;
  }

private:
  ColorMap colorMap_;
};

template <typename ColorMap>
class vistor : public boost::default_dfs_visitor
{
private:
  ColorMap colorMap_;
  ColorWriter<ColorMap> writer_;
  template <typename Graph, typename Vertex>
  void colorAllVertices(Vertex, Graph g) const
  {
    Counter c;
    std::ofstream file(c.id());
    boost::write_graphviz(file, g, writer_);
  }

public:
  vistor(ColorMap colorMap)
    : colorMap_(colorMap)
    , writer_(colorMap_)
  {
  }
  template <typename Graph, typename Vertex>
  void start_vertex(Vertex v, Graph g) const
  {
    colorAllVertices(v, g);
  }
  template <typename Graph, typename Vertex>
  void discover_vertex(Vertex v, Graph g) const
  {
    colorAllVertices(v, g);
  }
  template <typename Graph, typename Vertex>
  void finish_vertex(Vertex v, Graph g) const
  {
    colorAllVertices(v, g);
  }
};

int main()
{
  Graph g = create_graph();

  boost::graph_traits<Graph>::vertex_descriptor u = *boost::vertices(g).first;

  std::vector<boost::default_color_type> color(
    boost::num_vertices(g), boost::white_color);

  auto colorMap = boost::make_iterator_property_map(
    color.begin(), boost::get(boost::vertex_index, g));

  vistor vis(colorMap);
  boost::depth_first_visit(g, u, vis, colorMap);
  return 0;
}
