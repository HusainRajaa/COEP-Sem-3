/* Write a program to read numbers until –1 is entered and display whether it is
an Armstrong number or not.*/
#include <stdio.h>
#include <math.h>
void Armstrong(int n){
    int original, power, lastdigit, sum = 0, count = 0;
    original = n;
    while(n != 0){
        n = n / 10;
        count++;
    }
    // printf("%d\n",count);
    n = original;

    while(n != 0){+
        lastdigit = n % 10;
        // printf("%d\n",lastdigit);
        power = 1;
        for(int i = 0 ; i < count ; i++){
            power *= lastdigit;
        }
        // printf("%d\n",power);
        sum = sum + power;
        // printf("%d\n",sum);
        n = n / 10;
        // printf("%d\n",n);
    }
    // printf("%d\n",sum);
    if(sum == original){
        printf("The Number %d is an Armstrong Number\n", original);
    }
    else{
        printf("The Number %d is not an Armstrong Number\n", original);
    }
}
int main(){
    int a;
    printf("Enter Numbers (enter -1 to stop):\n");
    while(1){
        scanf("%d", &a);
        if(a == -1){
            break;
        }
        Armstrong(a);
    }
    return 0;
}
