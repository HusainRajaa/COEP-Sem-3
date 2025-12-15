#include <stdio.h>
int main () {
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);
    printf("Is %d divisible by 5 and 6? ", n);
    if ((n % 5 == 0) && (n % 6 == 0)){
        printf("true\n");
    } else {
        printf("false\n");
    }
    printf("Is %d divisible by 5 or 6? ", n);
    if ((n % 5 == 0) || (n % 6 == 0)){
        printf("true\n");
    } else {
        printf("false\n");
    }
    printf("Is %d divisible by 5 or 6, but not both? ", n);
    if (((n % 5 == 0) || (n % 6 == 0)) && ((n % 5 != 0) && (n % 6 != 0))){
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}