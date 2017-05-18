#include "graph.h"

Graph::Graph(uint32_t size)
{
    this->size = size;
    connMat = new uint32_t*[size];
    for(uint32_t i = 0; i < size; ++i)
        connMat[i] = new uint32_t[size];
    for(uint32_t i = 0; i < size; ++i)
        for(uint32_t j = 0; j < size; ++j)
            connMat[i][j] = 0;
}

Graph::Graph(const Graph &rhs)
{
    size = rhs.size;
    connMat = new uint32_t*[size];
    for(uint32_t i = 0; i < size; ++i)
        connMat[i] = new uint32_t[size];
    for(uint32_t i = 0; i < size; ++i)
        for(uint32_t j = 0; j < size; ++j)
            connMat[i][j] = rhs.connMat[i][j];
}

Graph::~Graph()
{
    for(uint32_t i = 0; i < size; ++i)
        delete [] connMat[i];
    delete[] connMat;
}

void Graph::setEdge(uint32_t vFirst, uint32_t vSecond, uint32_t eWeight)
{
    connMat[vFirst][vSecond] = connMat[vSecond][vFirst] = eWeight;
}

void Graph::unsetEdge(uint32_t vFirst, uint32_t vSecond)
{
    connMat[vFirst][vSecond] = connMat[vSecond][vFirst] = 0;
}

uint32_t Graph::getEdgeWeight(uint32_t vFirst, uint32_t vSecond) const
{
    return connMat[vFirst][vSecond];
}

uint32_t Graph::getSize() const
{
    return size;
}
