#include <stdio.h>
char Grade(float a , float b , float c, float d, float e){
    float percentage = (a + b + c + d + e)/5;
    printf("Your Percentage is %f\n", percentage);
    if(percentage >= 90){
        return 'A';
    }
    else if(percentage >= 80){
        return 'B';
    }
    else if(percentage >= 70){
        return 'C';
    }
    else if(percentage >= 60){
        return 'D';
    }
    else if(percentage >= 40){
        return 'E';
    }
    else{
        return 'F';
    }
}
int main(){
    float a, b, c, d, e;
    printf("Enter Marks of Five Subjects : ");
    scanf("%f%f%f%f%f", &a, &b, &c, &d, &e);
    char grade = Grade(a, b, c, d, e);
    printf("Your Grade is %c",grade);
    return 0;
}