#include "../include/bin_tree.h"
#include <cstdlib>

#include <queue>
bin_tree::bin_tree() {
  tree_size = 0;
  root = 0;
}
bin_tree::~bin_tree() {}

bin_node **bin_tree::search_for_insert(int value) {
  bin_node *curr_node = root, **prev_node = &root;
  while (curr_node != 0) {
    if (curr_node->value == value) {
      return NULL;
    } else if (value > curr_node->value) {
      prev_node = &curr_node->right;
      curr_node = curr_node->right;
    } else {
      prev_node = &curr_node->left;
      curr_node = curr_node->left;
    }
  }
  return prev_node;
}

int bin_tree::search(int value) {
  bin_node *curr_node = root;
  while (curr_node != 0) {
    if (curr_node->value == value)
      return 1;
    else if (value > curr_node->value)
      curr_node = curr_node->right;
    else
      curr_node = curr_node->left;
  }
  return 0;
}
int bin_tree::insert(int value) {
  bin_node **prev_node = search_for_insert(value);
  if (prev_node == 0) return 1;
  *prev_node = reinterpret_cast<bin_node *>(malloc(sizeof(bin_node)));
  (*prev_node)->value = value;
  (*prev_node)->left = (*prev_node)->right = 0;
  tree_size++;
  return 0;
}
int bin_tree::get_size() { return tree_size; }

bin_node *bin_tree::bin_bal_tree_creat(int *a, int size) {
  int from = 0, to = size - 1, mid;
  std::queue<int> q;
  q.push(from);
  q.push(to);
  while (!q.empty()) {
    from = q.front();
    q.pop();
    to = q.front();
    q.pop();
    if (to - from < 0) {
      continue;
    }
    mid = (from + to) >> 1;
    this->insert(a[mid]);
    q.push(from);
    q.push(mid - 1);
    q.push(mid + 1);
    q.push(to);
  }
  return root;
}
