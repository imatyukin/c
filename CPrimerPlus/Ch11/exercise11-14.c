/* Упражнение по программированию 11.14 */
#include <stdio.h>
#include <stdlib.h> /* для atof() */
#include <math.h> /* для pow() */

int main(int argc, char *argv[])
{
    double num, exp;

    if (argc != 3)
        printf("Использование: %s число экспонента\n", argv[0]);
    else
    {
        num = atof(argv[1]);
        exp = atof(argv[2]);
        printf("%f в степени %f = %g\n", num, exp, pow(num,exp));
    }

    return 0;
}