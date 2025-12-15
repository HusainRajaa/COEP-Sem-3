#include<stdio.h>
/*
* Array declaration, PARTIAL initialization and retrieval
*/
int main() {
    int marks[15] = {18,19,20,15,16};
    int i;
    for(i = 0; i < 15; i++)
        printf("%d\n", marks[i]);
    return 0;
}
