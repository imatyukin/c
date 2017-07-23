/* exercise6-14.c */
#include <stdio.h>

#define ELEMENTS 8

int main(void)
{
	double array[ELEMENTS], array_cumul[ELEMENTS];
	double sum = 0;
	int index;

	printf("Введите значения восьми элементов первого массива:\n");
	for (index = 0; index < ELEMENTS; index++)
	{
		scanf("%lf", &array[index]);
		sum += array[index];
		array_cumul[index] = sum;
	}
	printf("\n");

	for (index = 0; index < ELEMENTS; index++)
	{
		printf("%8g ", array[index]);
	}
	printf("\n");

	for (index = 0; index < ELEMENTS; index++)
	{
		printf("%8g ", array_cumul[index]);
	}
	printf("\n");

	return 0;
}
