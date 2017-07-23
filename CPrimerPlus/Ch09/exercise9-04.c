// Chapter 9 Exercise 4
#include <stdio.h>

void flush_input_buffer(void);
double HarmonicMean(double, double);

int main(void)
{
	char quit;
	double a, b;

	printf("Введите два числа (или 'Q' для завершения): ");
	do
	{
		quit = getchar();
		ungetc(quit, stdin);
		if (quit == 'q' || quit == 'Q')
			break;
		else if (scanf("%lf %lf", &a, &b) == 2)
		{
			printf("Среднее гармоническое значение двух чисел %.3lf и %.3lf равно: %.3lf",
				a, b, HarmonicMean(a, b));
			flush_input_buffer();
			printf("\nВведите следующие два числа (или 'Q' для завершения): ");
			continue;
		}
		else
		{
			printf("Недопустимый ввод. Повторите попытку.\n");
			flush_input_buffer();
			printf("Введите два числа (или 'Q' для завершения): ");
			continue;
		}
	}while (quit != 'q' || quit != 'Q');
	printf("Программа завершена.\n");

	return 0;
}

void flush_input_buffer(void)
{
	while (getchar() != '\n')
		;
}

double HarmonicMean(double a, double b)
{
	double ra = 1 / a;			// reciprocals
	double rb = 1 / b;

	double hm = 2 / (ra + rb);	// reciprocal of the arithmetic mean of the two
	return hm;
}
