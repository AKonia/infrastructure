#ifndef INCLUDE_PATHFINDING_DIJKSTRA_DECLARATION_H_
#define INCLUDE_PATHFINDING_DIJKSTRA_DECLARATION_H_

#include <list>

#include "graph.h"

template <typename StoragingType>
list<Vertex<int> > findShortestPath(Graph<StoragingType>* rhs, int from,
                                    int to);

#endif  // INCLUDE_PATHFINDING_DIJKSTRA_DECLARATION_H_
