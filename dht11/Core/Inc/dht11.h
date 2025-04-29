#pragma once
#include <cstdint>
#include <stm32f3xx_hal.h>

class DHT11 {
private:
    GPIO_TypeDef* sensor_port;
    uint16_t sensor_pin;
    uint8_t data[40] { 0 };

    bool init_communication();

public:
    explicit DHT11 (GPIO_TypeDef* port, const uint16_t pin) : sensor_port(port), sensor_pin(pin) {
        for (uint8_t i = 0; i < 40; i++) {
            data[i] = 0;
        }
    };   // ToDo: Check what is explicit

    bool read_data();
    float get_temp();
    float get_humid();

};



