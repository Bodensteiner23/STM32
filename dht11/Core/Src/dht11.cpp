#include "dht11.h"
#include <stm32f3xx_hal.h>


bool DHT11::init_communication() {
    HAL_GPIO_WritePin(sensor_port, sensor_pin, GPIO_PIN_RESET);
    HAL_Delay(20);
    HAL_GPIO_WritePin(sensor_port, sensor_pin, GPIO_PIN_SET);
    // delayMicroseconds(80);   // ToDo: Microseconds
    if (HAL_GPIO_ReadPin(sensor_port, sensor_pin) == 0) {
        // delayMicroseconds(80);
        if (HAL_GPIO_ReadPin(sensor_port, sensor_pin) == 1) {
            return true;
        }
    }
    return false;
}


bool DHT11::read_data() {
    if (!DHT11::init_communication()) {
        // No communication
        return false;
    }

    for (uint8_t i = 0; i < 40; i++) {
        while (HAL_GPIO_ReadPin(sensor_port, sensor_pin) != 0) {
            // Wait until transmission starting
            // ToDo: Add timer to avoid endless loop. Also return false if that timer elapsed
        }

        // delayMicroseconds(100);
        if (HAL_GPIO_ReadPin(sensor_port, sensor_pin) == 1) {
            DHT11::data[i] = 1;
        } else {
            DHT11::data[i] = 0;
        }
    }

    return true;
}


float DHT11::get_humid() {
    int humid_int = 0;
    int humid_dec = 0;

    for (uint8_t i = 0; i < 8; i++) {
        humid_int |= (data[i] & 1) << i;
    }
    for (uint8_t i = 8; i < 16; i++) {
        humid_dec |= (data[i] & 1) << (i % 8);
    }

    float humid = humid_int + (humid_dec / 100);

    return humid;
}


float DHT11::get_temp() {
    int temp_int = 0;
    int temp_dec = 0;

    for (uint8_t i = 17; i < 24; i++) {
        temp_int |= (data[i] & 1) << (i % 8);
    }
    for (uint8_t i = 24; i < 32; i++) {
        temp_dec |= (data[i] & 1) << (i % 8);
    }

    float temp = temp_int + (temp_dec / 100);

    return temp;
}



