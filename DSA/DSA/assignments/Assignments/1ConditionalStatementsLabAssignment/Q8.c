#include<stdio.h>
#include<stdlib.h>
void RandomNoGenerator(int min , int max , int no){
    int c, n;
    for (c = 1; c <= no; c++) {
        n = rand() % (max - min + 1) + min;
        printf("%d\n", n);
    }
}
int main() {
    printf("Ten random numbers in [1,100]\n");
    RandomNoGenerator(1 , 100 , 10);   
    return 0;
}
