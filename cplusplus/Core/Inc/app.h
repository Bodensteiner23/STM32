#pragma once

#ifdef __cplusplus

template <class T, class U>
double calculate(T a, U b) {
    double result = a * b;
    return result;
}


extern "C" {
#endif
    double app_test_function(void);

#ifdef __cplusplus
}
#endif
