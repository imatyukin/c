/* exercise6-06.c */
#include <stdio.h>

int main(void)
{
	int upper_limit, lower_limit, i, x, x2, x3;

	printf("Введите верхний и нижний пределы таблицы: ");
	scanf( "%d %d", &upper_limit, &lower_limit);

	for (i = lower_limit; i <= upper_limit; ++i)
	{
		for (x = i; x <= i; x++)
			printf("%d ", x);
		for (x2 = i*i; x2 <= i*i; x2++)
			printf("%d ", x2);
		for (x3 = i*i*i; x3 <= i*i*i; x3++)
			printf("%d", x3);
		printf("\n");
	}

	return 0;
}
