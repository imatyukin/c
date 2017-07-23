#include <stdio.h>

int main () {

   int c = 10;
   int counter = 1;

   while(c > 0) {
	   printf("Я не должен писать код в виде классов. Значение c: %d\n", c);
	   c = c - 1;
   }


   while (counter < 11) {
	   printf("%i бутылок висело на стене\n", counter);
	   counter++;
   }


   return 0;
}
