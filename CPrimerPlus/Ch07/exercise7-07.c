/* Упражнение по программированию 7.7 */
#include <stdio.h>

#define BASIC_WAGE_RATE 10.0	// $10 в час
#define OVERTIME_HOURS 40.0		// часов по основной тарифной ставке
#define OVERTIME_MULTIPLIER 1.5	// в 1.5 раза больше
#define TAX_RATE_1 0.15			// ставка для 1-го уровня
#define TAX_BRACKET_1 300.0		// 1-й уровень тарифов
#define TAX_RATE_2 0.20			// ставка для 2-го уровня
#define TAX_BRACKET_2 450.0		// 2-й уровень тарифов
#define TAX_RATE_3 0.25			// ставка для 3-го уровня

float calculate_gross_pay(float hours);
float calulate_taxes(float gross_pay);

int main(void)
{
	double hours_per_week, gross_pay, taxes, net_salary;

	printf("Введите количество часов, отработанных за неделю: ");

	if (scanf("%lf", &hours_per_week) == 1)
	{
		gross_pay = calculate_gross_pay(hours_per_week);
		taxes = calulate_taxes(gross_pay);
		net_salary = gross_pay - taxes;

		printf("Общая сумма начислений $%.2f, налогов $%.2f и чистой зарплаты $%.2f.",
				gross_pay, taxes, net_salary);
	}
	else
		printf("Недопустимый ввод... завершение программы.\n");

	return 0;
}

float calculate_gross_pay(float hours)
{
	double gross_pay;

	if (hours > OVERTIME_HOURS)
		gross_pay = OVERTIME_HOURS * BASIC_WAGE_RATE + (hours - OVERTIME_HOURS) * BASIC_WAGE_RATE * OVERTIME_MULTIPLIER;
	else
		gross_pay = hours * BASIC_WAGE_RATE;

	return gross_pay;
}

float calulate_taxes(float gross_pay)
{
	double taxes;

	if (gross_pay <= TAX_BRACKET_1)
		taxes = gross_pay * TAX_RATE_1;
	else if (gross_pay > TAX_BRACKET_1 && gross_pay <= TAX_BRACKET_2)
		taxes = TAX_BRACKET_1 * TAX_RATE_1 + (gross_pay - TAX_BRACKET_1) * TAX_RATE_2;
	else
		taxes = TAX_BRACKET_1 * TAX_RATE_1 + (TAX_BRACKET_2 - TAX_BRACKET_1) * TAX_RATE_2 + (gross_pay - TAX_BRACKET_2) * TAX_RATE_3;

	return taxes;
}
