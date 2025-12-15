#include "header.h"
#include <stdio.h>
#include <ctype.h>
int main(){
    int questionNumber;
    printf("Enter Question Number ( 1 - 15 ):");
    scanf("%d",&questionNumber);
    getchar();
    switch (questionNumber){
        case 1: {
            ThreeNumbersInLine(10);
            break;
        }
        case 2: {
            EvenNumbersCount(1 , 200);
            break;
        }
        case 3: {
            char str[1000];
            printf("Enter text: ");
            scanf("%[^\n]s",str);
            NumberOfVowels(str , 1000);
            break;
        }
        case 4:{
            float a , b;
            printf("Enter two floating point numbers: ");
            scanf("%f%f", &a, &b);
            int sum = AddTwoFloat(a, b);
            printf("Sum of %f and %f converted to int is %d", a, b, sum);
            break;
        }
        case 5:{
            float a;
            printf("Enter floating point number: ");
            scanf("%f", &a);
            printf("Rightmost digit of integral part: %d", RightMost(a));
            break;
        }
        case 6:{
            float principal, rate, time;
            printf("Enter the principal amount: ");
            scanf("%f", &principal);
            printf("Enter the rate of interest (in percentage): ");
            scanf("%f", &rate);
            printf("Enter the time period (in years): ");
            scanf("%f", &time);
            printf("Simple Interest = %.2f\n", SimpleInterest(principal , rate , time));
            printf("Compound Interest = %.2f\n", CompoundInterest(principal , rate , time));
            break;
        }
        case 7:{
            const float HRA = 10.0 / 100;
            const float TA = 5.0 / 100;
            float base, salary;
            printf("Enter the basic salary : ");
            scanf("%f",&base);
            salary = base + (base * HRA) + (base * TA);
            printf("The salary of the employee is : %f",salary);
            break;
        }
        case 8:{
            bill();
            break;
        }
        case 9:{
            int number;
            printf("Enter an integer: ");
            scanf("%d", &number);
            printf("Decimal: %d\n", number);
            printf("Octal: %o\n", number);
            printf("Hexadecimal: %x\n", number);
            break;
        }
        case 10:{
            float value;
            printf("Enter a floating point value: ");
            scanf("%f", &value);
            printf("Value in exponent form (correct to two decimal places): %.2e\n", value);
            printf("Value in exponent form (correct to four decimal places): %.4e\n", value);
            printf("Value in exponent form (correct to eight decimal places): %.8e\n", value);
            break;
        }
        case 11:{
            char ch;
            printf("Enter character : ");
            scanf("%c", &ch);
            if(ch >= 'a' && ch <= 'z'){
                printf("Captial letter is: %c", ch - 32);
            }
            else if(ch >= 'A' && ch <= 'Z'){
                printf("Small letter is: %c", ch + 32);
            }
            break;
        }
        case 12:{
            float a,b,c;
            float result;
            printf("Enter three floating point numbers: ");
            scanf("%f%f%f", &a, &b, &c);
            result = a + b + c;
            printf("Their sum is %.2f",result);
            break;
        }
        case 13:{
            char s;
            printf("Enter a character: ");
            scanf("%c",&s);
            if(s>='a' && s <='z'){
                printf("It is lower-case alphabet");
            }
            else if(s>='A' && s <='Z'){
                printf("It is upper-case alphabet");
            }
            else if(s>='0' && s<='9'){
                printf("It is Number");
            }
            else{
                printf("It is Special Character");
            }
            break;
        }
        case 14:{
            int n;
            printf("Enter the value of n: ");
            scanf("%d", &n);
            int sum = 0;
            float avg;
            for(int i = 1; i <= n; i++){
                sum += i;
            }
            avg = sum / n;
            printf("The sum is: %d\n", sum);
            printf("The average is: %f\n", avg);
            break;
        }
        case 15:{
            int m, n, i;
            printf("Enter the values of m and n: ");
            scanf("%d%d", &m, &n);
            printf("Odd Numbers are: ");
            for (i = m; i < n; i++){
            if (i % 2 == 1)
                printf("%d ", i);
            }
            break;
        }
        case 16:{
            int m, n, i, j;
            printf("Enter the range m and n : ");
            scanf("%d %d", &m, &n);
            printf("Prime Numbers are: ");
            for(i = m; i <= n; i++){
                int flag = 0;
                for(j = 2; j <= i - 1; j++){
                    if(i % j == 0){
                        flag = 1;
                        break;
                    }
                }   
                if(i == 1){
                    continue;
                }
                else if(flag == 0){
                    printf("%d ", i);
                }
                else{
                    continue;
                }
            }
            break;
        }
        case 17:{
            int a;
            printf("Enter Numbers (enter -1 to stop):\n");
            while(1){
                scanf("%d", &a);
                if(a == -1){
                    break;
                }
                Armstrong(a);
            }
            break;
        }
        case 18:{
            int wind;
            float temp;
            float WCI;
            printf("Enter the wind speed:");
            scanf("%d",&wind);
            getchar();
            printf("Enter the temperature:");
            scanf("%f", &temp);
            if(wind >= 0 && wind <= 4){
                WCI = temp;
                printf("The value of WCI is: %f.\n", WCI);
            }
            else if(wind >= 45){
                WCI = 1.6 * temp - 55;
                printf("The value of WCI is: %f.\n",WCI);
            }
            else{
                WCI=91.4+(91.4-temp)*(0.0203*wind-0.304*wind*1/2-0.474);
                printf("The value of WCI is: %f.\n",WCI);
            }
            break;
        }
        case 19:{
            int n;
            printf("Enter an integer: ");
            scanf("%d", &n);
            printf("Is %d divisible by 5 and 6? ", n);
            if ((n % 5 == 0) && (n % 6 == 0)){
                printf("true\n");
            } else {
                printf("false\n");
            }
            printf("Is %d divisible by 5 or 6? ", n);
            if ((n % 5 == 0) || (n % 6 == 0)){
                printf("true\n");
            } else {
                printf("false\n");
            }
            printf("Is %d divisible by 5 or 6, but not both? ", n);
            if (((n % 5 == 0) || (n % 6 == 0)) && ((n % 5 != 0) && (n % 6 != 0))){
                printf("true\n");
            } else {
                printf("false\n");
            }
            break;
        }
        case 20:{
            bill2();
            break;
        }
        default:
            break;
    }
    return 0;
}



