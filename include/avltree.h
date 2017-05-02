// Copyright 2017 AKonia
#ifndef INCLUDE_AVLTREE_H_
#define INCLUDE_AVLTREE_H_

#include <cmath>
#include <exception>
#include <queue>
#include <stack>
#include <stdexcept>
#include <algorithm>

#include "avltree_iterator.h"

using std::queue;
using std::stack;
using std::cout;
using std::endl;

namespace akon {

template <typename DataType, bool isMulti>
typename AVLTree<DataType, isMulti>::AVLNode **
AVLTree<DataType, isMulti>::lookup(const DataType &val, AVLNode **parent,
                                   int countChanging) {
  AVLNode **curr = &root, *temp = root;
  while (temp != nullptr) {
    if (*(temp->data) == val) {
      temp->count += countChanging;
      treeCount += countChanging;
      if (!isMulti && (temp->count > 1))
        throw std::logic_error(
            "AVLTree::insert(): Insertion of existing element not permitted");
      if (temp->count == 0) remove(temp);
      return nullptr;
    }
    if (*(temp->data) < val) {
      *parent = temp;
      curr = &temp->right;
      temp = temp->right;
    } else {
      *parent = temp;
      curr = &temp->left;
      temp = temp->left;
    }
  }
  return curr;
}

template <typename DataType, bool isMulti>
void AVLTree<DataType, isMulti>::leftRotate(AVLNode **P) {
  int8_t upper = (*P)->height;
  int8_t center = (*P)->right->height;
  (*P)->right->height -= 1;
  (*P)->height -= (center + ((upper < 0) ? -1 : 1));
  AVLNode *PP = (*P)->right;
  if (PP->right == nullptr) {
    std::swap(PP->parent, PP->left);
    std::swap(PP->left->right, PP->left->parent);
    std::swap(PP->left->right, PP->parent);
    if (PP->parent == nullptr) {
      root = PP;
    } else {
      if (PP->parent->left == PP->left)
        PP->parent->left = PP;
      else
        PP->parent->right = PP;
    }
  } else {
    if (PP->left != nullptr) PP->left->parent = PP->parent;

    std::swap(PP->left, PP->parent->right);
    std::swap(PP->left, PP->parent->parent);
    std::swap(PP->parent, PP->left);
    if (PP->parent == nullptr) {
      root = PP;
    } else {
      if (PP->parent->left == PP->left)
        PP->parent->left = PP;
      else
        PP->parent->right = PP;
    }
  }
}

template <typename DataType, bool isMulti>
void AVLTree<DataType, isMulti>::rightRotate(AVLNode **P) {
  int8_t upper = (*P)->height;
  int8_t center = (*P)->left->height;
  (*P)->left->height += 1;
  (*P)->height -= (center + ((upper < 0) ? -1 : 1));
  AVLNode *PP = (*P)->left;
  if (PP->left == nullptr) {
    std::swap(PP->parent, PP->right);
    std::swap(PP->right->left, PP->right->parent);
    std::swap(PP->right->left, PP->parent);
    if (PP->parent == nullptr) {
      root = PP;
    } else {
      if (PP->parent->right == PP->right)
        PP->parent->right = PP;
      else
        PP->parent->left = PP;
    }
  } else {
    if (PP->right != nullptr) PP->right->parent = PP->parent;
    std::swap(PP->right, PP->parent->left);
    std::swap(PP->right, PP->parent->parent);
    std::swap(PP->parent, PP->right);
    if (PP->parent == nullptr) {
      root = PP;
    } else {
      if (PP->parent->right == PP->right)
        PP->parent->right = PP;
      else
        PP->parent->left = PP;
    }
  }
}

template <typename DataType, bool isMulti>
void AVLTree<DataType, isMulti>::rebalance(AVLNode *rhs,
                                           int8_t balancingFactor) {
  AVLNode *updaterBalance = rhs->parent, *direction = rhs;
  while (updaterBalance != nullptr) {
    if (updaterBalance->left == direction)
      updaterBalance->height += balancingFactor;
    else
      updaterBalance->height -= balancingFactor;
    if (abs(updaterBalance->height) == 1) break;
    if (abs(updaterBalance->height) == 2) {
      if (updaterBalance->height > 0)
        leftRotate(&updaterBalance);
      else
        rightRotate(&updaterBalance);
      break;
    }
    direction = updaterBalance;
    updaterBalance = updaterBalance->parent;
  }
}

template <typename DataType, bool isMulti>
void AVLTree<DataType, isMulti>::remove(AVLNode *rhs) {
  --treeSize;
  if ((rhs->left == nullptr) && (rhs->right == nullptr)) {
    if (rhs == root) {
      delete root->data;
      root->data = nullptr;
      delete root;
      root = nullptr;
      return;
    }
    rebalance(rhs);
    if (rhs->parent->left == rhs)
      rhs->parent->left = nullptr;
    else
      rhs->parent->right = nullptr;

  } else if ((rhs->left == nullptr) || (rhs->right == nullptr)) {
    AVLNode *temp = (rhs->left == nullptr) ? rhs->right : rhs->left;
    if (rhs == root) {
      delete root->data;
      root->data = nullptr;
      delete root;
      root = temp;
      root->parent = nullptr;
      return;
    }

    temp->parent = rhs->parent;

    if (rhs->parent->left == rhs)
      rhs->parent->left = temp;
    else
      rhs->parent->right = temp;

    rebalance(temp);
  } else {
    AVLNode *replacementPosition = rhs->right;
    while (replacementPosition->left != nullptr)
      replacementPosition = replacementPosition->left;
    if (replacementPosition == rhs->right) {
      replacementPosition->parent = rhs->parent;
      replacementPosition->left = rhs->left;
      rhs->left->parent = replacementPosition;
      if (rhs == root) {
        root = replacementPosition;
      } else {
        if (rhs->parent->left == rhs)
          rhs->parent->left = replacementPosition;
        else
          rhs->parent->right = replacementPosition;
      }
      replacementPosition->height += rhs->height - 1;
      if (replacementPosition->height == -2)
        rightRotate(&replacementPosition);
      else if (replacementPosition->height == 2)
        leftRotate(&replacementPosition);
    } else {
      delete rhs->data;
      rhs->data = replacementPosition->data;
      rhs->count = replacementPosition->count;
      rebalance(replacementPosition);
      replacementPosition->parent->left = replacementPosition->right;
      delete replacementPosition;
      return;
    }
  }
  delete rhs->data;
  delete rhs;
}

template <typename DataType, bool isMulti>
AVLTree<DataType, isMulti>::AVLTree() {
  treeSize = treeCount = 0;
  root = nullptr;
}

template <typename DataType, bool isMulti>
AVLTree<DataType, isMulti>::AVLTree(const AVLTree<DataType, isMulti> &rhs) {
  root = nullptr;
  treeCount = treeSize = 0;
  queue<AVLNode *> copier;
  copier.push(rhs.root);
  while (!copier.empty()) {
    AVLNode *temp = copier.front();
    if (temp != nullptr) {
      insert(*(temp->data));
      if (temp->count > 1) {
        AVLNode *buf = nullptr;
        lookup(*(temp->data), &buf, temp->count - 1);
      }
      copier.push(temp->left);
      copier.push(temp->right);
    }
    copier.pop();
  }
}

template <typename DataType, bool isMulti>
AVLTree<DataType, isMulti>::~AVLTree() {
  if (treeSize == 0) return;
  stack<AVLNode *> tree;
  AVLNode *currentToDelete = nullptr;
  tree.push(root);
  while (!tree.empty()) {
    currentToDelete = tree.top();
    tree.pop();
    if (currentToDelete != nullptr) {
      tree.push(currentToDelete->left);
      tree.push(currentToDelete->right);
      currentToDelete->left = currentToDelete->right = nullptr;

      delete currentToDelete->data;
      currentToDelete->data = nullptr;
      delete currentToDelete;
    }
  }
}

template <typename DataType, bool isMulti>
bool AVLTree<DataType, isMulti>::find(const DataType &val) noexcept {
  AVLNode *par = nullptr;
  return lookup(val, &par) == nullptr;
}

template <typename DataType, bool isMulti>
void AVLTree<DataType, isMulti>::insert(const DataType &val) {
  AVLNode *par = nullptr;
  AVLNode **freepos = lookup(val, &par, 1);
  if (freepos == nullptr) return;
  *freepos = new AVLNode;
  (*freepos)->data = new DataType;
  *((*freepos)->data) = val;
  (*freepos)->left = (*freepos)->right = nullptr;
  (*freepos)->parent = par;
  (*freepos)->height = 0;
  (*freepos)->count = 1;
  ++treeSize;
  ++treeCount;
  AVLNode *updaterBalance = (*freepos)->parent, *direction = (*freepos);
  int8_t history[2] = {0, 0};
  while (updaterBalance != nullptr) {
    if (updaterBalance->left == direction) {
      history[1] = history[0];
      history[0] = -1;
      --(updaterBalance->height);
    } else {
      history[1] = history[0];
      history[0] = 1;
      ++(updaterBalance->height);
    }
    if (updaterBalance->height == 0) return;
    if (abs(updaterBalance->height) == 2) {
      if (history[0] == history[1]) {
        if (history[0] == 1)
          leftRotate(&updaterBalance);
        else
          rightRotate(&updaterBalance);
      } else {
        if (history[0] == -1) {
          leftRotate(&updaterBalance->left);
          rightRotate(&updaterBalance);
        } else {
          rightRotate(&updaterBalance->right);
          leftRotate(&updaterBalance);
        }
      }
      break;
    }
    direction = updaterBalance;
    updaterBalance = updaterBalance->parent;
  }
}

template <typename DataType, bool isMulti>
void AVLTree<DataType, isMulti>::erase(const DataType &val) {
  AVLNode *par = nullptr;
  AVLNode **tmp = lookup(val, &par, -1);
  if (tmp != nullptr)
    throw std::logic_error(
        "AVLTree::erase(const DataType&): Erasing of unexisting element");
}

template <typename DataType, bool isMulti>
constexpr bool AVLTree<DataType, isMulti>::isEmpty() const noexcept {
  return treeSize == 0;
}

template <typename DataType, bool isMulti>
constexpr uint32_t AVLTree<DataType, isMulti>::getSize() const noexcept {
  return treeSize;
}

template <typename DataType, bool isMulti>
const DataType &AVLTree<DataType, isMulti>::getMin() const {
  AVLNode *tmp = root;
  if (isEmpty()) throw std::range_error("AVLTree::getMin(): Tree is Empty");
  while (tmp->left != nullptr) tmp = tmp->left;
  return *(tmp->data);
}

template <typename DataType, bool isMulti>
const DataType &AVLTree<DataType, isMulti>::getMax() const {
  AVLNode *tmp = root;
  if (isEmpty()) throw std::range_error("AVLTree::getMax(): Tree is Empty");
  while (tmp->right != nullptr) tmp = tmp->right;
  return *(tmp->data);
}
}  // namespace akon

#endif  // INCLUDE_AVLTREE_H_
