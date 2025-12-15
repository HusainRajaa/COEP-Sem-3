#include<stdio.h>
#include<stdlib.h>
/*
 * Simple calculator
 *
 */

int main() {
    int a, b, c, choice;
    char ch;
    do {
        getch();
        printf("Enter your choice 1..5\n");
        printf(" 1: Add\n");
        printf(" 2: Subtract\n");
        printf(" 3: Multiply\n");
        printf(" 4: Divide\n");
        printf(" 5: Exit\n");
        scanf("%d", &choice);
        if(choice >= 5)
            exit(0);
        else {
            printf("Enter values of two operands\n");
            scanf("%d%d", &a, &b);
            switch(choice) {
                case 1: c = a + b;
                        break;
                case 2: c = a - b;
                        break;
                case 3: c = a * b;
                        break;
                case 4: c = a / b;
                        break;

            }
            printf("Result = %d\n", c);
            getch();
            system("cls");
        }
    }while(choice < 5);
    return 0;
}
