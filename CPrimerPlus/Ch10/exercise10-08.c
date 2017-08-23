/* Упражнение по программированию 10.8 */
#include <stdio.h>
#include <stdlib.h>

double randZeroToOne();
void copy_ptrs(double *target, double *source_start, double *source_end);
void print_results(void);

double SevenElementArray[7];
double ThreeElementArray[3];

int main()
{
    // initialize source array
    for (int i = 0; i < 7; i++)
        SevenElementArray[i] = randZeroToOne();

    // copy arrays
    copy_ptrs(ThreeElementArray, SevenElementArray + 2, SevenElementArray + 5);

    // print array contents
    print_results();

    return 0;
}

double randZeroToOne()
{
    // generate on the interval (0, 1)

    return rand() / (RAND_MAX + 1.);
}

void copy_ptrs(double *target, double *source_start, double *source_end)
{
    // copy array using pointer notation and pointer endpoint

    for (double *ptr = source_start; ptr < source_end; ptr++, target++)
        *target = *ptr;
}

void print_results(void)
{
    // print array contents

    printf("*-----------------------------------------------------------*\n");
    printf("%6s\n", "SOURCE:");
    printf("%5s ", "Index"); for (int i = 0; i < 7; i++) printf("| %5d ", i); printf("\n");
    printf("%5s ", "Value"); for (int i = 0; i < 7; i++) printf("| %.3f ", SevenElementArray[i]); printf("\n");
    printf("*-----------------------------------------------------------*\n");
    printf("%6s\n", "TARGET: ");
    printf("%5s ", "Index"); for (int i = 0; i < 3; i++) printf("| %5d ", i); printf("\n");
    printf("%5s ", "Value"); for (int i = 0; i < 3; i++) printf("| %.3f ", ThreeElementArray[i]); printf("\n");
    printf("*-----------------------------------------------------------*\n");
}