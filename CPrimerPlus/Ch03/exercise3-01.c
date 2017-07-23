// exercise3-01.c
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
	printf("The number of bits in a byte %d\n", CHAR_BIT);

	printf("\nThe minimum value of CHAR = %d\n", CHAR_MIN);
	printf("The maximum value of CHAR = %d\n", CHAR_MAX);
	printf("The minimum value of SIGNED CHAR = %d\n", SCHAR_MIN);
	printf("The maximum value of SIGNED CHAR = %d\n", SCHAR_MAX);
	printf("The maximum value of UNSIGNED CHAR = %d\n", UCHAR_MAX);

	// Signed char overflow
	signed char c1 = 130;
	signed char c2 = -130;
	printf("c1 = %d, c2 = %d\n", c1, c2);

	// Unsigned char overflow
	unsigned char c3 = 260;
	unsigned char c4 = -6;
	printf("c3 = %d, c4 = %d\n", c3, c4);

	printf("\nThe minimum value of SHORT INT = %d\n", SHRT_MIN);
	printf("The maximum value of SHORT INT = %d\n", SHRT_MAX);

	// Unsigned short overflow
	unsigned short a = 65000;
	unsigned short b = 540;
	unsigned short c = 0;
	c = a + b;
	printf("Result is %hu + %hu = %hu\n", a, b, c);

	printf("\nThe minimum value of INT = %d\n", INT_MIN);
	printf("The maximum value of INT = %d\n", INT_MAX);
	printf("The minimum value of LONG = %ld\n", LONG_MIN);
	printf("The maximum value of LONG = %ld\n", LONG_MAX);

	// Integer overflow
	printf("%d - 1 = %d\n", INT_MIN, (INT_MIN-1));
	printf("%d + 1 = %d\n", INT_MAX, (INT_MAX+1));
	printf("%ld - 1 = %ld\n", LONG_MIN, (LONG_MIN-1));
	printf("%ld + 1 = %ld\n", LONG_MAX, (LONG_MAX+1));

	printf("\nThe minimum value of float = %.10e\n", FLT_MIN);
	printf("The maximum value of float = %.10e\n", FLT_MAX);

	// Float overflow
	printf("%.10e - 1.0 = %.10e\n", FLT_MIN, (FLT_MIN-1.0));
	printf("%.10e + 1.0 = %.10e\n", FLT_MAX, (FLT_MAX+1.0));
	float nmin=-3.3e38f;
	float pmax= 3.5e38f;
	float min= 1.0e-38f;
	printf("%f, %f, %f", nmin, pmax, min);

	return 0;
}
