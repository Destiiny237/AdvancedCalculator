#ifndef SRC_TESTS_ME_H
#define SRC_TESTS_ME_H

#include "../Backend/backend.h"
#include "../SmartCalc.h"

#include <check.h>

double get_result(char* test_expression, double x);

Suite *test_calc(void);

#endif
