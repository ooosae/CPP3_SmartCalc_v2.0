#ifndef GRAPH_H
#define GRAPH_H

#define pi acos(-1)
#define eps 1e-7

#define WIDTH 80
#define HEIGHT 25

#include <math.h>
#include <stdio.h>

#include "expressionCalculation.h"
#include "stack.h"

void draw(s21::Stack *stack, double l, double r, double step,
          double coords[][2]);

#endif  // GRAPH_H
