#include <stdio.h>
int main(){
    FILE *fp;
    int a= 3,b=5,c=0;
    fp = fopen("output.txt","w+"); // write + read mode
    fprintf(fp," Value of a is %d and b is %d. ",a,b);
    fscanf(fp, "%d %d", &a, &b);
    c = a + b ;
    fprintf(fp,"Sum of %d and %d is %d",a,b,c);
    return 0;
}