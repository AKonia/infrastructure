#include "../include/pathfinding_dijkstra.h"

#include <map>
#include <climits>

using std::multimap;

template <typename StoragingType>
list< Vertex<StoragingType> > findShortestPath(const Graph<StoragingType> & rhs, int from, int to)
{
    list<int> waypoints;
    vector<bool> isVisited(rhs.getVertexCount(), false);
    multimap<int, int> m;
    for(int i = 0; i < rhs.getVertexCount(); ++i)
    {
        if(i != from)
            m.insert(INT_MAX, i);
        else
            m.insert(0, i);
    }
    for(int c = 0; c < rhs.getVertexCount(); ++c)
    {
        int currVertex = (m.begin())->second;
        for( list< pair< int, int > >::iterator i = rhs.getEdgesList(currVertex).begin(); i != rhs.getEdgesList(currVertex).end(); ++i)
        {
            for(multimap<int, int>::iterator e = m.begin(); e != m.end(); ++e)
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
    }
    /*
    <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
    Для первой вершины сначала установим начальный вес равный 0(длина пути),
    Остальные установим в бесконечность
    далее выбираем вершину с наим. расстоянием для неё и посмотрим уменьшается
    ли расстояние до других вершин за счёт того что мы проверим сумму
    расстояния до текущей вершины до всех с которыми связана текущая если
    расстояние уменьшиться, то перепишем их, иначе пропустим,рассматривавшиеся
    вершины помечаются посещёнными и пропускаются при просмотре
    <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
    */

    waypoints.reverse();
    return waypoints;
}
