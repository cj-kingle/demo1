#ifndef MAIN_TASK_HPP
#define MAIN_TASK_HPP

#include "main.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void Task_Init(void);

extern volatile uint32_t tick;

#ifdef __cplusplus
}
#endif

#endif