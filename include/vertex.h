#ifndef _VERTEX_H_
#define _VERTEX_H_

#include <list>
#include <vector>
#include <utility>

using std::list;
using std::pair;
using std::vector;


template <typename StoragingType>
class Vertex
{
    private:
        list< pair< int, int > > edges; // pair< to, weight >, рёбра имеют положительные веса
        StoragingType * data; // Полезные данные хранимые в вершине допускаю например координаты x [y, z] в данной работе ?уместно? поставить флаг(bool) посещения вершины

    public:
        Vertex();
        explicit Vertex(StoragingType * vData);
        Vertex(const Vertex & rhs);
        ~Vertex(); // del data

        // Методы работы с рёбрами
        void setEdge(int vNumber, int eWeight); // Ограничение 1 - отрицательных весов нет , нулевой вес означает удаление ребра; Ограничение 2 - нельзя соединять с несуществующей вершиной, т.е. number <
        void setEdges(const vector<int>& vNumbers, const vector<int>& eWeights);
        void removeEdge(int vNumber); // = setEdge(int number , 0);
        const list< pair< int, int > > & getEdgesList() const;

        // Методы работы с данными
        void setData(StoragingType * data); // можно записать данные по вершине, предлагаю для лабы и д/з записывать факт посещения вершины
        const StoragingType * getData() const;
};

#endif // _VERTEX_H_
