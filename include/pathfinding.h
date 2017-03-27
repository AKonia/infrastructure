#ifndef INCLUDE_PATHFINDING_H_
#define INCLUDE_PATHFINDING_H_

#include <queue>
using std::queue;

queue<char> findpath(const int x, const int y) {
  queue<char> way;
  for (int i = x; i < 0; i++) {
    way.push('E');
    way.push('W');
  }
  for (int i = 0; i < x; i++) {
    way.push('W');
    way.push('E');
  }
  for (int i = y; i < 0; i++) {
    way.push('N');
    way.push('S');
  }
  for (int i = 0; i < y; i++) {
    way.push('S');
    way.push('N');
  }
  return way;
}

#endif  // INCLUDE_PATHFINDING_H_
