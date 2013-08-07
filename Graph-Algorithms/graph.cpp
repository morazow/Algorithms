#include "graph.h"

Graph::Graph(bool _directed) {
    m_nodes = m_edges = 0;
    m_directed = _directed;
    m_adj = m_rev = NULL;
}

Graph::Graph(uint32_t _nodes = 0, uint32_t _edges = 0, bool _directed)
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

void Graph::addEdge(uint32_t u, uint32_t v) {
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
    std::vector<uint32_t>::const_iterator it = m_rev[u].begin();
    for (; it != m_rev[u].end(); it++) {
        if (!vis[*it]) RevDfs(*it, vis, seq);
    }
    seq.push_back(u);
}

void Graph::Dfs(uint32_t u, std::vector<bool> &vis, uint32_t &size) {
    vis[u] = false;
    size++;
    std::vector<uint32_t>::const_iterator it = m_adj[u].begin();
    for (; it != m_adj[u].end(); it++) {
        if (vis[*it]) Dfs(*it, vis, size);
    }
}

void Graph::SCC() {
    // reverse edges
    // DFS on reserved edges
    // find connected components
    // using reverse visited order in previous DFS

    // First DFS Loop
    std::vector<bool> visited(m_nodes, false);
    std::vector<uint32_t> visited_order;
    visited_order.reserve(m_nodes);
    for (uint32_t i = 0; i < m_nodes; i++) {
        if (!visited[i]) RevDfs(i, visited, visited_order);
    }

    // Second DFS Loop
    // Re use the visited array as it is.
    uint32_t max_size = 0, size;
    std::vector<uint32_t>::const_reverse_iterator it = visited_order.rbegin();
    for (; it != visited_order.rend(); it++) {
        if (!visited[*it]) continue;
        size = 0;
        Dfs(*it, visited, size);
        if (max_size < size)
            max_size = size;
    }
}
