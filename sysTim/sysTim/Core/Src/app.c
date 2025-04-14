#include "app.h"

#include "main.h"

uint8_t data[] = "HELLO_WORLD\n";
uint8_t test[] = "TEST";
UART_HandleTypeDef *app_huart;

void app_init(UART_HandleTypeDef *huart) {
    app_huart = huart;
}

void app_hello_world() {
    HAL_UART_Transmit(app_huart, data, 12, HAL_MAX_DELAY);
}

void app_test() {
    HAL_UART_Transmit(app_huart, test, 4, HAL_MAX_DELAY);
}

void app_test_uart() {
    HAL_UART_Transmit(app_huart, data, 11, 1);
    HAL_Delay(1000);
}