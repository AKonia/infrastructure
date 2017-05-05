// Copyright 2017 AKonia
#include <fstream>
#include <iostream>
#include <list>

#include "pathfinding_dijkstra.h"

using std::list;
using std::cout;
using std::endl;
using std::ifstream;

int main() {
  int n, from, to, weight;
  n = from = to = weight = 0;
  ifstream in("graph.in");

  in >> n;
  Graph<bool> g(n);
  while (!in.eof()) {
    in >> from >> to >> weight;
    g.setEdge(from, to, weight);
  }
  in.close();

  cout << "<<< Pathfinding based on PriorityQueue >>>" << endl;
  list<Vertex<int> > waypoints = findShortestPathPQ(&g, 0, 6);
  for (list<Vertex<int> >::iterator i = waypoints.begin(); i != waypoints.end();
       ++i)
    cout << "WayPoint: " << i->getData() << endl;
  cout << endl;

  cout << "<<< Pathfinding based on AVLTrees >>>" << endl;
  waypoints = findShortestPathTree(&g, 0, 6);
  for (list<Vertex<int> >::iterator i = waypoints.begin(); i != waypoints.end();
       ++i)
    cout << "WayPoint: " << i->getData() << endl;
  cout << endl;

  return 0;
}
