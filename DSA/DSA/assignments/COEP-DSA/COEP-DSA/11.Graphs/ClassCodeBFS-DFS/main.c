#include<stdio.h>
#include<stdlib.h>
#include "graph.h"

int main() {
    graph g;
    init_graph(&g, 5); // Correct size based on the highest numbered vertex

    // Adding edges
    addEdge(&g, 0, 1);
    addEdge(&g, 1, 2);
    addEdge(&g, 2, 3);
    addEdge(&g, 3, 4);
    addEdge(&g, 0, 4);

    BFS(g, 0); // Assuming BFS function is implemented correctly

    if (isCyclicConnected(&g, 0)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
