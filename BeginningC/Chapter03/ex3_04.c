// Exercise 3-4.
// Modify the last example in the chapter that implemented a calculator so that the user is given the option to enter y
// or Y to carry out another calculation, and n or N to end the program. (Note: You’ll have to use a goto statement for
// this here, but you’ll learn a better way of doing this in the next chapter.)
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double number1 = 0.0;          /* First operand value a decimal number  */
    double number2 = 0.0;          /* Second operand value a decimal number */
    char operation = 0;              /* Operation - must be +, -, *, /, or %  */

    L: printf("\nEnter the calculation\n");
    scanf("%lf %c %lf", &number1, &operation, &number2);

    switch(operation)
    {
        case '+':                     // No checks necessary for add
            printf("= %lf\n", number1 + number2);
            break;

        case '-':                     // No checks necessary for subtract
            printf("= %lf\n", number1 - number2);
            break;

        case '*':                     // No checks necessary for multiply
            printf("= %lf\n", number1 * number2);
            break;

        case '/':
            if(number2 == 0)           // Check second operand for zero
                printf("\n\n\aDivision by zero error!\n");
            else
                printf("= %lf\n", number1 / number2);
            break;

        case '%':                    // Check second operand for zero
            if((long)number2 == 0)
                printf("\n\n\aDivision by zero error!\n");
            else
                printf("= %ld\n", (long)number1 % (long)number2);
            break;

        default:                     // Operation is invalid if we get to here
            printf("\n\n\aIllegal operation!\n");
            break;
    }

    printf("\nTo perform another calculation, press Y/y or N/n to exit:\n");
    scanf(" %c", &operation);

    if(operation == 'Y' || operation == 'y')
        goto L;
    else
        printf("\nThe program complete.");

    return 0;
}
