


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


#include "stack.h"



Stack* createStack(uint32_t argCapacity) /*0 is the default value -> undefined capacity*/
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    if (stack==NULL) return NULL; /*Pas de else, on exit la fonction de toute facon*/
    stack->size = 0;
    stack->top = NULL;

    if (argCapacity==0){

        stack->capacity = 0;

    } else {
        stack->capacity = argCapacity;
    }

    return stack;
} 


void deleteStack(Stack *stack){

    if(stack == NULL) return;
    
    while(stack->size > 0) {
        pop(stack);
    }
    free(stack);
}

void push(Stack *stack, int value){


    if (!(stack->size>=stack->capacity) || stack->capacity==0){

        Element *newE = (Element*)malloc(sizeof(Element));
        if(newE!=NULL){
            newE->value = value;
            newE->index = 0;
        } else {return;}


        if(stack->top==NULL){ // If it is the first element
            stack->top = newE;
            stack->top->bottomE = NULL;
            stack->size++;

        } else {
            stack->top->index++;
            newE->bottomE = stack->top;
            
            stack->top = newE;
            stack->size++;
        }
        
    } else {
        fprintf(stderr, "push error : Stack size exceeded\n");
    }

}

void pop(Stack *stack){

    if(stack==NULL) {fprintf(stderr, "Stack Error");return;}

    if (stack->size!=0 && stack->top!=NULL){

        // Get the old top
        Element *old = stack->top;
        // Save the new top
        Element *newTop = old->bottomE;

        stack->top = newTop;

        free(old);
        stack->size--;
        if (stack->size==0){
            stack->top = NULL;
        }

    } else {
        printf("pop error : La stack est vide !\n");
    }


}

  void stackFirstElement(Stack *stack){
    // security verifications
    if (stack == NULL) {
        fprintf(stderr, "SFE Erreur : La pile est NULL\n");
        return;
    }
    
    if (stack->top == NULL) {
        fprintf(stderr, "SFE Erreur : La pile est vide\n");
        return;
    }

    printf("%d\n", stack->top->value);
}

void prStackSize(Stack *stack){
    if(stack==NULL) return;
    printf("La taille de la stack est : %d", stack->size);
}


int searchIndex(Stack *stack, int value){
    
    if(stack==NULL || stack->top==NULL) return -1;
    Stack *temp = createStack(stack->capacity); // temp
    int t = stack->size;
    int found = -1;
    for(int i = 0;i<t;i++){
        if(stack->top->value==value){
            found = i;
            break;
        }
        else {
            push(temp, stack->top->value);
            pop(stack);
        }
    }
    while(temp->size>0){
        push(stack, temp->top->value);
        pop(temp);
    }
    deleteStack(temp);
    if(found==-1) printf("Element not found");
    return found;
}

