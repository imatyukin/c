// Exercise 3-2.
// Write a program that prompts the user to enter the date as three integer values for the month, the day in the month,
// and the year. The program should then output the date in the form 31st December 2003 when the user enters 12 31 2003,
// for example.
// You will need to work out when th, nd, st, and rd need to be appended to the day value. Don’t forget 1st, 2nd, 3rd,
// 4th; but 11th, 12th, 13th, 14th; and 21st, 22nd, 23rd, and 24th.
#include <stdio.h>

int main(void)
{
    unsigned int month, day, year = 0;

    printf("Enter the date as three integer values for the month, the day in the month, and the year.\n");
    printf("(e.g. 12 31 2003)> ");
    scanf("%d %d %d", &month, &day, &year);

    if(month < 1 || month > 12 || day < 1 || day > 31) {
        printf("\n\aIllegal date!\n");
        return 1;
    }

    switch(day) {
        case 1: case 21: case 31:
            printf("%dst", day);
            break;
        case 2: case 22:
            printf("%dnd", day);
            break;
        case 3: case 23:
            printf("%drd", day);
            break;
        default:
            printf("%dth", day);
            break;
    }

    switch(month) {
        case 1:  printf(" January ");   break;
        case 2:  printf(" February ");  break;
        case 3:  printf(" March ");     break;
        case 4:  printf(" April ");     break;
        case 5:  printf(" May ");       break;
        case 6:  printf(" June ");      break;
        case 7:  printf(" July ");      break;
        case 8:  printf(" August ");    break;
        case 9:  printf(" September "); break;
        case 10: printf(" October ");   break;
        case 11: printf(" November ");  break;
        case 12: printf(" December ");  break;
    }

    printf("%d\n", year);

    return 0;
}
