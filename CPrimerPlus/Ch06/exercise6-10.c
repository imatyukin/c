/* exercise6-10.c */
#include <stdio.h>

void result(int n, int m);

int main(void)
{
	int var1, var2;

	printf("Введите нижний и верхний целочисленные пределы: ");
	do {
		scanf("%d %d", &var1, &var2);
		if (var2 <= var1)
			break;
		else
			result(var1, var2);
		printf("Введите следующую комбинацию пределов: ");
	} while (var1 <= var2);
	printf("Работа завершена");

	return 0;
}

void result(int n, int m)
{
	int s, i;
	for (s = 0, i = n; i <= m; s += i*i, i++);
	printf("Сумма квадратов целых чисел от %d до %d равна %d\n", n*n, m*m, s);
}
