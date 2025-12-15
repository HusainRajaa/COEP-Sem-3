#include<stdio.h>
#include<stdlib.h>
#include "header.h"

int main(){

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
    l3 = intersection(l1,l2);
    printf("\nintersection\n");
    printlistLR(l3);
    printf("\n%d\n", search(l1,3));
    int len = length(l1);
    printf("%d\n", len);
    reverse(&l1);
    printlistLR(l1);
    SortedInsert(&l2,80);
    SortedInsert(&l2,10);
    SortedInsert(&l2,40);
    SortedInsert(&l2,35);
    printlistLR(l2);
    removelist(&l1, 20);
    printlistLR(l1);
    removeDuplicates(&l2);
    printlistLR(l2);
    freelist(&l1);
    return 0;
}


