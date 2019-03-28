// Exercise 2-4.
// Write a program that prompts for the user’s weekly pay in dollars and the hours worked to be entered through the
// keyboard as floating-point values. The program should then calculate and output the average pay per hour in the
// following form:
// Your average hourly pay rate is 7 dollars and 54 cents.
#include <stdio.h>

int main(void)
{
    double income, hours = 0.0;

    printf("Enter your weekly pay in dollars and the hours worked: ");
    scanf("%lf %lf", &income, &hours);

    double hourly_rate = income / hours;
    int dollars = (int)hourly_rate / 1;
    int cents = (int)((100.0 * hourly_rate) - (100.0 * dollars) + 0.5);

    printf("Your average hourly pay rate is %d dollars and %d cents.", dollars, cents);

    return 0;
}