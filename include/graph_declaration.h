#ifndef INCLUDE_GRAPH_DECLARATION_H_
#define INCLUDE_GRAPH_DECLARATION_H_

#include <list>
#include <utility>
#include <vector>

#include "vertex.h"

using std::list;
using std::pair;
using std::vector;

template <typename StoragingType = bool>
class Graph {
 private:
  vector<Vertex<StoragingType> > *vertices;

 public:
  Graph();
  explicit Graph(int qOfVertices);
  Graph(const Graph &rhs);
  ~Graph();

  void insertVertices(int qOfVertices);
  void setEdge(int vNumberFrom, int vNumberTo, int eWeight);
  void removeEdge(int vNumberFrom, int vNumberTo);
  int getEdgeWeight(int vNumberFrom, int vNumberTo);
  list<pair<int, int> > &getEdgesList(int vNumber);
  const Vertex<StoragingType> &getVertex(int vNumber);

  void setVertexData(int vNumber, const StoragingType &data);

  int getVertexCount();
  int getEdgesCount();
};

#endif  // INCLUDE_GRAPH_DECLARATION_H_
