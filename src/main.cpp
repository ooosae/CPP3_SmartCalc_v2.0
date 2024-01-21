#include "view.h"

int main(int argc, char *argv[]) {
  s21::model myModel;
  s21::controller myController(myModel);
  s21::view myView(myController);
  myView.start(argc, argv);
  return 0;
}
