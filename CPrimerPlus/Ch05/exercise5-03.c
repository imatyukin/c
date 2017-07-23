// exercise5-03.c
#include <stdio.h>

int main(void)
{
	int amount_of_days, week, day;

	printf("Введите количество дней (или <=0 для выхода):\n");
	scanf("%d", &amount_of_days);
	while (amount_of_days > 0)
	{
		week = amount_of_days / 7;
		day = amount_of_days - week * 7;
		printf("%d дней составляют %d нед. и %d д.\n", amount_of_days, week, day);
		printf("Введите количество дней (или <=0 для выхода):\n");
		scanf("%d", &amount_of_days);
	}
	printf("Программа завершена.");

	return 0;
}
