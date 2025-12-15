#include <stdio.h>
int RightMost(float a){
    int s = (int)a;
    int r = s % 10;
    return r;
}
int main(){
    float a;
    printf("Enter floating point number: ");
    scanf("%f", &a);
    printf("%d", RightMost(a));
    return 0;
}