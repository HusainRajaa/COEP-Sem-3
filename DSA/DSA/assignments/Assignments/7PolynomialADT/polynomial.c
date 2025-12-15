#include <stdio.h>
#include "polynomial.h"
#include <stdlib.h>
#include <string.h>

void init_poly(poly *p, int max_terms){
    p -> n = 0;
    p -> t = (term *)malloc(max_terms * sizeof(term));
}

void append(poly *p, int coef, int exp){
    p -> t[p -> n].coef = coef;
    p -> t[p -> n].exp = exp;
    p -> n++;
}

void display(poly p){
    for(int i = 0; i < p.n; i++){
        if(p.t[i].coef < 0){
            printf(" - %dx^%d", - (p.t[i].coef), p.t[i].exp);
        }else{
            if(i > 0){
                printf(" + ");
            }
            printf("%dx^%d", p.t[i].coef, p.t[i].exp);
        }
    }
    printf("\n");
}

void addition_polynomial(poly *p1, poly *p2, poly *p3){
    int i = 0, j = 0;
    p3 -> n = 0;
    while(i < p1 -> n && j < p2 -> n){
        if(p1 -> t[i].exp > p2 -> t[j].exp){
            append(p3, p1 -> t[i].coef, p1 -> t[i].exp);
            i++;
        }
        else if(p1 -> t[i].exp < p2 -> t[j].exp){
            append(p3, p2 -> t[j].coef, p2 -> t[j].exp);
            j++;
        }
        else{
            int sum = p1 -> t[i].coef + p2 -> t[j].coef;
            if(sum != 0){
                append(p3, sum, p1 -> t[i].exp);
            }
            i++;
            j++;
        }
    }
    while(i < p1 -> n){
        append(p3, p1->t[i].coef, p1->t[i].exp);
        i++;
    }
    while(j < p2 -> n){
        append(p3, p2->t[j].coef, p2->t[j].exp);
        j++;
    }
}

void subtraction_polynomial(poly *p1, poly *p2, poly *p3){
    int i = 0, j = 0;
    p3 -> n = 0;
    while(i < p1 -> n && j < p2 -> n){
        if(p1 -> t[i].exp > p2 -> t[j].exp){
            append(p3, p1 -> t[i].coef, p1 -> t[i].exp);
            i++;
        }
        else if(p1 -> t[i].exp < p2 -> t[j].exp){
            append(p3, -p2 -> t[j].coef, p2 -> t[j].exp);
            j++;
        }
        else{
            int diff = p1 -> t[i].coef - p2 -> t[j].coef;
            if(diff != 0){
                append(p3, diff, p1 -> t[i].exp);
            }
            i++;
            j++;
        }
    }   
    while(i < p1->n){
        append(p3, p1->t[i].coef, p1->t[i].exp);
        i++;
    }
    
    while(j < p2->n){
        append(p3, -p2->t[j].coef, p2->t[j].exp);
        j++;
    }
}