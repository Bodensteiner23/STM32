#include "app.h"

#include <main.h>


void app_green_led() {
    HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
}


void app_red_led() {
    HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
}