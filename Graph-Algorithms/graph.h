#ifndef _GRAPH_H_
#define _GRAPH_H_

// STL
#include <vector>

// C
#include <stdio.h>
#include <stdint.h>
#include <assert.h>

class Graph {
    uint32_t m_nodes;
    uint32_t m_edges;
    bool m_directed;

    std::vector<uint32_t> *m_adj;
    std::vector<uint32_t> *m_rev;

    void RevDfs(uint32_t, std::vector<bool> &, std::vector<uint32_t> &);
    void Dfs(uint32_t, std::vector<bool> &, uint32_t &);

    public:
        Graph(bool _directed = false);
        Graph(const Graph &);
        Graph(int, int, bool _directed = false);
        ~Graph();

        void addEdge(int, int);
        void SCC();
};

#endif
