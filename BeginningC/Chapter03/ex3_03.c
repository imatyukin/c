// Exercise 3-3.
// Write a program that will calculate the price for a quantity entered from the keyboard, given that the unit price is
// $5 and there is a discount of 10 percent for quantities over 30 and a 15 percent discount for quantities over 50.
#include <stdio.h>

int main(void)
{
    int quantity = 0;
    const double unit_price = 5.0;
    const double discount1 = 0.1;
    const double discount2 = 0.15;
    double total_price = 0;

    printf("Enter the quantity to calculate the price: ");
    scanf("%d", &quantity);

    total_price = quantity < 31 ? quantity * unit_price :
            (quantity > 30 && quantity < 51 ? 30 * unit_price + ((quantity - 30) * unit_price - (quantity - 30) * unit_price * discount1) :
             30 * unit_price + (20 * unit_price - 20 * unit_price * discount1) + (quantity - 50) * unit_price - (quantity - 50) * unit_price * discount2);

    printf("The total price for %d items is $%.2lf\n", quantity, total_price);

    return 0;
}
