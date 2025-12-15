#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
    int size = 1000;
    int count = 0;
    char str[size];
    printf("Enter text: ");
    getchar();
    scanf("%[^\n]",str);
    for(int i = 0 ; str[i] != '\0' ; i++){
        char ch = tolower(str[i]);
        if((ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u')){
            count++;
        }
    }
    printf("Number of Vowels are %d", count);
    return 0;
}