// Write a program to print all prime numbers from m to n
#include <stdio.h>
int main(){
    int m, n, i, j;
    printf("Enter the range m and n : ");
    scanf("%d %d", &m, &n);
    printf("Prime Numbers are: ");
    for(i = m; i <= n; i++){
        int flag = 0;
        for(j = 2; j <= i - 1; j++){
            if(i % j == 0){
                flag = 1;
                break;
            }
        }
        if(i == 1){
            continue;
        }
        else if(flag == 0){
            printf("%d ", i);
        }
        else{
            continue;
        }
    }
    return 0;
}

