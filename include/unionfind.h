// Copyright 2017 AKonia
#ifndef INCLUDE_UNIONFIND_H_
#define INCLUDE_UNIONFIND_H_

#include <cstdint>

class UnionFind {
 private:
  uint32_t size;
  uint32_t *unionParents;
  uint32_t *unionSizes;

 public:
  explicit UnionFind(uint32_t quantity);
  ~UnionFind();
  bool find(uint32_t first, uint32_t second);
  bool unite(uint32_t first, uint32_t second);
  uint32_t getSize();
};

#endif  // INCLUDE_UNIONFIND_H_
