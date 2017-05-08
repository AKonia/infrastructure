// Copyright 2017 AKonia
#ifndef INCLUDE_PRIORITY_QUEUE_H_
#define INCLUDE_PRIORITY_QUEUE_H_

#include "heap.h"

namespace akon {
template <typename DataType>
using PriorityQueue = Heap<DataType, 3>;
}

#endif  // INCLUDE_PRIORITY_QUEUE_H_
