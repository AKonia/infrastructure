// Copyright 2017 AKonia
#ifndef INCLUDE_HEAP_DECLARATION_H_
#define INCLUDE_HEAP_DECLARATION_H_

#if (__cplusplus < 201103L)
#error "C++11 required"
#endif

#include <cstdint>

namespace akon {
template <typename DataType, uint8_t base = 3>
class Heap {
 private:
  DataType *data;

  int32_t heapSize;
  int32_t currSize;

 public:
  explicit Heap(uint32_t size = 256);
  explicit Heap(const Heap &rhs);

  void insert(const DataType &rhs);
  const DataType &top() const;
  const DataType pop();

  const Heap &operator=(const Heap &rhs);

  void resize(int32_t size);
  constexpr uint32_t getSize() const;
  constexpr uint32_t getHeapSize() const;

  constexpr bool isEmpty() const;
};
}  // namespace akon

#endif  // INCLUDE_HEAP_DECLARATION_H_
