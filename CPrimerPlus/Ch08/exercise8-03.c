// Chapter 8 Exercise 3
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int ch;
	int upper_counter = 0, lower_counter = 0, other_count = 0;

	printf("Выход из программы Ctrl-D.\n");
	printf("Введите поток символов:\n");
	while ((ch = getchar()) != '\n' && ch != EOF)
	{
		if (isupper(ch))
			upper_counter++;
		else if (islower(ch))
			lower_counter++;
		else
			other_count++;
	}

	printf("\nКоличество прописных букв: %d", upper_counter);
	printf("\nКоличество строчных букв: %d", lower_counter);
	printf("\nКоличество остальных символов: %d", other_count);

	return 0;
}
