/* Упражнение по программированию 10.10 */
#include <stdio.h>
#include <stdlib.h>

#define COLS 4

int randMtoN(int M, int N);
void sumarr(int cols, int source1[cols], int source2[cols], int target[cols]);
void showarr(int cols, int ar[cols]);

int main()
{
    int source1[COLS];
    int source2[COLS];
    int target[COLS];

    // initialize source arrays
    for (int i = 0; i < 4; i++) {
        source1[i] = randMtoN(1, 100);
        source2[i] = randMtoN(1, 100);
    }

    // sum of elements of source1 and source2
    sumarr(COLS, source1, source2, target);

    // display contents of arrays
    printf("Source 1:\n");
    showarr(COLS, source1);
    putchar('\n');

    printf("Source 2:\n");
    showarr(COLS, source2);
    putchar('\n');

    printf("Target:\n");
    showarr(COLS, target);
    putchar('\n');

    return 0;
}

int randMtoN(int M, int N)
{
    // generate a random number in the range from (M, N)

    return M + (rand() / (RAND_MAX / (N - M)));
}

void sumarr(int cols, int source1[cols], int source2[cols], int target[cols])
{
    // sum of elements of two source arrays

    for (int i = 0; i < cols; i++)
        target[i] = source1[i] + source2[i];
}

void showarr(int cols, int ar[cols])
{
    // show the contents of a array

    for (int i = 0; i < cols; i++)
        printf("%d ", ar[i]);

    putchar('\n');
}

