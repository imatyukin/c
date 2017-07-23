/* exercise6-17.c */
#include <stdio.h>

int main(void)
{
	const float PRIZE = 1000000.0f;
	const float BET = 0.08f;
	const float WITHDRAW = 100000.0f;

	int time_period = 1;
	float interest;
	float account_balance = PRIZE;

	while (account_balance > 0)
	{
		interest = account_balance * BET;
		account_balance += interest;
		account_balance -= WITHDRAW;
		printf("Год: %d; остаток на счёте: %.2f USD\n", time_period, account_balance);
		time_period++;
	}

	printf("На %d год, у Чака Лаки на счету будет %.2f USD.\n", time_period - 1, account_balance);

	return 0;
}
