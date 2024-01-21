#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <stdio.h>
#include <stdlib.h>

#include "bonusPart.h"
#include "model.h"

#define EXIT_EDGES_ERROR 40

namespace s21 {
class controller {
 public:
  explicit controller(const model &mdl) : model_(mdl) {}
  int solveExpression(char *expression, double x, double *answer);
  int getGraph(char *expression, double l, double r, double step,
               double coordinates[][2]);
  model model_;
};
}  // namespace s21

#endif  // CONTROLLER_H
