// exercise4-05.c
#include <stdio.h>

int main(void)
{
	float mbit_per_sec, mbyte, bits_per_sec, bits, sec;

	printf("Введите скорость загрузки в мегабитах в секунду: ");
	scanf("%f", &mbit_per_sec);
	printf("Введите размер файла в мегабайтах: ");
	scanf("%f", &mbyte);
	bits_per_sec = mbit_per_sec * 1024 * 1024;
	bits = mbyte * 1024 * 1024 * 8;
	sec = bits / bits_per_sec;
	printf("При скорости загрузки %.2f мегабит в секунду файл размером %.2f мегабайт "
			"загружается за %.2f секунд(ы).\n", mbit_per_sec, mbyte, sec);

	return 0;
}
