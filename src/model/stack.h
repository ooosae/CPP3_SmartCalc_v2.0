#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

namespace s21 {
class Stack {
 public:
  char data;
  double value;
  Stack *prev;
};

void pop(Stack **stack, char *symb, double *num);
void push(Stack **stack, char symb, double num);
void reverseStack(Stack *oldStack, Stack **newStack);
void destroyStack(Stack *st);
}  // namespace s21

#endif  // STACK_H
