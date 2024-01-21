#include <gtest/gtest.h>

#include "controller.h"

#define eps2 0.1
#define eps3 1e-3

TEST(ExpressionTests, Test1) {
  char *expression = "7 mod (-4)";
  double real_ans = 3.0;
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer), 0);
  ASSERT_NEAR(answer, real_ans, eps);
}

TEST(ExpressionTests, Test2) {
  char *expression = "1 + log(3) / 5.24";
  double real_ans = 1.091053675;
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer), 0);
  ASSERT_NEAR(answer, real_ans, eps);
}

TEST(ExpressionTests, Test3) {
  char *expression = "sqrt(1.23)";
  double real_ans = 1.109053651;
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer), 0);
  ASSERT_NEAR(answer, real_ans, eps);
}

TEST(ExpressionTests, Test4) {
  char *expression = "sin(3.14159265359)";
  double real_ans = 0;
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer), 0);
  ASSERT_NEAR(answer, real_ans, eps);
}

TEST(ExpressionTests, Test5) {
  char *expression = "cos(sqrt(4.35))";
  double real_ans = -0.492420866636;
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer), 0);
  ASSERT_NEAR(answer, real_ans, eps);
}

TEST(ExpressionTests, Test6) {
  char *expression = "12 / sqrt(0.12) * 5.245 - (-8)";
  double real_ans = 189.692129714;
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer), 0);
  ASSERT_NEAR(answer, real_ans, eps);
}

TEST(ExpressionTests, Test7) {
  char *expression = "+0 - (+9) * (123)";
  double real_ans = -1107;
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer), 0);
  ASSERT_NEAR(answer, real_ans, eps);
}

TEST(ExpressionTests, Test8) {
  char *expression = "+0 - (+9) mod (123)";
  double real_ans = -9;
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer), 0);
  ASSERT_NEAR(answer, real_ans, eps);
}

TEST(ExpressionTests, TestParseError1) {
  char *expression = "3 -";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParseError2) {
  char *expression = "/2";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParseError3) {
  char *expression = "so";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParseError4) {
  char *expression = "sin(4 +";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParseError5) {
  char *expression = "lmn(3)";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParseError6) {
  char *expression = "3(log(3))";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParseError7) {
  char *expression = "sqrt(* 7)";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParseError8) {
  char *expression = "-*tan(3)";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParseError9) {
  char *expression = "9 --3";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParseError10) {
  char *expression = "3 ++3";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParseError11) {
  char *expression = "1_3";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParseError12) {
  char *expression = "0..";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParseError13) {
  char *expression = "cos(3))";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParseError14) {
  char *expression = "ln()";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParseError15) {
  char *expression = "loglog3";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParseError16) {
  char *expression = "+892+";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParseError17) {
  char *expression = "";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParseError18) {
  char *expression = "3+mod5";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParseError19) {
  char *expression = "(^9)";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParseError20) {
  char *expression = "sqrt";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, Test9) {
  char *expression = "log(3 + sqrt(123.023)) / (9 - 3 mod 1)";
  double real_ans = 0.127662165;
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer), 0);
  ASSERT_NEAR(answer, real_ans, eps);
}

TEST(ExpressionTests, Test10) {
  char *expression = "acos(cos(1.0))";
  double real_ans = 1;
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer), 0);
  ASSERT_NEAR(answer, real_ans, eps);
}

TEST(ExpressionTests, Test11) {
  char *expression = "atan(asin(0.123))";
  double real_ans = 0.122692891014;
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer), 0);
  ASSERT_NEAR(answer, real_ans, eps);
}

TEST(ExpressionTests, Test12) {
  char *expression = "3 * 123 mod 3 - 123 * 89 + (+8)";
  double real_ans = -10939;
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer), 0);
  ASSERT_NEAR(answer, real_ans, eps);
}

TEST(ExpressionTests, Test13) {
  char *expression = "3 ^ 1.23 - (7 ^ 0.13)";
  double real_ans = 2.574574376;
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer), 0);
  ASSERT_NEAR(answer, real_ans, eps);
}

TEST(ExpressionTests, Test14) {
  char *expression = "3 * 5 ^ 7.7";
  double real_ans = 723086.557875011;
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer), 0);
  ASSERT_NEAR(answer, real_ans, eps);
}

TEST(ExpressionTests, Test15) {
  char *expression = "3 ^ 2 ^ 2";
  double real_ans = 81;
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer), 0);
  ASSERT_NEAR(answer, real_ans, eps);
}

