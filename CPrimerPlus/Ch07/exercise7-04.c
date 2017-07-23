/* Упражнение по программированию 7.4 */
#include <stdio.h>

#define STOP '#'

int main(void)
{
	char ch;
	int count = 0;

	printf("Введите входные данные (символ %c окончание ввода):\n", STOP);
	while ((ch = getchar()) != STOP)
	{
		if (ch == '.')
		{
			putchar('!');
			count++;
		}
		else if (ch == '!')
		{
			putchar('!');
			putchar('!');
			count++;
		}
		else
			printf("%c", ch);
	}
	printf("\n");
	printf("Количество произведенных замен - %d", count);

	return 0;
}
