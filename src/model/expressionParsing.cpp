#include "expressionParsing.h"

int pars(char *str, s21::Stack **stack) {
  if (*str == '\0') return EXIT_EXPR_PARSING_ERROR;
  int i = 0;
  char prev = '=';
  char tmp = '=';
  s21::Stack *tempStack = NULL;
  int rc = EXIT_SUCCESS;
  while (*(str + i) != '\0') {
    if (*(str + i) == ' ') {
      ++i;
      continue;
    }
    prev = tmp;
    tmp = *(str + i);
    if (*(str + i) == 'm') {
      if (!isdigit(prev) && prev != 'x' && prev != ')') {
        rc = EXIT_EXPR_PARSING_ERROR;
        break;
      }
      i += 3;
      while (tempStack != NULL &&
             (tempStack->data == '*' || tempStack->data == '/' ||
              tempStack->data == 'm' || tempStack->data == '^')) {
        char op;
        double num;
        s21::pop(&tempStack, &op, &num);
        s21::push(stack, op, num);
      }
      push(&tempStack, 'm', 0.0);
      continue;
    }
    if (*(str + i) == '^') {
      if (!isdigit(prev) && prev != 'x' && prev != ')') {
        rc = EXIT_EXPR_PARSING_ERROR;
        break;
      }
      ++i;
      while (tempStack != NULL && tempStack->data == '^') {
        char op;
        double num;
        s21::pop(&tempStack, &op, &num);
        s21::push(stack, op, num);
      }
      push(&tempStack, '^', 0.0);
      continue;
    }
    if (*(str + i) == '*') {
      if (!isdigit(prev) && prev != 'x' && prev != ')') {
        rc = EXIT_EXPR_PARSING_ERROR;
        break;
      }
      ++i;
      while (tempStack != NULL &&
             (tempStack->data == '*' || tempStack->data == '/' ||
              tempStack->data == 'm' || tempStack->data == '^')) {
        char op;
        double num;
        s21::pop(&tempStack, &op, &num);
        s21::push(stack, op, num);
      }
      push(&tempStack, '*', 0.0);
      continue;
    }
    if (*(str + i) == '/') {
      if (!isdigit(prev) && prev != 'x' && prev != ')') {
        rc = EXIT_EXPR_PARSING_ERROR;
        break;
      }
      ++i;
      while (tempStack != NULL &&
             (tempStack->data == '*' || tempStack->data == '/' ||
              tempStack->data == 'm' || tempStack->data == '^')) {
        char op;
        double num;
        s21::pop(&tempStack, &op, &num);
        s21::push(stack, op, num);
      }
      push(&tempStack, '/', 0.0);
      continue;
    }
    if (*(str + i) == '+') {
      ++i;
      if (prev == '=' || prev == '(') {
        push(&tempStack, '&', 0.0);
        continue;
      }
      if (!isdigit(prev) && prev != ')' && prev != 'x') {
        rc = EXIT_EXPR_PARSING_ERROR;
        break;
      }
      while (tempStack != NULL &&
             (tempStack->data == '-' || tempStack->data == '+' ||
              tempStack->data == '*' || tempStack->data == '/' ||
              tempStack->data == 'm' || tempStack->data == '^')) {
        char op;
        double num;
        s21::pop(&tempStack, &op, &num);
        s21::push(stack, op, num);
      }
      push(&tempStack, '+', 0.0);
      continue;
    }
    if (*(str + i) == '-') {
      ++i;
      if (prev == '=' || prev == '(') {
        push(&tempStack, '_', 0.0);
        continue;
      }
      if (!isdigit(prev) && prev != ')' && prev != 'x') {
        rc = EXIT_EXPR_PARSING_ERROR;
        break;
      }
      while (tempStack != NULL &&
             (tempStack->data == '-' || tempStack->data == '+' ||
              tempStack->data == '*' || tempStack->data == '/' ||
              tempStack->data == 'm' || tempStack->data == '^')) {
        char op;
        double num;
        s21::pop(&tempStack, &op, &num);
        s21::push(stack, op, num);
      }
      push(&tempStack, '-', 0.0);
      continue;
    }
    if (*(str + i) == '(') {
      if (prev != '*' && prev != '/' && prev != 'm' && prev != '^' &&
          prev != '(' && prev != '-' && prev != '+' && prev != '=' &&
          prev != 's' && prev != 'c' && prev != 'a' && prev != 't' &&
          prev != 'l') {
        rc = EXIT_EXPR_PARSING_ERROR;
        break;
      }
      ++i;
      push(&tempStack, '(', 0.0);
      continue;
    }
    if (*(str + i) == ')') {
      if (!isdigit(prev) && prev != 'x' && prev != ')') {
        rc = EXIT_EXPR_PARSING_ERROR;
        break;
      }
      ++i;
      while (tempStack != NULL && tempStack->data != '(') {
        char op;
        double num;
        s21::pop(&tempStack, &op, &num);
        s21::push(stack, op, num);
      }
      if (tempStack == NULL) {
        rc = EXIT_EXPR_PARSING_ERROR;
        break;
      }
      char op;
      double num;
      pop(&tempStack, &op, &num);
      if (tempStack->data == 's' || tempStack->data == 'q' ||
          tempStack->data == 'c' || tempStack->data == 'k' ||
          tempStack->data == 'a' || tempStack->data == 'g' ||
          tempStack->data == 't' || tempStack->data == 'l' ||
          tempStack->data == 'n') {
        s21::pop(&tempStack, &op, &num);
        s21::push(stack, op, num);
      }
      continue;
    }
    if (prev != '*' && prev != '/' && prev != '-' && prev != '+' &&
        prev != 'm' && prev != '^' && prev != '(' && prev != '=') {
      rc = EXIT_EXPR_PARSING_ERROR;
      break;
    }

    if (*(str + i) == 's' && *(str + i + 1) == 'i' && *(str + i + 2) == 'n') {
      i += 3;
      s21::push(&tempStack, 's', 0.0);
      continue;
    }
    if (*(str + i) == 's' && *(str + i + 1) == 'q' && *(str + i + 2) == 'r' &&
        *(str + i + 3) == 't') {
      i += 4;
      s21::push(&tempStack, 'q', 0.0);
      continue;
    }
    if (*(str + i) == 'c' && *(str + i + 1) == 'o' && *(str + i + 2) == 's') {
      i += 3;
      s21::push(&tempStack, 'c', 0.0);
      continue;
    }
    if (*(str + i) == 'a' && *(str + i + 1) == 'c' && *(str + i + 2) == 'o' &&
        *(str + i + 3) == 's') {
      i += 4;
      s21::push(&tempStack, 'k', 0.0);
      continue;
    }
    if (*(str + i) == 'a' && *(str + i + 1) == 's' && *(str + i + 2) == 'i' &&
        *(str + i + 3) == 'n') {
      i += 4;
      s21::push(&tempStack, 'a', 0.0);
      continue;
    }
    if (*(str + i) == 'a' && *(str + i + 1) == 't' && *(str + i + 2) == 'a' &&
        *(str + i + 3) == 'n') {
      i += 4;
      s21::push(&tempStack, 'g', 0.0);
      continue;
    }
    if (*(str + i) == 't' && *(str + i + 1) == 'a' && *(str + i + 2) == 'n') {
      i += 3;
      s21::push(&tempStack, 't', 0.0);
      continue;
    }
    if (*(str + i) == 'l' && *(str + i + 1) == 'o' && *(str + i + 2) == 'g') {
      i += 3;
      s21::push(&tempStack, 'l', 0.0);
      continue;
    }
    if (*(str + i) == 'l' && *(str + i + 1) == 'n') {
      i += 2;
      s21::push(&tempStack, 'n', 0.0);
      continue;
    }
    if (*(str + i) == 'x') {
      ++i;
      s21::push(stack, 'x', 0.0);
      continue;
    }
    char *end;
    double value = strtod(str + i, &end);
    if (end == str - i) {
      rc = EXIT_EXPR_PARSING_ERROR;
      break;
    } else {
      i += end - str - i;
      s21::push(stack, 'd', value);
    }
  }
  if (tmp == '=' && i > 0) rc = EXIT_EXPR_PARSING_ERROR;
  if (tempStack != NULL && tempStack->data == '(')
    rc = EXIT_EXPR_PARSING_ERROR;
  else {
    while (tempStack != NULL) {
      char op;
      double num;
      s21::pop(&tempStack, &op, &num);
      s21::push(stack, op, num);
    }
  }

  s21::destroyStack(tempStack);

  return rc;
}
