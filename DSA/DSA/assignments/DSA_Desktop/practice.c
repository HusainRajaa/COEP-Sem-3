#include<stdio.h>
int main(){
    // int a[] = {6,2,1,5,3};
    int a[5];
    int *q;
    q = a;
    for(int i = 0 ; i < 5 ; i++){
        scanf("%d",&q[i]);
    }
    for(int i = 0 ; i < 5 ; i++){
        printf("%d ",q[i]);
    }

    
    // printf("%d\n",*a);
    // printf("%d\n",*(a+1));
    // printf("%d\n",*a+1);
    // printf("Address of a[0] %p\n",a);
    // printf("Address of a[1] %p\n",a+1);
    // printf("Address of a[2] %p\n",a+2);
    // printf("Address of a[3] %p\n",a+3);
    // printf("Address of a[4] %p\n",a+4);
    // printf("Address of a[5] %p\n",&a+1);
    // printf("Address of a[1] %p\n",&a[0]+1);

    // printf("%p\n",q);
    // q++;         => Valid
    // printf("%p\n",q);
    // q = q*2;     => Invalid
    // printf("%p\n",q);

    
    return 0;
}