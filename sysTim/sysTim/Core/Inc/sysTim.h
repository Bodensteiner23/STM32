#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

    void sysTim_add_task(void (*function_task)(void), const uint32_t period);
    void sysTim_check_for_events();

#ifdef __cplusplus
}
#endif


