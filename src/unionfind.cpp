// Copyright 2017 AKonia
#include "unionfind.h"

UnionFind::UnionFind(uint32_t quantity) {
  size = quantity;
  unionParents = new uint32_t[size];
  unionSizes = new uint32_t[size];
  for (uint32_t i = 0; i < size; ++i) {
    unionParents[i] = i;
    unionSizes[i] = 1;
  }
}

UnionFind::~UnionFind() {
  delete[] unionParents;
  delete[] unionSizes;
  unionParents = unionSizes = nullptr;
}

bool UnionFind::find(uint32_t first, uint32_t second) {
  if ((first >= size) || (second >= size)) return false;  // throw
  while (first != unionParents[first]) first = unionParents[first];
  while (second != unionParents[second]) second = unionParents[second];
  return first == second;
}

bool UnionFind::unite(uint32_t first, uint32_t second) {
  if ((first >= size) || (second >= size)) return false;  // throw
  while (first != unionParents[first]) first = unionParents[first];
  while (second != unionParents[second]) second = unionParents[second];
  if (first == second) return false;
  if (unionSizes[first] > unionSizes[second]) {
    unionSizes[first] += unionSizes[second];
    unionParents[second] = unionParents[first];
  } else {
    unionSizes[second] += unionSizes[first];
    unionParents[first] = unionParents[second];
  }
  return true;
}

uint32_t UnionFind::getSize() { return size; }
