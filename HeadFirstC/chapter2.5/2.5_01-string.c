#include <stdio.h>
#include <string.h>

char tracks[][80] = {
		"I left my heart in Harvard Med School",
		"Newark, Newark - a wonderful town",
		"Dancing with a Dork",
		"From here to maternity",
		"The girl from Iwo Jima",
};

void find_track(char search_for[])
{
	int i;
	for (i = 0; i < 5; i++) {
		if (strstr(tracks[i], search_for))
			printf("Track %i: '%s'\n", i, tracks[i]);
	}
}

void print_reverse(char *s)
{
	size_t len = strlen(s);
	char *t = s + len - 1;
	while (t >= s) {
		printf("%c", *t);
		t = t - 1;
	}
	puts("");
}

int main()
{
	puts(tracks[4]);

	char s0[] = "дисфункция";
	char s1[] = "фун";
	if (strstr(s0, s1))
	puts("Я нашёл фун в дисфункции!");

	printf("\n================================ RESTART ================================\n\n");

	char search_for[80];
	printf("Искать: ");
	fgets(search_for, 80, stdin);
	search_for[strlen(search_for) - 1] = '\0';
	find_track(search_for);

	printf("\n================================ RESTART ================================\n\n");

	print_reverse(tracks[1]);	// nwot lufrednow a - kraweN ,kraweN

	printf("\n================================ RESTART ================================\n\n");

	char *names_for_dog[] = {"Бобик", "Рекс", "Джим"};
	puts(names_for_dog[1]);	// Рекс

	printf("\n================================ RESTART ================================\n\n");

	char *juices[] = {
			"dragonfruit", "waterberry", "sharonfruit", "uglifruit",
			"rumberry", "kiwifruit", "mulberry", "strawberry",
			"blueberry", "blackberry", "starfruit"
	};

	char *a;

	puts(juices[6]);	// mulberry

	print_reverse(juices[7]);	// yrrebwarts
	a = juices[2];
	juices[2] = juices[8];
	juices[8] = a;

	puts(juices[8]);	// sharonfruit

	print_reverse(juices[(18 + 7) / 5]);	// tiurfiwik

	puts(juices[2]);	// blueberry

	print_reverse(juices[9]);	// yrrebkcalb
	juices[1] = juices[3];

	puts(juices[10]);	// starfruit

	print_reverse(juices[1]);	// tiurfilgu

	return 0;
}
