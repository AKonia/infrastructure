#ifndef INCLUDE_BIN_TREE_H_
#define INCLUDE_BIN_TREE_H_

struct bin_node {
  int value;
  bin_node *left, *right;
};

class bin_tree {
 public:
  bin_tree();
  ~bin_tree();
  int search(int value);
  bin_node **search_for_insert(int value);
  int insert(int value);
  int get_size();
  bin_node *bin_bal_tree_creat(int *a, int size);

 private:
  int tree_size;
  bin_node *root;
};

#endif  // INCLUDE_BIN_TREE_H_
