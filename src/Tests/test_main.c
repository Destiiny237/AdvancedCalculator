#include "test_main.h"

int main() {
  int failed = 0;

  Suite *calc_test[] = { test_calc(), NULL};

  for (int i = 0; calc_test[i] != NULL; i++) {
    SRunner *sr = srunner_create(calc_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}

double get_result(char* test_expression, double x){
    char* expression = expression_parser(test_expression);
    double result = expression_solver(expression, x);
    free(expression);
    return result;
}