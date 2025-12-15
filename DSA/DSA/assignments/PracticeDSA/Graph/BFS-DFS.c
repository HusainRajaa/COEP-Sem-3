#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int vertex;
    struct Node* next;
}Node;

typedef struct Graph{
    int numVertices;
    Node** adjLists;
}Graph;

typedef struct Queue{
    int* data;
    int size;
    int front, rear;
}Queue;

typedef struct Stack{
    int *data;
    int size;
    int top;
}Stack;

void initQueue(Queue *q, int size){
    q -> size = size;
    q -> front = 0;
    q -> rear = 0;
    q -> data = (int *)malloc(size * sizeof(int));
}

void enqueue(Queue *q, int data){
    if((q -> rear + 1) % (q -> size) == q -> front){
        printf("Queue is Full\n");
        return;
    }else{
        q -> rear = (q -> rear + 1) % (q -> size);
        q -> data[q -> rear] = data;
    }
}

int dequeue(Queue *q){
    if(q -> front == q -> rear){
        printf("Queue is empty\n");
        return -1;
    }else{
        int x;
        q -> front = (q -> front + 1) % (q -> size);
        x = q -> data[q -> front];
        return x;
    }
}

int isEmpty(Queue q){
    if(q.front == q.rear){
        return 1;
    }else{
        return 0;
    }
}

int isFull(Queue q){
    if((q.rear + 1) % (q.size) == q.front){
        return 1;
    }else{
        return 0;
    }
}

void displayQueue(Queue q){
    int i = q.front + 1;
    do{
        printf("%d ", q.data[i]);
        i = (i + 1) % (q.size);
    }while(i != (q.rear + 1) % (q.size));
    printf("\n");
}

void initStack(Stack *s, int size){
    s -> size = size;
    s -> top = -1;
    s -> data = (int *)malloc(size * sizeof(int));
}

void push(Stack *s, int data){
    if((s -> top == s -> size - 1)){
        printf("Stack Overflow\n");
        return;
    }else{
        s -> data[++s -> top] = data;
    }
}

int pop(Stack *s){
    if(s -> top == -1){
        printf("Stack Underflow\n");
        return -1;
    }else{
        int x = -1;
        x = s -> data[s -> top];
        s -> top--;
        return x;
    }
}

int peek(Stack *s){
    if(s -> top == -1){
        printf("Stack Undeflow\n");
        return -1;
    }else{
        return s -> data[s -> top];
    }
}

int isEmptyStack(Stack s){
    if(s.top == -1){
        return 1;
    }else{
        return 0;
    }
}

int isFullStack(Stack s){
    if(s.top == s.size - 1){
        return 1;
    }else{
        return 0;
    }
}

void displayStack(Stack s){
    for(int i = s.top; i >= 0; i++){
        printf("%d ", s.data[i]);
    }
    printf("\n");
}

void initGraph(Graph *g, int vertices){
    g -> numVertices = vertices;
    g -> adjLists = (Node **)malloc(vertices * sizeof(Node *));
    for(int i = 0; i < vertices; i++){
        g -> adjLists[i] = NULL;
    }
    return;
}

Node *createNode(int d){
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode -> vertex = d;
    newnode -> next = NULL;
    return newnode;
}

void addEdge(Graph *g, int src, int dest){
    Node *newnode = createNode(dest);
    newnode -> next = g -> adjLists[src];
    g -> adjLists[src] = newnode;

    newnode = createNode(src);
    newnode -> next = g -> adjLists[dest];
    g -> adjLists[dest] = newnode;
}

void displayList(Graph *g){
    for(int i = 0; i < g -> numVertices; i++){
        printf("Adjacency List for Verted %d : ", i);
        Node *p = g -> adjLists[i];
        while(p){
            printf("%d ", p -> vertex);
            p = p -> next;
        }
        printf("\n");
    }
}

void BFS(Graph g, int svertex){
    int k, i;
    Queue q;
    initQueue(&q, g.numVertices);
    int *visited = (int *)calloc(g. numVertices, sizeof(int));
    
    visited[svertex] = 1;
    enqueue(&q, svertex);
    printf("%d ", svertex);

    while(!isEmpty(q)){
        k = dequeue(&q);
        Node *p = g.adjLists[k];
        while(p){
            i = p -> vertex;
            if(visited[i] == 0){
                printf("%d ", i);
                enqueue(&q, i);
                visited[i] = 1;
            }
            p = p -> next;
        }
    }
}

void DFS(Graph g, int svertex){
    int k, i;
    Stack s;
    initStack(&s, g.numVertices);
    int *visited = (int *)calloc(g.numVertices, sizeof(int));

    visited[svertex] = 1;
    push(&s, svertex);
    printf("%d ", svertex);

    while(!isEmptyStack(s)){
        k = pop(&s);
        if(visited[k] == 0){
            printf("%d ", k);
            visited[k] = 1;
        }
        Node *p = g.adjLists[k];
        while(p){
            i = p -> vertex;
            if(visited[i] == 0){
                push(&s, i);
            }
            p = p -> next;
        }
    }
}

int main(){
    Graph g;
    initGraph(&g, 5);

    addEdge(&g, 0, 1);
    addEdge(&g, 1, 2);
    addEdge(&g, 2, 3);
    addEdge(&g, 3, 4);
    addEdge(&g, 0, 4);

    BFS(g, 0);
    printf("\n");
    DFS(g, 0);
    return 0;
}