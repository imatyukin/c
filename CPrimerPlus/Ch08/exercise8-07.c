// Chapter 8 Exercise 7
#include <stdio.h>
#include <stdbool.h>

#define OVERTIME_HOURS 40.0
#define OVERTIME_MULTIPLIER 1.5
#define TAX_RATE_1 0.15
#define TAX_BRACKET_1 300.0
#define TAX_RATE_2 0.20
#define TAX_BRACKET_2 450.0
#define TAX_RATE_3 0.25

void flush_input_buffer(void);
float calculate_gross_pay(float hours, float BASIC_WAGE_RATE);
float calulate_taxes(float gross_pay);

int main(void)
{
	char action;
	bool exit_flag = false;
	float BASIC_WAGE_RATE, hours_per_week, gross_pay, taxes, net_salary;

	// print usage instructions
	Start: printf("*********************************************************************\n"
			"Введите букву, соответствующую желаемой тарифной ставке или действию:\n"
			"a) $8.75/ч\t\t\tb) $9.33/ч\n"
			"c) $10.00/ч\t\t\td) $11.20/ч\n"
			"q) Выход\n"
			"*********************************************************************\n");

	while(1) {	// main program loop

		if (scanf(" %c", &action) == 0) { break; }
		switch (action)
		{
			case 'a' :
				BASIC_WAGE_RATE = 8.75;
				break;
			case 'b' :
				BASIC_WAGE_RATE = 9.33;
				break;
			case 'c' :
				BASIC_WAGE_RATE = 10.00;
				break;
			case 'd' :
				BASIC_WAGE_RATE = 11.20;
				break;
			case 'q' :
				exit_flag = true;
				break;
			default :
				flush_input_buffer();
				printf("\nНеобходимо ввести букву между 'a'-'d' или 'q'.\n\n");
				goto Start;
		}

		if (exit_flag)
			goto End; // exit program

		Invalid_input: printf("Введите количество отработанных часов: ");

		if (scanf("%f", &hours_per_week) == 1 && hours_per_week >= 0)
		{
			gross_pay = calculate_gross_pay(hours_per_week, BASIC_WAGE_RATE);
			taxes = calulate_taxes(gross_pay);
			net_salary = gross_pay - taxes;

			printf("Общая сумма начислений $%.2f, налогов $%.2f и чистой зарплаты $%.2f.\n",
					gross_pay, taxes, net_salary);
			printf("\n");
			goto Start;
		}
		else
		{
			flush_input_buffer();
			printf("\nНедопустимый ввод...\n\n");
			goto Invalid_input;
			continue;
		}

	}

	flush_input_buffer();
	printf("\nНеобходимо ввести букву между 'a'-'d' или 'q'.\n\n");
	goto Start;

	End: printf("Программа завершена.\n");

	return 0;
}

void flush_input_buffer(void)
{
	while (getchar() != '\n')
		;
}

float calculate_gross_pay(float hours, float BASIC_WAGE_RATE)
{
	float gross_pay;

	if (hours > OVERTIME_HOURS)
		gross_pay = OVERTIME_HOURS * BASIC_WAGE_RATE + (hours - OVERTIME_HOURS) * BASIC_WAGE_RATE * OVERTIME_MULTIPLIER;
	else
		gross_pay = hours * BASIC_WAGE_RATE;

	return gross_pay;
}

float calulate_taxes(float gross_pay)
{
	float taxes;

	if (gross_pay <= TAX_BRACKET_1)
		taxes = gross_pay * TAX_RATE_1;
	else if (gross_pay > TAX_BRACKET_1 && gross_pay <= TAX_BRACKET_2)
		taxes = TAX_BRACKET_1 * TAX_RATE_1 + (gross_pay - TAX_BRACKET_1) * TAX_RATE_2;
	else
		taxes = TAX_BRACKET_1 * TAX_RATE_1 + (TAX_BRACKET_2 - TAX_BRACKET_1) * TAX_RATE_2 + (gross_pay - TAX_BRACKET_2) * TAX_RATE_3;

	return taxes;
}
