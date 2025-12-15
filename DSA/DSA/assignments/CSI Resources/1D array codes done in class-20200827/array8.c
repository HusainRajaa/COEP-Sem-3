#include<stdio.h>
/*
* Array declaration, initialization using scanf() and retrieval
*/
#define size 5
int main() {
    int marks[size];
    int i;
    for(i = 0; i < size; i++)
        scanf("%d", &marks[i]);
    printf("\nArray Elements are:\n");
    for(i = 0; i < size; i++)
        printf("%d\n", marks[i]);
    return 0;
}
