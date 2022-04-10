#include "stack.h"
#define FALSE 0
#define TRUE 1
void ST_init(Stack* s) {
    s->top = -1;
}

int ST_empty(Stack s) {
    return s.top == -1;
}



int ST_full(Stack s) {
    return s.top == (STACK_SIZE - 1);
}

int ST_push(Stack* s, elem x) {
    if (ST_full(*s))
        return FALSE;
    else {
        (s->top)++;
        s->array[s->top] = x;
    }
    return TRUE;
}

int ST_pop(Stack* s, elem* x) {
    if (ST_empty(*s)) {
        return FALSE;
    }
    else {
        *x = s->array[s->top];
        s->top--;
    }

    return TRUE;
}

void ST_print(Stack* s) {
    int tmp_top = s->top;
    for (tmp_top; tmp_top > -1; tmp_top--) {
        std::cout << s->array[tmp_top] << " ";
    }
    std::cout << std::endl;
}



