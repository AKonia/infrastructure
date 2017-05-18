#ifndef HEAP_DECLARATION_H
#define HEAP_DECLARATION_H

#if (__cplusplus < 201103L)
    #error "C++11 required"
#endif

//#if !defined(__linux__) && !defined(__gnu_linux__)
//    #warning "Visual app GNU/Linux required"
//#endif

#include <cstdint>

namespace akon
{
    template <typename DataType, uint8_t base = 3>
    class Heap
    {
    private:
        DataType * data;

    int32_t heapSize; // ориентировочный рост <<1
    int32_t currSize;

public:
    explicit Heap(uint32_t size = 256);
    explicit Heap(const Heap &rhs);

    void insert(const DataType &rhs);
    const DataType & top() const;
    const DataType pop();

    const Heap & operator=(const Heap &rhs);

    void resize(int32_t size); // Можно изментить размер в ручную
    constexpr uint32_t getSize() const;
    constexpr uint32_t getHeapSize() const;

    constexpr bool isEmpty() const;
};

}
// Следующий код нужно вынести в отдельный заголовок
//template <typename DataType> // изначально template <typename DataType, uint32_t base = 3>
//using PriorityQueue = Heap<DataType, 3>; // а здесь using PriorityQueue = Heap<DataType, base>;
// Я же установил постоянным второй параметр так, что теперь PriorityQueue это однопараметрический шаблон
// Так прикольнее)), правда cpp11(но оно же того стоит :) )

#endif // HEAP_DECLARATION_H
