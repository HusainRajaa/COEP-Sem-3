#include <stdio.h>
void TypeOfTriangle(float a, float b, float c){
    if(a + b + c == 180){
        if(a == b && b == c && a == c){
            printf("The Triangle is Equilateral");
        }
        else if((a == b && a != c) || (b == c && a != b) || (a == c && b != c)){
            printf("The Triangle is Isosceles");
        }
        else{
            printf("The Triangle is Scalene");
        }
    }
    else{
        printf("The Triangle is Invalid");
    }
}
int main(){
    float a , b , c;
    printf("Enter Angles of Triangle : ");
    scanf("%f%f%f", &a, &b, &c);
    TypeOfTriangle(a, b, c);
    return 0;   
}