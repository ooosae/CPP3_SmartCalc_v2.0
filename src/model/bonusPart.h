#ifndef BONUS_PART_H
#define BONUS_PART_H

#define EXIT_SUCCESS 0
#define EXIT_INPUT_ERROR 2

#include <math.h>
#include <stdio.h>

#define eps 1e-7

#define EXIT_CREDIT_INPUT_ERROR 30
#define EXIT_DEPOSIT_INPUT_ERROR 31

int calcCredit(double totalLoanAmount, int monthTerm, double interestRate,
               char type, double *paymentMonth, double *overpayment,
               double *totalPayment);
int calcDeposit(double depositAmount, int monthTerm, double interestRate,
                double taxRate, int repaymentPeriodicity,
                int interestCapitalization, double replenishment[][2],
                int withdrawCount, double withdraw[][2], int replenishmentCount,
                double *accruedInterest, double *taxAmount,
                double *amountOnDeposit);

#endif  // BONUS_PART_H
