#include <stdio.h>
#include "polynomial.h"
#include <stdlib.h>
#include <string.h>

int main(){
    poly p1, p2, p3;
    int n1, n2;
    printf("Enter maximum no of terms in polynomial 1: ");
    scanf("%d", &n1);
    printf("Enter maximum no of terms in polynomial 2: ");
    scanf("%d", &n2);
    init_poly(&p1, n1);
    init_poly(&p2, n2);
    init_poly(&p3, n1 + n2);

    for(int i = 0; i < n1; i++){
        int c, e;
        printf("Enter coefficient and power of term %d of polynomial 1\n", i + 1);
        scanf("%d%d", &c, &e);
        append(&p1, c, e);
    }
    for(int i = 0; i < n2; i++){
        int c, e;
        printf("Enter coefficient and power of term %d of polynomial 2\n", i + 1);
        scanf("%d%d", &c, &e);
        append(&p2, c, e);
    }


    printf("Polynomial 1: ");
    display(p1);

    printf("Polynomial 2: ");
    display(p2);

    addition_polynomial(&p1, &p2, &p3);
    printf("Sum of Polynomials: ");
    display(p3);

    subtraction_polynomial(&p1, &p2, &p3);
    printf("Difference of Polynomials: ");
    display(p3);

    return 0;   
}