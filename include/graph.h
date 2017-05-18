// Copyright 2017 AKonia
#ifndef INCLUDE_GRAPH_H_
#define INCLUDE_GRAPH_H_

#include <cstdint>

class Graph {
 private:
  uint32_t size;
  uint32_t** connMat;

 public:
  explicit Graph(uint32_t size);
  explicit Graph(const Graph& rhs);
  ~Graph();

  void setEdge(uint32_t vFirst, uint32_t vSecond, uint32_t eWeight);
  void unsetEdge(uint32_t vFirst, uint32_t vSecond);

  uint32_t getEdgeWeight(uint32_t vFirst, uint32_t vSecond) const;
  uint32_t getSize() const;
};

#endif  // INCLUDE_GRAPH_H_
