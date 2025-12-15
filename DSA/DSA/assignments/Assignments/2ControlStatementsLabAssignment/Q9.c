#include <stdio.h>
int main() {
    int number;
    printf("Enter an integer: ");
    scanf("%d", &number);
    printf("Decimal: %d\n", number);
    printf("Octal: %o\n", number);
    printf("Hexadecimal: %x\n", number);
    return 0;
}