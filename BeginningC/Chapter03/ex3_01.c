// Exercise 3-1.
// Write a program that will first allow a user to choose one of two options:
// 1. Convert a temperature from degrees Celsius to degrees Fahrenheit.
// 2. Convert a temperature from degrees Fahrenheit to degrees Celsius.
// The program should then prompt for the temperature value to be entered and output the new value that results from the
// conversion. To convert from Celsius to Fahrenheit you can multiply the value by 1.8 and then add 32. To convert from
// Fahrenheit to Celsius, you can subtract 32 from the value, then multiply by 5, and divide the result by 9.
#include <stdio.h>

int main(void)
{
    unsigned int operation = 0;
    double temp = 0.0;

    printf("Press 1 to convert a temperature from degrees Celsius to degrees Fahrenheit.\n"
           "Press 2 to convert a temperature from degrees Fahrenheit to degrees Celsius.\n");
    printf("(1 or 2)> ");
    scanf("%d", &operation);

    if(operation == 1 || operation == 2) {
        printf("Enter a temperature in degrees %s: ",
               (operation == 1 ?  "Centigrade" : "Fahrenheit"));
        scanf("%lf", &temp);
    }

    switch(operation)
    {
        case 1:
            printf("%.2lf Celsius is %.2lf Fahrenheit\n", temp, temp*1.8+32.0);
            break;
        case 2:
            printf("%.2lf Fahrenheit is %.2lf Celsius\n", temp, (temp-32.0)*5.0/9.0);
            break;
        default:
            printf("\n\aIllegal operation!\n");
            break;
    }

    return 0;
}
