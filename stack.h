
#ifndef STACK_H
#define STACK_H

#include <stdint.h>

typedef struct Stack{

    struct Element *top;
    int size;
    int capacity;

} Stack;


typedef struct Element
{
    struct Stack *pParentStack;
    struct Element *bottomE;
    int value;
    int index;             // Position dans la pile (0 = sommet)

} Element;


Stack* createStack(uint32_t argCapacity); /*0 is the default value*/
void deleteStack(Stack *stack);

void push(Stack *stack, int value);
void pop(Stack *stack);
void prStackSize(Stack *stack);

void stackFirstElement(Stack *stack);
int searchIndex(Stack *stack, int value);




#endif


