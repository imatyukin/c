/* Упражнение по программированию 7.9 */
#include <stdio.h>

int check_prime_number(int);

int main(void)
{
	int n, i, result, start = 2;

	printf ("Введите положительное целое число: ");
	scanf("%d", &n);

	if (n == 0 || n == 1)
		printf ("Простых чисел, которые меньше или равны '%d' нет\n", n);
	else
		printf ("Простые числа, которые меньше или равны '%d': ", n);
		for (i = start; i <= n; i++)
		{
			result = check_prime_number(i);

			if (result == 1)
			{
				printf ("%d ", i);
			}
			else
				continue;
		}

	return 0;
}

int check_prime_number(int a)
{
	int c;

	for (c = 2; c <= a - 1; c++)
	{
		if (a % c == 0)
			return 0;
	}
	if (c == a)
		return 1;

	return 2;
}
