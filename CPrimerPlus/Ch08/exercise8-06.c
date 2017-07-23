// Chapter 8 Exercise 6
#include <stdio.h>
#include <ctype.h>

int get_first(void);

int main(void)
{
	int ch;

	printf("Test program for get_first():\n");
	printf("Enter a line; you should see the first non-whitespace\n");
	printf("character echoed in the terminal:\n");

	ch = get_first();
	printf("%c\n", ch);

	return 0;
}

int get_first(void)
{
	int ch;

	ch = getchar();
	while (ch == 32)
	{
		ch = getchar();
	}

	return ch;
}
