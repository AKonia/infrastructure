// Copyright 2017 AKonia
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <vector>

#include "percolation.h"

using std::cout;
using std::endl;
using std::vector;

int main() {
  srand(time(0));

  uint32_t field[100];
  memset(field, 0, sizeof(field));

  vector<int> v(100);
  for (uint32_t i = 0; i < v.size(); i++) v[i] = i;

  int count = 0;
  for (uint32_t i = 0; i < 1000; ++i) {
    for (uint32_t k = 0; !percolationTest(field, 10); ++k) {
      field[v[k]] = 1;
      ++count;
    }
    random_shuffle(v.begin(), v.end());
    memset(field, 0, sizeof(field));
  }
  cout << endl << "Vacancy probability: " << (count / 1000.0f) << "%" << endl;
  return 0;
}
