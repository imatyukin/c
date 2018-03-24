// Exercise 1-4. Write a program to print the corresponding Celsius to Fahrenheit table.
#include <stdio.h>

/* print Celsius-Fahrenheit table
    for celsius = 0, 20, ..., 300; floating-point version   */
int main(void)
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;          /* lower limit of temperature scale */
    upper = 300;        /* upper limit                      */
    step = 20;          /* step size                        */

    printf("Celsius Fahrenheit\n");
    celsius = lower;
    while (celsius <= upper) {
        fahr = (9.0*celsius) / 5.0+32.0;
        printf("%5.0f %10.1f\n", celsius, fahr);
        celsius = celsius + step;
    }

    return 0;
}
