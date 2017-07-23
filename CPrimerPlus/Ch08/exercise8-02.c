// Chapter 8 Exercise 2
#include <stdio.h>

int main(void)
{
	int ch, char_count = 0;

	printf("Выход из программы Ctrl-D.\n");
	printf("Введите поток символов:\n");
	while ((ch = getchar()) != EOF)
	{
		if (ch >= ' ')
			printf("\'%c\': %d", ch, ch);
		else if (ch == '\n')
			printf("\'\\n\': %d", ch);
		else if (ch == '\t')
			printf("\'\\t\': %d", ch);
		else // ascii control characters
			printf("\'^%c\': %d", ch + 64, ch);

		char_count++;
		if (char_count % 10 == 0)
			printf("\n"); // print new line for every 10 characters
		else
			printf("  "); // otherwise, print spaces
	}

	printf("\n");

	return 0;
}
