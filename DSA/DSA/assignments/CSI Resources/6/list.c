#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "queue.h"
#include "stack.h"
#include <ctype.h>
#include<limits.h>
void append(node **l, int vertex,int data) {
	node *newnode, *p;
	newnode = (node *)malloc(sizeof(node));
	if(!newnode)
		return;
	newnode -> vertex = vertex;
	newnode -> next = NULL;
	newnode ->weight = data;
	if(*l == NULL) {
		*l = newnode;
		return;
	}
	p = *l;
	while(p -> next)
		p = p -> next;
	p -> next = newnode;
	return;
}

void initGraphList(graphList *g, char *filename) {
	int vertices, data;
	FILE *f;
	f = fopen(filename, "r");
	fscanf(f, "%d", &vertices);
	g -> vertices = vertices;
	g -> arr = (node **)malloc(sizeof(node *) * vertices);
	for(int i = 0; i < g -> vertices; i++) {
		g -> arr[i] = NULL;
		for(int j = 0; j < g -> vertices; j++) {
			if(fscanf(f, "%d", &data) != EOF && data != 0)
				append(&(g -> arr[i]), j,data);
		}
	}
	return;
}
void printMatrix(graphList g){
	printf("\nPrinting in matrix form\n");
	int arr2[g.vertices][g.vertices];
      for (int i = 0; i < g.vertices; i++)
      {
         for (int j = 0; j < g.vertices; j++)
          {
              arr2[i][j] = 0;
          }
      }
       for (int i = 0; i < g.vertices; i++)
       {
           node *p = g.arr[i];
           while (p != NULL)
           {
               arr2[i][p->vertex] = p->weight;
               p = p->next;
           }
       }
	for(int i=0;i<g.vertices;i++){
		for(int j=0;j<g.vertices;j++){
			printf("%d ",arr2[i][j]);
			}
			printf("\n");
	}
	return;
}
void printGraphList(graphList g) {
	printf("\nAdjacency List\n");
	node *p;
	for(int i = 0; i < g.vertices; i++) {
		printf("Vertex %d: ", i);
		p = g.arr[i];
		while(p) {
			printf(" v: %d, w: %d|", p -> vertex, p->weight);
			p = p -> next;
		}
		printf("\n");
	}
	printf("\n");
	return;
}

void BFSList(graphList g, int src) {
	printf("\nBFS List: ");
	queue q;
	node *p;
	int x;
	initQueue(&q, 128);
	int visited[g.vertices];
	for(int i = 0; i < g.vertices; i++)
		visited[i] = 0;
	enqueue(&q, src);
	visited[src] = 1;
	while(!isQueueEmpty(q)) {
		x = dequeue(&q);
		printf("%d ", x);
		p = g.arr[x];
		while(p) {
			if(!visited[p -> vertex]) {
				enqueue(&q, p -> vertex);
				visited[p -> vertex] = 1;
			}
			p = p -> next;
		}
	}
	printf("\n");
	return;
}

void DFSList(graphList g, int src) {
	printf("DFS List: ");
	stack s;
	node *p;
	int x;
	initStack(&s, 128);
	int visited[g.vertices];
	for(int i = 0; i < g.vertices; i++)
		visited[i] = 0;
	push(&s, src);
	visited[src] = 1;
	while(!isStackEmpty(s)) {
		x = pop(&s);
		printf("%d ", x);
		p = g.arr[x];
		while(p) {
			if(!visited[p -> vertex]) {
				push(&s, p -> vertex);
				visited[p -> vertex] = 1;
			}
			p = p -> next;
		}
	}
	printf("\n");
	return;
}

edge* createEdge(int weight, int start, int end){
    edge* nn;
    nn = (edge*)malloc(sizeof(edge));
	if(!nn)
		return NULL;
	nn -> weight = weight;
	nn -> start = start;
	nn -> end = end;
	return nn;
}

void printMST(edge *MST, int n) {
	int sum = 0;
	for(int i = 0; i < n; i++) {
		printf("%d - %d : %d\n", MST[i].start, MST[i].end, MST[i].weight);
		sum = sum + MST[i].weight;
	}
	printf("Minimum cost: %d\n", sum);
	return;
}

