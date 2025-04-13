#include "sysTim.h"
#include <stdint.h>

#define MAX_TASKS 10

static void (*sysTim_function_task[MAX_TASKS])(void);
static uint8_t number_of_task = 1;
static uint32_t sysTim_task_period[MAX_TASKS];
static uint32_t elapsed_time[MAX_TASKS];
static bool task_waiting[MAX_TASKS];
static bool no_task = true;



void sysTim_add_task(void (*function_task)(void), const uint32_t period) {
    if (period != 0 || number_of_task < MAX_TASKS) {
        if (no_task) {
            no_task = false;
        }
        sysTim_function_task[number_of_task] = function_task;
        sysTim_task_period[number_of_task] = period;
        elapsed_time[number_of_task] = 0;

        number_of_task++;
    }
}


void sysTim_check_for_events() {
    for (uint8_t i = 0; i < number_of_task; i++) {
        if (task_waiting[i]) {
            task_waiting[i] = false;
            elapsed_time[i] = 0;
            sysTim_function_task[i]();
        }
    }
}


void HAL_SYSTICK_Callback(void) {
    for (uint8_t i = 0; i < MAX_TASKS; i++) {
        if (elapsed_time[i] == sysTim_task_period[i]) {
            task_waiting[i] = true;
        } else {
            elapsed_time[i]++;
        }
    }
}