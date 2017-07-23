/* swap3.c -- использование указателей для обмена значениями переменных */
#include <stdio.h>

void interchange(int * u, int * v);

int main(void)
{
	int x = 5, y = 10;

	printf("Первоначально x = %d и y = %d.\n", x, y);
	interchange(&x, &y);	// передача адресов в функцию
	printf("Теперь x = %d и y = %d.\n", x, y);

	return 0;
}

void interchange(int * u, int * v)
{
	int temp;

	temp = *u;				// temp получает значение, на которое указывает u
	*u = *v;
	*v = temp;
}
