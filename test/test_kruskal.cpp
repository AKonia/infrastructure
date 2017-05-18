#include <gtest/gtest.h>
#include <set>
#include <utility>
#include <list>

#include "graph.h"
#include "kruskal.h"


TEST(Kruskal, can_find_mst_kruskal) {
    Graph g(8);
    g.setEdge(0, 6, 51);
    g.setEdge(0, 1, 32);
    g.setEdge(0, 2, 29);
    g.setEdge(4, 3, 34);
    g.setEdge(5, 3, 18);
    g.setEdge(7, 4, 46);
    g.setEdge(5, 4, 40);
    g.setEdge(0, 5, 60);
    g.setEdge(6, 4, 51);
    g.setEdge(7, 0, 31);
    g.setEdge(7, 6, 25);
    g.setEdge(7, 1, 21);
    std::set< pair<uint32_t, uint32_t> > s;
    s.insert(std::make_pair(3, 5));
    s.insert(std::make_pair(1, 7));  
    s.insert(std::make_pair(6, 7));
    s.insert(std::make_pair(4, 7));
    s.insert(std::make_pair(3, 4));
    s.insert(std::make_pair(0, 2));
    s.insert(std::make_pair(0, 7));   
    std::list< pair<uint32_t, uint32_t> > mst = findMinSpanTreeKruskal(g);
    for(list< pair<uint32_t, uint32_t> >::iterator i = mst.begin(); i != mst.end(); ++i)
    {
        if(i->second > i->first)
            ASSERT_NO_THROW(s.erase(std::make_pair(i->first, i->second)));
        else
            ASSERT_NO_THROW(s.erase(std::make_pair(i->second, i->first)));
    }   
    EXPECT_EQ(s.empty(), true);
}



