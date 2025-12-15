#include<stdio.h>
/*
* Exceeding array size during retrieval
*/
int main() {
    int marks[3] = {18,19,20,15,16};
    int i;
    for(i = 0; i < 15; i++)
        printf("%d\n", marks[i]);
    return 0;
}
