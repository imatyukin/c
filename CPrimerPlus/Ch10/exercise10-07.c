/* Упражнение по программированию 10.7 */
#include <stdio.h>
#include <stdlib.h>

double randMtoN(double M, double N);
void print_row(double (*arr)[6], int row);
void copy_ptr(double *target, double *source, int arr_len);

int main()
{
    // copy one 6 by 6 array to another 6 by 6 array

    double source[6][6];
    double target[6][6];

    // initialize source array
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 6; j++)
            source[i][j] = randMtoN(1, 100);

    // copy source array to target
    for(int i = 0; i < 6; i++)
        copy_ptr(target[i], source[i], 6);

    // print arrays
    printf("%-48s", "Source");
    printf("%-48s", "Target");
    putchar('\n');
    for (int i = 0; i < 45; i++)
        putchar('-');
    printf("   ");
    for (int i = 0; i < 45; i++)
        putchar('-');
    putchar('\n');

    for (int i = 0; i < 6; i++)
    {
        print_row(source, i);
        print_row(target, i);
        putchar('\n');
    }

    return 0;
}

double randMtoN(double M, double N)
{
    // generate a random number in the range from (M, N)

    return M + (rand() / (RAND_MAX / (N - M)));
}

void copy_ptr(double *target, double *source, int arr_len)
{
    // copy array using pointer notation

    for (int i = 0; i < arr_len; i++)
        *(target + i) = *(source + i);
}

void print_row(double (*arr)[6], int row)
{
    // print a row from a n by 6 array of doubles

    for (int i = 0; i < 6; i++)
    {
        printf("%2.2f\t", arr[row][i]);
    }
}
