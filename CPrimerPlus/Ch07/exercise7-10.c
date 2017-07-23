/* Упражнение по программированию 7.10 */
#include <stdio.h>

#define SINGLE 1
#define HEAD_OF_HOUSEHOLD 2
#define MARRIED_JOINT 3
#define MARRIED_SEPARATE 4
#define EXIT 5

#define RATE_1 0.15f
#define RATE_2 0.28f

void flush_input_buffer(void);

int main(void)
{
	int category;
	float income, bracket, taxes;

	printf("Шкала федеральных налоговых ставок Соединенных Штатов в 1988 году.\n");

	while(1)
	{
		printf("_______________________________________________________________________________\n"
				"Категория\t\t\t\tНалог\n"
				"_______________________________________________________________________________\n"
				"1) Одинокий\t\t\t\t15%% с первых $17 850 плюс 28%% от суммы,\n"
				"\t\t\t\t\tпревышающей указанную\n"
				"2) Глава семейства\t\t\t15%% с первых $23 900 плюс 28%% от суммы,\n"
				"\t\t\t\t\tпревышающей указанную\n"
				"3) Состоит в браке, совместное\t\t15%% с первых $29 750 плюс 28%% от суммы,\n"
				"   ведение хозяйства\t\t\tпревышающей указанную\n"
				"4) Состоит в браке, раздельное\t\t15%% с первых $14 875 плюс 28%% от суммы,\n"
				"   ведение хозяйства\t\t\tпревышающей указанную\n"
				"_______________________________________________________________________________\n"
				"Введите свою налоговую категорию (1-4) или 5 для выхода:\n");
		scanf("%d", &category);

		switch (category)
		{
			case (SINGLE) :
				bracket = 17850.0;
				break;
			case (HEAD_OF_HOUSEHOLD) :
				bracket = 23900.0;
				break;
			case (MARRIED_JOINT) :
				bracket = 29750.0;
				break;
			case (MARRIED_SEPARATE) :
				bracket = 14875.0;
				break;
			case (EXIT) :
				printf("До свидания.\n");
				return 0; // Exit Program
			default :
				flush_input_buffer();
				printf("Недопустимый ввод: введите целое число от 1 до 5.\n");
				continue;
		}
		printf("Введите свой доход: ");
		while (scanf("%f", &income) != 1 || income < 0)
		{
			flush_input_buffer();
			printf("Недопустимый ввод: введите положительное число.\n");
			printf("Введите свой доход: ");
		}

		if (income > bracket)
			taxes = RATE_2 * (income - bracket) + RATE_1 * bracket;
		else
			taxes = RATE_1 * income;

		printf("Вы должны заплатить $%.2f налогов.\n\n", taxes);
	}

	return 0;
}

void flush_input_buffer(void)
{
	while (getchar() != '\n')
		;
}
