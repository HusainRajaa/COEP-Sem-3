#include <stdio.h>
void main(){
    FILE *fp;
    int a,b,c;
    a = 10;
    b = 20;
    fp = fopen("output.txt","w"); // Open File in Write Mode
    c = a + b ;
    fprintf(fp,"Sum of %d and %d is %d",a,b,c);
}