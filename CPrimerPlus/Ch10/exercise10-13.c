/* Упражнение по программированию 10.13 */
#include <stdio.h>

#define ROWS 3
#define COLS 5

void showSet(int cols, double array[cols]);
void showArray(double (*array)[COLS], int rows);
void averageSet(double *array);
double averageArray(double array[ROWS][COLS]);
double maxElement(double array[ROWS][COLS]);

int main(void)
{
    double set1[COLS], set2[COLS], set3[COLS];
    double array[ROWS][COLS];

    printf("Введите три набора по пять чисел с плавающей запятой:\n");
    for (int i = 0; i < COLS; i++)
        scanf("%lf", &set1[i]);
    for (int i = 0; i < COLS; i++)
        scanf("%lf", &set2[i]);
    for (int i = 0; i < COLS; i++)
        scanf("%lf", &set3[i]);
    putchar('\n');

    printf("Set 1:\n");
    showSet(COLS, set1);
    printf("Set 2:\n");
    showSet(COLS, set2);
    printf("Set 3:\n");
    showSet(COLS, set3);
    putchar('\n');

    // Сохранение информации в массиве 3х5.
    for (int j = 0; j < COLS; j++) {
        array[0][j] = set1[j];
        array[1][j] = set2[j];
        array[2][j] = set3[j];
    }

    printf("Array 3x5:\n");
    showArray(array, 3);
    putchar('\n');

    printf("Average for sets:\n");
    for (int i = 0, n = 1; i < ROWS; i++, n++) {
        printf("Set %d - ", n);
        averageSet(array[i]);
    }
    putchar('\n');

    printf("Average for the array: %.2lf\n", averageArray(array));

    printf("The largest value of the array: %.2lf\n", maxElement(array));

    return 0;
}

void showSet(int cols, double array[cols])
{
    // show the contents of the sets

    for (int i = 0; i < cols; i++)
        printf("%.2lf ", array[i]);

    putchar('\n');
}

void showArray(double (*array)[COLS], int rows)
{
    // print the contents of an N x 5 array of ints

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; ++j) {
            printf("%.2lf\t", array[i][j]);
        }
        putchar('\n');
    }
}

void averageSet(double *array)
{
    // calculate the average for sets

    double sum = 0.0, average;

    for (int j = 0; j < COLS; j++)
        sum += array[j];

    average = sum / COLS;
    printf("%.2lf", average);
    putchar('\n');
}

double averageArray(double array[ROWS][COLS])
{
    // calculate the average for an array

    double sum = 0.0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            sum += array[i][j];
        }
    }

    return sum / (ROWS * COLS);
}

double maxElement(double array[ROWS][COLS])
{
    // show the maximum element in a array

    double max = array[0][0];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (array[i][j] > max)
                max = array[i][j];
        }
    }

    return max;
}