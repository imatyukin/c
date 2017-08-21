/* Упражнение по программированию 10.5 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

double MaxMinDiff(const double *array, int size);

int main(void)
{

    double array[SIZE];
    srand(time(NULL));

    for (int i = 0; i < SIZE; i++)
        array[i] = rand() / (double) RAND_MAX;

    printf("%5s ", "Index");
    for (int i = 0; i < SIZE; i++)
        printf("| %6d ", i);
    printf("\n");
    printf("%5s ", "Value");
    for (int i = 0; i < SIZE; i++)
        printf("| %6.4f ", array[i]);
    printf("\n");
    printf("\n");

    printf("\nРазность между наибольшим и наименьшим значением в массиве = %.4f\n", MaxMinDiff(array, SIZE));

    return 0;
}

double MaxMinDiff(const double *array, int size)
{
    double max = array[0], min = array[0];

    for (int i = 1; i < size; i++)
    {
        if (max < array[i])
            max = array[i];

        else if (min > array[i])
            min = array[i];
    }

    printf("Максимальный элемент = %.4f\n", max);
    printf("Минимальный элемент = %.4f", min);

    return max - min;
}