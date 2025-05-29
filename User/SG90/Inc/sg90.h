
#ifndef __SG90_H__
#define __SG90_H__

#include <stdint.h>

/*
 * @brief 初始化舵机
 */
void SG90_Init(void);

/*
 * @brief 设置舵机角度
 * @param duty 占空比值，范围在2.5到12.5之间
 */
void SG90_SetAngle(float duty);

#endif /* __SG90_H__ */
