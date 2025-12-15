#include <stdio.h>
#define MAX_ITEMS 100

typedef struct {
    char name[50];
    int quantity;
    float pricePerUnit;
} Item;

void bill(){
    Item items[MAX_ITEMS];
    int n;
    float totalAmount = 0.0;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_ITEMS) {
        printf("Invalid number of items.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for item %d:\n", i + 1);
        printf("Item name: ");
        scanf(" %[^\n]", items[i].name);
        printf("Quantity: ");
        scanf("%d", &items[i].quantity);
        printf("Price per unit: ");
        scanf("%f", &items[i].pricePerUnit);
    }

    printf("\n************************* B I L L *************************\n");
    printf("ITEM\t\tQUANTITY\tPRICE\t\tAMOUNT\n");
    printf("_____________________________________________________________\n");

    for (int i = 0; i < n; i++) {
        float amount = items[i].quantity * items[i].pricePerUnit;
        printf("%-15s\t%d\t\t%.2f\t\t%.2f\n", items[i].name, items[i].quantity, items[i].pricePerUnit, amount);
        totalAmount += amount;
    }

    printf("-------------------------------------------------------------\n");
    printf("Total Amount: %.2f\n", totalAmount);
    printf("-------------------------------------------------------------\n");
}

int main(){
    bill();
    return 0;
}
