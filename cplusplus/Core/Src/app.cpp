#include "app.h"


double app_test_function(void) {
    double a_doub = 20;
    double b_doub = 30;

    auto result = calculate(a_doub, b_doub);

    return result;
}