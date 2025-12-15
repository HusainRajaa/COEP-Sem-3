#include <stdio.h>
    #include <stdlib.h>

    typedef struct node {
        int coeff;
        int exp;
        struct node *next;
    } node;

    void append(node **head, int coeff, int exp) {
        node *newNode = (node *)malloc(sizeof(node));
        newNode->coeff = coeff;
        newNode->exp = exp;
        newNode->next = NULL;
        
        if (*head == NULL) {
            *head = newNode;
        } else {
            node *temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    node *add(node *p1, node *p2) {
        node *result = NULL;

        while (p1 != NULL && p2 != NULL) {
            if (p1->exp == p2->exp) {
                append(&result, p1->coeff + p2->coeff, p1->exp);
                p1 = p1->next;
                p2 = p2->next;
            } else if (p1->exp > p2->exp) {
                append(&result, p1->coeff, p1->exp);
                p1 = p1->next;
            } else {
                append(&result, p2->coeff, p2->exp);
                p2 = p2->next;
            }
        }

        // Append remaining terms of p1 or p2
        while (p1 != NULL) {
            append(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        }
        while (p2 != NULL) {
            append(&result, p2->coeff, p2->exp);
            p2 = p2->next;
        }

        return result;
    }

    node *sub(node *p1, node *p2){
        node *result = NULL;
        while (p1 && p2){
            if (p1->exp == p2->exp){
                append(&result, p1->coeff - p2->coeff, p1->exp);
                p1 = p1->next;
                p2 = p2->next;
            } else if (p1->exp > p2->exp) {
                append(&result, p1->coeff, p1->exp);
                p1 = p1->next;
            } else {
                append(&result, -p2->coeff, p2->exp);
                p2 = p2->next;
            }
        }
        while (p1 != NULL) {
            append(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        }
        while (p2 != NULL) {
            append(&result, -p2->coeff, p2->exp);
            p2 = p2->next;
        }
        return result;
    }

    void display(node *p) {
        while (p != NULL) {
            printf("%dx^%d", p->coeff, p->exp);
            if (p->next != NULL) {
                printf(" + ");
            }
            p = p->next;
        }
        printf("\n");
    }

    int main() {
        node *poly1 = NULL, *poly2 = NULL, *result = NULL;

        append(&poly1, 5, 2);  // 5x^2
        append(&poly1, 4, 1);  // 4x^1
        append(&poly1, 2, 0);  // 2

        append(&poly2, 3, 2);  // 3x^2
        append(&poly2, 1, 1);  // 1x^1
        append(&poly2, 7, 0);  // 7

        result = add(poly1, poly2);

        printf("Polynomial 1: ");
        display(poly1);

        printf("Polynomial 2: ");
        display(poly2);

        printf("Sum: ");
        display(result);

        return 0;
    }