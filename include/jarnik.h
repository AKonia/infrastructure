// Copyright 2017 AKonia
#ifndef INCLUDE_JARNIK_H_
#define INCLUDE_JARNIK_H_

#include <cstdint>
#include <list>
#include <utility>
#include "graph_mat_ident.h"

using std::list;
using std::pair;

list<pair<uint32_t, uint32_t> > findMinSpanTreeJarnik(const GraphMatIdent &gid);

#endif  // INCLUDE_JARNIK_H_
