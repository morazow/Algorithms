#include <iostream>

#include "graph.h"

int main(int argc, char* argv[]) {
    int N, u, v;
    bool directed = true;

    fscanf(stdin, "%d", &N);
    Graph *G = new Graph(N, 0, directed);
    while (fscanf(stdin, "%d %d", &u, &v) != EOF) {
        u--; v--;
        G->addEdge(u, v);
    }
    G->SCC();
    delete G;

    return 0;
}
