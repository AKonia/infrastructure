#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

#include "percolation.h"

using namespace std;

int main()
{
    const uint fieldSize = 100;
    srand(time(0));

    uint field[fieldSize];
    memset(field, 0, sizeof(field));

    vector<int> v(fieldSize);
    for(uint32_t i = 0; i < v.size(); i++)
        v[i] = i;

    int count = 0;
    for(uint32_t i = 0; i < 1000; ++i)
    {
        for(uint32_t k = 0;!percolationTest(field, 10); ++k)
        {
            field[v[k]] = 1;
            ++count;
        }
        random_shuffle(v.begin(), v.end());
        memset(field, 0, sizeof(field));
    }
    cout << endl << "Vacancy probability: " << (count / 1000.0f) << "%" << endl;
    return 0;
}
