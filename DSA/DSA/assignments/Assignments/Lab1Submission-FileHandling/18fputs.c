#include <stdio.h>
void main(){
    char name[20];
    FILE *fp;
    char ch;
    int i,n;
    fp=fopen("div8_string.txt","w");
    printf("Enter the number of names\n");
    scanf("%d",&n);
    printf("Enter %d names\n",n);
    for(i=1; i<=n; i++){
        scanf(" %s",name);
        fputs(name,fp);
        fputc('\n',fp); // to put every name on new line in file
    }
    fclose(fp);
}