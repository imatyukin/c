/* Упражнение по программированию 7.6 */
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define STOP '#'

int main(void)
{
	char ch;
	unsigned int ei_count = 0;
	bool e_flag = false;

	printf("Введите входные данные (символ %c окончание ввода):\n", STOP);
	while ((ch = getchar()) != STOP)
	{
		ch = tolower(ch);
		if (ch == 'e')
			e_flag = true;
		else if (ch == 'i')
		{
			if (e_flag)
				ei_count++;
			e_flag = false;
		}
		else
			e_flag = false;
	}

	printf("Количество вхождений последовательности ei - %d", ei_count);

	return 0;
}
