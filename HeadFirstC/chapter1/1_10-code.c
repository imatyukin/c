#include <stdio.h>

int main()

// A. The program displays “Дешёвая карта”
/* {
	int card = 1;
	if (card > 1)
		card = card - 1;
	if (card < 7)
		puts("Дешёвая карта");
	else {
		puts("Туз!");
	}
	return 0;
} */

// B. The program displays nothing
/* {
	int card = 1;
	if (card > 1) {
		card = card - 1;
		if (card < 7)
			puts("Дешёвая карта");
		else
			puts("Туз!");
	}
	return 0;
} */

// C. The program displays "Туз!"
/* {
	int card = 1;
	if (card > 1) {
		card = card - 1;
		if (card < 7)
			puts("Дешёвая карта");
	} else
		puts("Туз!");
	return 0;
} */

// 00 11 21 32 42
/* {
	int x = 0;
	int y = 0;
	while (x < 5) {
		y = x - y;
		printf("%i%i ", x, y);
		x = x + 1;
	}
	return 0;
} */

// 00 11 23 36 410
/* {
	int x = 0;
	int y = 0;
	while (x < 5) {
		y = y + x;
		printf("%i%i ", x, y);
		x = x + 1;
	}
	return 0;
} */

// 02 14 25 36 47
/* {
	int x = 0;
	int y = 0;
	while (x < 5) {
		y = y + 2;
		if (y > 4)
			y = y - 1;
		printf("%i%i ", x, y);
		x = x + 1;
	}
	return 0;
} */

// 11 34 59
/* {
	int x = 0;
	int y = 0;
	while (x < 5) {
		x = x + 1;
		y = y + x;
		printf("%i%i ", x, y);
		x = x + 1;
	}
	return 0;
} */

// 02 14 36 48
{
	int x = 0;
	int y = 0;
	while (x < 5) {
		if (y < 5) {
			x = x + 1;
			if (y < 3)
				x = x - 1;
		}
		y = y + 2;
		printf("%i%i ", x, y);
		x = x + 1;
	}
	return 0;
}
