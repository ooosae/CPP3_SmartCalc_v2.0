#include "bonusPart.h"

int calcCredit(double totalLoanAmount, int monthTerm, double interestRate,
               char type, double *paymentMonth, double *overpayment,
               double *totalPayment) {
  if ((type != 'a' && type != 'd') || totalLoanAmount <= 0 ||
      interestRate <= 0.0 || monthTerm <= 0)
    return EXIT_CREDIT_INPUT_ERROR;

  double monthlyInterestRate = interestRate / 100.0 / 12;

  if (type == 'a') {
    double powFactor = pow(1 + monthlyInterestRate, monthTerm);
    double pMonth =
        totalLoanAmount * monthlyInterestRate * powFactor / (powFactor - 1);
    for (int i = 0; i < monthTerm; ++i) paymentMonth[i] = pMonth;
    *totalPayment = *paymentMonth * monthTerm;
    *overpayment = *totalPayment - totalLoanAmount;
  } else {
    *paymentMonth = 0.0;
    *totalPayment = 0.0;
    *overpayment = 0.0;
    double principalPayment = totalLoanAmount / monthTerm;

    for (int i = 0; i < monthTerm; i++) {
      double interestPayment = totalLoanAmount * monthlyInterestRate;
      totalLoanAmount -= principalPayment;
      paymentMonth[i] = principalPayment + interestPayment;
      *overpayment += interestPayment;
      *totalPayment += paymentMonth[i];
    }
  }

  return EXIT_SUCCESS;
}

int calcDeposit(double depositAmount, int monthTerm, double interestRate,
                double taxRate, int repaymentPeriodicity,
                int interestCapitalization, double replenishment[][2],
                int withdrawCount, double withdraw[][2], int replenishmentCount,
                double *accruedInterest, double *taxAmount,
                double *amountOnDeposit) {
  if (depositAmount <= 0 || monthTerm <= 0 || interestRate <= 0 ||
      taxRate < 0 || repaymentPeriodicity <= 0 || interestCapitalization < 0 ||
      withdrawCount < 0 || replenishmentCount < 0)
    return EXIT_DEPOSIT_INPUT_ERROR;
  for (int i = 0; i < replenishmentCount; ++i) {
    if (replenishment[i][1] <= 0 || replenishment[i][1] > monthTerm)
      return EXIT_DEPOSIT_INPUT_ERROR;
    if (replenishment[i][0] <= 0) return EXIT_DEPOSIT_INPUT_ERROR;
  }
  for (int i = 0; i < withdrawCount; ++i) {
    if (withdraw[i][1] <= 0 || withdraw[i][1] > monthTerm)
      return EXIT_DEPOSIT_INPUT_ERROR;
    if (withdraw[i][0] <= 0) return EXIT_DEPOSIT_INPUT_ERROR;
  }

  double monthlyInterestRate = interestRate / 100.0 / 12.0;
  double totalInterest = 0.0;
  *taxAmount = 0.0;
  *accruedInterest = 0.0;
  taxRate /= 100;

  for (int month = 1; month <= monthTerm; month++) {
    double monthlyWithdraw = 0.0;

    for (int i = 0; i < replenishmentCount; i++) {
      if (fabs(replenishment[i][1] - month) < eps) {
        depositAmount += replenishment[i][0];
      }
    }
    for (int i = 0; i < withdrawCount; i++) {
      if (fabs(withdraw[i][1] - month) < eps) {
        monthlyWithdraw = withdraw[i][0];
        if (monthlyWithdraw > depositAmount) {
          monthlyWithdraw = depositAmount;
        }
        depositAmount -= monthlyWithdraw;
      }
    }

    totalInterest += depositAmount * monthlyInterestRate;

    if (month % repaymentPeriodicity == 0) {
      *taxAmount += totalInterest * taxRate;
      totalInterest -= totalInterest * taxRate;
      if (interestCapitalization > 0) {
        depositAmount += totalInterest;
      }
      *accruedInterest += totalInterest;
      totalInterest = 0.0;
    }
  }
  *amountOnDeposit = depositAmount;

  return EXIT_SUCCESS;
}
