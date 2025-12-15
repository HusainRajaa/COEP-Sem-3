#include <limits.h>
int findMin(int *dist, int *visited, int vertices){
    int min = INT_MAX, u = -1;
    for(int i = 0; i < vertices; i++){
        if(!visited[i] && dist[i] < min){
            min = dist[i];
            u = i;
        }
    }
    return u;
}

void Dijkstra(Graph *g, int src){
    int vertices = g -> numVertices;
    int dist[vertices];
    int visited[vertices];

    for(int i = 0; i < vertices; i++){
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for(int i = 0; i < vertices - 1; i++){
        int u = findMin(dist, visited, vertices);
        visited[u] = 1;

        for(int v = 0; v < vertices; v++){
            if(visited[v] != 0 && g -> adjMatrix[u][v] != INT_MAX && dist[u] + g -> adjMatrix[u][v] < dist[v]){
                dist[v] = dist[u] + g -> adjMatrix[u][v];
            }
        }
    }

    printf("Vertex\tDistance from source\n");
    for(int i = 0; i < vertices; i++){
        if(dist[i] == INT_MAX){
            printf("%d\tINF\n", i);
        }else{
            printf("%d\t%d", i, dist[i]);
        }
    }
}