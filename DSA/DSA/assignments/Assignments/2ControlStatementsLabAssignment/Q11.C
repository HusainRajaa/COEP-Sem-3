#include <stdio.h>
int main(){
    char ch;
    printf("Enter character : ");
    scanf("%c", &ch);
    if(ch >= 'a' && ch <= 'z'){
        printf("Capital character is: %c", ch - 32);
    }
    else if(ch >= 'A' && ch <= 'Z'){
        printf("Small character is: %c", ch + 32);
    }
    return 0;
}