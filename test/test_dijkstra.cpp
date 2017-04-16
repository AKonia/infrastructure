#include "pathfinding_dijkstra.h"
#include <gtest/gtest.h>


TEST(Dijkstra, can_find_correct_way)
{
    Graph<int> g(7);
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

    list < Vertex<int> > waypoints = findShortestPath(g, 0, 0);
    vector<int> v = {0};
    size_t j = 0;
    for(list< Vertex<int> >::iterator i = waypoints.begin(); i != waypoints.end(), j < v.size(); ++i, ++j)
        EXPECT_EQ(i->getData(), v[j]);
}

TEST(Dijkstra, can_find_correct_way_to_the_self_vertex)
{
    Graph<int> g(7);
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

    list < Vertex<int> > waypoints = findShortestPath(g, 0, 0);
    vector<int> v = {0};
    size_t j = 0;
    for(list< Vertex<int> >::iterator i = waypoints.begin(); i != waypoints.end(), j < v.size(); ++i, ++j)
        EXPECT_EQ(i->getData(), v[j]);
}
