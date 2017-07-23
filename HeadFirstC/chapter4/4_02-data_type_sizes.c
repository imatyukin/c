#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
	printf("The value of CHAR_MAX is %i\n", CHAR_MAX);
	printf("The value of CHAR_MIN is %i\n", CHAR_MIN);
	printf("A char takes %li bytes\n", sizeof(char));

	printf("The value of SHRT_MAX is %i\n", SHRT_MAX);
	printf("The value of SHRT_MIN is %i\n", SHRT_MIN);
	printf("A short takes %li bytes\n", sizeof(short));

	printf("The value of INT_MAX is %i\n", INT_MAX);
	printf("The value of INT_MIN is %i\n", INT_MIN);
	printf("An int takes %li bytes\n", sizeof(int));

	printf("The value of FLT_MAX is %f\n", FLT_MAX);
	printf("The value of FLT_MIN is %.50f\n", FLT_MIN);
	printf("A float takes %li bytes\n", sizeof(float));

	printf("The value of LONG_MAX is %li\n", LONG_MAX);
	printf("The value of LONG_MIN is %li\n", LONG_MIN);
	printf("A long takes %li bytes\n", sizeof(long));

	printf("The value of DBL_MAX is %f\n", DBL_MAX);
	printf("The value of DBL_MIN is %.50f\n", DBL_MIN);
	printf("A double takes %li bytes\n", sizeof(double));

	return 0;
}
