// Copyright 2017 AKonia
#ifndef INCLUDE_PATHFINDING_DIJKSTRA_DECLARATION_H_
#define INCLUDE_PATHFINDING_DIJKSTRA_DECLARATION_H_

#include <list>

#include "graph.h"

template <typename StoragingType>
list<Vertex<int> > findShortestPathTree(Graph<StoragingType> *rhs, int from,
                                        int to);

template <typename StoragingType>
list<Vertex<int> > findShortestPathPQ(Graph<StoragingType> *rhs, int from,
                                      int to);

#endif  // INCLUDE_PATHFINDING_DIJKSTRA_DECLARATION_H_
