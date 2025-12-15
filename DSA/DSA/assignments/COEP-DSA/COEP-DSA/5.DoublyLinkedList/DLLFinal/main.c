#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(){
    DLL L1, L2, L3;
    init_DLL(&L1);
    init_DLL(&L2);

    insert_right(&L1, 10);
    insert_right(&L1, 12);

    insert_left(&L1, 15);
    insert_left(&L1, 20);
    insert_left(&L1, 12);

    displayLR(&L1);

    insert_pos(&L1, 25, 1);
    displayLR(&L1);

    removeDuplicates(&L1);
    displayLR(&L1);

    printf("sorted ");
    sort(&L1);
    displayLR(&L1);
    displayRL(&L1);

    printf("Remove Beginning: \n");
    remove_beg(&L1);
    displayLR(&L1);

    remove_end(&L1);
    displayLR(&L1);

    remove_pos(&L1, 1);
    displayLR(&L1);

    init_DLL(&L2);
    init_DLL(&L3);

    insert_left(&L2, 2);
    insert_left(&L2, 3);
    insert_left(&L2, 5);
    insert_left(&L2, 7);
    insert_left(&L2, 12);

    
    L3 = listunion(L1, L2);
    displayLR(&L3);

    L3 = intersection(L1, L2);
    displayLR(&L3);

    insert_right(&L3, 20);
    insert_right(&L3, 12);
    insert_right(&L3, 20);

    is_palindrome(&L3);
    return 0;
}