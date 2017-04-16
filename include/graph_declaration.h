#ifndef _GRAPH_DECLARATION_H_
#define _GRAPH_DECLARATION_H_

#include <list>
#include <vector>
#include <utility>

#include "vertex.h"

using std::list;
using std::pair;
using std::vector;

template< typename StoragingType = bool > // Граф задаётся количеством вершин, затем для каждой вершины прописываются рёбра
class Graph
{
    private:
        vector< Vertex<StoragingType> > *vertices;

    public:
        Graph(); // обнулить массив вершин и их количество, аналогично с рёбрами
        explicit Graph(int qOfVertices); // new vector<>[q]; new edges<>[q];
        Graph(const Graph & rhs);
        ~Graph(); // удалить массив списков рёбер

        void insertVertices(int qOfVertices);
        void setEdge(int vNumberFrom, int vNumberTo, int eWeight);
        void removeEdge(int vNumberFrom, int vNumberTo);
        int getEdgeWeight(int vNumberFrom, int vNumberTo);
        list< pair< int, int > > & getEdgesList(int vNumber);
        const Vertex<StoragingType> &getVertex(int vNumber);


        void setVertexData(int vNumber, StoragingType & data);

        int getVertexCount();
        int getEdgesCount();
};

#endif // _GRAPH_H_
