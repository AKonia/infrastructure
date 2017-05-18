// Copyright 2017 AKonia
#include <gtest/gtest.h>
#include <list>
#include <set>
#include <utility>
#include "graph_mat_ident.h"
#include "jarnik.h"

TEST(Jarnik, can_find_mst_jarnik_prim) {
  GraphMatIdent gid(8, 12);
  gid.setEdge(0, 6, 0, 51);
  gid.setEdge(0, 1, 1, 32);
  gid.setEdge(0, 2, 2, 29);
  gid.setEdge(4, 3, 3, 34);
  gid.setEdge(5, 3, 4, 18);
  gid.setEdge(7, 4, 5, 46);
  gid.setEdge(5, 4, 6, 40);
  gid.setEdge(0, 5, 7, 60);
  gid.setEdge(6, 4, 8, 51);
  gid.setEdge(7, 0, 9, 31);
  gid.setEdge(7, 6, 10, 25);
  gid.setEdge(7, 1, 11, 21);
  std::set<pair<uint32_t, uint32_t> > s;
  s.insert(std::make_pair(3, 5));
  s.insert(std::make_pair(1, 7));
  s.insert(std::make_pair(6, 7));
  s.insert(std::make_pair(4, 7));
  s.insert(std::make_pair(3, 4));
  s.insert(std::make_pair(0, 2));
  s.insert(std::make_pair(0, 7));
  std::list<pair<uint32_t, uint32_t> > mst = findMinSpanTreeJarnik(gid);
  for (list<pair<uint32_t, uint32_t> >::iterator i = mst.begin();
       i != mst.end(); ++i) {
    if (i->second > i->first)
      ASSERT_NO_THROW(s.erase(std::make_pair(i->first, i->second)));
    else
      ASSERT_NO_THROW(s.erase(std::make_pair(i->second, i->first)));
  }
  EXPECT_EQ(s.empty(), true);
}
