#ifndef PATFINDING_DIJKSTRA_H
#define PATFINDING_DIJKSTRA_H

#include "pathfinding_dijkstra_declaration.h"
#include <set>
#include <utility>
#include <climits>

using namespace std;

template <typename StoragingType>
list<Vertex<int> > findShortestPath(Graph<StoragingType> & rhs, int from, int to)
{
    vector<int> pts(rhs.getVertexCount());
    vector<int> weights(rhs.getVertexCount());
    int indx = rhs.getVertexCount() - 1;
    vector<bool> isVisited(rhs.getVertexCount(), false);
    set< pair<int, int> > m;

    for(int i = 0; i < rhs.getVertexCount(); ++i)
    {
        if(i != from)
            m.insert(pair<int, int>(INT_MAX, i));
        else
            m.insert(pair<int, int>(0, i));
    }

    for(int c = 0; c < rhs.getVertexCount(); ++c)
    {
        int currVertex = (m.begin())->second;
        for( list< pair< int, int > >::iterator i = rhs.getEdgesList(currVertex).begin(); i != rhs.getEdgesList(currVertex).end(); ++i)
        {
            for(set< pair<int, int> >::iterator e = m.begin(); e != m.end(); ++e)
            {
                if(e->second == i->first && !isVisited[e->second])
                {
                    if(e->first > (m.begin())->first + i->second)
                    {
                        int indx = i->first;
                        int upgWeight = (m.begin())->first + i->second;
                        m.erase(e);
                        m.insert(pair<int, int>(upgWeight, indx));
                        break;
                    }
                    else
                        break;
                }
            }
        }
        isVisited[(m.begin())->second] = true;
        pts[indx] = (m.begin())->second;
        weights[indx--] = (m.begin())->first;
        m.erase(m.begin());
    }

    list< Vertex<int> > waypoints;
    indx = 0;

    while(pts[indx] != to)
        ++indx;

    waypoints.push_back(Vertex<int>(pts[indx]));
    for(int i = indx+1; i < ((int)pts.size()); ++i)
    {
        for(list< pair<int, int> >::iterator edgeInVert =
            rhs.getEdgesList(pts[i]).begin();
            edgeInVert != rhs.getEdgesList(pts[i]).end();
            ++edgeInVert)
        {
            if((pts[indx] == edgeInVert->first))
            {
                if((weights[indx] - edgeInVert->second) == weights[i])
            {
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

#endif // PATHFINDING_DECLARATION
