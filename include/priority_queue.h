#ifndef PRIORITY_QUEUE_H_
#define PRIORITY_QUEUE_H_

#include "heap.h"

namespace akon
{
    template <typename DataType>
    using PriorityQueue = Heap<DataType, 4>;
}

#endif // PRIORITY_QUEUE_H_
