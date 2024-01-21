#include "expressionCalculation.h"

int calc(s21::Stack *stack, double x, double *answer) {
  char symb;
  double num;
  s21::Stack *ptr = stack;
  s21::Stack *tempStack = NULL;
  int rc = EXIT_SUCCESS;
  while (ptr != NULL) {
    num = ptr->value;
    symb = ptr->data;
    switch (symb) {
      case '+': {
        double num1, num2;
        char symb1, symb2;

        if (!tempStack) {
          rc = EXIT_EXPR_PARSING_ERROR;
          ptr = NULL;
          break;
        }
        s21::pop(&tempStack, &symb1, &num1);
        if (!tempStack) {
          rc = EXIT_EXPR_PARSING_ERROR;
          ptr = NULL;
          break;
        }
        s21::pop(&tempStack, &symb2, &num2);
        s21::push(&tempStack, 'd', num1 + num2);
        break;
      }
      case '-': {
        double num1, num2;
        char symb1, symb2;
        if (!tempStack) {
          rc = EXIT_EXPR_PARSING_ERROR;
          ptr = NULL;
          break;
        }
        s21::pop(&tempStack, &symb1, &num1);
        if (!tempStack) {
          rc = EXIT_EXPR_PARSING_ERROR;
          ptr = NULL;
          break;
        }
        s21::pop(&tempStack, &symb2, &num2);
        s21::push(&tempStack, 'd', num2 - num1);
        break;
      }
      case '_': {
        double num1;
        char symb1;
        if (!tempStack) {
          rc = EXIT_EXPR_PARSING_ERROR;
          ptr = NULL;
          break;
        }
        s21::pop(&tempStack, &symb1, &num1);
        s21::push(&tempStack, 'd', -num1);
        break;
      }
      case '&': {
        double num1;
        char symb1;
        if (!tempStack) {
          rc = EXIT_EXPR_PARSING_ERROR;
          ptr = NULL;
          break;
        }
        s21::pop(&tempStack, &symb1, &num1);
        s21::push(&tempStack, 'd', +num1);
        break;
      }
      case '*': {
        double num1, num2;
        char symb1, symb2;
        if (!tempStack) {
          rc = EXIT_EXPR_PARSING_ERROR;
          ptr = NULL;
          break;
        }
        s21::pop(&tempStack, &symb1, &num1);
        if (!tempStack) {
          rc = EXIT_EXPR_PARSING_ERROR;
          ptr = NULL;
          break;
        }
        s21::pop(&tempStack, &symb2, &num2);
        s21::push(&tempStack, 'd', num1 * num2);
        break;
      }
      case '^': {
        double num1, num2;
        char symb1, symb2;
        if (!tempStack) {
          rc = EXIT_EXPR_PARSING_ERROR;
          ptr = NULL;
          break;
        }
        s21::pop(&tempStack, &symb1, &num1);
        if (!tempStack) {
          rc = EXIT_EXPR_PARSING_ERROR;
          ptr = NULL;
          break;
        }
        s21::pop(&tempStack, &symb2, &num2);
        if (fabs(num2) < eps && num1 < 0) {
          rc = EXIT_POW_ZERO_NEG_EXP_ERROR;
          ptr = NULL;
          break;
        }
        s21::push(&tempStack, 'd', pow(num2, num1));
        break;
      }
      case '/': {
        double num1, num2;
        char symb1, symb2;
        if (!tempStack) {
          rc = EXIT_EXPR_PARSING_ERROR;
          ptr = NULL;
          break;
        }
        s21::pop(&tempStack, &symb1, &num1);
        if (!tempStack) {
          rc = EXIT_EXPR_PARSING_ERROR;
          ptr = NULL;
          break;
        }
        s21::pop(&tempStack, &symb2, &num2);
        if (fabs(num1) < eps) {
          rc = EXIT_ZERO_DIVISION_ERROR;
          ptr = NULL;
          break;
        }
        s21::push(&tempStack, 'd', num2 / num1);
        break;
      }
      case 'm': {
        double num1, num2;
        char symb1, symb2;
        if (!tempStack) {
          rc = EXIT_EXPR_PARSING_ERROR;
          ptr = NULL;
          break;
        }
        s21::pop(&tempStack, &symb1, &num1);
        if (!tempStack) {
          rc = EXIT_EXPR_PARSING_ERROR;
          ptr = NULL;
          break;
        }
        s21::pop(&tempStack, &symb2, &num2);
        if (fabs(num1) < eps) {
          rc = EXIT_ZERO_DIVISION_ERROR;
          ptr = NULL;
          break;
        }
        s21::push(&tempStack, 'd', fmod(num2, num1));
        break;
      }
      case 's': {
        double num1;
        char symb1;
        if (!tempStack) {
          rc = EXIT_EXPR_PARSING_ERROR;
          ptr = NULL;
          break;
        }
        s21::pop(&tempStack, &symb1, &num1);
        s21::push(&tempStack, 'd', sin(num1));
        break;
      }
      case 'q': {
        double num1;
        char symb1;
        if (!tempStack) {
          rc = EXIT_EXPR_PARSING_ERROR;
          ptr = NULL;
          break;
        }
        s21::pop(&tempStack, &symb1, &num1);
        if (num1 < 0.0) {
          rc = EXIT_NEG_ROOT_ERROR;
          ptr = NULL;
          break;
        }
        s21::push(&tempStack, 'd', sqrt(num1));
        break;
      }
      case 't': {
        double num1;
        char symb1;
        if (!tempStack) {
          rc = EXIT_EXPR_PARSING_ERROR;
          ptr = NULL;
          break;
        }
        s21::pop(&tempStack, &symb1, &num1);
        if (fabs(fmod(num1, PI) - PI / 2) < eps ||
            fabs(fmod(num1, PI) + PI / 2) < eps) {
          rc = EXIT_INF_TAN_ERROR;
          ptr = NULL;
          break;
        }
        s21::push(&tempStack, 'd', tan(num1));
        break;
      }
      case 'n': {
        double num1;
        char symb1;
        if (!tempStack) {
          rc = EXIT_EXPR_PARSING_ERROR;
          ptr = NULL;
          break;
        }
        s21::pop(&tempStack, &symb1, &num1);
        if (num1 <= 0.0) {
          rc = EXIT_NON_POS_LOG_ERROR;
          ptr = NULL;
          break;
        }
        s21::push(&tempStack, 'd', log(num1));
        break;
      }
      case 'c': {
        double num1;
        char symb1;
        if (!tempStack) {
          rc = EXIT_EXPR_PARSING_ERROR;
          ptr = NULL;
          break;
        }
        s21::pop(&tempStack, &symb1, &num1);
        s21::push(&tempStack, 'd', cos(num1));
        break;
      }
      case 'a': {
        double num1;
        char symb1;
        if (!tempStack) {
          rc = EXIT_EXPR_PARSING_ERROR;
          ptr = NULL;
          break;
        }
        s21::pop(&tempStack, &symb1, &num1);
        if (fabs(num1) > 1.0) {
          rc = EXIT_ARCSIN_RANGE_ERROR;
          ptr = NULL;
          break;
        }
        s21::push(&tempStack, 'd', asin(num1));
        break;
      }
      case 'k': {
        double num1;
        char symb1;
        if (!tempStack) {
          rc = EXIT_EXPR_PARSING_ERROR;
          ptr = NULL;
          break;
        }
        s21::pop(&tempStack, &symb1, &num1);
        if (fabs(num1) > 1.0) {
          rc = EXIT_ARCCOS_RANGE_ERROR;
          ptr = NULL;
          break;
        }
        s21::push(&tempStack, 'd', acos(num1));
        break;
      }
      case 'g': {
        double num1;
        char symb1;
        if (!tempStack) {
          rc = EXIT_EXPR_PARSING_ERROR;
          ptr = NULL;
          break;
        }
        s21::pop(&tempStack, &symb1, &num1);
        s21::push(&tempStack, 'd', atan(num1));
        break;
      }
      case 'l': {
        double num1;
        char symb1;
        if (!tempStack) {
          rc = EXIT_EXPR_PARSING_ERROR;
          ptr = NULL;
          break;
        }
        s21::pop(&tempStack, &symb1, &num1);
        if (num1 <= 0.0) {
          rc = EXIT_NON_POS_LOG_ERROR;
          ptr = NULL;

          break;
        }
        s21::push(&tempStack, 'd', log10(num1));
        break;
      }
      case 'd': {
        s21::push(&tempStack, 'd', num);
        break;
      }
      case 'x': {
        s21::push(&tempStack, 'd', x);
        break;
      }
      default:
        break;
    }
    if (ptr) ptr = ptr->prev;
  }
  if (!rc) s21::pop(&tempStack, &symb, &num);
  *answer = num;
  s21::destroyStack(tempStack);
  return rc;
}
