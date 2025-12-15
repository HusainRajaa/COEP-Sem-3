#include <stdio.h>
#include <stdlib.h>
#include "list.h"
int main(int argc, char *argv[]) {
	graphList g1;
	initGraphList(&g1, argv[1]);
	printGraphList(g1);
	printMatrix(g1);
	BFSList(g1, 0);
	DFSList(g1, 0);
	if(isDirected(&g1)==1){
        degree(&g1);
	}
    if(isDirected(&g1)==0){
        Indegree(&g1);
        outDegree(g1);
    }
	primsAlgoList(g1, 0);
	dijkstra(&g1,0,4);
	return 0;
}
