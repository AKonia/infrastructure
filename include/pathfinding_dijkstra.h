// Copyright 2017 AKonia
#ifndef INCLUDE_PATHFINDING_DIJKSTRA_H_
#define INCLUDE_PATHFINDING_DIJKSTRA_H_

#include <climits>
#include <set>
#include <utility>
#include <list>
#include <vector>
#include "pathfinding_dijkstra_declaration.h"

#include "priority_queue.h"
#include "set.h"

using std::vector;
using std::list;
using std::pair;
using std::make_pair;

template <typename StoragingType>
list<Vertex<int> > findShortestPathTree(Graph<StoragingType> *rhs, int from,
                                        int to) {
  int indx = rhs->getVertexCount() - 1;
  vector<int> weights(rhs->getVertexCount());
  vector<bool> isVisited(rhs->getVertexCount(), false);
  akon::set<pair<int, int> > s;
  vector<int> pts(rhs->getVertexCount());
  s.insert(make_pair(0, from));

  while (!s.isEmpty()) {
    int currVtxWeight = (s.getMin()).first;
    int currVtxNumber = (s.getMin()).second;
    s.erase(make_pair(currVtxWeight, currVtxNumber));
    if (!isVisited[currVtxNumber]) {
      isVisited[currVtxNumber] = true;
      for (auto i = rhs->getEdgesList(currVtxNumber).begin();
           i != rhs->getEdgesList(currVtxNumber).end(); ++i) {
        if (!isVisited[i->first])
          s.insert(make_pair(currVtxWeight + i->second, i->first));
        else
          continue;
      }
      pts[indx] = currVtxNumber;
      weights[indx--] = currVtxWeight;
    }
  }

  list<Vertex<int> > waypoints;
  indx = 0;
  while (pts[indx] != to) ++indx;
  waypoints.push_back(Vertex<int>(pts[indx]));
  for (int i = indx + 1; i < (static_cast<int>(pts.size())); ++i) {
    for (list<pair<int, int> >::iterator edgeInVert =
             rhs->getEdgesList(pts[i]).begin();
         edgeInVert != rhs->getEdgesList(pts[i]).end(); ++edgeInVert) {
      if ((pts[indx] == edgeInVert->first)) {
        if ((weights[indx] - edgeInVert->second) == weights[i]) {
          indx = i;
          waypoints.push_back(Vertex<int>(pts[i]));
          break;
        }
      }
    }
  }
  waypoints.reverse();
  return waypoints;
}

template <typename StoragingType>
list<Vertex<int> > findShortestPathPQ(Graph<StoragingType> *rhs, int from,
                                        int to) {
  int indx = rhs->getVertexCount() - 1;
  vector<int> weights(rhs->getVertexCount());
  vector<bool> isVisited(rhs->getVertexCount(), false);
  akon::PriorityQueue<pair<int, int> > s;
  vector<int> pts(rhs->getVertexCount());
  s.insert(make_pair(0, from));

  while (!s.isEmpty()) {
    int currVtxWeight = s.top().first;
    int currVtxNumber = s.top().second;
    s.pop();
    if (!isVisited[currVtxNumber]) {
      isVisited[currVtxNumber] = true;
      for (auto i = rhs->getEdgesList(currVtxNumber).begin();
           i != rhs->getEdgesList(currVtxNumber).end(); ++i) {
        if (!isVisited[i->first])
          s.insert(make_pair(currVtxWeight + i->second, i->first));
        else
          continue;
      }
      pts[indx] = currVtxNumber;
      weights[indx--] = currVtxWeight;
    }
  }

  list<Vertex<int> > waypoints;
  indx = 0;
  while (pts[indx] != to) ++indx;
  waypoints.push_back(Vertex<int>(pts[indx]));
  for (int i = indx + 1; i < (static_cast<int>(pts.size())); ++i) {
    for (list<pair<int, int> >::iterator edgeInVert =
             rhs->getEdgesList(pts[i]).begin();
         edgeInVert != rhs->getEdgesList(pts[i]).end(); ++edgeInVert) {
      if ((pts[indx] == edgeInVert->first)) {
        if ((weights[indx] - edgeInVert->second) == weights[i]) {
          indx = i;
          waypoints.push_back(Vertex<int>(pts[i]));
          break;
        }
      }
    }
  }
  waypoints.reverse();
  return waypoints;
}

#endif  // INCLUDE_PATHFINDING_DIJKSTRA_H_
