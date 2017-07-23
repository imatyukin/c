/* exercise6-11.c */
#include <stdio.h>

#define NUMBER_OF_ELEMENTS 8

int main(void)
{
	int array[NUMBER_OF_ELEMENTS], i = 0;

	printf("Введите восемь целых чисел: ");
	while(i < NUMBER_OF_ELEMENTS && scanf("%d", &array[i++]));
	while(i--) printf("%d", array[i]);

	return 0;
}
