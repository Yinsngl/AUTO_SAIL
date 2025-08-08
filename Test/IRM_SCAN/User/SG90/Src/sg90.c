/*
 * @file sg90.c 
 * @brief 舵机控制实现
 * @note 舵机控制PWM信号频率50Hz，占空比范围2.5%到12.5%
 */
#include "sg90.h"
#include "tim.h"

#include "usart.h"
#include <stdio.h>

/* @brief 控制舵机的Timer*/
#define SG90_TIM &htim2
/* @brief 控制舵机的Timer通道*/
#define SG90_CHANNEL TIM_CHANNEL_2

/* @brief 舵机周期（单位：ms）*/
#define SG90_PERIOD 20
/* @brief 舵机最小占空比（百分比）*/
#define SG90_MIN_DUTY 2.5f
/* @brief 舵机最大占空比（百分比）*/
#define SG90_MAX_DUTY 12.5f
/* 
 * @brief 舵机占空比修正值（百分比）
 * @note 该值根据实际角度与预期偏转角度差值进行调整
 */
#define SG90_MODIFER 0.0f

#if SHEEPNUM == 1
/* 
 * @brief 船1对应参数
 */

/* @brief 舵机初始角度*/
#define SG90_INIT_ANGLE 150 
/* @brief 舵机向左转向时的角度*/
#define SG90_LEFT_ANGLE 180
/* @brief 舵机向右转向时的角度*/
#define SG90_RIGHT_ANGLE 115
#endif	

#if SHEEPNUM == 2
/* 
 * @brief 船2对应参数
 */	

/* @brief 舵机初始角度*/
#define SG90_INIT_ANGLE 30
/* @brief 舵机向左转向时的角度*/
#define SG90_LEFT_ANGLE 80
/* @brief 舵机向右转向时的角度*/
#define SG90_RIGHT_ANGLE 0
#endif

#define SG90_INIT_DUTY (SG90_INIT_ANGLE / 18.0f) + 2.5

char message[20];
uint32_t defaultCMP = (uint32_t)((SG90_INIT_DUTY + SG90_MODIFER) * SG90_PERIOD);


/* 
 * @brief 设置舵机控制PWM占空比
 * @param duty 占空比值，范围在2.5到12.5之间
 */
void __SG90_SetDuty(float duty)
{
	/*
	#if SHEEPNUM == 1
	uint32_t cmp = __HAL_TIM_GET_COMPARE(&htim2, TIM_CHANNEL_2);
	int direction = 1;
	if (cmp > defaultCMP)
	direction = 2;
	else if (cmp < defaultCMP)
	direction = 0;

	// sprintf(message, "direction:%d\n", direction);
	// HAL_UART_Transmit(&huart2, (uint8_t*)message, sizeof(message), HAL_MAX_DELAY);
	// sprintf(message, "cmp:%d\n", (int)cmp);
	// HAL_UART_Transmit(&huart2, (uint8_t*)message, sizeof(message), HAL_MAX_DELAY);
	
	int turn = 1;
	if (duty > SG90_INIT_DUTY)
	turn = 2;
	else if (duty < SG90_INIT_DUTY)
	turn = 0;

	// sprintf(message, "turn:%d\n", turn);
	// HAL_UART_Transmit(&huart2, (uint8_t*)message, sizeof(message), HAL_MAX_DELAY);
	// sprintf(message, "duty:%f\n", duty);
	// HAL_UART_Transmit(&huart2, (uint8_t*)message, sizeof(message), HAL_MAX_DELAY);
	// sprintf(message, "def:%d\n", defaultCMP);
	// HAL_UART_Transmit(&huart2, (uint8_t*)message, sizeof(message), HAL_MAX_DELAY);

	if (direction == 1)
	__HAL_TIM_SET_COMPARE(SG90_TIM, SG90_CHANNEL, (duty + SG90_MODIFER) * SG90_PERIOD);
	else if (direction != turn)
	__HAL_TIM_SET_COMPARE(SG90_TIM, SG90_CHANNEL, (SG90_INIT_DUTY + SG90_MODIFER) * SG90_PERIOD);
	#endif

	#if SHEEPNUM == 2
	*/
	__HAL_TIM_SET_COMPARE(SG90_TIM, SG90_CHANNEL, (duty + SG90_MODIFER) * SG90_PERIOD);
	// #endif
}

/* 
 * @brief 舵机初始化函数 
 */
void SG90_Init(void)
{
	HAL_TIM_PWM_Start(SG90_TIM, SG90_CHANNEL);
	SG90_SetAngle(SG90_INIT_ANGLE);
}

/*
 * @brief 设置舵机角度
 * @param angle 舵机角度，0-180之间，90度为正
 */
void SG90_SetAngle(int angle)
{
	/*if (angle < 0 || angle > 180)
	{
		return;
	}*/

	float duty = (angle / 18.0f) + 2.5;
	__SG90_SetDuty(duty);
	return;
}

/* 
 * @brief 舵机向左转向
 */
void SG90_TurnLeft()
{
	SG90_SetAngle(SG90_LEFT_ANGLE);
}

/* 
 * @brief 舵机向右转向
 */
void SG90_TurnRight()
{
	SG90_SetAngle(SG90_RIGHT_ANGLE);
}

/* 
 * @brief 舵机归中
 */
void SG90_Reset()
{
	SG90_SetAngle(SG90_INIT_ANGLE);
}