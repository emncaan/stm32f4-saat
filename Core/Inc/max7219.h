/**
  ******************************************************************************
  * @file    STM32F4_MAX7219/Inc/max7219.h 
  * @author  thzvm
  * @brief   Header for max7219.c module
  *
  *
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef MAX7219_H_
#define MAX7219_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "main.h"

/* Exported constants --------------------------------------------------------*/
#define SEGMENTS 8

/* Register Address Map */
#define MAX7219_No_Op         0x00
#define MAX7219_DIG_0         0x01
#define MAX7219_DIG_1         0x02
#define MAX7219_DIG_2         0x03
#define MAX7219_DIG_3         0x04
#define MAX7219_DIG_4         0x05
#define MAX7219_DIG_5         0x06
#define MAX7219_DIG_6         0x07
#define MAX7219_DIG_7         0x08
#define MAX7219_DECODE_MODE   0x09  // No decode: 0x00, DIG_0: 0x01; DIG_0..3: 0x0F, DIG_0..7: 0xFF
#define MAX7219_INTENSITY     0x0A  // 0x00 - 0x0F
#define MAX7219_SCAN_LIMIT    0x0B  // 0x00 - 0x07 (num of segments - 1)
#define MAX7219_SHUTDOWN      0x0C  // Shutdown 0x00, Normal 0x01
#define MAX7219_DISPLAY_TEST  0x0F  // 0x00, 0x01

/* Code B Font */
#define MAX7219_CodeB_0       0x7E  
#define MAX7219_CodeB_1       0x30  
#define MAX7219_CodeB_2       0x6D   
#define MAX7219_CodeB_3       0x79
#define MAX7219_CodeB_4       0x33
#define MAX7219_CodeB_5       0x5B
#define MAX7219_CodeB_6       0x5F
#define MAX7219_CodeB_7       0x70
#define MAX7219_CodeB_8       0x7F
#define MAX7219_CodeB_9       0x7B
#define MAX7219_CodeB_dash    0x01
#define MAX7219_CodeB_dot     0x80
#define MAX7219_CodeB_E       0x0E
#define MAX7219_CodeB_H       0x37
#define MAX7219_CodeB_L       0x0D
#define MAX7219_CodeB_P       0x67
#define MAX7219_CodeB_blank   0x00
 
#define DECODE_MODE_DISABLE   0x00
#define DECODE_MODE_ENABLE    0xFF

#define ENABLE                    0x01
#define DISABLE                   0x00

/* Exported functions ------------------------------------------------------- */
void CS_SET(void);
void CS_RESET(void);
void MAX7219_Init(void);
void MAX7219_SendByte(uint8_t address, uint8_t data);
void MAX7219_Clear(void);

#endif /* MAX7219_H_    */
