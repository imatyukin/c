// exercise5-08.c
#include <stdio.h>

int main(void)
{
	int foperand, soperand, result;

	printf("Эта программа вычисляет результаты деления по модулю.\n");
	printf("Введите целое число, которое будет служить вторым операндом: ");
	scanf("%d", &soperand);
	printf("Теперь введите первый операнд: ");
	scanf("%d", &foperand);
	result = foperand % soperand;
	printf("%d %% %d равно %d\n", foperand, soperand, result);
	while (foperand > 0)
	{
		printf("Введите следующее число для первого операнда (<= О для выхода из программы): ");
		scanf("%d", &foperand);
		if (foperand <= 0)
			break;
		result = foperand % soperand;
		printf("%d %% %d равно %d\n", foperand, soperand, result);
	}
	printf("Готово");

	return 0;
}
