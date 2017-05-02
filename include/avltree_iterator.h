// Copyright 2017 AKonia
#ifndef INCLUDE_AVLTREE_ITERATOR_H_
#define INCLUDE_AVLTREE_ITERATOR_H_

#include <exception>
#include <stdexcept>

#include "avltree_declaration.h"

namespace akon {

template <typename DataType, bool isMulti>
AVLTree<DataType, isMulti>::__Avl_tree_iterator::__Avl_tree_iterator() {
  root_private = currNode = nullptr;
  alreadyVisited = 0;
}

template <typename DataType, bool isMulti>
AVLTree<DataType, isMulti>::__Avl_tree_iterator::~__Avl_tree_iterator() {}

template <typename DataType, bool isMulti>
AVLTree<DataType, isMulti>::__Avl_tree_iterator::__Avl_tree_iterator(
    const __Avl_tree_iterator &rhs) {
  root_private = rhs.root_private;
  currNode = rhs.currNode;
  alreadyVisited = rhs.alreadyVisited;
}

template <typename DataType, bool isMulti>
typename AVLTree<DataType, isMulti>::__Avl_tree_iterator
    AVLTree<DataType, isMulti>::__Avl_tree_iterator::operator++() {
  if (currNode == nullptr)
    throw std::logic_error("AVLTree::operator++(): empty tree");
  AVLNode *lastNode = nullptr;
  if (alreadyVisited == -1) ++alreadyVisited;
  if (alreadyVisited == 1) return *this;  // не будем портить ?

  if (currNode->right == nullptr) {
    while (lastNode == currNode->right) {
      lastNode = currNode;
      currNode = currNode->parent;
    }
  } else if (currNode->right != nullptr) {
    lastNode = currNode;
    currNode = currNode->right;
    while (currNode->left != nullptr) {
      lastNode = currNode;
      currNode = currNode->left;
    }
  }
  AVLNode *rt = root_private;
  while (rt->right != nullptr) rt = rt->right;
  if (rt == currNode) ++alreadyVisited;
  return *this;
}

template <typename DataType, bool isMulti>
typename AVLTree<DataType, isMulti>::__Avl_tree_iterator
    AVLTree<DataType, isMulti>::__Avl_tree_iterator::operator++(int flag) {
  if (currNode == nullptr)
    throw std::logic_error("AVLTree::operator++(): empty tree");
  __Avl_tree_iterator copy = *this;
  AVLNode *lastNode = nullptr;
  if (alreadyVisited == -1) ++alreadyVisited;
  if (alreadyVisited == 1) return *this;  // не будем портить ?
  if (currNode->right == nullptr) {
    while (lastNode == currNode->right) {
      lastNode = currNode;
      currNode = currNode->parent;
    }
  } else if (currNode->right != nullptr) {
    lastNode = currNode;
    currNode = currNode->right;
    while (currNode->left != nullptr) {
      lastNode = currNode;
      currNode = currNode->left;
    }
  }
  AVLNode *rt = root_private;
  while (rt->right != nullptr) rt = rt->right;
  if (rt == currNode) ++alreadyVisited;
  return copy;
}

template <typename DataType, bool isMulti>
typename AVLTree<DataType, isMulti>::__Avl_tree_iterator
    AVLTree<DataType, isMulti>::__Avl_tree_iterator::operator--() {
  if (currNode == nullptr)
    throw std::logic_error("AVLTree::operator--(): empty tree");
  AVLNode *lastNode = nullptr;
  if (alreadyVisited == 1) --alreadyVisited;
  if (alreadyVisited == -1) return *this;  // не будем портить ?

  if (currNode->left == nullptr) {
    while (lastNode == currNode->left) {
      lastNode = currNode;
      currNode = currNode->parent;
    }
  } else if (currNode->left != nullptr) {
    lastNode = currNode;
    currNode = currNode->left;
    while (currNode->right != nullptr) {
      lastNode = currNode;
      currNode = currNode->right;
    }
  }
  AVLNode *rt = root_private;
  while (rt->left != nullptr) rt = rt->left;
  if (rt == currNode) --alreadyVisited;
  return *this;
}

template <typename DataType, bool isMulti>
typename AVLTree<DataType, isMulti>::__Avl_tree_iterator
    AVLTree<DataType, isMulti>::__Avl_tree_iterator::operator--(int flag) {
  if (currNode == nullptr)
    throw std::logic_error("AVLTree::operator--(): empty tree");
  __Avl_tree_iterator copy = *this;
  AVLNode *lastNode = nullptr;
  if (alreadyVisited == 1) --alreadyVisited;
  if (alreadyVisited == -1) return *this;  // не будем портить ?

  if (currNode->left == nullptr) {
    while (lastNode == currNode->left) {
      lastNode = currNode;
      currNode = currNode->parent;
    }
  } else if (currNode->left != nullptr) {
    lastNode = currNode;
    currNode = currNode->left;
    while (currNode->right != nullptr) {
      lastNode = currNode;
      currNode = currNode->right;
    }
  }
  AVLNode *rt = root_private;
  while (rt->left != nullptr) rt = rt->left;
  if (rt == currNode) --alreadyVisited;
  return copy;
}

template <typename DataType, bool isMulti>
typename AVLTree<DataType, isMulti>::__Avl_tree_iterator &
AVLTree<DataType, isMulti>::__Avl_tree_iterator::operator=(
    const __Avl_tree_iterator &rhs) {
  this->alreadyVisited = rhs.alreadyVisited;
  this->currNode = rhs.currNode;
  this->root_private = rhs.root_private;
  return *this;
}

template <typename DataType, bool isMulti>
constexpr DataType AVLTree<DataType, isMulti>::__Avl_tree_iterator::operator*()
    const noexcept {
  return *(currNode->data);
}
template <typename DataType, bool isMulti>
constexpr DataType *AVLTree<DataType, isMulti>::__Avl_tree_iterator::
operator->() const noexcept {
  return currNode->data;
}

template <typename DataType, bool isMulti>
constexpr bool AVLTree<DataType, isMulti>::__Avl_tree_iterator::operator==(
    const __Avl_tree_iterator &rhs) const noexcept {
  if (currNode == rhs.currNode && alreadyVisited == rhs.alreadyVisited)
    return true;
  return false;
}

template <typename DataType, bool isMulti>
constexpr bool AVLTree<DataType, isMulti>::__Avl_tree_iterator::operator!=(
    const __Avl_tree_iterator &rhs) const noexcept {
  return !(*this == rhs);
}

template <typename DataType, bool isMulti>
typename AVLTree<DataType, isMulti>::__Avl_tree_iterator
AVLTree<DataType, isMulti>::begin() {
  __Avl_tree_iterator i;
  i.currNode = root;
  i.root_private = root;
  while (i.currNode->left != nullptr) i.currNode = i.currNode->left;
  i.alreadyVisited = -1;
  return i;
}

template <typename DataType, bool isMulti>
typename AVLTree<DataType, isMulti>::__Avl_tree_iterator
AVLTree<DataType, isMulti>::end() {
  __Avl_tree_iterator i;
  i.root_private = root;
  i.currNode = root;
  while (i.currNode->right != nullptr) i.currNode = i.currNode->right;
  i.alreadyVisited = 1;
  return i;
}

template <typename DataType, bool isMulti>
void AVLTree<DataType, isMulti>::erase(__Avl_tree_iterator *rhs) {
  __Avl_tree_iterator copy = *rhs;
  if (isMulti && (rhs.currNode->count > 1)) {
    erase(*copy);
  } else {
    ++(*rhs);
    erase(*copy);
  }
}
}  // namespace akon

#endif  // INCLUDE_AVLTREE_ITERATOR_H_
