#include <stdio.h>
#include "header.h"
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
int main() {
    int choice;
    printf("Enter Question Number (1-15): ");
    scanf("%d", &choice);
    /*
        Clear the input buffer to handle the newline character after scanf("%d", &question)
    */
    getchar();
    switch (choice) {
        case 1: {
            char str[100], c;
            printf("Enter a string: ");
            scanf("%[^\n]s", str);
            getchar();
            printf("Enter a character: ");
            scanf(" %c", &c);
            int count = countOccurrences(str, c);
            printf("The character '%c' occurs %d times.\n", c, count);
            break;
        }
        case 2: {
            char str[100], *token;
            printf("Enter a string: ");
            scanf("%[^\n]s", str);
            token = my_strtok(str, " ,?");
            while (token) {
                printf("%s\n", token);
                token = my_strtok(NULL, " ,?");
            }
            break;
        }
        case 3: {
            char str1[100], str2[100], *subseq;
            printf("Enter first string: ");
            scanf("%[^\n]s", str1);
            getchar();
            printf("Enter second string: ");
            scanf("%[^\n]s", str2);
            int len = longestSubsequence(str1, str2, &subseq);
            if (len > 0) {
                printf("Longest subsequence: %.*s\n", len, subseq);
            } else {
                printf("No common subsequence found.\n");
            }
            break;
        }
        case 4: {
            int a, b;
            printf("Enter two numbers: ");
            scanf("%d %d", &a, &b);
            int result = gcd(a, b);
            printf("GCD of %d and %d is %d.\n", a, b, result);
            break;
        }
        case 5: {
            int a, b;
            printf("Enter two numbers: ");
            scanf("%d %d", &a, &b);
            int result = lcm(a, b);
            printf("LCM of %d and %d is %d.\n", a, b, result);
            break;
        }
        case 6: {
            int n;
            char binary[33];  
            printf("Enter a decimal number: ");
            scanf("%d", &n);
            printf("Binary representation: %s\n", decimalToBinary(n, binary));
            break;
        }
        case 7: {
            char str1[100], str2[100];
            printf("Enter first string: ");
            scanf("%[^\n]s", str1);
            getchar();
            printf("Enter second string: ");
            scanf("%[^\n]s", str2);
            int result = my_strcasecmp(str1, str2);
            if (result == 0) {
                printf("The strings are equal.\n");
            } else {
                printf("The strings are not equal.\n");
            }
            break;
        }
        case 8: {
            char str[100];
            char *word;
            char *str_ptr;  
            char temp[100];  

            printf("Enter a string: ");
            scanf(" %[^\n]s", temp);  
            str_ptr = temp; 
            strncpy(str, temp, sizeof(str) - 1);
            str[sizeof(str) - 1] = '\0';  

            word = my_strsep(&str_ptr, " ");
            while (word != NULL) {
                printf("Word: %s\n", word);
                word = my_strsep(&str_ptr, " ");
            }
            break;
        }
        case 9: {
            char str1[100], str2[100];
            printf("Enter first string: ");
            scanf("%[^\n]s", str1);
            getchar();
            printf("Enter second string: ");
            scanf("%[^\n]s", str2);
            int result = my_strcoll(str1, str2);
            if (result == 0) {
                printf("The strings are equal.\n");
            } else if (result < 0) {
                printf("String 1 is less than String 2.\n");
            } else {
                printf("String 1 is greater than String 2.\n");
            }
            break;
        }
        case 10:{
            wchar_t str1[100];
            wchar_t str2[100];
            wprintf(L"Enter the first wide-character string: ");
            wscanf(L"%ls", str1);

            wprintf(L"Enter the second wide-character string: ");
            wscanf(L"%ls", str2);
            int result = wcscmp(str1, str2);
            if (result == 0) {
                wprintf(L"The two wide-character strings are equal.\n");
            } else if (result < 0) {
                wprintf(L"The first wide-character string is less than the second.\n");
            } else {
                wprintf(L"The first wide-character string is greater than the second.\n");
            }
            break;
        }
        case 11:{
            double x, result_sin, result_asin, result_cos, result_acos, result_tan, verify;
            printf("Enter a value for x (in radians): ");
            scanf("%lf", &x);
            result_sin = my_sin(x);
            result_asin = my_asin(result_sin);
            result_cos = my_cos(x);
            result_acos = my_acos(result_cos);
            result_tan = my_tan(x);
            verify = my_sin(my_asin(x));
            printf("sin(%.2lf) = %.6lf\n", x, result_sin);
            printf("asin(sin(%.2lf)) = %.6lf\n", x, result_asin);
            printf("cos(%.2lf) = %.6lf\n", x, result_cos);
            printf("acos(cos(%.2lf)) = %.6lf\n", x, result_acos);
            printf("tan(%.2lf) = %.6lf\n", x, result_tan);
            printf("Verification: sin(asin(%.2lf)) = %.6lf\n", x, verify);
            break;
        }
        case 12:{
            int number;
            printf("Enter a number: ");
            scanf("%d", &number);
            int reverse = reverseInteger(number);
            printf("The reversed integer is: %d", reverse);
            break;
        }
        case 13:{
            char str[100];
            printf("Enter a string: ");
            scanf("%s", str);
            if(isAllDigits(str)){
                int number = atoi(str); 
                printf("The integer representation is: %d\n", number);
            }else{
                printf("The string contains non-digit characters.\n");
            }
            break;
        }
        case 14: {
            char str[100];
            printf("Enter a string: ");
            scanf("%[^\n]s", str);
            rev(str);
            printf("Reversed string: %s\n", str);
            break;
        }
        case 15: {
            char str[100], ch;
            printf("Enter a string: ");
            scanf("%[^\n]s", str);
            printf("Enter a character: ");
            scanf(" %c", &ch);
            char *result = cutonchar(str, ch);
            printf("Result after cut: %s\n", result);
            break;
        }
        default:
            printf("Invalid choice.\n");
            break;
    }
    return 0;
}
    
