// Chapter 14 Exercise 11
#include <stdio.h>
#include <math.h>

#define ARRLENGTH 20

void transform(const double * source, double * target, int n, double (*func)(double));
double squared(double);
double cubed(double);

int main(void)
{
    // test transform function

    double source[ARRLENGTH];
    double target[ARRLENGTH];

    for (int i = 0; i < ARRLENGTH; i++)
        source[i] = i;

    transform(source, target, ARRLENGTH, sin);
    for (int i = 0; i < ARRLENGTH; i++)
    {
        printf("sin(%.2f) = %.2f\n", source[i], target[i]);
    }
    puts("");

    transform(source, target, ARRLENGTH, tan);
    for (int i = 0; i < ARRLENGTH; i++)
    {
        printf("tan(%.2f) = %.2f\n", source[i], target[i]);
    }
    puts("");

    transform(source, target, ARRLENGTH, squared);
    for (int i = 0; i < ARRLENGTH; i++)
    {
        printf("%.2f ^ 2 = %.2f\n", source[i], target[i]);
    }
    puts("");

    transform(source, target, ARRLENGTH, cubed);
    for (int i = 0; i < ARRLENGTH; i++)
    {
        printf("%.2f ^ 3 = %.2f\n", source[i], target[i]);
    }
    puts("");

    return 0;
}

void transform(const double * source, double * target, int n, double (*func)(double))
{
    for (int i = 0; i < n; i++)
        target[i] = func(source[i]);

    return;
}

double squared(double x)
{
    return x * x;
}

double cubed(double x)
{
    return x * x * x;
}

