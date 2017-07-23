// exercise5-06.c
#include <stdio.h>

int main(void)
{
	int count, sum, max;

	count = 0;
	sum = 0;
	printf("Насколько далеко должно распространяться вычисление: ");
	scanf("%d", &max);
	while (count++ < max)
		sum =  count * count;
	printf("sum = %d\n", sum);

	return 0;
}
