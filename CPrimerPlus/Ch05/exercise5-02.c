// exercise5-02.c
#include <stdio.h>

int main(void)
{
	int integer, integer_add_ten;

	printf("Введите целое число:\n");
	scanf("%d", &integer);
	integer_add_ten = integer + 10;
	while (integer <= integer_add_ten)
	{
		printf("%d ", integer);
		integer++;
	}

	return 0;
}
