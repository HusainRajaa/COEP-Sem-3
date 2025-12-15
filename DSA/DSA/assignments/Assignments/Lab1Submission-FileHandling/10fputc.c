#include<stdio.h>
int main(){
    FILE *fp;
    char ch;
    fp=fopen("/home/coep/Music/div7.txt","w");
    printf("Keep typing characters. Type q to terminate\n");
    do {
        scanf(" %c", &ch);
        if (ch != 'q') {
            fputc(ch, fp);
        }
    } while (ch != 'q');
    fclose(fp);
    return 0;
}