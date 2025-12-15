#include <stdio.h>
#define MAX_ITEMS 100
typedef struct{
    char name[50];
    float price;
}Item;


void bill2(){
    Item item[MAX_ITEMS];
    int n , shipping;
    float Amount , totalAmount , ShippingAmount;
    printf("Enter the number of items : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the item : ");
        scanf("%s",&item[i].name);
        printf("Enter the price : ");
        scanf("%f",&item[i].price);
        Amount += item[i].price; 
    }
    printf("Overnight delivery (Enter 0 for no and 1 for yes): ");
    scanf("%d",&shipping);

    if(Amount > 100 && shipping == 1){
        ShippingAmount = 80;
        totalAmount = Amount + 80;
    }
    else if(Amount > 100 && shipping == 0){
        ShippingAmount = 30;
        totalAmount = Amount + 30;
    }
    else if(Amount < 100 && shipping == 1){
        ShippingAmount = 70;
        totalAmount = Amount + 70;
    }
    else{
        ShippingAmount = 20;
        totalAmount = Amount + 20;
    }
    printf(":Invoice\n");
    for(int i = 0 ; i < n ; i++){
        printf("%-15s ",item[i].name);
        printf("Rs. %f \n",item[i].price);
    }
    printf("Shipping Rs. %.2f\n",ShippingAmount);
    printf("Total Amount Rs. %f", totalAmount);
}
int main(){
    bill();
    return 0;
}