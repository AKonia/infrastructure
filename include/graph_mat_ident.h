// Copyright 2017 AKonia
#ifndef INCLUDE_GRAPH_MAT_IDENT_H_
#define INCLUDE_GRAPH_MAT_IDENT_H_

#include <cstdint>

class GraphMatIdent {
  uint32_t countVertices;
  uint32_t countEdges;
  uint32_t **idenMat;

 public:
  GraphMatIdent(uint32_t countVertices, uint32_t countEdges);
  GraphMatIdent(const GraphMatIdent &rhs);
  ~GraphMatIdent();
  void setEdge(uint32_t vFirst, uint32_t vSecond, uint32_t eNumber,
               uint32_t eWeight);

  uint32_t getEdgeWeight(uint32_t vFirst, uint32_t eNumber) const;
  uint32_t getEdgesSize() const;
  uint32_t getVerticesSize() const;
};

#endif  // INCLUDE_GRAPH_MAT_IDENT_H_
