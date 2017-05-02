// Copyright 2017 AKonia
#ifndef INCLUDE_AVLTREE_DECLARATION_H_
#define INCLUDE_AVLTREE_DECLARATION_H_

#if (__cplusplus < 201103L)
#error "C++11 required"
#endif

#include <cstdint>
#include <utility>

namespace akon {

template <typename DataType, bool isMulti = false>
class AVLTree {
 protected:
  uint32_t treeSize;
  uint32_t treeCount;
  struct AVLNode {
    int8_t height;
    AVLNode *parent;
    AVLNode *left;
    AVLNode *right;
    DataType *data;
    uint32_t count;
  } * root;
  AVLNode **lookup(const DataType &val, AVLNode **parent,
                   int countChanging = 0);
  void remove(AVLNode *rhs);
  void leftRotate(AVLNode **P);
  void rightRotate(AVLNode **P);
  void rebalance(AVLNode *rhs, int8_t balancingFactor = 1);

 public:
  struct __Avl_tree_iterator {
    friend class AVLTree;

   private:
    AVLNode *currNode;
    AVLNode *root_private;
    int8_t alreadyVisited;

   public:
    __Avl_tree_iterator();
    ~__Avl_tree_iterator();
    __Avl_tree_iterator(const __Avl_tree_iterator &rhs);
    __Avl_tree_iterator operator++();
    __Avl_tree_iterator operator++(int flag);
    __Avl_tree_iterator operator--();
    __Avl_tree_iterator operator--(int flag);
    __Avl_tree_iterator &operator=(const __Avl_tree_iterator &rhs);
    constexpr bool operator==(const __Avl_tree_iterator &rhs) const noexcept;
    constexpr bool operator!=(const __Avl_tree_iterator &rhs) const noexcept;
    constexpr DataType operator*() const noexcept;
    constexpr DataType *operator->() const noexcept;
  };
  typedef __Avl_tree_iterator iterator;

  AVLTree();
  AVLTree(const AVLTree &rhs);
  ~AVLTree();
  bool find(const DataType &val) noexcept;
  void insert(const DataType &val);
  void erase(const DataType &val);
  void erase(__Avl_tree_iterator *rhs);

  constexpr bool isEmpty() const noexcept;
  constexpr uint32_t getSize() const noexcept;
  const DataType &getMin() const;
  const DataType &getMax() const;

  __Avl_tree_iterator begin();
  __Avl_tree_iterator end();
};
}  // namespace akon
#endif  // INCLUDE_AVLTREE_DECLARATION_H_
