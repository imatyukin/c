// Chapter 9 Exercise 7
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void flush_input_buffer(void);
int ch_to_num(char);

int main(void)
{
	int ch, num;

	while ((ch = getchar()) != EOF)
	{
		num = ch_to_num(ch);
		if (num == -1)
		{
			printf("'%c' не является буквой. Код %d.\n", ch, num);
			flush_input_buffer();
		}
		else
		{
			printf("'%c' является буквой. Порядковый номер в алфавите %d.\n", ch, num);
			flush_input_buffer();
		}
	}

	return 0;
}

void flush_input_buffer(void)
{
	while (getchar() != '\n')
		;
}

int ch_to_num(char ch)
{
	int n = -1;
	static const char * const alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	char *p = strchr(alphabet, toupper((unsigned char)ch));

	if (p)
	{
		n = (p - alphabet) + 1;
	}

	return n;
}
