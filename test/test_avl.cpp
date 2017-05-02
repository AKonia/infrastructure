#include <gtest/gtest.h>
#include "../include/set.h"

TEST(AVL_Tree, can_insert_to_avl_tree)
{
    akon::set<int> s;
    for(int i = 20; i > 0; --i)
        ASSERT_NO_THROW((s.insert(i)));
}

TEST(AVL_Tree, can_find_in_tree)
{
    akon::set<int> s;
    for(int i = 20; i > 0; --i)
        ASSERT_NO_THROW((s.insert(i)));
    EXPECT_EQ(s.find(17), true);
}

TEST(AVL_Tree, can_erase_in_tree)
{
    akon::set<int> s;
    for(int i = 20; i > 0; --i)
        ASSERT_NO_THROW((s.insert(i)));
    EXPECT_EQ(s.find(17), true);
    ASSERT_NO_THROW(s.erase(17));
    EXPECT_EQ(s.find(17), false);
}

TEST(AVL_Tree, can_get_size_of_tree)
{
    akon::set<int> s;
    for(unsigned int i = 20; i > 0; --i)
        ASSERT_NO_THROW((s.insert(i)));
    EXPECT_EQ((int)s.getSize(), 20);
}

TEST(AVL_Tree, can_sort_with_tree)
{
    akon::set<int> s;
    for(int i = 20; i > 0; --i)
        ASSERT_NO_THROW((s.insert(i)));
    for(int i = 1; !s.isEmpty(); ++i)
    {
        EXPECT_EQ(i, s.getMin());
        s.erase(s.getMin());
    }
}

TEST(AVL_Tree, can_get_min_and_max_values)
{
    akon::set<int> s;
    for(int i = 20; i > 0; --i)
        ASSERT_NO_THROW((s.insert(i)));
    EXPECT_EQ(20, s.getMax());
    EXPECT_EQ(1, s.getMin());
}

TEST(AVL_Tree, can_use_pseudo_iterators_in_tree)
{
    akon::set<int> s;
    for(int i = 20; i > 0; --i)
        ASSERT_NO_THROW((s.insert(i)));
    int j = 1;
    for(akon::set<int>::iterator i = s.begin();; ++i, ++j)
    {
        EXPECT_EQ((*i), j);
        if(i == s.end())
            break;
    }
}