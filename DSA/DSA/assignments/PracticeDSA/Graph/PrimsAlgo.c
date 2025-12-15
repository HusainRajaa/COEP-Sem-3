#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Graph{
    int numVertices;
    int** adjMatrix;
}Graph;

void initGraph(Graph *g, int vertices){
    g -> numVertices = vertices;
    g -> adjMatrix = (int **)malloc(vertices * sizeof(int *));
    for(int i = 0; i < vertices; i++){
        g -> adjMatrix[i] = (int *)calloc(vertices , sizeof(int));
    }
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            g->adjMatrix[i][j] = INT_MAX;
        }
    }
    return;
}

void addEdge(Graph *g, int src, int dest, int wt){
    g -> adjMatrix[src - 1][dest - 1] = wt;
    g -> adjMatrix[dest - 1][src - 1] = wt;
    return;
}

void displayList(Graph *g){
    for(int i = 0; i < g -> numVertices; i++){
        for(int j = 0; j < g -> numVertices; j++){
            printf("%d ", g -> adjMatrix[i][j]);
        }
        printf("\n");
    }
}


void prim(Graph *g, int x){
    int startvertex = x - 1;
    int d = g -> numVertices;
    int minwt = INT_MAX, u, v;

    int *near = (int *)malloc(d * sizeof(int));
    for(int i =0; i < d; i++){
        near[i] = INT_MAX;
    }

    int *MST[2];
    MST[0] = (int *)calloc(d - 1, sizeof(int));
    MST[1] = (int *)calloc(d - 1, sizeof(int));

    // To find starting edge
    for(int i = 0; i < d; i++){
        if(g -> adjMatrix[startvertex][i] < minwt){
            minwt = g -> adjMatrix[startvertex][i];
            u = startvertex;
            v = i;
        }
    }
    MST[0][0] = u;
    MST[1][0] = v;
    near[u] = 0;
    near[v] = 0;

    // To fill the near array after first step
    for(int i = 0; i < d; i++){
        if(near[i] != 0){
            if(g -> adjMatrix[i][u] < g -> adjMatrix[i][v]){
                near[i] = u;
            }else{
                near[i] = v;
            }
        }
    }

    int k;
    for(int i = 1; i < d - 1; i++){
        minwt = INT_MAX;
        for(int j = 0; j < d; j++){
            if((near[j] != 0) && g -> adjMatrix[j][near[j]] < minwt){
                minwt = g -> adjMatrix[j][near[j]];
                k = j;
            }
        }
        MST[0][i] = k;
        MST[1][i] = near[k];
        near[k] = 0;

        for(int j = 0; j < d; j++){
            if((near[j] != 0) && (g -> adjMatrix[j][k] < g -> adjMatrix[j][near[j]])){
                near[j] = k;
            }
        }
    }

    for(int i = 0; i < d - 1; i++){
        printf("\n%d -> %d", MST[0][i] + 1, MST[1][i] + 1);
    }
}

int main(){
    Graph g;
    initGraph(&g, 4);
    addEdge(&g, 2, 3, 10);
    addEdge(&g, 4, 2, 60);
    addEdge(&g, 1, 3, 80);
    addEdge(&g, 3, 4, 20);
    addEdge(&g, 1, 2, 30);
    addEdge(&g, 1, 4, 25);

    printf("Edges in min spanning tree are");
    prim(&g, 3);
    return 0;
}