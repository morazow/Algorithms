#include "graph.h"

#include <iostream>
#include <set>
int main() {
    //int N = 875714, u, v;
    int N;
    fscanf(stdin, "%d", &N);
    Graph *G = new Graph(N, 0, true);
    int u, v;
    std::set<int> S;
    while (fscanf(stdin, "%d %d", &u, &v) != EOF) {
        u--; v--;
        S.insert(u);
        S.insert(v);
        G->addEdge(u, v);
    }
    assert(S.size() == N);
    G->SCC();
    delete G;
    return 0;
}
