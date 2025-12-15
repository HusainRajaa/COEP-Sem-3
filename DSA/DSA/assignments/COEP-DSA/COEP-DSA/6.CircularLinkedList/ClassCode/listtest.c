#include<stdio.h>
#include<stdlib.h>
#include "list.h"


void main(){

    list l1,l2;
    init(&l1);
    init(&l2);
    insertright(&l1,10);
    insertright(&l1,20);
    insertright(&l1,30);
    insertright(&l1,15);
    sort(&l1);
    printlistLR(l1);
    insertright(&l2,40);
    insertright(&l2,80);
    insertright(&l2,70);
    insertright(&l2,10);
    printlistLR(l2);
    list l3 = listunion(l1,l2);
    printf("\nUNION\n");
    printlistLR(l3);
    printf("\n%d\n", search(l1,3));
    int len = length(l1);
    printf("%d\n", len);
    reverse(&l1);
    printlistLR(l1);
    insertsorted(&l2,80);
    insertsorted(&l2,10);
    insertsorted(&l2,40);
    insertsorted(&l2,35);
    printlistLR(l2);
    removelist(&l1, 20);
    printlistLR(l1);
    freelist(&l1);
   
}


