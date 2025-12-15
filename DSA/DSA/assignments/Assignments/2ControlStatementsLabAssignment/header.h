#define MAX_ITEMS 100

typedef struct {
    char name[50];
    int quantity;
    float pricePerUnit;
} Item;

typedef struct{
    char name[50];
    float price;
}Item1;


void ThreeNumbersInLine(int n);
void EvenNumbersCount(int min , int max);
void NumberOfVowels(char str[] , int size);
int AddTwoFloat(float a , float b);
int RightMost(float a);
float SimpleInterest(float p , float r , float t);
float CompoundInterest(float p , float r , float t);
void bill();
void Armstrong(int n);
void bill2();