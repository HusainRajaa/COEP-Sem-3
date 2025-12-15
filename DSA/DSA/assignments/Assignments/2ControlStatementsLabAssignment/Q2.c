#include <stdio.h>
int main(){
    int count = 0;
    int sum = 0;
    for(int i = 1 ; i <= 120 ; i++){
        if(i % 2 == 0){
            count++;
            sum += i;
        }
    }
    printf("Even Numbers between 1 to 120 are %d and their sum is : %d", count, sum);
    return 0;
}