// Copyright 2017 AKonia
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>

#include "islands.h"

using std::cout;
using std::endl;

int main() {
  srand(time(0));

  uint32_t field[100];
  uint32_t fieldCopy[100];
  memset(field, 0, sizeof(field));

  for (uint32_t i = 0; i < 45; ++i) field[rand() % 100] = 1;
  memcpy(fieldCopy, field, sizeof(field));

  cout << "\nBEFORE DELUGE";
  for (uint32_t i = 0; i < 100; ++i) {
    if (i % 10 == 0) cout << endl;
    if (field[i] == 1)
      cout << "\x1b[0m\x1b[33m\x1b[43m";
    else
      cout << "\x1b[0m\x1b[34m\x1b[44m";
    cout << field[i] << " \x1b[0m";
  }

  islands(field, 10);

  cout << "\nAFTER DELUGE";
  for (uint32_t i = 0; i < 100; ++i) {
    if (i % 10 == 0) cout << endl;
    if (field[i] == 1)
      cout << "\x1b[0m\x1b[33m\x1b[43m";
    else
      cout << "\x1b[0m\x1b[34m\x1b[44m";
    cout << field[i] << " \x1b[0m";
  }
  cout << endl;
  return 0;
}
