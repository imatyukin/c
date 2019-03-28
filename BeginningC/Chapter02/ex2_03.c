// Exercise 2-3.
// You’re selling a product that’s available in two versions: type 1 is a standard version priced at $3.50, and type 2
// is a deluxe version priced at $5.50. Write a program using only what you’ve learned up to now that prompts for the
// user to enter the product type and a quantity, and then calculates and outputs the price for the quantity entered.
#include <stdio.h>

int main(void)
{
    const double product_type1 = 3.50;
    const double product_type2 = 5.50;
    int type, quantity = 0;
    double price = 0.0;

    printf("Enter the product type (1 or 2) and the quantity: ");
    scanf("%d %d", &type, &quantity);

    price = quantity * (product_type1 + (type - 1) * (product_type2 - product_type1));

    printf("The price for the quantity entered is $%.2f.\n", price);

    return 0;
}