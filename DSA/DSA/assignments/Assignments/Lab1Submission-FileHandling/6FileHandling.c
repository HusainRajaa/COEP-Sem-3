#include <stdio.h>
int main(){
    FILE *f1;
    char ch;
    f1 = fopen("INPUT.txt", "r");
    if (f1 == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    while ((ch = fgetc(f1)) != EOF) {
        printf("%c", ch);
    }
    if (feof(f1)) {
        printf("\nEnd of data\n");
    }
    fclose(f1);
    return 0;
}