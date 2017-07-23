// Chapter 8 Exercise 8
#include <stdio.h>
#include <ctype.h>

void print_menu(void);
int get_first(void);
float get_number(void);

int main(void)
{
	int operation;
	float num1, num2;

	print_menu();
	while ((operation = get_first()) != 'q')
	{
		printf("Введите первое число: ");
		num1 = get_number();
		printf("Введите второе число: ");
		num2 = get_number();

		switch (operation)
		{
			case ('a') :
				printf("%.3f + %.3f = %.3f\n", num1, num2, num1 + num2);
				break;
			case ('s') :
				printf("%.3f - %.3f = %.3f\n", num1, num2, num1 - num2);
				break;
			case ('m') :
				printf("%.3f * %.3f = %.3f\n", num1, num2, num1 * num2);
				break;
			case ('d') :
				while (num2 == 0)
				{
					printf("Введите число, отличное от О: ");
					num2 = get_number();
				}
				printf("%.3f / %.3f = %.3f\n", num1, num2, num1 / num2);
				break;
			default :
				printf("Недопустимый ввод. Попробуйте повторить.\n");
		}
		print_menu();
	}

	return 0;
}

void print_menu(void)
{
	printf("Выберите желаемую операцию:\n");
	printf("a. сложение	s. вычитание\n");
	printf("m. умножение	d. деление\n");
	printf("q. завершение\n");
}

int get_first(void)
{
	// return first non-whitespace character
	int ch;

	do ch = getchar(); while (isspace(ch));

	while (getchar() != '\n')
		;

	return ch;
}

float get_number(void)
{
	int ch;
	float num;

	while (scanf("%f", &num) != 1)
	{
		while ((ch = getchar()) != '\n') // echo user input and clear stream
			putchar(ch);

		printf(" не является числом.\n");
		printf("Введите число, такое как 2.5, -1.78Е8 или 3: ");
	}

	return num;
}
