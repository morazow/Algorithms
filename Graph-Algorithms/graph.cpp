#include "graph.h"

#include <algorithm>

Graph::Graph(bool _directed) {
    m_nodes = m_edges = 0;
    m_directed = _directed;
    m_adj = m_rev = NULL;
}

Graph::Graph(const Graph &G) {
}

Graph::Graph(int _nodes = 0, int _edges = 0, bool _directed)
    :m_nodes(_nodes),
     m_edges(_edges),
     m_directed(_directed) {
    assert(m_nodes >= 0 && m_edges >= 0);
    m_adj = new std::vector<uint32_t>[m_nodes];
    m_rev = new std::vector<uint32_t>[m_nodes];
    assert(m_adj != NULL && m_rev != NULL);
}

Graph::~Graph() {
    delete []m_adj;
    delete []m_rev;
}

void Graph::addEdge(int u, int v) {
    assert(u >= 0 && u < m_nodes);
    assert(v >= 0 && v < m_nodes);

    m_adj[u].push_back(v);
    m_rev[v].push_back(u);
    if (!m_directed)
        m_adj[v].push_back(u),
        m_rev[u].push_back(v);
}


void Graph::RevDfs(uint32_t u, std::vector<bool> &vis, std::vector<uint32_t> &seq) {
    vis[u] = true;
    std::vector<uint32_t>::iterator it = m_rev[u].begin();
    for (; it != m_rev[u].end(); it++) {
        if (!vis[*it]) RevDfs(*it, vis, seq);
    }
    seq.push_back(u);
}

void Graph::Dfs(uint32_t u, std::vector<bool> &vis, uint32_t &size) {
    vis[u] = false;
    size++;
    std::vector<uint32_t>::iterator it = m_adj[u].begin();
    for (; it != m_adj[u].end(); it++) {
        if (vis[*it]) Dfs(*it, vis, size);
    }
}

void Graph::SCC() {
    // reverse edges
    // DFS on reserved edges
    // find connected components
    // using reverse visited order in previous DFS

    // DFS Loop
    std::vector<bool> visited(m_nodes, false);
    std::vector<uint32_t> order;
    order.reserve(m_nodes);
    for (uint32_t i = 0; i < m_nodes; i++) {
        if (!visited[i]) RevDfs(i, visited, order);
    }

    // Re use the visited array as it is.
    std::vector<uint32_t> sizes;
    std::vector<uint32_t>::reverse_iterator it = order.rbegin();
    for (; it != order.rend(); it++) {
        if (!visited[*it]) continue;
        uint32_t size = 0;
        Dfs(*it, visited, size);
        sizes.push_back(size);
    }
    std::sort(sizes.begin(), sizes.end());
    size_t Sz = sizes.size();
    if (Sz > 5) Sz = 5;
    for (int i = 0; i < Sz; i++)
        printf("%d ", sizes[sizes.size() - i - 1]);
    printf("\n");
}
