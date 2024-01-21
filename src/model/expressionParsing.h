#ifndef EXPRESSION_PARSING_H
#define EXPRESSION_PARSING_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

#define EXIT_EXPR_PARSING_ERROR 20

int pars(char *str, s21::Stack **stack);

#endif  // EXPRESSION_PARSING_H
