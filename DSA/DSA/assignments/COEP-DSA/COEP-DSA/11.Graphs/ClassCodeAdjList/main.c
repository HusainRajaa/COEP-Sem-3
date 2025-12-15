#include <stdio.h>
#include <stdlib.h>
#include "graph.h"



int main() {
    int vertices = 4;

    // Initialize graph structure
    Graph g;
    initGraph(&g, vertices);

    // Add edges
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 2);
    addEdge(&g, 2, 3);

    // Display the graph
    displayGraph(&g);

    // Free the allocated memory
    freeGraph(&g);

    return 0;
}

