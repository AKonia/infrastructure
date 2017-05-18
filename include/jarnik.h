#ifndef PRIM_H
#define PRIM_H

#include "graph_mat_ident.h"
#include <list>
#include <utility>
#include <cstdint>

using std::list;
using std::pair;

list< pair<uint32_t, uint32_t> > findMinSpanTreeJarnik(const GraphMatIdent &gid);

#endif // PRIM_H
