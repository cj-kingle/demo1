#include "main_task.hpp"

extern TIM_HandleTypeDef htim3;
extern IWDG_HandleTypeDef hiwdg;

volatile uint32_t tick = 0;

extern "C"
void Task_Init(void)
{

    // PC13低电平，LED亮
    HAL_GPIO_WritePin(
        GPIOC,
        GPIO_PIN_13,
        GPIO_PIN_RESET
    );


    // 开启TIM3更新中断
    HAL_TIM_Base_Start_IT(&htim3);

}



extern "C"
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if(htim->Instance == TIM3)
    {
        tick = tick + 1;
        // 定时器喂狗
        //HAL_IWDG_Refresh(&hiwdg);

    }

}