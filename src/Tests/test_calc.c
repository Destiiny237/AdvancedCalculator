#include "test_main.h"

START_TEST(test_calc_1) {
  char test_expression[MAX_STRING_LENGTH] = "-2+2*(3-2)";
  double real_result = 0.0f;
  if(isValid(test_expression)){
    double result = get_result(test_expression, 0);
    ck_assert_double_eq_tol(real_result, result, 1.0E-7);
  } else{
    ck_abort();
  }
}
END_TEST

START_TEST(test_calc_2) {
  char test_expression[MAX_STRING_LENGTH] = "sin(cos(tan(5)))";
  double real_result = -0.8257855f;
  if(isValid(test_expression)){
    double result = get_result(test_expression, 0);
    ck_assert_double_eq_tol(real_result, result, 1.0E-7);
  } else{
    ck_abort();
  }
}
END_TEST

START_TEST(test_calc_3) {
  char test_expression[MAX_STRING_LENGTH] = "sin(8 * tan(4 + 8 * 2^(5 + 5 * 2)))";
  double real_result = -0.9998264f;
  if(isValid(test_expression)){
    double result = get_result(test_expression, 0);
    ck_assert_double_eq_tol(real_result, result, 1.0E-7);
  } else{
    ck_abort();
  }
}
END_TEST

START_TEST(test_calc_4) {
  char test_expression[MAX_STRING_LENGTH] = "-ln(12.659)";
  double real_result = -2.5383684f;
  if(isValid(test_expression)){
    double result = get_result(test_expression, 0);
    ck_assert_double_eq_tol(real_result, result, 1.0E-7);
  } else{
    ck_abort();
  }
}
END_TEST

START_TEST(test_calc_5) {
  char test_expression[MAX_STRING_LENGTH] = "log(ln(6^2))";
  double real_result = 0.5543097f;
  if(isValid(test_expression)){
    double result = get_result(test_expression, 0);
    ck_assert_double_eq_tol(real_result, result, 1.0E-7);
  } else{
    ck_abort();
  }
}
END_TEST

START_TEST(test_calc_6) {
  char test_expression[MAX_STRING_LENGTH] = "log(log(log(52)))";
  double real_result = -0.6298235f;
  if(isValid(test_expression)){
    double result = get_result(test_expression, 0);
    ck_assert_double_eq_tol(real_result, result, 1.0E-7);
  } else{
    ck_abort();
  }
}
END_TEST

START_TEST(test_calc_7) {
  char test_expression[MAX_STRING_LENGTH] = "(2 * 3 + 6 / 2 - 3) * (2 + 6 + (4 / 3 - 6 + 9 * (2 + 2)))";
  double real_result = 236.0f;
  if(isValid(test_expression)){
    double result = get_result(test_expression, 0);
    ck_assert_double_eq_tol(real_result, result, 1.0E-7);
  } else{
    ck_abort();
  }
}
END_TEST

START_TEST(test_calc_8) {
  char test_expression[MAX_STRING_LENGTH] = "10mod(3*2)";
  double real_result = 4.0f;
  if(isValid(test_expression)){
    double result = get_result(test_expression, 0);
    ck_assert_double_eq_tol(real_result, result, 1.0E-7);
  } else{
    ck_abort();
  }
}
END_TEST

START_TEST(test_calc_9) {
  char test_expression[MAX_STRING_LENGTH] = "-(2) * 3";
  double real_result = -6.0f;
  if(isValid(test_expression)){
    double result = get_result(test_expression, 0);
    ck_assert_double_eq_tol(real_result, result, 1.0E-7);
  } else{
    ck_abort();
  }
}
END_TEST

START_TEST(test_calc_10) {
  char test_expression[MAX_STRING_LENGTH] = "23mod(asin(0.9))";
  double real_result = 0.6046098;
  if(isValid(test_expression)){
    double result = get_result(test_expression, 0);
    ck_assert_double_eq_tol(real_result, result, 1.0E-7);
  } else{
    ck_abort();
  }
}
END_TEST

START_TEST(test_calc_11) {
  char test_expression[MAX_STRING_LENGTH] = "ln(sqrt(log(sqrt(5233332.555)*log(3876.8768))))";
  double real_result = 0.6823182;
  if(isValid(test_expression)){
    double result = get_result(test_expression, 0);
    ck_assert_double_eq_tol(real_result, result, 1.0E-7);
  } else{
    ck_abort();
  }
}
END_TEST

START_TEST(test_calc_12) {
  char test_expression[MAX_STRING_LENGTH] = "+atan(sqrt(x) * 5) + acos(sqrt(0.45235))";
  double real_result = 2.3763357;
  if(isValid(test_expression)){
    double result = get_result(test_expression, 52.555);
    ck_assert_double_eq_tol(real_result, result, 1.0E-7);
  } else{
    ck_abort();
  }
}
END_TEST

