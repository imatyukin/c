/* Упражнение по программированию 10.2 */
#include <stdio.h>

#define LENGTH 5

double source[LENGTH] = {1.1, 2.2, 3.3, 4.4, 5.5};
double target1[LENGTH];
double target2[LENGTH];
double target3[LENGTH];

// prototype declarations
void copy_arr(double target[], double source[], int arr_len);               // copy with array notation
void copy_ptr(double *target, double *source, int arr_len);                 // copy with pointer notation
void copy_ptrs(double *target, double *source_start, double *source_end);   // copy with two pointers
void print_results(void);                                                   // print array contents

int main(void)
{
    // print array contents
    printf("BEFORE calling functions\n");
    print_results();

    // copy arrays
    copy_arr(target1, source, LENGTH);
    copy_ptr(target2, source, LENGTH);
    copy_ptrs(target3, source, source + LENGTH);

    // print array contents
    printf("AFTER calling functions\n");
    print_results();

    return 0;
}

void copy_arr(double target[], double source[], int arr_len)
{
    // copy array using array notation

    for (int i = 0; i < arr_len; i++)
        target[i] = source[i];
}

void copy_ptr(double *target, double *source, int arr_len)
{
    // copy array using pointer notation

    for (int i = 0; i < arr_len; i++)
        *(target + i) = *(source + i);
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

    printf("*----------------------------*\n");
    printf("SOURCE  : ");
    for (int i = 0; i < LENGTH; i++) printf("%1.1f ", source[i]); printf("\n");
    printf("TARGET1 : ");
    for (int i = 0; i < LENGTH; i++) printf("%1.1f ", target1[i]); printf("\n");
    printf("TARGET2 : ");
    for (int i = 0; i < LENGTH; i++) printf("%1.1f ", target2[i]); printf("\n");
    printf("TARGET3 : ");
    for (int i = 0; i < LENGTH; i++) printf("%1.1f ", target3[i]); printf("\n");
    printf("*----------------------------*\n");
}