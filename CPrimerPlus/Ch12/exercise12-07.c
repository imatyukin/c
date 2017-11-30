// Chapter 12 Exercise 7
#include <stdio.h>
#include <stdlib.h> /* для srand() */
#include <time.h> /* для time() */

int rollem(int);

int main(void)
{
    int dice, count, roll;
    int sides;
    int set, sets;

    srand((unsigned int) time(0)); /* рандомизировать rand() */
    printf("Введите количество бросаний или q для завершения: ");
    while (scanf("%d", &sets) == 1)
    {
        printf("Сколько граней и сколько костей? ");
        if (scanf("%d %d", &sides, &dice) != 2)
        {
            puts("не целые числа -- завершение цикла ввода.");
            break;
        }
        printf("Имеем %d бросаний %d костей с %d гранями.\n", sets, dice, sides);
        for (set = 0; set < sets; set++)
        {
            for (roll = 0, count = 0; count < dice; count++)
                roll += rollem(sides);
            /* промежуточная сумма точек костей */
            printf("%4d ", roll);
            if (set % 15 == 14)
                putchar('\n');
        }
        if (set % 15 != 0)
            putchar('\n');
        printf("Введите количество бросаний или q для завершения: ");
    }
    puts("Пусть удача не покидает вас!\n");

    return 0;
}
int rollem(int sides)
{
    int roll;

    roll = rand() % sides + 1;

    return roll;
}
