/* exercise6-15.c */
#include <stdio.h>
#include <string.h>

int reverseString();

int main(void)
{
	char str[255] = {'\0'};
	int i = 0;
	char ch;

	printf("Введите строку: ");
	while ((scanf("%c", &ch) == 1) && ch != '\n') {
		if (i < 255) {
			str[i] = ch;
			++i;
		}
	}

	reverseString(str);
	printf("Строка в обратном порядке: %s", str);

	return 0;
}

int reverseString(char string[]) {
	size_t str_len = strlen(string);

	for (int i = 0; i < str_len / 2; ++i) {
		char temp = string[i];
		string[i] = string[str_len - i - 1];
		string[str_len - i - 1] = temp;
	}

	return 0;
}
