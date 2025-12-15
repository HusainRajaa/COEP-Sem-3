#include<stdio.h>
/*
 * crowd funding of Rs 1000
 *
 */

int main() {
    int n, sum  = 0, i = 0;
    printf("Enter donation amount:\n");

    while( sum < 1000) {
        scanf("%d", &n);
        sum = sum + n;
        i++;
    }
    printf("%d people donated total sum of %d", i, sum);
    return 0;
}
