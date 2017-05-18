#include <gtest/gtest.h>
#include "unionfind.h"

TEST(Union_Find, can_unite_sets) {
    UnionFind uf(10);
    EXPECT_EQ(uf.find(2, 4), false);
    uf.unite(2, 4);
    EXPECT_EQ(uf.find(2, 4), true);
}

TEST(Union_Find, can_unite_big_sets) {
    UnionFind uf(10);
    EXPECT_EQ(uf.find(2, 7), false);
    EXPECT_EQ(uf.find(2, 3), false);
    EXPECT_EQ(uf.find(3, 4), false);
    EXPECT_EQ(uf.find(4, 7), false);
    uf.unite(2, 3);
    uf.unite(4, 7);
    EXPECT_EQ(uf.find(2, 3), true);
    EXPECT_EQ(uf.find(2, 7), false);
    EXPECT_EQ(uf.find(4, 7), true);
    EXPECT_EQ(uf.find(3, 4), false);
    uf.unite(3, 4);
    EXPECT_EQ(uf.find(2, 7), true);
    EXPECT_EQ(uf.find(2, 3), true);
    EXPECT_EQ(uf.find(4, 7), true);
    EXPECT_EQ(uf.find(3, 4), true);
}


