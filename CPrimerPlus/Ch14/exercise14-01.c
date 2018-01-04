// Chapter 14 Exercise 1
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct month {
    char name[16];
    char abbrev[6];
    int days;
    int monumb;
};

const struct month months[12] = {
        {"Январь", "Янв", 31, 1},
        {"Февраль", "Фев", 28, 2},
        {"Март", "Мар", 31, 3},
        {"Апрель", "Апр", 30, 4},
        {"Май", "Май", 31, 5},
        {"Июнь", "Июн", 30, 6},
        {"Июль", "Июл", 31, 7},
        {"Август", "Авг", 31, 8},
        {"Сентябрь", "Сен", 30, 9},
        {"Октябрь", "Окт", 31, 10},
        {"Ноябрь", "Ноя", 30, 11},
        {"Декабрь", "Дек", 31, 12}
};

int days(char * m);

int main(void)
{
    char input[20];
    int daytotal;

    printf("Введите название месяца: ");
    while (scanf("%s", input) == 1 && input[0] != 'q')
    {
        daytotal = days(input);
        if (daytotal > 0)
            printf("С начала года прошло %d дней, включая %s.\n", daytotal, input);
        else
            printf("%s не является допустимым вводом.\n", input);
        printf("Введите следующее название месяца (или q для завершения): ");
    }
    puts("Программа завершена.");

    return 0;
}

int days(char * m)
{
    int total = 0;
    int mon_num = 0;
    int i;
    m[0] = toupper(m[0]);

    for (i = 1; m[i] != '\0'; i++)
        m[i] = tolower(m[i]);
    for (i = 0; i < 12; i++)
        if (strcmp(m, months[i].name) == 0)
        {
            mon_num = months[i].monumb;
            break;
        }
    if (mon_num == 0)
        total = -1;
    else
        for (i = 0; i < mon_num; i++)
            total +=months[i].days;

    return total;
}
