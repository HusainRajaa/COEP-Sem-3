#include<stdio.h>
int NumberOfElements(int size){
    int number = size/sizeof(int);
    return number;
}
int main(){
    int size = 200;
    printf("%d\n",sizeof(int));
    printf("%d",NumberOfElements(size));
    return 0;
}