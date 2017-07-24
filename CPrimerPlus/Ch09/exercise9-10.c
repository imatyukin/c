// Chapter 9 Exercise 10
#include <stdio.h>

void to_base_n(unsigned long number, unsigned short base);

int main(void)
{
    unsigned long number;
    unsigned short base;

    printf("Bвeдитe целое число и основание системы счисления (от 2 до 10) ('q' для завершения):\n");
        while (scanf ("%lu %hd", &number, &base) == 2)
        {
            if(base >=2 && base <= 10)
            {
                printf("Эквивалент числа %lu в системе счисления с основанием %d: ", number, base);
                to_base_n(number, base);
                putchar('\n');
                printf("Bвeдитe целое число и основание системы счисления (от 2 до 10) ('q' для завершения):\n");
            }
            else
                printf("Bвeдитe целое число и основание системы счисления (от 2 до 10) ('q' для завершения):\n");
        }
        printf("Пporpaммa завершена.\n");

        return 0;
}

void to_base_n(unsigned long number, unsigned short base) /* рекурсивная функция */
{
    int index, i;
    int n[32];

    index = 0;            /* initialize index to zero */
    while(number > 0)
    {
        n[index] = number % base;
        number = number / base;
        index++;
    }
    /* print value in reverse order */
    for(i = (index - 1); i >= 0; i--)
        printf("%d", n[i]);

    return;
}