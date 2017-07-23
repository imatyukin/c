// Chapter 8 Exercise 4
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
	int ch;
	int numWords = 0;
	int numLetters = 0;
	bool prevWasASpace = true; //spaces at beginning are ignored

	printf("Выход из программы Ctrl-D.\n");
	printf("Введите поток символов:\n");
	while ((ch = getchar()) != EOF && ch != '\n')
	{
		if (isspace(ch) || ispunct (ch))
			prevWasASpace = true;
		else
		{
			if (prevWasASpace)
				numWords++;
			prevWasASpace = false;
			numLetters++;
		}
	}

	if (numWords > 0)
	{
		double avg = numLetters / (float)(numWords);
		printf("Среднее количество букв в словах: %.1f (букв = %d, слов = %d).\n", avg, numLetters, numWords);
	}
	else
		printf("Вы не ввели никаких слов.\n");

	return 0;
}
