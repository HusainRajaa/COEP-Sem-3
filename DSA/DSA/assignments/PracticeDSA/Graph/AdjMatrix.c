#include <stdio.h>
#include <stdlib.h>

typedef struct graph{
    int numVertices;
    int **adjMatrix;
}graph;

void init(graph *graph, int vertices){
    graph -> numVertices = vertices;
    graph -> adjMatrix = (int **)malloc(sizeof(int *) * vertices);
    for(int i = 0; i < vertices; i++){
        graph -> adjMatrix[i] = (int *)malloc(sizeof(int) * vertices);
        for(int j = 0; j < vertices; j++){
            graph -> adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(graph *graph, int src, int dest){
    graph -> adjMatrix[src][dest] = 1;
    graph -> adjMatrix[dest][src] = 1;      // Undirected Graph
}

void removeEdge(graph *graph, int src, int dest){
    graph -> adjMatrix[src][dest] = 0;
    graph -> adjMatrix[dest][src] = 0;      // Unidirected Graph
}

void displayGraph(graph *graph){
    printf("Adjacency Matrix: \n");
    for(int i = 0; i < graph -> numVertices; i++){
        for(int j = 0; j < graph -> numVertices; j++){
            printf("%d ", graph -> adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void freeGraph(graph *graph){
    for(int i = 0; i < graph -> numVertices; i++){
        free(graph -> adjMatrix[i]);
    }
    free(graph -> adjMatrix);
}

int main(){
    graph g;
    int vertices = 4;
    init(&g, vertices);

    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 2);
    addEdge(&g, 2, 3);

    displayGraph(&g);

    freeGraph(&g);
    return 0;
}