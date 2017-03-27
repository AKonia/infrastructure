#include <gtest/gtest.h>
#include <queue>
using std::queue;
#include "pathfinding.h"
bool check_way(queue<char> a, int x, int y) {
  int st = 1;
  int cx = 0, cy = 0;
  while (!a.empty()) {
    switch (a.front()) {
      case 'N':
        cy += st;
        break;
      case 'E':
        cx += st;
        break;
      case 'W':
        cx -= st;
        break;
      case 'S':
        cy -= st;
        break;
      default:
        return false;
    }
    st++;
    a.pop();
  }
  return (cx == x) && (cy == y);
}

TEST(Pathfinding, can_find_true_way) {
  for (int x = -50; x < 50; x++)
    for (int y = -50; y < 50; y++)
      EXPECT_EQ(check_way(findpath(x, y), x, y), true);
}
