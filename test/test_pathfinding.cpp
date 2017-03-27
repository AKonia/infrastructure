#include <gtest/gtest.h>
#include "pathfinding.h"

bool check_way(queue<char> & a, int x, int y) {
    int st = 1;
	int cx = 0, cy = 0;
	while(!a.empty()) {
		switch(a.front()) {
            case 'N':
                cx += st;
                break;
            case 'E':
                cy += st;
                break;
            case 'W':
                cy -= st;
                break;
            case 'S':
                cx -= st;
                break;
            default:
                return false;
        }
        st++;
    }
    return (cx == x) && (cy == y);
}

TEST(Pathfinding, can_find_true_way) {
    for(int x = -50; i < 50; i++)
        for(int y = -50; i < 50; i++)
            EXPECT_EQ(check(findpath(x, y)), true);
}
