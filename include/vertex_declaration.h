#ifndef _VERTEX_DECLARATION_H_
#define _VERTEX_DECLARATION_H_

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
        StoragingType data; // Полезные данные хранимые в вершине допускаю например координаты x [y, z] в данной работе ?уместно? поставить флаг(bool) посещения вершины

    public:
        Vertex();
        explicit Vertex(StoragingType &vData);
        Vertex(const Vertex & rhs);
        ~Vertex();

        // Методы работы с рёбрами
        void setEdge(int vNumber, int eWeight); // Ограничение 1 - отрицательных весов нет , нулевой вес означает удаление ребра; Ограничение 2 - нельзя соединять с несуществующей вершиной, т.е. number <
        void setEdges(const vector<int>& vNumbers, const vector<int>& eWeights);
        void removeEdge(int vNumber); // = setEdge(int number , 0);
        list< pair< int, int > > & getEdgesList();

        // Методы работы с данными
        void setData(StoragingType &new_data);
        StoragingType getData() const;
};

#endif // _VERTEX_DECLARATION_H_
