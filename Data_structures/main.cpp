/*Author: Andreas Andreou
Basic ímplementation of a stack*/
#include "stack.h"
#include <iostream>

int main() {
    Stack s;
    ST_init(&s);
    elem x[] = { 10,20,30,40,50 };
    elem returned = 0;
    std::cout << ST_push(&s, x[0]) << std::endl;
    std::cout << ST_push(&s, x[1]) << std::endl;
    std::cout << ST_push(&s, x[2]) << std::endl;
    std::cout << ST_pop(&s, &returned) << std::endl;
    //std::cout << ST_pop(&s, &returned) << std::endl;
    //std::cout << ST_pop(&s, &returned) << std::endl;
    // std::cout << ST_pop(&s, &returned) << std::endl;
    ST_print(&s);
    //std::cout<< <<std::endl;
    //std::cout<< <<std::endl;
}