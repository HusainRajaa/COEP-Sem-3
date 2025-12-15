#include<stdio.h>
int main(){
    FILE *fp;
    fp = fopen("INPUT.txt","r"); // Open file in Read mode
    if(fp == NULL){
        printf("File does not exists \n");
        return 1;
    }
    fprintf(fp,"Hello world this is a c class");
    fclose(fp); // Close File after Reading
    return 0;
}