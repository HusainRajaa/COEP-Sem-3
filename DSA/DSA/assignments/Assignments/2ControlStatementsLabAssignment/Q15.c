#include <stdio.h>

int main(){
    int m, n, i;
    printf("Enter the values of m and n: ");
    scanf("%d%d", &m, &n);
    printf("Odd Numbers are: ");
    for (i = m; i < n; i++){
        if (i % 2 == 1)
            printf("%d ", i);
    }
    return 0;;
}