START_TEST(test_calc_13) {
  char test_expression[MAX_STRING_LENGTH] = "sin(x))";
  ck_assert_int_eq(isValid(test_expression), 0);
}
END_TEST

START_TEST(test_calc_14) {
  char test_expression[MAX_STRING_LENGTH] = "--sin(5)";
  ck_assert_int_eq(isValid(test_expression), 0);
}
END_TEST

START_TEST(test_calc_15) {
  char test_expression[MAX_STRING_LENGTH] = "()/2";
  ck_assert_int_eq(isValid(test_expression), 0);
}
END_TEST

START_TEST(test_calc_16) {
  char test_expression[MAX_STRING_LENGTH] = "34.+4";
  ck_assert_int_eq(isValid(test_expression), 0);
}
END_TEST

START_TEST(test_calc_17) {
  char test_expression[MAX_STRING_LENGTH] = "34+(*)";
  ck_assert_int_eq(isValid(test_expression), 0);
}
END_TEST

START_TEST(test_calc_18) {
  char test_expression[MAX_STRING_LENGTH] = "sin()";
  ck_assert_int_eq(isValid(test_expression), 0);
}
END_TEST

START_TEST(test_calc_19) {
  char test_expression[MAX_STRING_LENGTH] = "mod5";
  ck_assert_int_eq(isValid(test_expression), 0);
}
END_TEST

START_TEST(test_calc_20) {
  char test_expression[MAX_STRING_LENGTH] = "3mod(3+3)";
  ck_assert_int_eq(isValid(test_expression), 1);
}
END_TEST

START_TEST(test_calc_21) {
  char test_expression[MAX_STRING_LENGTH] = "3mod()";
  ck_assert_int_eq(isValid(test_expression), 0);
}
END_TEST

START_TEST(test_calc_22) {
  char test_expression[MAX_STRING_LENGTH] = "2+54.1234+";
  ck_assert_int_eq(isValid(test_expression), 0);
}
END_TEST

START_TEST(test_calc_23) {
  char test_expression[MAX_STRING_LENGTH] = "2+54.1234+cos";
  ck_assert_int_eq(isValid(test_expression), 0);
}
END_TEST

START_TEST(test_calc_24) {
  char test_expression[MAX_STRING_LENGTH] = "cossin1";
  ck_assert_int_eq(isValid(test_expression), 0);
}
END_TEST

START_TEST(test_calc_25) {
  char test_expression[MAX_STRING_LENGTH] = "()))()";
  ck_assert_int_eq(isValid(test_expression), 0);
}
END_TEST

START_TEST(test_calc_26) {
  char test_expression[MAX_STRING_LENGTH] = "x2+1";
  ck_assert_int_eq(isValid(test_expression), 0);
}
END_TEST

START_TEST(test_calc_27) {
  char test_expression[MAX_STRING_LENGTH] = "xxx";
  ck_assert_int_eq(isValid(test_expression), 0);
}
END_TEST

Suite *test_calc(void) {
  Suite *s = suite_create("\033[45m-=calc_test=-\033[0m");
  TCase *tc = tcase_create("calc_tc");

  tcase_add_test(tc, test_calc_1);
  tcase_add_test(tc, test_calc_2);
  tcase_add_test(tc, test_calc_3);
  tcase_add_test(tc, test_calc_4);
  tcase_add_test(tc, test_calc_5);
  tcase_add_test(tc, test_calc_6);
  tcase_add_test(tc, test_calc_7);
  tcase_add_test(tc, test_calc_8);
  tcase_add_test(tc, test_calc_9);
  tcase_add_test(tc, test_calc_10);
  tcase_add_test(tc, test_calc_11);
  tcase_add_test(tc, test_calc_12);
  tcase_add_test(tc, test_calc_13);
  tcase_add_test(tc, test_calc_14);
  tcase_add_test(tc, test_calc_15);
  tcase_add_test(tc, test_calc_16);
  tcase_add_test(tc, test_calc_17);
  tcase_add_test(tc, test_calc_18);
  tcase_add_test(tc, test_calc_19);
  tcase_add_test(tc, test_calc_20);
  tcase_add_test(tc, test_calc_21);
  tcase_add_test(tc, test_calc_22);
  tcase_add_test(tc, test_calc_23);
  tcase_add_test(tc, test_calc_24);
  tcase_add_test(tc, test_calc_25);
  tcase_add_test(tc, test_calc_26);
  tcase_add_test(tc, test_calc_27);

  suite_add_tcase(s, tc);
  return s;
}
