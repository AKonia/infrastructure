#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "graph.h"
#include <list>
#include <utility>
#include <cstdint>
using std::list;
using std::pair;

list< pair<uint32_t, uint32_t> > findMinSpanTreeKruskal(const Graph & g);

#endif // KRUSKAL_H
