#pragma once
#include <iostream>
#define STACK_SIZE 10
typedef int elem;
#define FALSE 0
#define TRUE 1
struct Stack {
    elem array[STACK_SIZE];
    int top;
};


void ST_init(Stack* s);
int ST_empty(Stack s);
int ST_full(Stack s);
int ST_push(Stack* s, elem x);
int ST_pop(Stack* s, elem* x);
void ST_print(Stack* s);


