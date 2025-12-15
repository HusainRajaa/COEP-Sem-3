#include <stdio.h>
int main(){
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    int sum = 0;
    float avg;
    for(int i = 1; i <= n; i++){
        sum += i;
    }
    avg = sum / n;
    printf("The sum is: %d\n", sum);
    printf("The average is: %f\n", avg);
    return 0;
}