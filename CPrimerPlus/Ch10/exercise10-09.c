/* Упражнение по программированию 10.9 */
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 5

double randMtoN(double M, double N);
void cp_ar(int rows, int cols, double source[rows][cols], double target[rows][cols]);
void display(int rows, int cols, double ar[rows][cols]);

int main()
{
    double ar1[ROWS][COLS];
    double ar2[ROWS][COLS];

    // initializing two-dimensional arrays ar1[3][5]
    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLS; j++)
            ar1[i][j] = randMtoN(1, 100);

    // copy ar1 to ar2
    cp_ar(ROWS, COLS, ar1, ar2);

    // display contents of arrays
    printf("Array 1:\n");
    display(ROWS, COLS, ar1);
    putchar('\n');

    printf("Array 2:\n");
    display(ROWS, COLS, ar2);

    return 0;
}

double randMtoN(double M, double N)
{
    // generate a random number in the range from (M, N)

    return M + (rand() / (RAND_MAX / (N - M)));
}

void cp_ar(int rows, int cols, double source[rows][cols], double target[rows][cols])
{
    // copy one two-dimensional array to another

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            target[i][j] = source[i][j];
        }
    }
}

void display(int rows, int cols, double ar[rows][cols])
{
    // display the contents of a variable-length two-dimensional array

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
            printf("%6.3f ", ar[i][j]);

        putchar('\n');
    }
}