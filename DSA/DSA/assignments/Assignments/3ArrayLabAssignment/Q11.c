#include <stdio.h>
void AnglesOfTriangle(float a, float b, float c){
    if(a + b + c == 180){
        printf("The Triangle is Valid");
    }
    else{
        printf("The Triangle is Invalid");
    }
}
int main(){
    float a , b , c;
    printf("Enter Angles of Triangle : ");
    scanf("%f%f%f", &a, &b, &c);
    AnglesOfTriangle(a, b, c);
    return 0;   
}