#include<stdio.h>
/*
 * Print sum of all numbers divisible by 7
 * between n and m.
 * ‘n’ and 'm' are accepted from user
 */

int main() {
    int n, m, sum  = 0, i;
    printf("Enter value of n and m:\t");
    scanf("%d%d", &n, &m);
    i = n;
    while( i <= m) {
        if(!(i%7))
            sum += i;
        i++;
    }
    printf("\nSum = %d", sum);
    return 0;
}
