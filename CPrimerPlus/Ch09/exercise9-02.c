// Chapter 9 Exercise 2
#include <stdio.h>

void chline(char, unsigned int, unsigned int);

int main(void)
{
	char ch;
	unsigned int i, j;

	printf("Введите символ и два целых числа (или 'Ctrl+D' для завершения): ");
	while (scanf("%c %u %u", &ch, &i, &j) == 3)
	{
		chline(ch, i, j);
		printf("\n");

		while (getchar() != '\n') continue; // clear input

		printf("Введите символ и два целых числа (или 'Ctrl+D' для завершения): ");
	}

	return 0;
}

void chline(char ch, unsigned int i, unsigned int j)
{
	unsigned int x;

	for (x = 1; x < i; x++)
		putchar(' ');

	for (; x <= j; x++)
		putchar(ch);
}
