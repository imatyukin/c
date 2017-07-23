// Chapter 8 Exercise 5
#include <stdio.h>

void flush_input_buffer(void);

int main (void)
{
	int response;
	int guess = 50;
	int low = 1;
	int high = 100;

	printf("Выберите целое число в интервале от 1 до 100. Я попробую угадать его.");
	printf("\nНажмите клавишу 'y', если моя догадка верна или '>', если число больше задуманного или '<', если меньше.");
	printf("\nВашим числом является %d?\n", guess);

	do
	{
		response = getchar();

		if(response == 'y')
			break;
		if(response == '<')
		{
			high = guess;
			guess = low + ((high - low) / 2);
			printf("Ладно, тогда это %d?\n", guess);
			flush_input_buffer();
			continue;
		}
		else if(response == '>')
		{
			low = guess;
			guess = high - ((high - low) / 2);
			printf("Ладно, тогда это %d?\n", guess);
			flush_input_buffer();
			continue;
		}
		else
		{
			printf("Неправильный ответ. Попробуйте снова.\n");
			flush_input_buffer();
			continue;
		}
	}while(response != 'y');

	printf("Я знал, что у меня получится!\n");

	return 0;
}

void flush_input_buffer(void)
{
	while (getchar() != '\n')
		;
}
