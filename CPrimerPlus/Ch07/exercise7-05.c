/* Упражнение по программированию 7.5 */
#include <stdio.h>

#define STOP '#'
#define DOT '.'
#define EXCLAMATION_POINT '!'

int main(void)
{
	char ch;
	int count = 0;

	printf("Введите входные данные (символ %c окончание ввода):\n", STOP);
	while ((ch = getchar()) != STOP)
	{
		switch (ch)
		{
			case DOT :
				putchar('!');
				count++;
				break;
			case EXCLAMATION_POINT :
				putchar('!');
				putchar('!');
				count++;
				break;
			default :
				printf("%c", ch);
		}
	}
	printf("\n");
	printf("Количество произведенных замен - %d", count);

	return 0;
}
