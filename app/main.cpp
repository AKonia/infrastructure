#include <iostream>
#include <list>

#include "pathfinding_dijkstra.h"

using std::list;
using std::ostream;
using std::cout;
using std::endl;

struct point {
  int x, y;
  friend ostream &operator<<(ostream &stream, point p);
};

ostream &operator<<(ostream &stream, point p) {
  stream << "x: " << p.x << " y: " << p.y;
  return stream;
}

int main() {
  Graph<point> g(7);
  point p = {3, 4};
  for (int i = 1; i <= g.getVertexCount(); i++) g.setVertexData(i - 1, p);
  g.setEdge(0, 1, 2);
  g.setEdge(0, 2, 1);
  g.setEdge(2, 1, 5);
  g.setEdge(1, 3, 4);
  g.setEdge(2, 3, 3);
  g.setEdge(3, 4, 7);
  g.setEdge(3, 5, 6);
  g.setEdge(4, 5, 8);
  g.setEdge(4, 6, 10);
  g.setEdge(5, 6, 9);

  /*
                   1
                 // \
            (1) //   \ (2)
               // (5) \
               3 ----- 2
               \\     /
            (3) \\   / (5)
                 \\ /
                   4
                 // \
             (6)//   \ (7)
               // (8) \
               6 ----- 5
               \\     /
            (9) \\   / (10)
                 \\ /
                   7



  */

  list<Vertex<int> > waypoints = findShortestPath(&g, 0, 6);
  for (list<Vertex<int> >::iterator i = waypoints.begin(); i != waypoints.end();
       ++i)
    cout << "WayPoint: " << i->getData()
         << " have data = " << g.getVertex(i->getData()).getData() << endl;
  cout << endl;
  return 0;
}
