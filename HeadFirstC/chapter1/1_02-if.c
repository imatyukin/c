#include <stdio.h>

int main () {

   int card_count = 11;

   if(card_count > 10) {
      printf("Карты в колоде удачные. Повышаем ставку.\n" );
   }

   printf("Значение card_count: %d\n", card_count);

   return 0;
}
