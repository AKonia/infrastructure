// Copyright 2017 AKonia
#include "islands.h"
#include <vector>
#include "unionfind.h"

void islands(uint32_t *field, uint32_t width) {
  UnionFind uf(width * width);
  for (uint32_t i = 0; i < width; ++i) {
    for (uint32_t j = 0; j < width; ++j) {
      if ((j > 0) && (field[width * i + j - 1] == field[width * i + j]))
        uf.unite(width * i - 1 + j, width * i + j);
      if ((j < (width - 1)) &&
          (field[width * i + j + 1] == field[width * i + j]))
        uf.unite(width * i + 1 + j, width * i + j);
      if ((i > 0) && (field[width * i - width + j] == field[width * i + j]))
        uf.unite(width * i - width + j, width * i + j);
      if ((j < (width - 1)) &&
          (field[width * i + width + j] == field[width * i + j]))
        uf.unite(width * i + width + j, width * i + j);
    }
  }

  std::vector<int> v;
  for (uint32_t i = 0; i < 10; ++i) {
    if (field[i] == 1) v.push_back(i);
    if (field[i * 10] == 1) v.push_back(i * 10);
    if (field[i * 10 + width - 1] == 1) v.push_back(i * 10 + width - 1);
    if (field[width * width - width + i] == 1)
      v.push_back(width * width - width + i);
  }

  for (uint32_t i = 1; i < (width - 1); ++i) {
    for (uint32_t j = 1; j < (width - 1); ++j) {
      bool flag = true;
      for (uint32_t k = 0; k < v.size(); ++k) {
        if (uf.find(v[k], i * 10 + j)) {
          flag = false;
          break;
        }
      }
      if (flag) field[i * 10 + j] = 0;
    }
  }
}
