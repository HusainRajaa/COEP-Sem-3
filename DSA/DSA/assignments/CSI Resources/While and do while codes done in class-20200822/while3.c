#include<stdio.h>
/*
 * print numbers from n to m
 */

int main() {
    int n , m, i, s;
    printf("Enter value of n and m and s:\t");
    scanf("%d%d%d", &n, &m, &s);
    i = n;
    while (i <=  m) {
        printf ( "%d\n", i ) ;
        i = i + s;
    }
    return 0;
}
