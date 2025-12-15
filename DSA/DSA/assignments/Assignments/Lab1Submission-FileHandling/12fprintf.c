#include <stdio.h>
void main(){
    FILE *fp;
    fp = fopen("output.txt","w"); // Open File in Write Mode
    fprintf(fp,"Hello World");
}