TEST(ExpressionTests, Test16) {
  char *expression = "124 /2 / (-8) *9 + 123 * 8 ^1";
  double real_ans = 914.25;
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer), 0);
  ASSERT_NEAR(answer, real_ans, eps);
}

TEST(ExpressionTests, Test17) {
  char *expression = "tan(sqrt(4) - 123 + 124 * (-1.000023)) - 9.9 + tan(3.14)";
  double real_ans = -9.860194048963;
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer), 0);
  ASSERT_NEAR(answer, real_ans, eps);
}

TEST(ExpressionTests, TestPowError22) {
  char *expression = "0^(-1.2)";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_POW_ZERO_NEG_EXP_ERROR);
}

TEST(ExpressionTests, TestZeroDivisionError23) {
  char *expression = "123 / 2 * 9 / 0 - 123 - 0";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_ZERO_DIVISION_ERROR);
}

TEST(ExpressionTests, TestNegRootError24) {
  char *expression = "sqrt(-0.000002)";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_NEG_ROOT_ERROR);
}

TEST(ExpressionTests, TestNegRootError25) {
  char *expression = "sqrt(2 * (-89))";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_NEG_ROOT_ERROR);
}

TEST(ExpressionTests, TestInfTanError26) {
  char *expression = "tan(-3.1415926535 / 2)";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer), EXIT_INF_TAN_ERROR);
}

TEST(ExpressionTests, TestInfTanError27) {
  char *expression = "tan(101 * (-3.1415926535) / 2)";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer), EXIT_INF_TAN_ERROR);
}

TEST(ExpressionTests, TestInfTanError28) {
  char *expression = "tan(-3 * (+3.1415926535) / 2) - 100";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer), EXIT_INF_TAN_ERROR);
}

TEST(ExpressionTests, TestNonPosLogError29) {
  char *expression = "log(-0.01230120)";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_NON_POS_LOG_ERROR);
}

TEST(ExpressionTests, TestNonPosLogError30) {
  char *expression = "ln(-0.0)";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_NON_POS_LOG_ERROR);
}

TEST(ExpressionTests, TestNonPosLogError31) {
  char *expression = "ln(-0.01230120)";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_NON_POS_LOG_ERROR);
}

TEST(ExpressionTests, TestNonPosLogError32) {
  char *expression = "log(0.0)";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_NON_POS_LOG_ERROR);
}

TEST(ExpressionTests, TestArcCosRangeError36) {
  char *expression = "acos(-1.00001)";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_ARCCOS_RANGE_ERROR);
}

TEST(ExpressionTests, TestArcCosRangeError33) {
  char *expression = "acos(123)";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_ARCCOS_RANGE_ERROR);
}

TEST(ExpressionTests, TestArcSinRangeError34) {
  char *expression = "asin(1.00001)";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_ARCSIN_RANGE_ERROR);
}

TEST(ExpressionTests, TestArcSinRangeError35) {
  char *expression = "asin(-123)";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_ARCSIN_RANGE_ERROR);
}

TEST(ExpressionTests, TestParsingError37) {
  char *expression = "+";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParsingError38) {
  char *expression = "++3";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParsingError39) {
  char *expression = "2+";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParsingError40) {
  char *expression = "-";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParsingError41) {
  char *expression = "--3";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParsingError42) {
  char *expression = "2-";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParsingError43) {
  char *expression = "*";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParsingError44) {
  char *expression = "*3";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParsingError45) {
  char *expression = "2*";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParsingError46) {
  char *expression = "/";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParsingError47) {
  char *expression = "2/";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParsingError48) {
  char *expression = "/3";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParsingError49) {
  char *expression = "^";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParsingError50) {
  char *expression = "2^";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParsingError51) {
  char *expression = "^2";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParsingError52) {
  char *expression = "^-";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParsingError53) {
  char *expression = "-(^)";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParsingError54) {
  char *expression = "2)(";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParsingError55) {
  char *expression = "mod";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParsingError56) {
  char *expression = "2mod";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParsingError57) {
  char *expression = "mod2";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParsingError58) {
  char *expression = "cos";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParsingError59) {
  char *expression = "cos(";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParsingError60) {
  char *expression = "sin)";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParsingError61) {
  char *expression = "tan3)";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParsingError62) {
  char *expression = "log";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParsingError63) {
  char *expression = "atan     ()";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParsingError64) {
  char *expression = "asin";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParsingError65) {
  char *expression = "acos     ()";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParsingError66) {
  char *expression = "atan";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParsingError67) {
  char *expression = "acos";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParsingError68) {
  char *expression = "log()";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParsingError69) {
  char *expression = "3 + ln";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParsingError70) {
  char *expression = "- sin";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestZeroDivisionError72) {
  char *expression = "4 mod (-0.0)";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_ZERO_DIVISION_ERROR);
}

