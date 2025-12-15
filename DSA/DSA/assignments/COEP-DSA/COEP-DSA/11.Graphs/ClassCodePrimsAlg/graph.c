    #include<stdio.h>
    #include<stdlib.h>
    #include<limits.h>
    #include"graph.h"

    void init_graph(graph *g, int n){
        g->vertices = n;
        g->matrix = (int**)malloc(n * sizeof(int*));
        for(int i=0; i < n; i++)
            g->matrix[i] = (int*)calloc(n, sizeof(int));

        for(int i=0; i < n; i++)
            for(int j=0; j < n; j++)
                g->matrix[i][j] = INT_MAX;
        return;
    }


    void add_edge_undirected(graph *g, int src, int dest, int wt){

        g->matrix[src - 1][dest - 1] = wt;
        g->matrix[dest - 1][src - 1] = wt;
        return;
    }

    void display(graph g){

        for(int i=0; i < g.vertices; i++){
            for(int j=0; j < g.vertices; j++){
                printf("%10d\t", g.matrix[i][j]);
            }
            printf("\n");
        }
    }

    void prim(graph *g, int x){
        int startvertex = x - 1;

        int d = g->vertices;
        int* near = (int*)calloc(d, sizeof(int));

        for(int i = 0; i < d; i++)
            near[i] = INT_MAX;

        int minwt = INT_MAX, u , v;

        int* MST[2];

        MST[0] = (int*)calloc(d - 1 , sizeof(int));
        MST[1] = (int*)calloc(d - 1 , sizeof(int));

        // To find the Starting edge
        for(int i = 0; i < d; i++){
            if(g->matrix[startvertex][i] < minwt){
                minwt = g->matrix[startvertex][i];
                u = startvertex;
                v = i;
            }
        }

        MST[0][0] = u;
        MST[1][0] = v;
        near[u] = 0;
        near[v] = 0;

        // To Fill the Near Array in first step
        for(int i = 0; i < d; i++){
            if(near[i] != 0){
                if(g->matrix[i][u] < g->matrix[i][v])
                    near[i] = u;
                else
                    near[i] = v;
            }
        }

        int k;
        for(int i = 1; i < d - 1; i++){
            minwt = INT_MAX;
            for(int j = 0; j < d; j++){
                if((near[j] != 0) && (g->matrix[j][near[j]] < minwt)){
                    minwt = g->matrix[j][near[j]];
                    k = j;
                }
            }
            MST[0][i] = k;
            MST[1][i] = near[k];
            near[k] = 0;

            for(int j = 0; j < d; j++){
                if((near[j] != 0) && (g->matrix[j][k] < g->matrix[j][near[j]])){
                    near[j] = k;
                }
            }
        }

        for(int i = 0; i < d-1; i++)
            printf("\n%d -> %d", MST[0][i] + 1, MST[1][i] + 1);
    }
