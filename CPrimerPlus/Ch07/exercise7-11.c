/* Упражнение по программированию 7.11 */
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	const double price_artichokes = 2.05;
	const double price_beets = 1.15;
	const double price_carrots = 1.09;
	const double DISCOUNT_RATE = 0.05;
	const double under5 = 6.50;
	const double under20 = 14.00;
	const double base20 = 14.00;
	const double extralb = 0.50;
	char ch;
	double lb_artichokes = 0;
	double lb_beets = 0;
	double lb_carrots = 0;
	double lb_temp;
	double lb_total;
	double cost_artichokes;
	double cost_beets;
	double cost_carrots;
	double cost_total;
	double final_total;
	double discount;
	double shipping;

	printf("Введите a для покупки артишоков, b для покупки свеклы, ");
	printf("c для покупки моркови, q для выхода: ");
	while ((ch = getchar()) != 'q' && ch != 'Q')
	{
		if (ch == '\n')
			continue;
		while (getchar() != '\n')
			continue;
		ch = tolower(ch);
		switch (ch)
		{
			case 'a' : printf("Введите желаемое количество фунтов артишоков: ");
					scanf("%lf", &lb_temp);
					lb_artichokes += lb_temp;
					break;
			case 'b' : printf("Введите желаемое количество фунтов свеклы: ");
					scanf("%lf", &lb_temp);
					lb_beets += lb_temp;
					break;
			case 'c' : printf("Введите желаемое количество фунтов моркови: ");
					scanf("%lf", &lb_temp);
					lb_carrots += lb_temp;
					break;
			default : printf("%c не является допустимым вариантом.\n", ch);
		}
		printf("Введите a для покупки артишоков, b для покупки свеклы, ");
		printf("c для покупки моркови, q для выхода: ");
	}

	cost_artichokes = price_artichokes * lb_artichokes;
	cost_beets = price_beets * lb_beets;
	cost_carrots = price_carrots * lb_carrots;
	cost_total = cost_artichokes + cost_beets + cost_carrots;
	lb_total = lb_artichokes + lb_beets + lb_carrots;
	if (lb_total <= 0)
		shipping = 0.0;
	else if (lb_total < 5.0)
		shipping = under5;
	else if (lb_total < 20)
		shipping = under20;
	else
		shipping = base20 + extralb * lb_total;
	if (cost_total > 100.0)
		discount = DISCOUNT_RATE * cost_total;
	else
		discount = 0.0;
	final_total = cost_total + shipping - discount;
	printf("Ваш заказ:\n");
	printf("%.2f фунтов артишоков по $%.2f за фунт: $%.2f\n",
			lb_artichokes, price_artichokes, cost_artichokes);
	printf("%.2f фунтов свеклы по $%.2f за фунт: $%.2f\n",
			lb_beets, price_beets, cost_beets);
	printf("%.2f фунтов моркови по $%.2f за фунт: $%.2f\n",
			lb_carrots, price_carrots, cost_carrots);
	printf("Суммарная стоимость овощей: $%.2f\n", cost_total);
	if (cost_total > 100)
		printf("Скидка: $%.2f\n", discount);
	printf("Доставка: $%.2f\n", shipping);
	printf("Общие расходы: $%.2f\n", final_total);

	return 0;
}