void primsAlgoList(graphList g, int src) {
    printf("\n");
	printf("\nPrim's Algorithm (List)\n");
    int visited[g.vertices], dis[g.vertices], x = 0;
    edge span[g.vertices - 1], *q;
    node *p;
  	for(int i = 0; i < g.vertices; i++) {
  		visited[i] = 0;
  		dis[i] = INT_MAX;
  	}
  	visited[src] = 1;
  	dis[src] = 0;
	for(int i = 0; i < g.vertices; i++) {
	    if(visited[i]) {
		    p = g.arr[i];
		    while(p) {
		      	if(!visited[p -> vertex] && dis[p -> vertex] > p -> weight && x < g.vertices - 1) {
		      		q = createEdge(p -> weight, i, p -> vertex);
		      		span[x] = *q;
		      		x += 1;
		      		visited[p -> vertex] = 1;
		      		dis[p -> vertex] = p -> weight;
		        }
		        p = p -> next;
		    }
	    }
	}
	printMST(span, g.vertices - 1);
	return;
}

int isDirected(graphList *g){
    int sym = 0;
    int arr2[g->vertices][g->vertices];
    for (int i = 0; i < g->vertices; i++)
    {
        for (int j = 0; j < g->vertices; j++)
        {
            arr2[i][j] = 0;
        }
    }
    for (int i = 0; i < g->vertices; i++)
    {
        node *p = g->arr[i];
        while (p != NULL)
        {
            arr2[i][p->vertex] = p->weight;
            p = p->next;
        }
    }
    for (int i = 0; i < g->vertices; i++)
    {
        for (int j = 0; j < g->vertices; j++)
        {
            if (arr2[i][j] != arr2[j][i])
            {
                sym = 0;
                //printf("%d",sym);
                return sym; // if not symmentric and hence directed
            }
            else{
                sym = 1; // if symmentric and hence undirected
            }
        }
    }
    return sym;
}
void degree(graphList *g)
{
    int arr2[g->vertices][g->vertices];
    for (int i = 0; i < g->vertices; i++)
    {
        for (int j = 0; j < g->vertices; j++)
        {
            arr2[i][j] = 0;
        }
    }
    for (int i = 0; i < g->vertices; i++)
    {
        node *p = g->arr[i];
        while (p != NULL)
        {
            arr2[i][p->vertex] = p->weight;
            p = p->next;
        }
    }
    printf("\nThe graph symmetric and hence it is undirected");
    for(int m=0;m<g->vertices;m++){
        int count = 0;
        for(int n=0;n<g->vertices;n++){
            if(arr2[m][n]!=0){
                count = count+1;
            }
            else{
                count = count;
            }
        }
        printf("\nDegree of %d is: %d",m,count);
    }
    return ;
}


void Indegree(graphList *g){
    int arr2[g->vertices][g->vertices];
    for (int i = 0; i < g->vertices; i++)
    {
        for (int j = 0; j < g->vertices; j++)
        {
            arr2[i][j] = 0;
        }
    }
    for (int i = 0; i < g->vertices; i++)
    {
        node *p = g->arr[i];
        while (p != NULL)
        {
            arr2[i][p->vertex] = p->weight;
            p = p->next;
        }
    }

    printf("\nThe graph is directed and hence not symmetric");
    for(int m =0;m<g->vertices;m++){
        int id=0;
        for(int n=0;n<g->vertices;n++){
            if(arr2[n][m]!=0){
                id++;
            }
        }
        printf("\nIndegree of vertex %d is: %d",m,id);
    }
}

void dijkstra(graphList *g, int src,int dest){
    int distance[g->vertices];
    int visited[g->vertices];
    for(int i=0;i<g->vertices;i++){
        visited[i]=0;
        distance[i]=INT_MAX;
    }

    distance[src]=0;
    for(int i=0;i<g->vertices;i++){
        int min=INT_MAX;
        int minIndex;
        for(int j=0;j<g->vertices;j++){
            if(visited[j]==0 && distance[j]<min){
                min = distance[j];
                minIndex=j;
            }
        }
        visited[minIndex]=1;
        node *p;
        p=g->arr[minIndex];
        p=p->next;
        while(p){
            if(!visited[p->vertex] && distance[minIndex]!=INT_MAX && (distance[minIndex] + p->weight < distance[p->vertex]))
                distance[p->vertex] = distance[minIndex] + p->weight;
            p=p->next;
        }
    }
    printf("\n");
    for(int j=0;j<g->vertices;j++){
        if(j==dest){
            printf("From %d to %d shortest distance is: %d ",src,dest,distance[dest]);
        }
    }
    printf("\nDistance array for Dijkstra's is:");
    for (int i = 0; i < g->vertices; i++)
        printf(" %d", distance[i]);
    printf("\n");

}

void outDegree(graphList g){
    node* p;
    for(int i=0;i<g.vertices;i++){
        int od=0;
        p=g.arr[i];
        while(p){
            od++;
            p=p->next;
        }
        printf("\nOutdegree of Vertex %d: %d",i,od);
    }
}
