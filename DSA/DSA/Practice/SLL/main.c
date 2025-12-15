#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "header.h"

int main(){
    srand(time(0));
    SLL L1;
    init_SLL(&L1);
    append(&L1);
    append(&L1);
    append(&L1);
    append(&L1);
    append(&L1);
    traverse_SLL(&L1);
    insert_beg(&L1);
    traverse_SLL(&L1);
    insert_end(&L1);
    traverse_SLL(&L1);
    insert_pos(&L1, 5);
    traverse_SLL(&L1);
    remove_beg(&L1);
    traverse_SLL(&L1);
    printf("Length is : %d\n", length(&L1));
    remove_end(&L1);
    traverse_SLL(&L1);
    remove_pos(&L1, 2);
    traverse_SLL(&L1);
    return 0;
}