#include<stdio.h>
void main(){
    char name[20];
    FILE *fp;
    char *ptr=NULL;
    int i,n;
    fp=fopen("div7_string.txt","r");
    for(i=1; !feof(fp); i++){
        fgets(name,20,fp); // reading strings from file
        if (ptr!=NULL) //print only if fgets returns success
        printf("%s",name); //printing strings of files on console
    }
    fclose(fp);
}