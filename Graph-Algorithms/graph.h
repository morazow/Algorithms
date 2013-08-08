#ifndef _GRAPH_H_
#define _GRAPH_H_

// STL
#include <vector>
#include <queue>

// C
#include <stdio.h>
#include <stdint.h>
#include <assert.h>

class Graph {
    uint32_t m_nodes;
    uint32_t m_edges;
    bool m_directed;

    // weighted edge, (d:weight, v:neighbour)
    typedef std::pair<int32_t, uint32_t> w_edge;

    std::vector<w_edge> *m_adj;
    std::vector<uint32_t> *m_rev;

    void RevDfs(uint32_t, std::vector<bool> &, std::vector<uint32_t> &);
    void Dfs(uint32_t, std::vector<bool> &, uint32_t &);

    public:
        Graph(bool _directed = false);
        Graph(const Graph &);
        Graph(uint32_t, uint32_t, bool _directed = false);
        ~Graph();

        void addEdge(uint32_t, uint32_t);
        void addEdge(uint32_t, uint32_t, int32_t);
        void SCC();
        void Dijkstra(uint32_t);
};

#endif
