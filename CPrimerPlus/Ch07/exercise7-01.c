/* Упражнение по программированию 7.1 */
#include <stdio.h>

int main(void)
{
	char ch;
	int whitespace = 0;
	int newline = 0;
	int chars = 0;

	printf("Введите входные данные; введите # для выхода:\n");
	while ((ch = getchar()) != '#')
	{
		if (ch == ' ') whitespace++;
		else if (ch == '\n') newline++;
		else chars++;
	}
	printf("Количество пробелов = %d, количество символов новой строки = %d, количество всех остальных символов = %d\n",
			whitespace, newline, chars);

	return 0;
}
