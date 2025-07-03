
#ifndef __SG90_H__
#define __SG90_H__

#include <stdint.h>

/* 
 * @brief 设置舵机控制PWM占空比
 * @param duty 占空比值，范围在2.5到12.5之间
 */
void __SG90_SetDuty(float duty);

/*
 * @brief 初始化舵机
 */
void SG90_Init(void);

/*
 * @brief 设置舵机角度
 * @param angle 舵机角度，0-180之间，90度为正
 */
void SG90_SetAngle(int angle);

/* 
 * @brief 舵机向左转向
 */
void SG90_TurnLeft(void);

/* 
 * @brief 舵机向右转向
 */
void SG90_TurnRight(void);

#endif /* __SG90_H__ */