TEST(ExpressionTests, TestParsingError71) {
  char *expression = "mod";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParsingError73) {
  char *expression = "ln";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParsingError74) {
  char *expression = "ln() - ()";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParsingError75) {
  char *expression = "tan()";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(ExpressionTests, TestParsingError76) {
  char *expression = "tan";
  double answer;
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.solveExpression(expression, 0.0, &answer),
            EXIT_EXPR_PARSING_ERROR);
}

TEST(PaymentCalculationTests, TestLoanTypeA1) {
  double total_loan_amount = 1000000.0;
  int month_term = 12;
  double interest_rate = 3.34;
  char type = 'a';

  double real_payment_month[10000];
  for (int i = 0; i < month_term; ++i) real_payment_month[i] = 84848.65;

  double real_overpayment = 18183.80;
  double real_total_payment = 1018183.80;

  double payment_month[10000];
  double overpayment;
  double total_payment;

  ASSERT_EQ(calcCredit(total_loan_amount, month_term, interest_rate, type,
                       payment_month, &overpayment, &total_payment),
            0);

  for (int i = 0; i < month_term; ++i)
    ASSERT_NEAR(payment_month[i], real_payment_month[i], eps2);

  ASSERT_NEAR(overpayment, real_overpayment, eps2);
  ASSERT_NEAR(total_payment, real_total_payment, eps2);
}

TEST(PaymentCalculationTests, TestLoanTypeA2) {
  double total_loan_amount = 12312321.12;
  const int month_term = 32;
  double interest_rate = 24.23;
  char type = 'a';

  double real_payment_month[10000];
  for (int i = 0; i < month_term; ++i) real_payment_month[i] = 526097.91;

  double real_overpayment = 4522812.00;
  double real_total_payment = 16835133.12;

  double payment_month[10000];
  double overpayment;
  double total_payment;

  ASSERT_EQ(calcCredit(total_loan_amount, month_term, interest_rate, type,
                       payment_month, &overpayment, &total_payment),
            0);

  for (int i = 0; i < month_term; ++i)
    ASSERT_NEAR(payment_month[i], real_payment_month[i], eps2);

  ASSERT_NEAR(overpayment, real_overpayment, eps2);
  ASSERT_NEAR(total_payment, real_total_payment, eps2);
}

TEST(PaymentCalculationTests, TestLoanTypeD) {
  double total_loan_amount = 12312321.12;
  const int month_term = 32;
  double interest_rate = 24.23;
  char type = 'd';

  double real_payment_month[10000];
  real_payment_month[0] = 633366.32;
  real_payment_month[1] = 625597.37;
  real_payment_month[2] = 617828.43;
  real_payment_month[3] = 610059.48;
  real_payment_month[4] = 602290.53;
  real_payment_month[5] = 594521.59;
  real_payment_month[6] = 586752.64;
  real_payment_month[7] = 578983.69;
  real_payment_month[8] = 571214.75;
  real_payment_month[9] = 563445.80;
  real_payment_month[10] = 555676.86;
  real_payment_month[11] = 547907.91;
  real_payment_month[12] = 540138.96;
  real_payment_month[13] = 532370.02;
  real_payment_month[14] = 524601.07;
  real_payment_month[15] = 516832.12;
  real_payment_month[16] = 509063.18;
  real_payment_month[17] = 501294.23;
  real_payment_month[18] = 493525.28;
  real_payment_month[19] = 485756.34;
  real_payment_month[20] = 477987.39;
  real_payment_month[21] = 470218.45;
  real_payment_month[22] = 462449.50;
  real_payment_month[23] = 454680.55;
  real_payment_month[24] = 446911.61;
  real_payment_month[25] = 439142.66;
  real_payment_month[26] = 431373.71;
  real_payment_month[27] = 423604.77;
  real_payment_month[28] = 415835.82;
  real_payment_month[29] = 408066.87;
  real_payment_month[30] = 400297.93;
  real_payment_month[31] = 392528.98;

  double real_overpayment = 4102003.69;
  double real_total_payment = 16414324.81;

  double payment_month[10000];
  double overpayment;
  double total_payment;

  ASSERT_EQ(calcCredit(total_loan_amount, month_term, interest_rate, type,
                       payment_month, &overpayment, &total_payment),
            0);

  for (int i = 0; i < month_term; ++i)
    ASSERT_NEAR(payment_month[i], real_payment_month[i], eps2);

  ASSERT_NEAR(overpayment, real_overpayment, eps2);
  ASSERT_NEAR(total_payment, real_total_payment, eps2);
}

