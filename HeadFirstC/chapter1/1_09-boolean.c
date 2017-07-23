#include <stdio.h>
#include <stdlib.h>

int main()
{
	char card_name[3];
	puts("Введите название карты: ");
	scanf("%2s", card_name);
	int val=0;
	if (card_name[0] == 'K') {
		val = 10;
	} else if (card_name[0] == 'Q') {
		val = 10;
	} else if (card_name[0] == 'J') {
		val = 10;
	} else if (card_name[0] == 'A') {
		val = 11;
	} else {
		val = atoi(card_name);
	}
	/* Проверяем, находится ли значение между 3 и 6 */
	if ((val > 2) && (val < 7)) {
		puts("Счётчик увеличился");
	/* В противном случае проверяем, была ли эта карта 10, J (валетом), Q (дамой) или K (королём) */
	} else if (val == 10) {
		puts("Счётчик уменьшился");
	};
	return 0;
}
