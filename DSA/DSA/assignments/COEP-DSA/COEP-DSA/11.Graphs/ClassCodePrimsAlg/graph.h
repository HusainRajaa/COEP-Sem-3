#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

typedef struct graph{
    int vertices;
    int **matrix;
}graph;

void init_graph(graph *g, int size);

void add_edge_undirected(graph *g, int src, int dest, int wt);

void display(graph g);

void prim(graph *g, int x);
#endif // GRAPH_H_INCLUDED