TEST(CreditCalculationTests, TestInvalidInput1) {
  double total_loan_amount = 1000000.0;
  int month_term = 12;
  double interest_rate = 3.34;
  char type = 'p';
  double payment_month[10000];
  double overpayment;
  double total_payment;
  ASSERT_EQ(calcCredit(total_loan_amount, month_term, interest_rate, type,
                       payment_month, &overpayment, &total_payment),
            EXIT_CREDIT_INPUT_ERROR);
}

TEST(CreditCalculationTests, TestInvalidInput2) {
  double total_loan_amount = 1000000.0;
  int month_term = 12;
  double interest_rate = 3.34;
  char type = '1';
  double payment_month[10000];
  double overpayment;
  double total_payment;
  ASSERT_EQ(calcCredit(total_loan_amount, month_term, interest_rate, type,
                       payment_month, &overpayment, &total_payment),
            EXIT_CREDIT_INPUT_ERROR);
}

TEST(CreditCalculationTests, TestInvalidInput3) {
  double total_loan_amount = 0.0;
  int month_term = 12;
  double interest_rate = 3.34;
  char type = 'a';
  double payment_month[10000];
  double overpayment;
  double total_payment;
  ASSERT_EQ(calcCredit(total_loan_amount, month_term, interest_rate, type,
                       payment_month, &overpayment, &total_payment),
            EXIT_CREDIT_INPUT_ERROR);
}

TEST(CreditCalculationTests, TestInvalidInput4) {
  double total_loan_amount = -123;
  int month_term = 12;
  double interest_rate = 3.34;
  char type = 'a';
  double payment_month[10000];
  double overpayment;
  double total_payment;
  ASSERT_EQ(calcCredit(total_loan_amount, month_term, interest_rate, type,
                       payment_month, &overpayment, &total_payment),
            EXIT_CREDIT_INPUT_ERROR);
}

TEST(CreditCalculationTests, TestInvalidInput5) {
  double total_loan_amount = 1000000.0;
  int month_term = 0;
  double interest_rate = 3.34;
  char type = 'a';
  double payment_month[10000];
  double overpayment;
  double total_payment;
  ASSERT_EQ(calcCredit(total_loan_amount, month_term, interest_rate, type,
                       payment_month, &overpayment, &total_payment),
            EXIT_CREDIT_INPUT_ERROR);
}

TEST(CreditCalculationTests, TestInvalidInput6) {
  double total_loan_amount = 1000000.0;
  int month_term = -123;
  double interest_rate = 3.34;
  char type = 'a';
  double payment_month[10000];
  double overpayment;
  double total_payment;
  ASSERT_EQ(calcCredit(total_loan_amount, month_term, interest_rate, type,
                       payment_month, &overpayment, &total_payment),
            EXIT_CREDIT_INPUT_ERROR);
}

TEST(CreditCalculationTests, TestInvalidInput7) {
  double total_loan_amount = 1000000.0;
  int month_term = 12;
  double interest_rate = 0.0;
  char type = 'a';
  double payment_month[10000];
  double overpayment;
  double total_payment;
  ASSERT_EQ(calcCredit(total_loan_amount, month_term, interest_rate, type,
                       payment_month, &overpayment, &total_payment),
            EXIT_CREDIT_INPUT_ERROR);
}

TEST(CreditCalculationTests, TestInvalidInput8) {
  double total_loan_amount = 1000000.0;
  int month_term = 12;
  double interest_rate = -1.0;
  char type = 'a';
  double payment_month[10000];
  double overpayment;
  double total_payment;
  ASSERT_EQ(calcCredit(total_loan_amount, month_term, interest_rate, type,
                       payment_month, &overpayment, &total_payment),
            EXIT_CREDIT_INPUT_ERROR);
}

TEST(DepositCalculationTests, TestValidDeposit) {
  double deposit_amount = 1000000.0;
  int month_term = 12;
  double interest_rate = 3.24;
  double tax_rate = 0.0;
  int repayment_periodicity = 1;
  int interest_capitalization = 0;

  double replenishment[2][2] = {{20000, 4}, {14000, 10}};
  int replenishment_count = 2;

  double withdraw[2][2] = {{12345, 6}, {2140, 11}};
  int withdraw_count = 2;

  double real_accrued_interest = 32754.5235;
  double real_tax_amount = 0;
  double real_amount_on_deposit = 1019515.00;

  double amount_on_deposit;
  double accrued_interest;
  double tax_amount;

  ASSERT_EQ(
      calcDeposit(deposit_amount, month_term, interest_rate, tax_rate,
                  repayment_periodicity, interest_capitalization, replenishment,
                  replenishment_count, withdraw, withdraw_count,
                  &accrued_interest, &tax_amount, &amount_on_deposit),
      0);

  ASSERT_NEAR(real_accrued_interest, accrued_interest, eps2);
  ASSERT_NEAR(real_tax_amount, tax_amount, eps2);
  ASSERT_NEAR(real_amount_on_deposit, amount_on_deposit, eps2);
}

