#ifndef HEAP_H
#define HEAP_H

#include <exception>
#include <stdexcept>
#include <new>

#include "heap_declaration.h"

namespace akon
{

template <typename DataType, uint8_t base>
Heap<DataType, base>::Heap(uint32_t size)
{
    data = new DataType[size];
    //assert(data != nullptr);
    if(data == nullptr)
        throw std::runtime_error("Heap::Heap(uint32_t): Can't allocate memory for an array");
    //  throw std::bad_alloc(); // нужно придумать другое решение, т.к. не совсем уместно возвращать это вручную и для обычного массива
    //  по умному нужен самописец, отвечающий за вывод предупреждений или сомописный класс исключений наследованный от библиотечного
    currSize = -1;
    heapSize = size;
}

template <typename DataType, uint8_t base>
Heap<DataType, base>::Heap(const Heap &rhs)
{
    heapSize = rhs.heapSize;
    currSize = rhs.currSize;

    data = new DataType[rhs.heapSize];
    // assert(data != nullptr); // лучше халерного bad_alloc
    if(data == nullptr)
        throw std::runtime_error("Heap::Heap(const Heap&): Can't allocate memory for an array");
    //    throw std::bad_alloc(); // это логичнее но bad_alloc больше под объекты уместно ли ?
    for(int i = 0; i < currSize; ++i)
        data[i] = rhs.data[i];
}

template <typename DataType, uint8_t base>
void Heap<DataType, base>::insert(const DataType &rhs)
{
    if((currSize + 1) == heapSize)
        resize(heapSize*2);
    data[++currSize] = rhs;
    int indx = currSize, buf;
    while(data[buf = ((indx-1) / 3)] > rhs)
    {
        std::swap(data[buf], data[indx]);
        indx = buf;
    }

}
template <typename DataType, uint8_t base>
const DataType &Heap<DataType, base>::top() const
{
    return data[0];
}

template <typename DataType, uint8_t base>
const DataType Heap<DataType, base>::pop()
{
    if(currSize < 0)
        throw std::runtime_error("Heap::pop(): popping element from empty Heap");
    DataType temp = data[0];
    data[0] = data[currSize--];
    int indx = 0;
    bool childLess = true;
    while(childLess)
    {
        int minChildIndx = (indx * base) + 1;
        if(minChildIndx > currSize)
            break;
        childLess = false;
        for(int i = minChildIndx, j = 0; (j < base), (i <= currSize); i++, j++)
        {
            if(data[i] < data[minChildIndx])
            {
                minChildIndx = i;
                childLess = true;
            }
        }
        if(data[indx] > data[minChildIndx])
        {
            std::swap(data[indx], data[minChildIndx]);
            indx = minChildIndx;
        }
        else
            childLess = false;
    }

    return temp;
}

template <typename DataType, uint8_t base>
const Heap<DataType, base> & Heap<DataType, base>::operator=(const Heap &rhs)
{
    if(data != nullptr)
        delete[] data;

    heapSize = rhs.heapSize;
    currSize = rhs.currSize;

    data = new DataType[rhs.heapSize];
    if(data == nullptr)
        throw std::runtime_error("Heap::operator=(const Heap&): Can't allocate memory for an array");

    for(int i = 0; i < currSize; ++i)
        data[i] = rhs.data[i];
}

template <typename DataType, uint8_t base>
void Heap<DataType, base>::resize(int32_t size) // Можно изментить размер в ручную, но без ущерба для данных(например если есть ограничения по памяти)
{
    if(size <= currSize)
        throw std::length_error("Heap::resize(uint32_t): Bad new value of size(it can't be less than the old one)");

    DataType * updDataArray = new DataType[size];
    if(updDataArray == nullptr)
        throw std::runtime_error("Heap::resize(uint32_t): Can't allocate memory for an array");

    //    throw std::bad_alloc(); // как этого братца внедрить без проблем
    //    (загвоздка вот в чём: неудачное выделение памяти само бросит исключение)

    for(int i = 0; i < currSize; ++i)
        updDataArray[i] = data[i];
    delete [] data;
    data = updDataArray;
    heapSize = size;
}

template <typename DataType, uint8_t base>
constexpr uint32_t Heap<DataType, base>::getSize() const
{
    return currSize + 1;
}

template <typename DataType, uint8_t base>
constexpr uint32_t Heap<DataType, base>::getHeapSize() const
{
    return heapSize;
}

template <typename DataType, uint8_t base>
constexpr bool Heap<DataType, base>::isEmpty() const
{
    return currSize <= -1;
}

}
#endif // HEAP_H
