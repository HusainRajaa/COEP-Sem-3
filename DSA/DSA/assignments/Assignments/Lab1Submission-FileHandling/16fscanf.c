#include<stdio.h>
int main(){
    FILE *fp;
    char ch[100];
    int i = 0;
    fp=fopen("INPUT.txt","r");
    printf("Reading from file\n");
    while(!feof(fp)){
        fscanf(fp,"%s ",ch); // reading from file
        puts(ch); // printing on console
    }
    fclose(fp);
    return 1;
}