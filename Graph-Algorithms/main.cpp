#include <iostream>
#include <sstream>
#include <string>

#include "graph.h"

int main(int argc, char* argv[]) {
    int N, u, v, d;
    bool directed = false;
    char buffer[1024];

    fgets(buffer, 1024, stdin);
    sscanf(buffer, "%d", &N);

    Graph *G = new Graph(N, 0, directed);

    std::string line;
    char comma;
    while (fgets(buffer, 1024, stdin)) {
        std::istringstream in(buffer);
        in >> u;
        assert(u > 0 && u <= 200);
        u--;
        while (in >> v >> comma >> d) {
            assert(v > 0 && v <= 200);
            v--;
            G->addEdge(u, v, d);
        }
    }
    G->Dijkstra(0);
    delete G;

    return 0;
}
