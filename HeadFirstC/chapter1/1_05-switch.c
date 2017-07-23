#include <stdio.h>

int main () {

	char suit = 'H';
	int train = 65;
	int winnings = 0;
//	char card_name = 'Q';
//	int val = 0;

	switch(suit) {
	case 'C':
		puts("Clubs (Трефы)\n");
		break;
	case 'D':
		puts("Diamonds (Бубны)\n");
		break;
	case 'H':
		puts("Hearts (Черви)\n");
		break;
	default:
		puts("Spades (Пики)\n");
	}

	printf("Твоя масть %c\n", suit);


	switch(train) {
	case 37:
		winnings = winnings + 50;
		break;
	case 65:
		puts("Джекпот!");
		winnings = winnings + 80;
		break;
	case 12:
		winnings = winnings + 20;
		break;
	default:
		winnings = 0;
	}

	printf("Выигрыш равен %i\n", winnings);


/*	switch(card_name) {
	case 'K':
	case 'Q':
	case 'J':
		val = 10;
		break;
	case 'A':
		val = 11;
		break;
	default:
		val = atoi(card_name);
	}

	printf("Ценность карты %i\n", val);
*/

	return 0;
}
