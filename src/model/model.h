#ifndef MODEL_H
#define MODEL_H

#include "expressionCalculation.h"
#include "expressionParsing.h"
#include "graph.h"

namespace s21 {
class model {
 public:
  int Pars(char *str, s21::Stack **stack) { return pars(str, stack); }
  void Draw(s21::Stack *stack, double l, double r, double step,
            double coords[][2]) {
    draw(stack, l, r, step, coords);
  }
  int Calc(s21::Stack *stack, double x, double *answer) {
    return calc(stack, x, answer);
  }
};
}  // namespace s21

#endif  // MODEL_H