/*
#include <stdio.h>
#include <math.h>

//Q1
// void Three(int arr[]){
//     int i;
//     for(int i = 0 ; i < 10 ; i++){
//         if(i % 3 == 2){
//             printf("%d", arr[i]);
//             printf("\n");
//         }
//         else{
//             printf("%d, ", arr[i]);
//         }
//        }
// }

// int main(){
//     int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//     Three(arr);
// }


//Q2
// #include <stdio.h>
// int main(){
//     int count = 0;
//     int sum = 0;
//     for(int i = 1 ; i <= 200 ; i++){
//         if(i % 2 == 0){
//             count++;
//             sum += i;
//         }
//     }
//     printf("Even Numbers between 1 to 120 are %d and their sum is : %d", count, sum);
// return 0;
// }

//Q3

// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>
// int main(){
//     int size = 1000;
//     int count = 0;
//     char str[size];
//     printf("Enter text: ");
//     getchar();
//     scanf("%[^\n]",str);
//     for(int i = 0 ; str[i] != '\0' ; i++){
//         tolower(str[i]);
//         if((str[i] == 'a') || (str[i] == 'e') || (str[i] == 'i') || (str[i] == 'o') || (str[i] == 'u')){
//             count++;
//         }
//     }
//     printf("Number of Vowels are %d", count);
//     return 0;
// }

//Q4
// #include <stdio.h>

// int main(){

//     float a,b,sum;
//     printf("Enter the first number : ");
//     scanf("%f",&a);
//     printf("Enter the second number : ");
//     scanf("%f",&b);
//     sum = a + b;
//     printf("The first number is : %f\n",a);
//     printf("The second number is : %f\n",b);
//     printf("Sum of %f and %f is : %f",a,b,sum);
//     return 0;
// }

//Q5

//  #include <stdio.h>

//  int main(){
//     float a;
//     int b,last;
//     printf("Enter the floating number :");
//     scanf("%f",&a);
//     b=(int)a;
//     last=b%10;
//     printf("The last digit of integral part is : %d",last);
//     return 0;
//  }

//Q6

//Q7
// #include <stdio.h>

// int main(){
//     const float HRA =0.1;
//     const float TA =0.5;

//     float base,salary;
//     printf("Enter the basic salary : ");
//     scanf("%f",&base);
//     salary=base+(base*HRA)+(base*TA);
//     printf("The salary of the employee is : %f",salary);
//     return 0;
// }

//Q8

// void bill(){
//     char item[50];
//     int quantity,n;
//     float price, Amount , totalAmount = 0;
//     printf("Enter the number of items: ");
//     scanf("%d",&n);
//     for(int i = 0 ; i < n ; i++){
//         // printf("Enter the item name: ");
//         scanf("%s",&item);
//         // printf("Enter the quantity: ");
//         scanf("%d",&quantity);
//         // printf("Enter the price: ");
//         scanf("%f",&price);
//         Amount = quantity * price;
//         if(i=0){
//             printf("BILL\n");
//             printf("ITEM\t\tQUANTITY\tPRICE\t\t\tAMOUNT\n");
//         }
//         printf("%s\t\t%d\t\t%f\t\t%f\n", item, quantity, price, Amount);
//         // printf("The amount is: %.2f",Amount);
//         totalAmount += Amount;
//     }
//     printf("------------------------------------------------------------\n");
//     printf("Total Amount: %f\n",totalAmount);
//     printf("------------------------------------------------------------\n");
// }

// int main(){
//     bill();
//     return 0;
// }

//Q9
// #include <stdio.h>

// int main() {
//     int number;

//     // Prompt the user to enter an integer
//     printf("Enter an integer: ");
//     scanf("%d", &number);

//     // Display the integer in decimal, octal, and hexadecimal notations
//     printf("Decimal: %d\n", number);
//     printf("Octal: %o\n", number);
//     printf("Hexadecimal: %X\n", number);

//     return 0;
// }

//Q10

// int main() {
//     float value;

//     printf("Enter a floating-point value: ");
//     scanf("%f", &value);

//     printf("Value entered: %.6f\n", value);
//     printf("Value in exponent form (2 decimal places): %.2e\n", value);
//     printf("Value in exponent form (4 decimal places): %.4e\n", value);
//     printf("Value in exponent form (8 decimal places): %.8e\n", value);

//     return 0;
// }

Q11
int main(){
    char s;
    while(s != '*'){
        scanf("%c",&s);
        printf("%c %d\n",s,s);
        if(s>='a' && s <='z'){
            printf(" %c",s-32);
        }
        else if(s>='A' && s <='Z'){
            printf(" %c",s+32);
        }
    }
    return 0;
}

Q12
int main(){
    float a,b,c;
    float result;
    scanf("%f %f %f",&a,&b,&c);
    result=a+b+c;
    printf("Their sum is %.2f",result);
    return 0;
}

Q13
int main(){
char s;
scanf("%c",&s);
if(s>='a' && s <='z'){
    printf("It is lower");
}
else if(s>='A' && s <='Z'){
    printf("It is upper");
}
else if(s>='0' && s<='9'){
    printf("It is Number");
}
else{
    printf("It is Special Character");
}
}

Q14
int main(){
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    int sum = 0;
    float avg;
    for(int i = 1; i <= n; i++){
        sum += i;
    }
    avg = sum / n;
    printf("The sum is: %d\n", sum);
    printf("The average is: %f\n", avg);
    return 0;
}

// Q15

int main(){
    int m, n, i;
    printf("Enter the values of m and n: ");
    scanf("%d%d", &m, &n);
    for (i = m; i < n; i++){
        if (i % 2 == 1)
            printf("%d ", i);
    }
    return 0;;
}

//Q16

int main(){
    int n;
    int sum=0;
    int remainder;
    scanf("%d",&n);
    while(n !=0){
       remainder = n%10;
       sum  remainder;
       n = n/10;

    }
    printf("%d",sum);
}
    
 
//Q18

int main(){

    int wind;
    float temp;
    float WCI;
    printf("Enter the wind speed:");
    scanf("%d",&wind);
    printf("Enter the temperature:");
    scanf("%f",&temp);
    if(wind >=0 && wind <=4){
        WCI=temp;
        printf("The value of WCI is: %f.\n", WCI);
    }
    else if(wind>=45){
        WCI= 1.6*temp-55;
        printf("The value of WCI is: %f.\n",WCI);
    }
    else{
        WCI=91.4+(91.4-temp)*(0.0203*wind-0.304*wind*1/2-0.474);
        printf("The value of WCI is: %f.\n",WCI);
    }

    return 0;
}

//Q20
// #include <stdio.h>
// #define MAX_ITEMS 100
// typedef struct{
//     char name[50];
//     float price;
// }Item;


// void bill(){
//     Item item[MAX_ITEMS];
//     int n , shipping;
//     float Amount , totalAmount , ShippingAmount;
//     printf("Enter the number of items : ");
//     scanf("%d",&n);
//     for(int i=0;i<n;i++){
//         printf("Enter the item : ");
//         scanf("%s",&item[i].name);
//         printf("Enter the price : ");
//         scanf("%f",&item[i].price);
//         Amount += item[i].price; 
//     }
//     printf("Overnight delivery (Enter 0 for no and 1 for yes): ");
//     scanf("%d",&shipping);

//     // for(int i=0;i<n;i++){
//     //     Amount += item[i].price; 
//     //     printf("%-15s\t\t%.2f", item[i].name, item[i].price);        
//     // }
//     if(Amount > 100 && shipping == 1){
//         ShippingAmount = 80;
//         totalAmount = Amount + 80;
//     }
//     else if(Amount > 100 && shipping == 0){
//         ShippingAmount = 30;
//         totalAmount = Amount + 30;
//     }
//     else if(Amount < 100 && shipping == 1){
//         ShippingAmount = 70;
//         totalAmount = Amount + 70;
//     }
//     else{
//         ShippingAmount = 20;
//         totalAmount = Amount + 20;
//     }
//     printf(":Invoice\n");
//     for(int i = 0 ; i < n ; i++){
//         printf("%-15s ",item[i].name);
//         printf("Rs. %f \n",item[i].price);
//     }
//     printf("Shipping Rs. %.2f\n",ShippingAmount);
//     printf("Total Amount Rs. %f", totalAmount);
// }
// int main(){
//     bill();
//     return 0;
// }
*/