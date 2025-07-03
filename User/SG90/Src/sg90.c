/*
 * @file sg90.c 
 * @brief 舵机控制实现
 * @note 舵机控制PWM信号频率50Hz，占空比范围2.5%到12.5%
 */
#include "sg90.h"
#include "tim.h"

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
/* @brief 舵机初始占空比（百分比）*/
#define SG90_INIT_DUTY 7.5f //这里你们试一下设成多少舵是正的
/* @brief 舵机向左转向时的占空比（百分比）*/
#define SG90_LEFT_DUTY 0.0f //这里是左转的时候设置的角度
/* @brief 舵机向左转向时的占空比（百分比）*/
#define SG90_RIGHT_DUTY 0.0f //这里是右转的时候的角度
//注意上面三个角度必须在数值必须在2.5到12.5之间

/* 
 * @brief 设置舵机控制PWM占空比
 * @param duty 占空比值，范围在2.5到12.5之间
 */
void __SG90_SetDuty(float duty)
{
	if (duty <= SG90_MAX_DUTY && duty >= SG90_MIN_DUTY)
	{
		__HAL_TIM_SET_COMPARE(SG90_TIM, SG90_CHANNEL, (uint32_t)((duty + SG90_MODIFER) * SG90_PERIOD));
	}
}

/* 
 * @brief 舵机初始化函数 
 */
void SG90_Init(void)
{
	HAL_TIM_PWM_Start(SG90_TIM, SG90_CHANNEL);
	SG90_SetAngle(SG90_INIT_DUTY);
}

/*
 * @brief 设置舵机角度
 * @param angle 舵机角度，0-180之间，90度为正
 */
void SG90_SetAngle(float angle)
{
	if (angle < 0 || angle > 180)
	{
		return;
	}

	float duty = (angle / 18) + 2.5;
	__SG90_SetDuty(duty);
	return;
}

void SG90_TurnLeft()
{
	__SG90_SetDuty(SG90_LEFT_DUTY);
}

void SG90_TurnRight()
{
	__SG90_SetDuty(SG90_RIGHT_DUTY);
}
