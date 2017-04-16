#ifndef _VERTEX_H_
#define _VERTEX_H_

#include "vertex_declaration.h"

template <typename StoragingType>
Vertex<StoragingType>::Vertex()
{
    //data = 0;
}

template <typename StoragingType>
Vertex<StoragingType>::Vertex(StoragingType & vData)
{
    //data = new StoragingType();
    data = vData;
}

template <typename StoragingType>
Vertex<StoragingType>::Vertex(const Vertex & rhs)
{
    //data = new StoragingType();
    data = rhs.data;
    edges = rhs.edges;
}

template <typename StoragingType>
Vertex<StoragingType>::~Vertex()
{
    //if(data != 0)
    //    delete data;
}

template <typename StoragingType>
void Vertex<StoragingType>::setEdge(int vNumber, int eWeight)
{
    if(eWeight < 0) // !!!
        return;

    for(list< pair<int, int> >::iterator i = edges.begin(); i != edges.end(); ++i)
        if(vNumber == i->first)
        {
            if(eWeight == 0)
                edges.erase(i);
            else
                i->second = eWeight;
            return;
        }

    if(eWeight == 0)
        return; // Значит была попытка удалить несуществующее ребро

    edges.push_back(pair<int, int>(vNumber, eWeight));
}

template <typename StoragingType>
void Vertex<StoragingType>::setEdges(const vector<int>& vNumbers, const vector<int>& eWeights)
{
    if(vNumbers.size() != eWeights.size()) // !!!
        return;

    if(edges.empty())
    {
        for(int i = 0; i < vNumbers.size(); i++)
            if(eWeights[i]  > 0)
                edges.push_back(pair<int, int>(vNumbers[i], eWeights[i]));
    }
    else
        for(int i = 0; i < vNumbers.size(); i++)
            setEdge(vNumbers[i], eWeights[i]);
}

template <typename StoragingType>
void Vertex<StoragingType>::removeEdge(int vNumber)
{
    setEdge(vNumber, 0);
}

template <typename StoragingType>
list< pair< int, int > > & Vertex<StoragingType>::getEdgesList()
{
    return edges;
}

template <typename StoragingType>
void Vertex<StoragingType>::setData(StoragingType &new_data)
{
    data = new_data;
}

template <typename StoragingType>
StoragingType Vertex<StoragingType>::getData() const
{
    return data;
}


#endif // _VERTEX_DECLARATION_H_
