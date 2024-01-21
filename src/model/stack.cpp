#include "stack.h"

namespace s21 {
void push(Stack **stack, char symb, double num) {
  Stack *temp = static_cast<Stack *>(malloc(sizeof(Stack)));
  temp->data = symb;
  temp->value = num;
  temp->prev = *stack;
  *stack = temp;
}

void pop(Stack **stack, char *symb, double *num) {
  Stack *temp = (*stack)->prev;
  *symb = (*stack)->data;
  *num = (*stack)->value;
  free(*stack);
  *stack = temp;
}

void reverseStack(Stack *oldStack, Stack **newStack) {
  Stack *temp = oldStack;
  while (temp != nullptr) {
    push(newStack, temp->data, temp->value);
    temp = temp->prev;
  }
}

void deleteElement(Stack *elem) {
  Stack *tmp = elem->prev;
  free(elem);
  if (tmp) deleteElement(tmp);
}

void destroyStack(Stack *st) {
  if (!st) return;
  if (st->prev) deleteElement(st->prev);
  free(st);
}
}  // namespace s21
