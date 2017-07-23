#include <stdio.h>

void fortune_cookie(char *msg)
{
	printf("Сообщение гласит: %s\n", msg);
	printf("Строка msg хранится по адресу: %p\n", msg);
	printf("msg занимает %lu байтов\n", sizeof(msg));
}

int main()
{
	printf("%lu\n", sizeof(int));
	printf("%lu\n", sizeof("Черепахи!"));

	char quote[] = "Печенье вас полнит";
	fortune_cookie(quote);
	printf("Строка quote хранится по адресу: %p\n", quote);

	printf("\n================================ RESTART ================================\n\n");

	char s[] = "Насколько он большой?";
	char *t = s;
	printf("%lu\n", sizeof(s));
	printf("%lu\n", sizeof(t));
	printf("s хранится по адресу %p\n", &s);
	printf("t хранится по адресу %p\n", &t);

	return 0;

}