TEST(DepositCalculationTests, TestValidInput1) {
  double deposit_amount = 1000000.0;
  int month_term = 12;
  double interest_rate = 3.24;
  double tax_rate = 4.5;
  int repayment_periodicity = 2;
  int interest_capitalization = 1;
  double replenishment[2][2] = {{20000, 4}, {14000, 10}};
  int replenishment_count = 2;
  double withdraw[2][2] = {{12345, 6}, {2140, 11}};
  int withdraw_count = 2;
  double real_accrued_interest = 31685.2;
  double real_tax_amount = 1493.02;
  double real_amount_on_deposit = 1051200.2;
  double amount_on_deposit;
  double accrued_interest;
  double tax_amount;

  ASSERT_EQ(
      calcDeposit(deposit_amount, month_term, interest_rate, tax_rate,
                  repayment_periodicity, interest_capitalization, replenishment,
                  replenishment_count, withdraw, withdraw_count,
                  &accrued_interest, &tax_amount, &amount_on_deposit),
      0);

  ASSERT_NEAR(real_accrued_interest, accrued_interest, eps2);
  ASSERT_NEAR(real_amount_on_deposit, amount_on_deposit, eps2);
  ASSERT_NEAR(real_tax_amount, tax_amount, eps2);
}

TEST(DepositCalculationTests, TestInvalidInput1) {
  double deposit_amount = 1000000.0;
  int month_term = 12;
  double interest_rate = 3.24;
  double tax_rate = -0.001;
  int repayment_periodicity = 2;
  int interest_capitalization = 1;
  double replenishment[2][2] = {{20000, 4}, {14000, 10}};
  int replenishment_count = 2;
  double withdraw[2][2] = {{12345, 6}, {2140, 11}};
  int withdraw_count = 2;
  double amount_on_deposit;
  double accrued_interest;
  double tax_amount;

  ASSERT_EQ(
      calcDeposit(deposit_amount, month_term, interest_rate, tax_rate,
                  repayment_periodicity, interest_capitalization, replenishment,
                  replenishment_count, withdraw, withdraw_count,
                  &accrued_interest, &tax_amount, &amount_on_deposit),
      EXIT_DEPOSIT_INPUT_ERROR);
}

TEST(DepositCalculationTests, TestInvalidInput2) {
  double deposit_amount = 0.0;
  int month_term = 12;
  double interest_rate = 3.24;
  double tax_rate = 1;
  int repayment_periodicity = 2;
  int interest_capitalization = 1;
  double replenishment[2][2] = {{20000, 4}, {14000, 10}};
  int replenishment_count = 2;
  double withdraw[2][2] = {{12345, 6}, {2140, 11}};
  int withdraw_count = 2;
  double amount_on_deposit;
  double accrued_interest;
  double tax_amount;

  ASSERT_EQ(
      calcDeposit(deposit_amount, month_term, interest_rate, tax_rate,
                  repayment_periodicity, interest_capitalization, replenishment,
                  replenishment_count, withdraw, withdraw_count,
                  &accrued_interest, &tax_amount, &amount_on_deposit),
      EXIT_DEPOSIT_INPUT_ERROR);
}

TEST(DepositCalculationTests, TestInvalidInput3) {
  double deposit_amount = -1.0;
  int month_term = 12;
  double interest_rate = 3.24;
  double tax_rate = 1;
  int repayment_periodicity = 2;
  int interest_capitalization = 1;
  double replenishment[2][2] = {{20000, 4}, {14000, 10}};
  int replenishment_count = 2;
  double withdraw[2][2] = {{12345, 6}, {2140, 11}};
  int withdraw_count = 2;
  double amount_on_deposit;
  double accrued_interest;
  double tax_amount;

  ASSERT_EQ(
      calcDeposit(deposit_amount, month_term, interest_rate, tax_rate,
                  repayment_periodicity, interest_capitalization, replenishment,
                  replenishment_count, withdraw, withdraw_count,
                  &accrued_interest, &tax_amount, &amount_on_deposit),
      EXIT_DEPOSIT_INPUT_ERROR);
}

