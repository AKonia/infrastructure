// Copyright 2017 AKonia
#ifndef INCLUDE_KRUSKAL_H_
#define INCLUDE_KRUSKAL_H_

#include <cstdint>
#include <list>
#include <utility>
#include "graph.h"
using std::list;
using std::pair;

list<pair<uint32_t, uint32_t> > findMinSpanTreeKruskal(const Graph& g);

#endif  // INCLUDE_KRUSKAL_H_
