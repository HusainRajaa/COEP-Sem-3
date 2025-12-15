#include <stdio.h>
#include <math.h>
void RootsOfQuadratiEquation(float a, float b, float c){
    float root1, root2, realPart, imaginaryPart;
    float discriminant = b * b - 4 * a * c;
    if(a == 0){
        printf("It is not a quadratic equation");
    }
    else if(discriminant > 0){
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Roots of the quadratic equation are real and different\n");
        printf("Root1 = %f\n", root1);
        printf("Root2 = %f", root2);

    }
    else if(discriminant == 0){
        root1 = root2 = -b / (2 * a);
        printf("Roots of the quadratic equation are real and same\n");
        printf("Root1 = Root2 = %f\n",root1);
    }
    else{
        realPart = -b / (2 * a);
        imaginaryPart = sqrt(-discriminant) / (2 * a);
        printf("Roots of the quadratic equation are complex and different\n");
        printf("Root1 = %.2f + %.2fi\n", realPart, imaginaryPart);
        printf("Root2 = %.2f + %.2fi\n", realPart, imaginaryPart);
    }
}
int main(){
    float a, b, c;
    printf("Enter Coefficients a, b, c of Quadratic Equation: ");
    scanf("%f%f%f", &a, &b, &c);
    RootsOfQuadratiEquation(a, b, c);
    return 0;   
}