/* exercise6-12.c */
#include <stdio.h>

int main(void)
{
	long int limit;
	float sign = 1.0f;
	float series1 = 0, series2 = 0;

	printf("Введите количество элементов последовательностей: ");
	scanf("%ld", &limit);

	for (long int i = 1; i <= limit; i++)
	{
		// 1.0 + 1.0/2.0 + 1.0/3.О + 1.0/4.0 +...
		// 1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 +...
		series1 += 1.0f/i;
		series2 += (1.0f/i) * sign;
		sign = -sign; // toggle sign
	}

	printf("Промежуточная сумма для последовательности 1: %.5f\n", series1);
	printf("Промежуточная сумма для последовательности 2: %.5f\n", series2);

	// Answer: Series 1 has no limit. Series 2 appears to be bounded above

	return 0;
}
