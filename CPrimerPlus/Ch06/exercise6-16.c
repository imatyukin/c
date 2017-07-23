/* exercise6-16.c */
#include <stdio.h>
#include <math.h>

#define principal 100
#define simple_rate 10
#define compound_rate 5

struct result {
	float Simple;
	float Compound;
};

struct result interest(float p, float sr, float cr, int t) {
	struct result Interest;
	Interest.Simple = (p * t * sr) / 100;
	Interest.Compound = p*(pow((1 + cr/100), t) - 1);
	return Interest;
}

int main(void)
{
	struct result Interest;
	int time_period;

	for (time_period = 1; Interest.Simple > Interest.Compound; time_period++)
	{
		Interest = interest(principal, simple_rate, compound_rate, time_period);
		printf("Год %d:", time_period);
		printf("\nПростые проценты по вкладу Дафны: $%f\tСложные проценты по вкладу Дейдры: $%f\n", Interest.Simple, Interest.Compound);
	}
	printf("\nНа конец периода в %d лет: размер вклада Дафны - $%f, размер вклада Дейдры - $%f.", time_period - 1, Interest.Simple + principal, Interest.Compound + principal);

	return 0;
}
