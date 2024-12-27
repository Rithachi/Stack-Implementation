
/*Projet réussi avec perfection*/

#include <stdio.h>

#include "stack.c"


int main(void){

    Stack *stack = createStack(1);
    push(stack, 6);
    stackFirstElement(stack);
    pop(stack);
    pop(stack);
    stackFirstElement(stack);
    push(stack, 2);
    push(stack, 3);
    stackFirstElement(stack);
    pop(stack);
    stackFirstElement(stack);
    deleteStack(stack);
    Stack *stack2 = createStack(0);
    push(stack2, 1);push(stack2, 2);push(stack2, 9);push(stack2, 6);push(stack2, 7);
    printf("%d\n", searchIndex(stack2, 2));
    prStackSize(stack2);


    return 0;
}