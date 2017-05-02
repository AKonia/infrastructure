// Copyright 2017 AKonia
#ifndef INCLUDE_VERTEX_DECLARATION_H_
#define INCLUDE_VERTEX_DECLARATION_H_

#include <list>
#include <utility>
#include <vector>

using std::list;
using std::pair;
using std::vector;

template <typename StoragingType>
class Vertex {
 private:
  list<pair<int, int> > edges;
  StoragingType data;

 public:
  Vertex();
  explicit Vertex(const StoragingType& vData);
  Vertex(const Vertex& rhs);
  ~Vertex();
  void setEdge(int vNumber, int eWeight);
  void setEdges(const vector<int>& vNumbers, const vector<int>& eWeights);
  void removeEdge(int vNumber);
  list<pair<int, int> >& getEdgesList();
  void setData(const StoragingType& newData);
  StoragingType getData() const;
};

#endif  // INCLUDE_VERTEX_DECLARATION_H_
