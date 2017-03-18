#include "bin_tree.h"
#include <gtest/gtest.h>


TEST(BalancedTree, can_create_tree) {
    const int arr_size = 5;    
    int a[] = {1, 2, 6, 7, 9};
    bin_node tree;
    ASSERT_NO_THROW(tree.bin_bal_tree_creat(a, arr_size));
}

TEST(BalancedTree, all_inserted_elements_exists) {
    const int arr_size = 7;    
    int a[] = {1, 2, 6, 7, 9, 10, 11};
    bin_node tree;
    ASSERT_NO_THROW(tree.bin_bal_tree_creat(a, arr_size));
    EXPECT_EQ(arr_size, tree.get_size());
    for(int i = 0; i < arr_size; i++)
        EXPECT_EQ(tree.search(a[i]), 1);
}

TEST(BalancedTree, tree_is_really_balanced) {
    const int arr_size = 5;    
    int a[] = {1, 2, 6, 7, 9};
    bin_node tree;
    bin_node * root;
    ASSERT_NO_THROW(root = tree.bin_bal_tree_creat(a, arr_size));
    EXPECT_EQ(arr_size, tree.get_size());
    EXPECT_EQ(root->data, 6);
    EXPECT_EQ(root->left->data, 1);
    EXPECT_EQ(root->right->data, 7);
    EXPECT_EQ(root->left->right, 2);
    EXPECT_EQ(root->right->right , 9);
}