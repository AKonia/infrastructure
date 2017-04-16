#ifndef _PATHFINDING_DIJKSTRA_DECLARATION_H_
#define _PATHFINDING_DIJKSTRA_DECLARATION_H_

#include "graph.h"

template <typename StoragingType>
list< Vertex<int> > findShortestPath(Graph<StoragingType> & rhs, int from, int to);

#endif // _PATHFINDING_DIJKSTRA_H_
