#include <stdio.h>
#include <stdlib.h>
#include"graph.h"

int main()
{
    graph g;
    init_graph(&g, 4);
    add_edge_undirected(&g, 2, 3,10);
    add_edge_undirected(&g, 4, 2,60);
    add_edge_undirected(&g, 1, 3,80);
    add_edge_undirected(&g, 3, 4,20);
    add_edge_undirected(&g, 1, 2,30);
    add_edge_undirected(&g, 1, 4, 25);

    printf("Edges in min spanning tree are");
    prim(&g, 3);

    return 0;
}
