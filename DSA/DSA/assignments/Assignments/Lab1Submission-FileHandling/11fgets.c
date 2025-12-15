#include<stdio.h>
int main(){
    FILE *fp;
    char ch;
    fp=fopen("abc.txt","r");
    ch=fgetc(fp);       // reading a character at a time from a file opened by fp
    while(ch != feof){
        printf("%c",ch);
    }
    fclose(fp);
    return 0;
}