#include <gtest/gtest.h>
#include "../include/bin_tree.h"

TEST(BinaryTree, search_in_empty_tree) {
  bin_tree simpleTree;
  EXPECT_EQ(simpleTree.search(7), 0);
}

TEST(BinaryTree, search_existing_element) {
  bin_tree simpleTree;
  simpleTree.insert(7);
  simpleTree.insert(9);
  simpleTree.insert(8);
  EXPECT_EQ(simpleTree.search(8), 1);
}

TEST(BinaryTree, search_unexisting_element) {
  bin_tree simpleTree;
  simpleTree.insert(7);
  simpleTree.insert(9);
  simpleTree.insert(8);
  EXPECT_EQ(simpleTree.search(10), 0);
}

TEST(BinaryTree, inserting_existing_element) {
  bin_tree simpleTree;
  simpleTree.insert(7);
  simpleTree.insert(9);
  simpleTree.insert(8);
  EXPECT_EQ(simpleTree.search(8), 1);
  EXPECT_EQ(simpleTree.get_size(), 3);
  EXPECT_EQ(simpleTree.insert(8), 1);
  EXPECT_EQ(simpleTree.search(8), 1);
  EXPECT_EQ(simpleTree.get_size(), 3);
}

TEST(BinaryTree, inserting_unexisting_element) {
  bin_tree simpleTree;
  simpleTree.insert(7);
  simpleTree.insert(10);
  simpleTree.insert(8);
  EXPECT_EQ(simpleTree.search(9), 0);
  EXPECT_EQ(simpleTree.get_size(), 3);
  EXPECT_EQ(simpleTree.insert(9), 0);
  EXPECT_EQ(simpleTree.search(9), 1);
  EXPECT_EQ(simpleTree.get_size(), 4);
}

TEST(BinaryTree, inserting_right_arter_creation) {
  bin_tree simpleTree;
  EXPECT_EQ(simpleTree.search(7), 0);
  EXPECT_EQ(simpleTree.get_size(), 0);
  EXPECT_EQ(simpleTree.insert(7), 0);
  EXPECT_EQ(simpleTree.search(7), 1);
  EXPECT_EQ(simpleTree.get_size(), 1);
}
