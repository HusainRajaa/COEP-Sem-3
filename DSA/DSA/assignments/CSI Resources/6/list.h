#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int vertex,weight;
    struct node* next;
} node;

typedef struct graph{
    int vertices;
    node** arr;
}graphList;

typedef struct edge {
	int weight, start, end;
} edge;

void append(node **l, int vertex,int data);
void initGraphList(graphList *g, char *filename);
void printMatrix(graphList g);
void printGraphList(graphList g) ;
void BFSList(graphList g, int src);
void DFSList(graphList g, int src);
void symmetric(graphList g);
edge* createEdge(int weight, int start, int end);
void printMST(edge *MST, int n);
void primsAlgoList(graphList g, int src);
int isDirected(graphList *g);
void degree(graphList *g);
void Indegree(graphList *g);
void dijkstra(graphList *g, int src,int dest);
void outDegree(graphList g);

