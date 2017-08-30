/* Упражнение по программированию 10.11 */
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 5

int randMtoN(int M, int N);
void display(int (*array)[COLS], int rows);
void double_elements(int (*array)[COLS], int rows);

int main()
{
    int array[ROWS][COLS];

    // initializing two-dimensional array 3x5
    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLS; j++)
            array[i][j] = randMtoN(1, 100);

    printf("Original array:\n");
    display(array, 3);

    // double array and print new values
    double_elements(array, 3);
    printf("Doubled array:\n");
    display(array, 3);

    return 0;
}

int randMtoN(int M, int N)
{
    // generate a random number in the range from (M, N)

    return M + (rand() / (RAND_MAX / (N - M)));
}

void display(int (*array)[COLS], int rows)
{
    // print the contents of an N x 5 array of ints

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLS; ++j)
        {
            printf("%3d ", array[i][j]);
        }
        putchar('\n');
    }
}

void double_elements(int (*array)[COLS], int rows)
{
    // double the elements of an N x 5 array of ints

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < COLS; j++)
            array[i][j] *= 2;
}