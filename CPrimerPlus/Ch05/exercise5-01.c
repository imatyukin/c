// exercise5-01.c
#include <stdio.h>

const int time = 60;

int main(void)
{
	int min, hour;

	printf("Введите число в минутах (или <=0 для выхода):\n");
	scanf("%d", &min);
	while (min > 0)
	{
		hour = min / time;
		min = min % time;
		printf("Время в часах и минутах: %d час. %d мин.\n", hour, min);
		printf("Введите следующее значение (или <=0 для выхода):\n");
		scanf("%d", &min);
	}
	printf("Программа завершила работу.\n");

	return 0;
}
