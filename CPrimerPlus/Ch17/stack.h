/* stack.h -- заголовочный файл для типа stack */
#ifndef STACK_H_
#define STACK_H_
#include <stdbool.h> /* C99 */

/* enum bool {false, true}; */ /* до выхода C99*/
/* ПОМЕСТИТЕ СЮДА ОПРЕДЕЛЕНИЕ ТИПА ЭЛЕМЕНТА */
/* НАПРИМЕР, typedef int Item; */
typedef char Item;

#define MAXSTACK 100

typedef struct stack
{
    Item items[MAXSTACK]; /* содержит сведения о стеке */
    int top; /* индекс первой пустой ячейки */
} Stack;

/* операция: инициализация стека */
/* предусловие: ps указывает на стек */
/* постусловие: стек инициализирован пустым значением */
void InitializeStack(Stack * ps);

/* операция: проверяет, является ли стек полным */
/* предусловие: ps указывает на ранее инициализированный стек */
/* постусловие: возвращает значение true, если стек полон, */
/* иначе возвращает значение false */
bool FullStack(const Stack * ps);

/* операция: проверяет, является ли стек пустым */
/* предусловие: ps указывает на ранее инициализированный стек */
/* постусловие: возвращает значение true, если стек пуст, */
/* иначе возвращает значение false */
bool EmptyStack(const Stack *ps);

/* операция: заталкивает элемент в стек */
/* предусловие: ps указывает на ранее инициализированный стек */
/* элемент должен помещаться */
/* в верхушку стека */
/* постусловие: если стек не полон, элемент помещается */
/* в верхушку стека и функция возвращает */
/* значение true; иначе стек остается */
/* неизменным, а функция возвращает */
/* значение false */
bool Push(Item item, Stack * ps);

/* операция: удаляет элемент из верхушки стека */
/* предусловие: ps указывает на ранее инициализированный стек */
/* постусловие: если стек не пуст, элемент в верхушке */
/* стека копируется в *pitem и удаляется */
/* из стека, а функция возвращает */
/* значение true; если операция */
/* опустошает стек, стек */
/* переустанавливается в пустое состояние. */
/* Если стек пуст с самого начала, он */
/* остается неизменным, а функция */
/* возвращает значение false */
bool Pop(Item *pitem, Stack * ps);

#endif