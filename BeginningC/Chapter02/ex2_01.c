// Exercise 2-1.
// Write a program that prompts the user to enter a distance in inches and then outputs that distance in yards, feet,
// and inches. (For those unfamiliar with imperial units, there are 12 inches in a foot and 3 feet in a yard.)
#include <stdio.h>

int main(void)
{
    int inches = 0;
    int yards = 0;
    int feet = 0;

    const int inches_per_foot = 12;
    const int feet_per_yard = 3;

    printf("Enter a distance in inches: ");
    scanf("%d", &inches);

    feet = inches/inches_per_foot;
    yards = feet/feet_per_yard;
    feet %= feet_per_yard;
    inches %= inches_per_foot;

    printf("That is equivalent to %d yards %d feet and %d inches.\n",
           yards, feet, inches);

    return 0;
}
