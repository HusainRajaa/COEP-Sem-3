
#include<stdio.h>
#include "list.h"

int main(){
    list L1;
    init(&L1);
    
    insert_end(&L1, 1);
    insert_end(&L1, 2);
    insert_end(&L1, 3);
    insert_end(&L1, 4);
    traverse(L1);
    printf("\n");
    insert_beg(&L1,7);
    traverse(L1);
    printf("\n");
    delete_beg(&L1);
    traverse(L1);
    printf("\n");
    delete_end(&L1);
    traverse(L1);
   
    return 0;
}
