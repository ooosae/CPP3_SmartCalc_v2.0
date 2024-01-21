#include "controller.h"

namespace s21 {
int controller::solveExpression(char *expression, double x, double *answer) {
  int returnCode = EXIT_SUCCESS;
  s21::Stack *stack = nullptr;
  returnCode = model_.Pars(expression, &stack);
  if (!returnCode) {
    s21::Stack *reversedStack = nullptr;
    s21::reverseStack(stack, &reversedStack);
    returnCode = model_.Calc(reversedStack, x, answer);
    s21::destroyStack(reversedStack);
  }
  s21::destroyStack(stack);
  return returnCode;
}

int controller::getGraph(char *expression, double l, double r, double step,
                         double coordinates[][2]) {
  if (l >= r) return EXIT_EDGES_ERROR;
  int returnCode = EXIT_SUCCESS;
  s21::Stack *stack = nullptr;
  returnCode = model_.Pars(expression, &stack);
  if (!returnCode) {
    s21::Stack *reversedStack = nullptr;
    s21::reverseStack(stack, &reversedStack);
    model_.Draw(reversedStack, l, r, step, coordinates);
    s21::destroyStack(reversedStack);
  }
  s21::destroyStack(stack);
  return returnCode;
}
}  // namespace s21
