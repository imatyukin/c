// Chapter 9 Exercise 3
#include <stdio.h>

void chLineRow(char, unsigned int, unsigned int);

int main(void)
{
	char ch;
	unsigned int c, r;

	printf("Введите символ и два целых числа (или 'Ctrl+D' для завершения): ");
	while (scanf("%c %u %u", &ch, &c, &r) == 3)
	{
		chLineRow(ch, c, r);
		printf("\n");

		printf("Введите символ и два целых числа (или 'Ctrl+D' для завершения): ");
	}

	return 0;
}

void chLineRow(char ch, unsigned int c, unsigned int r)
{
	for (unsigned int rows = 1; rows <= r; rows++)
	{
		for (unsigned int cols = 1; cols <= c; cols++)
			printf (" %c", ch);
		putchar ('\n');
	}

	return;
}
