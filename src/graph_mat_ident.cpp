// Copyright 2017 AKonia
#include "graph_mat_ident.h"

GraphMatIdent::GraphMatIdent(uint32_t countVertices, uint32_t countEdges) {
  this->countEdges = countEdges;
  this->countVertices = countVertices;
  idenMat = new uint32_t *[countVertices];
  for (uint32_t i = 0; i < countVertices; ++i)
    idenMat[i] = new uint32_t[countEdges];
  for (uint32_t i = 0; i < countVertices; ++i)
    for (uint32_t j = 0; j < countEdges; ++j) idenMat[i][j] = 0;
}

GraphMatIdent::GraphMatIdent(const GraphMatIdent &rhs) {
  countEdges = rhs.countEdges;
  countVertices = rhs.countVertices;
  idenMat = new uint32_t *[countVertices];
  for (uint32_t i = 0; i < countVertices; ++i)
    idenMat[i] = new uint32_t[countEdges];
  for (uint32_t i = 0; i < countVertices; ++i)
    for (uint32_t j = 0; j < countEdges; ++j) idenMat[i][j] = rhs.idenMat[i][j];
}

GraphMatIdent::~GraphMatIdent() {
  for (uint32_t i = 0; i < countVertices; ++i) delete[] idenMat[i];
  delete[] idenMat;
}

void GraphMatIdent::setEdge(uint32_t vFirst, uint32_t vSecond, uint32_t eNumber,
                            uint32_t eWeight) {
  idenMat[vFirst][eNumber] = idenMat[vSecond][eNumber] = eWeight;
}

uint32_t GraphMatIdent::getEdgeWeight(uint32_t vFirst, uint32_t eNumber) const {
  vFirst %= countVertices;
  eNumber %= countEdges;
  return idenMat[vFirst][eNumber];
}

uint32_t GraphMatIdent::getEdgesSize() const { return countEdges; }

uint32_t GraphMatIdent::getVerticesSize() const { return countVertices; }
