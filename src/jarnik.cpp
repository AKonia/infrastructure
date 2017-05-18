#include <utility>

using std::pair;
using std::make_pair;

#include "priority_queue.h"
#include "unionfind.h"
#include "jarnik.h"
#include "graph.h"
#include "graph_mat_ident.h"

list< pair<uint32_t, uint32_t> > findMinSpanTreeJarnik(const GraphMatIdent & gid)
{
    Graph g(gid.getVerticesSize());
    for(uint32_t i = 0; i < gid.getEdgesSize(); ++i)
        for(uint32_t j = 0; j < gid.getVerticesSize(); ++j)
            if(gid.getEdgeWeight(j, i) > 0)
            {
                for(uint32_t k = j+1; k < gid.getVerticesSize(); ++k)
                    if(gid.getEdgeWeight(k, i) > 0)
                    {
                        g.setEdge(j, k, gid.getEdgeWeight(j, i));
                        break;
                    }
                break;
            }
    list< pair<uint32_t, uint32_t> > res;
    UnionFind uf(g.getSize());
    akon::PriorityQueue< pair<int, pair<int, int> > > pq;
    for(uint32_t i = 0; i < g.getSize(); ++i)
        if(g.getEdgeWeight(0, i) != 0)
            pq.insert(make_pair(g.getEdgeWeight(0, i), make_pair(0, i)));
    while(!pq.isEmpty())
    {
        uint32_t vFrom = pq.top().second.first;
        uint32_t vTo = pq.top().second.second;
        pq.pop();
        if(!uf.find(vFrom, vTo))
        {
            for(uint32_t i = 0; i < g.getSize(); ++i)
                if(g.getEdgeWeight(vTo, i) != 0 && !uf.find(vFrom, i))
                    pq.insert(make_pair(g.getEdgeWeight(vTo, i), make_pair(vTo, i)));

            uf.unite(vFrom, vTo);
            res.push_back(make_pair(vFrom, vTo));
        }
    }
    return res;
 }

