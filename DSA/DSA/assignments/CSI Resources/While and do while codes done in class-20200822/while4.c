#include<stdio.h>
/*
 * Print all numbers divisible by ‘n’ , between 1 to 1000.
 * ‘n’ accepted from user
 */

int main() {
    int n, i  = 1;
    printf("Enter value of n:\t");
    scanf("%d", &n);
    while( i <=  1000) {
        if(!(i%n))
            printf("%d\n", i);
        i++;
    }
    return 0;
}
