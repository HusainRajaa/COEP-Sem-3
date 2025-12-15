
#include<stdio.h>
#include"stack.h"


int main() {

   Stack s1;

   init(&s1);
   push(&s1,10);
   push(&s1,20);
   push(&s1,30);
   push(&s1,40);
   display(s1);
   int x = peek(&s1);
   printf("%d\n",x);
   //display(s1);
   pop(&s1);
   display(s1);
return 0;

}
