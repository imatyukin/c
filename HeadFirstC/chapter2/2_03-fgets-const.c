#include <stdio.h>

int main ()
{
	char name[40];
	printf("Введите ваше имя: ");
	scanf("%39s", name);

	int age;
	printf("Введите ваш возраст: ");
	scanf("%i", &age);

	char first_name[20];
	char last_name[20];
	printf("Введите имя и фамилию: ");
	scanf("%19s %19s", first_name, last_name);
	printf("Имя: %s Фамилия: %s\n", first_name, last_name);

	char food[5];
	printf("Введите любимую еду: ");
	fgets(food, sizeof(food), stdin);

	printf("Введите любимую еду: ");
	fgets(food, 5, stdin);

	char cards[] = "JQK";
	char a_card = cards[2];
	puts(cards);
	cards[2] = cards[1];
	puts(cards);
	cards[1] = cards[0];
	puts(cards);
	cards[0] = cards[2];
	puts(cards);
	cards[2] = cards[1];
	puts(cards);
	cards[1] = a_card;
	puts(cards);

	const char *s = "Какая-то строка";
	puts(s);

	char masked_raider[] = "Alive";
	char *jimmy = masked_raider;
	printf("Грабитель в маске сейчас %s Джимми сейчас %s\n", masked_raider, jimmy);
	masked_raider[0] = 'D';
	masked_raider[1] = 'E';
	masked_raider[2] = 'A';
	masked_raider[3] = 'D';
	masked_raider[4] = '!';
	printf("Грабитель в маске сейчас %s Джимми сейчас %s\n", masked_raider, jimmy);

	return 0;
}
