#include <stdio.h>
int main(){
    FILE *p1, *p2;
    p1 = fopen("INPUT.txt", "w");
    char c;
    while((c = getchar()) != EOF){
        putc(c, p1);
    }
    fclose(p1);
    p2 = fopen("INPUT.txt", "r");
    while((c = getc(p1)) != EOF){
        printf("%c", c);
    }
    fclose(p2);
    return 0;
}