TEST(DepositCalculationTests, TestInvalidInput4) {
  double deposit_amount = 1000000.0;
  int month_term = 0;
  double interest_rate = 3.24;
  double tax_rate = 1;
  int repayment_periodicity = 2;
  int interest_capitalization = 1;
  double replenishment[2][2] = {{20000, 4}, {14000, 10}};
  int replenishment_count = 2;
  double withdraw[2][2] = {{12345, 6}, {2140, 11}};
  int withdraw_count = 2;
  double amount_on_deposit;
  double accrued_interest;
  double tax_amount;

  ASSERT_EQ(
      calcDeposit(deposit_amount, month_term, interest_rate, tax_rate,
                  repayment_periodicity, interest_capitalization, replenishment,
                  replenishment_count, withdraw, withdraw_count,
                  &accrued_interest, &tax_amount, &amount_on_deposit),
      EXIT_DEPOSIT_INPUT_ERROR);
}

TEST(DepositCalculationTests, NegativeMonthTerm) {
  double deposit_amount = 1000000.0;
  int month_term = -1;
  double interest_rate = 3.24;
  double tax_rate = 1;
  int repayment_periodicity = 2;
  int interest_capitalization = 1;
  double replenishment[2][2] = {{20000, 4}, {14000, 10}};
  int replenishment_count = 2;
  double withdraw[2][2] = {{12345, 6}, {2140, 11}};
  int withdraw_count = 2;
  double amount_on_deposit;
  double accrued_interest;
  double tax_amount;
  EXPECT_EQ(
      calcDeposit(deposit_amount, month_term, interest_rate, tax_rate,
                  repayment_periodicity, interest_capitalization, replenishment,
                  replenishment_count, withdraw, withdraw_count,
                  &accrued_interest, &tax_amount, &amount_on_deposit),
      EXIT_DEPOSIT_INPUT_ERROR);
}

TEST(DepositCalculationTests, ZeroInterestRate) {
  double deposit_amount = 1000000.0;
  int month_term = 12;
  double interest_rate = 0.0;
  double tax_rate = 1;
  int repayment_periodicity = 2;
  int interest_capitalization = 1;
  double replenishment[2][2] = {{20000, 4}, {14000, 10}};
  int replenishment_count = 2;
  double withdraw[2][2] = {{12345, 6}, {2140, 11}};
  int withdraw_count = 2;
  double amount_on_deposit;
  double accrued_interest;
  double tax_amount;
  EXPECT_EQ(
      calcDeposit(deposit_amount, month_term, interest_rate, tax_rate,
                  repayment_periodicity, interest_capitalization, replenishment,
                  replenishment_count, withdraw, withdraw_count,
                  &accrued_interest, &tax_amount, &amount_on_deposit),
      EXIT_DEPOSIT_INPUT_ERROR);
}

TEST(DepositCalculationTests, NegativeInterestRate) {
  double deposit_amount = 1000000.0;
  int month_term = 12;
  double interest_rate = -5;
  double tax_rate = 1;
  int repayment_periodicity = 2;
  int interest_capitalization = 1;
  double replenishment[2][2] = {{20000, 4}, {14000, 10}};
  int replenishment_count = 2;
  double withdraw[2][2] = {{12345, 6}, {2140, 11}};
  int withdraw_count = 2;
  double amount_on_deposit;
  double accrued_interest;
  double tax_amount;
  EXPECT_EQ(
      calcDeposit(deposit_amount, month_term, interest_rate, tax_rate,
                  repayment_periodicity, interest_capitalization, replenishment,
                  replenishment_count, withdraw, withdraw_count,
                  &accrued_interest, &tax_amount, &amount_on_deposit),
      EXIT_DEPOSIT_INPUT_ERROR);
}

TEST(DepositCalculationTests, ZeroRepaymentPeriodicity) {
  double deposit_amount = 1000000.0;
  int month_term = 12;
  double interest_rate = 3.24;
  double tax_rate = 1;
  int repayment_periodicity = 0;
  int interest_capitalization = 1;
  double replenishment[2][2] = {{20000, 4}, {14000, 10}};
  int replenishment_count = 2;
  double withdraw[2][2] = {{12345, 6}, {2140, 11}};
  int withdraw_count = 2;
  double amount_on_deposit;
  double accrued_interest;
  double tax_amount;
  EXPECT_EQ(
      calcDeposit(deposit_amount, month_term, interest_rate, tax_rate,
                  repayment_periodicity, interest_capitalization, replenishment,
                  replenishment_count, withdraw, withdraw_count,
                  &accrued_interest, &tax_amount, &amount_on_deposit),
      EXIT_DEPOSIT_INPUT_ERROR);
}

