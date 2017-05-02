#include <iostream>
#include <fstream>

#include "pathfinding_dijkstra.h"

using namespace std;

int main()
{
    int n, from, to, weight;
    n = from = to = weight = 0;
    ifstream in("graph.in");
       
    in >> n;
    Graph<bool> g(n);
    while(!in.eof())
    {
        in >> from >> to >> weight;
        g.setEdge(from, to, weight);
    }
    in.close();

    cout << "<<< Pathfinding based on PriorityQueue >>>" << endl;    
    list < Vertex<int> > waypoints = findShortestPathPQ(&g, 0, 6);
    for(list< Vertex<int> >::iterator i = waypoints.begin(); i != waypoints.end(); ++i)
        cout << "WayPoint: " << i->getData() << endl;
    cout << endl;

    cout << "<<< Pathfinding based on AVLTrees >>>" << endl;    
    waypoints = findShortestPathTree(&g, 0, 6);
    for(list< Vertex<int> >::iterator i = waypoints.begin(); i != waypoints.end(); ++i)
        cout << "WayPoint: " << i->getData() << endl;
    cout << endl;

    return 0;
}
