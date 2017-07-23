/* exercise6-13.c */
#include <stdio.h>

#define ELEMENTS 8

double power(int n, int р);

int main(void)
{
	int array[ELEMENTS], xpow, exp, index = 0;

	for (exp = 0; exp < ELEMENTS; exp++)
	{
		xpow = power(2, exp);
		array[exp] = xpow;
	}

	do {
		printf("%d ", array[index]);
		index++;
	} while (index < ELEMENTS);

	return 0;
}

double power(int n, int р)
{
	int i, pow = 1;

	for (i = 1; i <= р ; i++)
		pow *= n;

	return pow;
}
