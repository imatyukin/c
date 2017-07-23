// exercise4-07.c
#include <stdio.h>
#include <float.h>

int main(void)
{
	double var_d = 1.0/3.0;
	float var_f = 1.0/3.0;

	printf("double: %.4f, %.12f, %.16f\n", var_d, var_d, var_d);
	printf("float: %.4f, %.12f, %.16f\n", var_f, var_f, var_f);
	printf("FLT_DIG: %d\n", FLT_DIG);
	printf("DBL_DIG: %d\n", DBL_DIG);

	return 0;
}
