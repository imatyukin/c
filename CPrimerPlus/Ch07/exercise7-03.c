/* Упражнение по программированию 7.3 */
#include <stdio.h>

#define STOP 0

int main(void)
{
	int integer, countEven = 0, sumEven = 0, countOdd = 0, sumOdd = 0;
	float averageEven, averageOdd;

	printf ("Введите целые числа (0 - завершение ввода):\n");
	while(scanf("%d", &integer) == 1 && integer != STOP)
	{
		if (integer % 2 == 0)
		{
			countEven++;
			sumEven += integer;
		}
		else
		{
			countOdd++;
			sumOdd += integer;
		}
	}
	averageEven = sumEven / (float) countEven;
	averageOdd = sumOdd / (float) countOdd;

	printf ("Общее количество введенных четных целых чисел (за исключением 0): %d\n", countEven);
	printf ("Среднее значение введенных четных целых чисел: %.2f\n", averageEven);
	printf ("Общее количество введенных нечетных целых чисел: %d\n", countOdd);
	printf ("Среднее значение введенных нечетных целых чисел: %.2f\n", averageOdd);

	return 0;
}
