#include <stdio.h>
#include "header.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int countOccurrences(char *str, char ch) {
    int count = 0;
    ch = tolower(ch);  
    while (*str) {     
        if (tolower(*str) == ch) {  
            count++;
        }
        str++;  
    }
    return count;
}

char *my_strtok(char *str, const char *delim){
    static char *nextToken = NULL;
    if(str != NULL){
        nextToken = str;
    }
    if(nextToken == NULL){
        return NULL;
    }
    char *tokenStart = nextToken;
    while(*nextToken){
        const char *d = delim;
        while(*d){
            if(*nextToken == *d){
                *nextToken = '\0';
                nextToken++;
                while(*nextToken && strchr(delim, *nextToken)){
                    nextToken++;
                }
                return tokenStart;
            }
            d++;
        }
        nextToken++;
    }
    nextToken = NULL;
    return tokenStart;
}
int longestSubsequence(char *str1, char *str2, char **subseq) {
    int maxLen = 0;
    char *bestMatch = NULL;

    for (int i = 0; str2[i] != '\0'; i++) {
        for (int j = 0; str1[j] != '\0'; j++) {
            int len = 0;
            while (str1[j + len] && str2[i + len] && str1[j + len] == str2[i + len]) len++;
            if (len > maxLen) {
                maxLen = len;
                bestMatch = &str1[j];
            }
        }
    }
    *subseq = bestMatch;
    return maxLen;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

char *decimalToBinary(int n, char *binary) {
    int i = 0;
    while (n > 0) {
        binary[i++] = (n % 2) + '0';
        n /= 2;
    }
    binary[i] = '\0';
    rev(binary);
    return binary;
}

int my_strcasecmp(const char *s1, const char *s2) {
    while (*s1 && (tolower(*s1) == tolower(*s2))) {
        s1++;
        s2++;
    }
    return tolower(*(unsigned char *)s1) - tolower(*(unsigned char *)s2);
}
char *my_strsep(char **stringp, const char *delim) {
    char *start = *stringp;
    char *p;
    if (!start) return NULL;

    p = strpbrk(start, delim);
    if (p) {
        *p = '\0';
        *stringp = p + 1;
    } else {
        *stringp = NULL;
    }

    return start;
}
int my_strcoll(const char *s1, const char *s2) {
    return strcmp(s1, s2);  
}
double my_sin(double x){
    return sin(x);
}
double my_asin(double x){
    return asin(x);
}
double my_cos(double x){
    return cos(x);
}
double my_acos(double x){
    return acos(x);
}
double my_tan(double x){
    return my_sin(x) / my_cos(x);
}

int reverseInteger(int number){
    int reverse = 0;
    while (number != 0) {
        int remainder = number % 10;
        reverse = reverse * 10 + remainder;
        number = number / 10;
    }
    return reverse;
}

int isAllDigits(const char *str){
    int i = 0;
    while (str[i] != '\0') {
        if (!isdigit(str[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}


void rev(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

char *cutonchar(char *str, char ch) {
    char *pos = strchr(str, ch);
    if(pos){
        *pos = '\0';
    }
    return str;
} 