#include <stdio.h>

void go_south_east(int *lat, int *lon)
{
	*lat = *lat - 1;
	*lon = *lon + 1;
}

void skip(char *msg)
{
	puts(msg + 3);
}

int main()
{

	int x = 4;
	printf("x равен %i\n", x);
	printf("x хранится по адресу %p\n", &x);
	int *address_of_x = &x;
	int value_stored = *address_of_x;
	printf("value_stored равен %i\n", value_stored);
	printf("value_stored хранится по адресу %p\n", &value_stored);
	*address_of_x = 99;
	printf("x равен %i\n", x);
	printf("value_stored равен %i\n", value_stored);

	int latitude = 32;
	int longitude = -64;
	go_south_east(&latitude, &longitude);
	printf("Стоп! Теперь наши координаты: [%i, %i]\n", latitude, longitude);

	printf("\n================================ RESTART ================================\n\n");

	int contestants[] = {1, 2, 3};
	int *choice = contestants;
	contestants[0] = 2;
	contestants[1] = contestants[2];
	contestants[2] = *choice;
	printf("Я собираюсь выбрать претендента номер %i\n", contestants[2]);

	printf("\n================================ RESTART ================================\n\n");

	int doses[] = {1, 3, 2, 1000};
	printf("Отпущенная доза %i", 3[doses]);

	printf("\n\n================================ RESTART ================================\n\n");

	int drinks[] = {4, 2, 3};
	printf("1-й заказ: %i напитка\n", drinks[0]);
	printf("1-й заказ: %i напитка\n", *drinks);
	printf("3-й заказ: %i напитка\n", drinks[2]);
	printf("3-й заказ: %i напитка\n", *(drinks + 2));

	printf("\n================================ RESTART ================================\n\n");

	char *msg_from_amy = "Не звони мне";
	skip(msg_from_amy);

	printf("\n================================ RESTART ================================\n\n");

	int nums[] = {1, 2, 3};
	printf("nums находится по адресу %p\n", nums);
	printf("nums + 1 находится по адресу %p\n", nums + 1);

	return 0;

}
