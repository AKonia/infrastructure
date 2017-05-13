// Copyright 2017 AKonia
#include "percolation.h"

bool percolationTest(uint32_t *field, uint32_t width) {
  uint32_t fieldSize = width * width;
  UnionFind uf(fieldSize);
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
  for (uint32_t i = 0; i < width; ++i) {
    for (uint32_t j = width * (width - 1); j < width * width; ++j)
      if ((field[j] == 1) && uf.find(j, i)) return true;
  }
  return false;
}
