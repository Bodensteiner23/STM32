#pragma once

#ifdef __cplusplus
extern "C" {
#endif
#include <stm32f3xx.h>
    void app_hello_world();
    void app_test();
    void app_init(UART_HandleTypeDef *huart);
    void app_test_uart();

#ifdef __cplusplus
}
#endif


