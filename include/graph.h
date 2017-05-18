#ifndef GRAPH_H
#define GRAPH_H

#include <cstdint>

class Graph
{
private:
    uint32_t size;
    uint32_t ** connMat;
public:
    Graph(uint32_t size);
    Graph(const Graph & rhs);
    ~Graph();

    void setEdge(uint32_t vFirst, uint32_t vSecond, uint32_t eWeight);
    void unsetEdge(uint32_t vFirst, uint32_t vSecond);

    uint32_t getEdgeWeight(uint32_t vFirst, uint32_t vSecond) const;
    uint32_t getSize() const;
};

#endif // GRAPH_H
