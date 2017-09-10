/* Упражнение по программированию 10.14 */
#include <stdio.h>

#define ROWS 3
#define COLS 5

void showSet(int cols, double array[cols]);
void showArray(int rows, int cols, double (*array)[cols]);
void averageSet(double *array, int cols);
double averageArray(int rows, int cols, double array[rows][cols]);
double maxElement(int rows, int cols, double array[rows][cols]);

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

    printf("Содержимое первого набора:\n");
    showSet(COLS, set1);
    printf("Содержимое второго набора:\n");
    showSet(COLS, set2);
    printf("Содержимое третьего набора:\n");
    showSet(COLS, set3);
    putchar('\n');

    // Сохранение информации в массиве 3х5.
    for (int j = 0; j < COLS; j++) {
        array[0][j] = set1[j];
        array[1][j] = set2[j];
        array[2][j] = set3[j];
    }

    printf("Содержимое массива:\n");
    showArray(ROWS, COLS, array);
    putchar('\n');

    printf("Среднее значение для строки:\n");
    for (int i = 0, n = 1; i < ROWS; i++, n++) {
        printf("Набор %d - ", n);
        averageSet(array[i], COLS);
    }
    putchar('\n');

    printf("Среднее значение для всех строк = %.2lf\n", averageArray(ROWS, COLS, array));

    printf("Наибольшее значение = %.2lf\n", maxElement(ROWS, COLS, array));

    printf("\nПрограмма завершена.\n");

    return 0;
}

void showSet(int cols, double array[cols])
{
    // show the contents of the sets

    for (int i = 0; i < cols; i++)
        printf("%.2lf ", array[i]);

    putchar('\n');
}

void showArray(int rows, int cols, double (*array)[cols])
{
    // print the contents of an RxC array

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; ++c) {
            printf("%.2lf\t", array[r][c]);
        }
        putchar('\n');
    }
}

void averageSet(double *array, int cols)
{
    // calculate the average for sets

    double sum = 0.0, average;

    for (int i = 0; i < cols; i++)
        sum += array[i];
    if (cols > 0)
        average = sum / cols;
    else
        average = 0.0;

    printf("%.2lf", average);
    putchar('\n');
}

double averageArray(int rows, int cols, double array[rows][cols])
{
    // calculate the average for an array

    double sum = 0.0;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            sum += array[r][c];
        }
    }

    if (rows * cols > 0)
        return sum / (rows * cols);
    else
        return 0.0;
}

double maxElement(int rows, int cols, double array[rows][cols])
{
    // show the maximum element in a array

    double max = array[0][0];

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (max < array[r][c])
                max = array[r][c];
        }
    }

    return max;
}