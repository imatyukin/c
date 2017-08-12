/* Упражнение по программированию 10.4 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int index_max(double *array, int size);

int main(void)
{
    // test index_max

    double array[SIZE];
    srand(time(NULL)); // seed random number generator

    // initialize test array with random doubles

    for (int i = 0; i < SIZE; i++)
        array[i] = rand() / (double) RAND_MAX;

    // print test array

    printf("%5s ", "Index");
    for (int i = 0; i < SIZE; i++)
        printf("| %6d ", i);
    printf("\n");
    printf("%5s ", "Value");
    for (int i = 0; i < SIZE; i++)
        printf("| %6.4f ", array[i]);
    printf("\n");
    printf("\n");

    printf("Индекс наибольшего значения в массиве = %d.\n", index_max(array, SIZE));

    return 0;
}

int index_max(double *array, int size)
{
    int index_max = 0;
    for (int i = 1; i < size; i++)
        if (array[i] > *array) {
            *array = array[i];
            index_max = i;
        }

    return index_max;
}