TEST(DepositCalculationTests, NegativeRepaymentPeriodicity) {
  double deposit_amount = 1000000.0;
  int month_term = 12;
  double interest_rate = 3.24;
  double tax_rate = 1;
  int repayment_periodicity = -2;
  int interest_capitalization = 1;
  double replenishment[2][2] = {{20000, 4}, {14000, 10}};
  int replenishment_count = 2;
  double withdraw[2][2] = {{12345, 6}, {2140, 11}};
  int withdraw_count = 2;
  double amount_on_deposit;
  double accrued_interest;
  double tax_amount;
  EXPECT_EQ(
      calcDeposit(deposit_amount, month_term, interest_rate, tax_rate,
                  repayment_periodicity, interest_capitalization, replenishment,
                  replenishment_count, withdraw, withdraw_count,
                  &accrued_interest, &tax_amount, &amount_on_deposit),
      EXIT_DEPOSIT_INPUT_ERROR);
}

TEST(DepositCalculationTests, NegativeInterestCapitalization) {
  double deposit_amount = 1000000.0;
  int month_term = 12;
  double interest_rate = 3.24;
  double tax_rate = 1;
  int repayment_periodicity = 2;
  int interest_capitalization = -1;
  double replenishment[2][2] = {{20000, 4}, {14000, 10}};
  int replenishment_count = 2;
  double withdraw[2][2] = {{12345, 6}, {2140, 11}};
  int withdraw_count = 2;
  double amount_on_deposit;
  double accrued_interest;
  double tax_amount;
  EXPECT_EQ(
      calcDeposit(deposit_amount, month_term, interest_rate, tax_rate,
                  repayment_periodicity, interest_capitalization, replenishment,
                  replenishment_count, withdraw, withdraw_count,
                  &accrued_interest, &tax_amount, &amount_on_deposit),
      EXIT_DEPOSIT_INPUT_ERROR);
}

TEST(DepositCalculationTests, InvalidReplenishmentAmount) {
  double deposit_amount = 1000000.0;
  int month_term = 12;
  double interest_rate = 3.24;
  double tax_rate = 1;
  int repayment_periodicity = 2;
  int interest_capitalization = 2;
  double replenishment[2][2] = {{0, 4}, {14000, 10}};
  int replenishment_count = 2;
  double withdraw[2][2] = {{12345, 6}, {2140, 11}};
  int withdraw_count = 2;
  double amount_on_deposit;
  double accrued_interest;
  double tax_amount;
  EXPECT_EQ(
      calcDeposit(deposit_amount, month_term, interest_rate, tax_rate,
                  repayment_periodicity, interest_capitalization, replenishment,
                  replenishment_count, withdraw, withdraw_count,
                  &accrued_interest, &tax_amount, &amount_on_deposit),
      EXIT_DEPOSIT_INPUT_ERROR);
}

TEST(DepositCalculationTests, InvalidWithdrawalAmount) {
  double deposit_amount = 1000000.0;
  int month_term = 12;
  double interest_rate = 3.24;
  double tax_rate = 1;
  int repayment_periodicity = 2;
  int interest_capitalization = 2;
  double replenishment[2][2] = {{123, 4}, {14000, 10}};
  int replenishment_count = 2;
  double withdraw[2][2] = {{12345, 6}, {-6, 11}};
  int withdraw_count = 2;
  double amount_on_deposit;
  double accrued_interest;
  double tax_amount;
  EXPECT_EQ(
      calcDeposit(deposit_amount, month_term, interest_rate, tax_rate,
                  repayment_periodicity, interest_capitalization, replenishment,
                  replenishment_count, withdraw, withdraw_count,
                  &accrued_interest, &tax_amount, &amount_on_deposit),
      EXIT_DEPOSIT_INPUT_ERROR);
}

TEST(DepositCalculationTests, NegativeWithdrawCount) {
  double deposit_amount = 1000000.0;
  int month_term = 12;
  double interest_rate = 3.24;
  double tax_rate = 1;
  int repayment_periodicity = 2;
  int interest_capitalization = 2;
  double replenishment[2][2] = {{123, 4}, {14000, 10}};
  int replenishment_count = 2;
  double withdraw[2][2] = {{12345, 6}, {2140, 11}};
  int withdraw_count = -1;
  double amount_on_deposit;
  double accrued_interest;
  double tax_amount;
  EXPECT_EQ(
      calcDeposit(deposit_amount, month_term, interest_rate, tax_rate,
                  repayment_periodicity, interest_capitalization, replenishment,
                  replenishment_count, withdraw, withdraw_count,
                  &accrued_interest, &tax_amount, &amount_on_deposit),
      EXIT_DEPOSIT_INPUT_ERROR);
}

