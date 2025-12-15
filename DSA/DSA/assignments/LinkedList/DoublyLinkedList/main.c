#include "header.h"
int main() {
    DLL L1;
    init_DLL(&L1);
    insert_beg(&L1, 10);
    insert_beg(&L1, 20);
    insert_beg(&L1, 30);

    insert_end(&L1, 40);
    insert_end(&L1, 50);

    displayLR(L1);

    insert_pos(&L1, 35, 2);

    displayRL(L1);

    if (is_palindrome(L1)) {
        printf("The list is a palindrome.\n");
    } else {
        printf("The list is not a palindrome.\n");
    }

    remove_beg(&L1);
    displayLR(L1);

    remove_end(&L1);
    displayLR(L1);

    remove_pos(&L1, 2);
    displayLR(L1);

    sort(&L1);
    displayLR(L1);

    remove_duplicates(&L1);
    displayLR(L1);

    return 0;
}
