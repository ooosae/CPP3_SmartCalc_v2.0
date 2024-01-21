#ifndef VIEW_H
#define VIEW_H

#include <cairo.h>
#include <gtk/gtk.h>

#include "controller.h"

namespace s21 {
class view;
class UserData {
 public:
  GtkWidget *entry;
  GtkWidget *output;
  GtkWidget *xField;
  GtkWidget *lEdge;
  GtkWidget *rEdge;
  int flag;
  view *view_;
};

class PlotData {
 public:
  GtkWidget *area;
  GtkWidget *entry;
  cairo_t *cr;
};

class CreditData {
 public:
  GtkWidget *overpaymentField;
  GtkWidget *totalPaymentField;
  GtkWidget *treeView;
  GtkWidget *totalLoanAmount;
  GtkWidget *monthTerm;
  GtkWidget *interestRate;
  GtkWidget *type;
};

class DepositData {
 public:
  GtkWidget *accruedInterest;
  GtkWidget *taxAmount;
  GtkWidget *amountOnDeposit;
  GtkWidget *depositAmount;
  GtkWidget *monthTerm;
  GtkWidget *interestRate;
  GtkWidget *taxRate;
  GtkWidget *repaymentPeriodicity;
  GtkWidget *interestCapitalization;
  GtkWidget *treeView1;
  GtkWidget *treeView2;
  GtkTreeStore *treeStore1;
  GtkTreeStore *treeStore2;
};

class view {
 public:
  explicit view(const controller &ctrl) : controller_(ctrl) {}
  int start(int argc, char *argv[]);
  controller controller_;
};

void on_rem_button_clicked_2(GtkButton *button, DepositData *depositData);
void on_rem_button_clicked_1(GtkButton *button, DepositData *depositData);
void on_add_button_clicked_2(GtkButton *button, DepositData *depositData);
void on_add_button_clicked_1(GtkButton *button, DepositData *depositData);
void button_calcDeposit(GtkWidget *button, DepositData *depositData,
                        gpointer data);
void button_calcCredit(GtkWidget *button, CreditData *creditData,
                       gpointer data);
void button_clear(GtkWidget *button, GtkWidget *entry, gpointer data);
void button_print(GtkWidget *button, GtkWidget *entry, gpointer data);
void button_draw_graph(GtkWidget *button, PlotData *plotData);
void go_flag(GtkWidget *button, UserData *userData);
gboolean draw_callback(GtkWidget *widget, cairo_t *cr, gpointer data);
void draw_axes_and_grid(cairo_t *cr, double width, double height, double min_x,
                        double max_x, double min_y, double max_y, int count);
void button_calc_expr(GtkWidget *button, UserData *userData, gpointer data);

}  // namespace s21

#endif  // VIEW_H
