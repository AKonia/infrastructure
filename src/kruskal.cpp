#include <utility>

using std::pair;
using std::make_pair;

#include "priority_queue.h"
#include "kruskal.h"
#include "unionfind.h"

list< pair<uint32_t, uint32_t> > findMinSpanTreeKruskal(const Graph &g)
{
    list< pair<uint32_t, uint32_t> > res;
    akon::PriorityQueue<pair<uint32_t, pair<uint32_t, uint32_t> > > pq; // вес откуда куда
    for(uint32_t i = 0; i < g.getSize(); ++i)
        for(uint32_t j = i+1; j < g.getSize(); ++j)
            if(g.getEdgeWeight(i, j) != 0)
                pq.insert(make_pair(g.getEdgeWeight(i, j), make_pair(i, j)));
    UnionFind uf(g.getSize());
    while(!pq.isEmpty())
    {
        int vFrom = pq.top().second.first, vTo = pq.top().second.second;
        if(!uf.find(vFrom, vTo))
        {
            uf.unite(vFrom, vTo);
            res.push_back(make_pair(vFrom, vTo));
        }
        pq.pop();
    }
    return res;
}