TEST(DepositCalculationTests, InvalidWithdrawalAmount2) {
  double deposit_amount = 1000000.0;
  int month_term = 12;
  double interest_rate = 3.24;
  double tax_rate = 1;
  int repayment_periodicity = 2;
  int interest_capitalization = 2;
  double replenishment[2][2] = {{123, 4}, {14000, 10}};
  int replenishment_count = 2;
  double withdraw[2][2] = {{0, 6}, {2140, 11}};
  int withdraw_count = 2;
  double amount_on_deposit;
  double accrued_interest;
  double tax_amount;
  EXPECT_EQ(
      calcDeposit(deposit_amount, month_term, interest_rate, tax_rate,
                  repayment_periodicity, interest_capitalization, replenishment,
                  replenishment_count, withdraw, withdraw_count,
                  &accrued_interest, &tax_amount, &amount_on_deposit),
      EXIT_DEPOSIT_INPUT_ERROR);
}

TEST(DepositCalculationTests, InvalidReplenishmentAmount2) {
  double deposit_amount = 1000000.0;
  int month_term = 12;
  double interest_rate = 3.24;
  double tax_rate = 1;
  int repayment_periodicity = 2;
  int interest_capitalization = 2;
  double replenishment[2][2] = {{123, 4}, {0, 10}};
  int replenishment_count = 2;
  double withdraw[2][2] = {{12345, 6}, {2140, 11}};
  int withdraw_count = 2;
  double amount_on_deposit;
  double accrued_interest;
  double tax_amount;
  EXPECT_EQ(
      calcDeposit(deposit_amount, month_term, interest_rate, tax_rate,
                  repayment_periodicity, interest_capitalization, replenishment,
                  replenishment_count, withdraw, withdraw_count,
                  &accrued_interest, &tax_amount, &amount_on_deposit),
      EXIT_DEPOSIT_INPUT_ERROR);
}

TEST(DepositCalculationTests, NegativeReplenishmentCount) {
  double deposit_amount = 1000000.0;
  int month_term = 12;
  double interest_rate = 3.24;
  double tax_rate = 1;
  int repayment_periodicity = 2;
  int interest_capitalization = 2;
  double replenishment[2][2] = {{123, 4}, {14000, 10}};
  int replenishment_count = -2;
  double withdraw[2][2] = {{12345, 6}, {2140, 0}};
  int withdraw_count = 2;
  double amount_on_deposit;
  double accrued_interest;
  double tax_amount;
  EXPECT_EQ(
      calcDeposit(deposit_amount, month_term, interest_rate, tax_rate,
                  repayment_periodicity, interest_capitalization, replenishment,
                  replenishment_count, withdraw, withdraw_count,
                  &accrued_interest, &tax_amount, &amount_on_deposit),
      EXIT_DEPOSIT_INPUT_ERROR);
}

TEST(DepositCalculationTests, InvalidReplenishmentPeriod) {
  double deposit_amount = 1000000.0;
  int month_term = 12;
  double interest_rate = 3.24;
  double tax_rate = 1;
  int repayment_periodicity = 2;
  int interest_capitalization = 2;
  double replenishment[2][2] = {{123, 14}, {14000, 10}};
  int replenishment_count = 2;
  double withdraw[2][2] = {{12345, 6}, {2140, 11}};
  int withdraw_count = 2;
  double amount_on_deposit;
  double accrued_interest;
  double tax_amount;
  EXPECT_EQ(
      calcDeposit(deposit_amount, month_term, interest_rate, tax_rate,
                  repayment_periodicity, interest_capitalization, replenishment,
                  replenishment_count, withdraw, withdraw_count,
                  &accrued_interest, &tax_amount, &amount_on_deposit),
      EXIT_DEPOSIT_INPUT_ERROR);
}

TEST(GeometricGraphTests, SinusoidalFunction) {
  char *expression = "sin(x)";
  double l = -10;
  double r = 10;
  double step = 2;
  int count = (int)((r - l) / step) + 1;
  double coordinates[100][2];
  double real_coordinates[100][2] = {{-10, 0.544}, {-8, -0.989}, {-6, 0.279},
                                     {-4, 0.757},  {-2, -0.909}, {0, 0},
                                     {2, 0.909},   {4, -0.757},  {6, -0.279},
                                     {8, 0.989},   {10, -0.544}};
  s21::model mdl;
  s21::controller cntr(mdl);
  ASSERT_EQ(cntr.getGraph(expression, l, r, step, coordinates), 0);
  for (int i = 0; i < count; ++i) {
    ASSERT_NEAR(coordinates[i][0], real_coordinates[i][0], eps3);
    ASSERT_NEAR(coordinates[i][1], real_coordinates[i][1], eps3);
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
