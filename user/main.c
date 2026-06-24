#include "debug.h"
#include "i2c_slave.h"
#include "gpio_conf.h"
/* ---------------- Pin Naming ---------------- */

/* Inputs */

/* ---------------- GPIO Config ---------------- */
//  

/* ---------------- Main ---------------- */
int main(void)
{
    Delay_Init();
    USART_Printf_Init(115200);

    printf("CH32V003 GPIO -> I2C Slave\r\n");

    GPIO_Config();
    IIC_Init(100000, I2C_SLAVE_ADDR);   // I2C Slave init @100kHz

    while(1)
    {
        uint8_t tStatus = 0;

        /* Pack GPIO inputs */
        tStatus |= (GPIO_ReadInputDataBit(T1_PORT, T1_PIN) << 0);
        tStatus |= (GPIO_ReadInputDataBit(T2_PORT, T2_PIN) << 1);
        tStatus |= (GPIO_ReadInputDataBit(T3_PORT, T3_PIN) << 2);
        tStatus |= (GPIO_ReadInputDataBit(T4_PORT, T4_PIN) << 3);
        tStatus |= (GPIO_ReadInputDataBit(T5_PORT, T5_PIN) << 4);
        tStatus |= (GPIO_ReadInputDataBit(T6_PORT, T6_PIN) << 5);

        /* Update I2C TX buffer with the latest value */
        I2C_SendByte(tStatus);

        /* Local debug print */
        printf("GPIO Byte = 0x%02X\r\n", tStatus);

        /* Control L1 LED */
        if(tStatus > 0) {
            GPIO_SetBits(L1_PORT, L1_PIN);
        } else {
            GPIO_ResetBits(L1_PORT, L1_PIN);
        }

        Delay_Ms(2);
    }
}
