#include <stdio.h>
#include <stdlib.h>
#include "CLL.h"

int main() {
    clist L1;
    init_CLL(&L1);
    insert_beg(&L1, 10);
    insert_beg(&L1, 20);
    insert_beg(&L1, 30);
    insert_end(&L1, 40);
    insert_end(&L1, 50);
    insert_end(&L1, 60);
    display(&L1);
    insert_pos(&L1, 25, 3);
    display(&L1);
    sort(&L1);
    display(&L1);
    remove_beg(&L1);
    display(&L1);
    remove_end(&L1);
    display(&L1);
    remove_pos(&L1, 3);
    display(&L1);
    return 0;
}
