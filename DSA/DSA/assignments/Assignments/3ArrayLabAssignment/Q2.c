#include <stdio.h>
void Check(float a){
    if(a > 0){
        printf("The Number %f is Positive", a);
    }
    else if(a < 0){
        printf("The Number %f is Negative", a);
    }
    else{
        printf("The Number %f is Zero", a);
    }
}
int main(){
    float a;
    printf("Enter the Number : ");
    scanf("%f",&a);
    Check(a);
    return 0;
}