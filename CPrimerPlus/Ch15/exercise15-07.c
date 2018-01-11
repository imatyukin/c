// Chapter 15 Exercise 7
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ID_MASK 0xFF
#define SIZE_MASK 0x7F00
#define LEFT 0x00000
#define CENTER 0x08000
#define RIGHT 0x10000
#define ALIGN_MASK 0x18000
#define REGULAR 0x00000
#define BOLD 0x20000
#define ITALIC 0x40000
#define UNDERLINE 0x80000
#define STYLE_MASK 0xE0000
#define SIZE_SHIFT 8

typedef unsigned long font;

char do_menu(font * f);
char get_choice(const char *);
void show_menu(void);
void show_font(font f);
void eatline(void);
void get_id(font * f);
void get_size(font * f);
void get_align(font * f);

int main(void)
{
    font sample = 1 | (12 <<SIZE_SHIFT) | LEFT | ITALIC;
    while (do_menu(&sample) != 'q')
        continue;
    puts("Программа завершена.");

    return 0;
}

char do_menu(font * f)
{
    char response;
    show_font(*f);
    show_menu();
    response = get_choice("fsabiuq");

    switch(response)
    {
        case 'f' : get_id(f); break;
        case 's' : get_size(f); break;
        case 'a' : get_align(f); break;
        case 'b' : *f ^= BOLD; break;
        case 'i' : *f ^= ITALIC; break;
        case 'u' : *f ^= UNDERLINE; break;
        case 'q' : break;
        default : fprintf(stderr, "проблема с меню\n");
    }

    return response;
}

char get_choice(const char * str)
{
    char ch;
    ch = getchar();
    ch = tolower(ch);
    eatline();

    while (strchr(str, ch) == NULL)
    {
        printf("Введите один из следующих вариантов: %s\n", str);
        ch = tolower(getchar());
        eatline();
    }

    return ch;
}

void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

void show_menu(void)
{
    puts("f) изменить шрифт s) изменить размер a) изменить выравнивание");
    puts("b) переключить полужирный i) переключить курсив u) переключить подчеркнутый");
    puts("q) завершить");
}

void show_font(font f)
{
    printf("\n%4s %6s %12s %5s %5s %5s\n",
           "ИД", "РАЗМЕР", "ВЫРАВНИВАНИЕ", "Ж", "К", "П");
    printf("%4lu %4lu", f & ID_MASK, (f & SIZE_MASK) >> SIZE_SHIFT);
    switch(f & ALIGN_MASK)
    {
        case LEFT : printf("%10s", "влево"); break;
        case RIGHT : printf("%10s", "вправо"); break;
        case CENTER : printf("%10s", "по центру"); break;
        default : printf("%10s", "неизвестно"); break;
    }
    printf("%8s %5s %5s\n\n", (f & BOLD) == BOLD? "вкл." : "откл.",
           (f & ITALIC) == ITALIC ? "вкл." : "откл.",
           (f & UNDERLINE) == UNDERLINE ? "вкл." : "откл.");
}

void get_id(font * f)
{
    int id;

    printf("Введите идентификатор шрифта (0-255): ");
    scanf("%d", &id);
    id = id & ID_MASK;
    *f |= id;
    eatline();
}

void get_size(font * f)
{
    int size;

    printf("Введите размер шрифта (0-127): ");
    scanf("%d", &size);
    *f |= (size << SIZE_SHIFT) & SIZE_MASK;
    eatline();
}

void get_align(font * f)
{
    puts("Выберите выравнивание:");
    puts("l) влево c) по центру r) вправо");
    switch (get_choice("lcr"))
    {
        case 'l' : *f &= ~ALIGN_MASK; *f |= LEFT; break;
        case 'c' : *f &= ~ALIGN_MASK; *f |= CENTER; break;
        case 'r' : *f &= ~ALIGN_MASK; *f |= RIGHT; break;
        default : fprintf(stderr, "проблема с выравниванием\n");
    }
}
