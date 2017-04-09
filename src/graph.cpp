#include "../include/graph.h"

template< typename StoragingType >
Graph<StoragingType>::Graph()
{
    vertices = 0;
}

template< typename StoragingType >
Graph<StoragingType>::Graph(int qOfVertices)
{
    vertices = new vector< Vertex<StoragingType> >(qOfVertices);
}

template< typename StoragingType >
Graph<StoragingType>::Graph(const Graph<StoragingType> & rhs)
{
    vertices = new vector< Vertex<StoragingType> >((rhs.vertices)->size());
    if(0 == rhs.vertices)
        vertices = 0;
    *vertices = *(rhs.vertices);
}

template< typename StoragingType >
Graph<StoragingType>::~Graph()
{
    delete vertices;
}

template< typename StoragingType >
void Graph<StoragingType>::insertVertices(int qOfVertices)
{
    if(0 == vertices)
    {
        *this = Graph(qOfVertices);
        return;
    }
    else
        vertices->insert(vertices->end(), qOfVertices, Vertex<StoragingType>());
}

template< typename StoragingType >
void Graph<StoragingType>::setEdge(int vNumberFrom, int vNumberTo, int eWeight)
{
    if(vNumberFrom >= vertices->size() || vNumberTo >= vertices->size() || vNumberTo == vNumberFrom || vNumberTo < 0 || vNumberFrom < 0)
        return; // throw

    (*vertices)[vNumberFrom].setEdge(vNumberTo, eWeight);
    (*vertices)[vNumberTo].setEdge(vNumberFrom, eWeight);
}

template< typename StoragingType >
void Graph<StoragingType>::removeEdge(int vNumberFrom, int vNumberTo)
{
    setEdge(vNumberFrom, vNumberTo, 0);
}

template< typename StoragingType >
int Graph<StoragingType>::getEdgeWeight(int vNumberFrom, int vNumberTo)
{
    if(vNumberTo >= vertices->size() || vNumberTo == vNumberFrom || vNumberTo < 0)
        throw -1; // exception

    for(list< pair<int, int> >::iterator j = getEdgesList(vNumberFrom).begin(); j != getEdgesList(vNumberFrom).end(); ++j)
        if(j->first == vNumberTo)
            return j->second;
    return 0; // Возвр. ноль, если ребра нет
}

template< typename StoragingType >
const list< pair< int, int > > & Graph<StoragingType>::getEdgesList(int vNumber) const
{
    if(vNumber >= vertices->size() || vNumber < 0)
        throw -1;
    return (*vertices)[vNumber].getEdgesList();
}

template< typename StoragingType >
int Graph<StoragingType>::getVertexCount()
{
    return vertices->size();
}

template< typename StoragingType >
int Graph<StoragingType>::getEdgesCount()
{
    int qOfEdges = 0;
    for(int i = 0; i < vertices->size(); ++i)
        qOfEdges += ((*vertices)[i]).edges.size();
    return qOfEdges >> 1;
}
