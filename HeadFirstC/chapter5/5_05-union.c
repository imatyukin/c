#include <stdio.h>

typedef union {
	float lemon;
	int lime_pieces;
} lemon_lime;

typedef struct {
	float tequila;
	float cointreau;
	lemon_lime citrus;
} margarita;

int main ()
{
	margarita m = {2.0, 1.0, {2}};
	printf("%2.1f measures of tequila\n%2.1f measures of cointreau\n%2.1f measures of juice\n", m.tequila, m.cointreau, m.citrus.lemon);
	/* 	2.0 measures of tequila
		1.0 measures of cointreau
		2.0 measures of juice */

	margarita m1 = {2.0, 1.0, {0.5}};
	printf("%2.1f measures of tequila\n%2.1f measures of cointreau\n%2.1f measures of juice\n", m1.tequila, m1.cointreau, m1.citrus.lemon);
	/*	2.0 measures of tequila
		1.0 measures of cointreau
		0.5 measures of juice */

	margarita m2 = {2.0, 1.0, {.lime_pieces=1}};
	printf("%2.1f measures of tequila\n%2.1f measures of cointreau\n%i pieces of lime\n", m2.tequila, m2.cointreau, m2.citrus.lime_pieces);
	/*	2.0 measures of tequila
		1.0 measures of cointreau
		1 pieces of lime */
}
