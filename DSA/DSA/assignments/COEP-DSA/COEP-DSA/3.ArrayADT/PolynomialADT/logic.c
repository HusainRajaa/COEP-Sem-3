#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int coef; // Coefficient
    int exp;  // Exponent
} Term;

typedef struct {
    int n;   // Number of terms
    Term *t; // Array of terms
} Poly;

// Initializes a polynomial
void init_poly(Poly *p, int num_terms) {
    p->n = num_terms;
    p->t = (Term *)malloc(num_terms * sizeof(Term));
}

// Adds a term to the polynomial
void append(Poly *p, int coef, int exp, int index) {
    p->t[index].coef = coef;
    p->t[index].exp = exp;
}

// Displays the polynomial
void display(Poly p) {
    for (int i = 0; i < p.n; i++) {
        printf("%dx^%d", p.t[i].coef, p.t[i].exp);
        if (i != p.n - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Adds two polynomials and returns the result
Poly *add(Poly *p1, Poly *p2) {
    int i = 0, j = 0, k = 0;
    Poly *sum = (Poly *)malloc(sizeof(Poly));
    sum->t = (Term *)malloc((p1->n + p2->n) * sizeof(Term));

    while (i < p1->n && j < p2->n) {
        if (p1->t[i].exp > p2->t[j].exp) {
            sum->t[k++] = p1->t[i++];
        } else if (p1->t[i].exp < p2->t[j].exp) {
            sum->t[k++] = p2->t[j++];
        } else {
            sum->t[k].exp = p1->t[i].exp;
            sum->t[k++].coef = p1->t[i++].coef + p2->t[j++].coef;
        }
    }
    while (i < p1->n) sum->t[k++] = p1->t[i++];
    while (j < p2->n) sum->t[k++] = p2->t[j++];

    sum->n = k;
    return sum;
}

// Subtracts the second polynomial from the first and returns the result
Poly *sub(Poly *p1, Poly *p2) {
    int i = 0, j = 0, k = 0;
    Poly *diff = (Poly *)malloc(sizeof(Poly));
    diff->t = (Term *)malloc((p1->n + p2->n) * sizeof(Term));

    while (i < p1->n && j < p2->n) {
        if (p1->t[i].exp > p2->t[j].exp) {
            diff->t[k++] = p1->t[i++];
        } else if (p1->t[i].exp < p2->t[j].exp) {
            diff->t[k] = p2->t[j++];
            diff->t[k++].coef *= -1;
        } else {
            diff->t[k].exp = p1->t[i].exp;
            diff->t[k++].coef = p1->t[i++].coef - p2->t[j++].coef;
        }
    }
    while (i < p1->n) diff->t[k++] = p1->t[i++];
    while (j < p2->n) {
        diff->t[k] = p2->t[j++];
        diff->t[k++].coef *= -1;
    }

    diff->n = k;
    return diff;
}

int main() {
    Poly p1, p2, *p3;

    // Initialize polynomials with the required number of terms
    init_poly(&p1, 3);
    init_poly(&p2, 3);

    // Append terms to the first polynomial
    append(&p1, 3, 2, 0); // 3x^2
    append(&p1, 5, 1, 1); // 5x
    append(&p1, 4, 0, 2); // 4

    // Append terms to the second polynomial
    append(&p2, 2, 1, 0); // 2x
    append(&p2, 3, 0, 1); // 3
    append(&p2, 1, 3, 2); // x^3

    // Display the polynomials
    printf("Polynomial 1: ");
    display(p1);
    printf("Polynomial 2: ");
    display(p2);

    // Add the polynomials and display the result
    p3 = add(&p1, &p2);
    printf("Sum: ");
    display(*p3);

    // Subtract the polynomials and display the result
    p3 = sub(&p1, &p2);
    printf("Difference: ");
    display(*p3);

    // Free allocated memory
    free(p1.t);
    free(p2.t);
    free(p3->t);
    free(p3);

    return 0;
}
