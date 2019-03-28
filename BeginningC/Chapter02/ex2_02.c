// Exercise 2-2.
// Write a program that prompts for input of the length and width of a room in feet and inches, and then calculates and
// outputs the floor area in square yards with two decimal places after the decimal point.
#include <stdio.h>

int main(void)
{
    long int lengthFeet, widthFeet, lengthInches, widthInches = 0L;

    const double feet_per_yard = 3.0;
    const double inches_per_yard = 36.0;

    printf("Enter the length and width of a room in feet and inches: ");
    scanf("%ld %ld %ld %ld", &lengthFeet, &lengthInches, &widthFeet, &widthInches);

    double lengthYards = (double)lengthFeet / feet_per_yard + (double)lengthInches / inches_per_yard;
    double widthYards = (double)widthFeet / feet_per_yard + (double)widthInches / inches_per_yard;

    printf("The floor area is %.2f square yards.\n", lengthYards * widthYards);

    return 0;
}
