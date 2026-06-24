#ifndef __GPIO_CONF_H
#define __GPIO_CONF_H


#include "debug.h"

#define T1_PORT   GPIOD
#define T1_PIN    GPIO_Pin_2   // PD2
#define T2_PORT   GPIOC
#define T2_PIN    GPIO_Pin_7   // PC7
#define T3_PORT   GPIOC
#define T3_PIN    GPIO_Pin_6   // PC6
#define T4_PORT   GPIOC
#define T4_PIN    GPIO_Pin_5   // PC5
#define T5_PORT   GPIOC
#define T5_PIN    GPIO_Pin_4   // PC4
#define T6_PORT   GPIOC
#define T6_PIN    GPIO_Pin_3   // PC3

/* Output */
#define L1_PORT   GPIOC
#define L1_PIN    GPIO_Pin_0   // PC0


void GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD, ENABLE);

    /* Output PC0 */
    GPIO_InitStructure.GPIO_Pin = L1_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_30MHz;
    GPIO_Init(L1_PORT, &GPIO_InitStructure);

    /* PD2 input */
    GPIO_InitStructure.GPIO_Pin = T1_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(T1_PORT, &GPIO_InitStructure);

    /* PC7,6,5,4,3 inputs */
    GPIO_InitStructure.GPIO_Pin = T2_PIN | T3_PIN | T4_PIN | T5_PIN | T6_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
}

#endif 