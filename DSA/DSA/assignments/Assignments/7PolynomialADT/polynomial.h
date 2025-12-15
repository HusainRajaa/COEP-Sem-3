typedef struct term {
    int coef;
    int exp;
} term;

typedef struct poly {
    int n;
    term *t; 
} poly;

void init_poly(poly *p, int max_terms);
void append(poly *p, int coef, int exp);
void display(poly p);
void addition_polynomial(poly *p1, poly *p2, poly *p3);
void subtraction_polynomial(poly *p1, poly *p2, poly *p3);