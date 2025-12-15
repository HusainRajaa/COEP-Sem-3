#include<stdio.h>
/*
 * Reverse digits of a number
 * number = 564319, 123, 5
 * output = 913465, 321, 5
 * ‘n’ accepted from user
 */

int main() {
    int n,revn = 0, tempn, r;
    printf("Enter value of n:\t");
    scanf("%d", &n);
    tempn = n;
    while(tempn) {
        r = tempn % 10;
        revn = revn * 10 + r;
        tempn = tempn / 10;
    }
    printf("Reverse of %d is %d:  ", n, revn);
    return 0;
}
