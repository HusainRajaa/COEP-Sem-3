#include <stdio.h>

int main() {
    float value;

    printf("Enter a floating point value: ");
    scanf("%f", &value);

    printf("Value in exponent form (correct to two decimal places): %.2e\n", value);
    printf("Value in exponent form (correct to four decimal places): %.4e\n", value);
    printf("Value in exponent form (correct to eight decimal places): %.8e\n", value);

    return 0;
}
