/**
  ******************************************************************************
  * @file    STM32F4_MAX7219/Src/max7219.c 
  * @author  thzvm
  * @brief   MAX7219
  *
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "max7219.h"

/* Exported constants --------------------------------------------------------*/
extern SPI_HandleTypeDef hspi4;

/* Private variables ---------------------------------------------------------*/
uint8_t SPI_BUF_TX[2] = {0};

/* Private functions ---------------------------------------------------------*/
void CS_SET(void){
  // Set chip select (CS)
  HAL_GPIO_WritePin(SPI4_CS_GPIO_Port, SPI4_CS_Pin, GPIO_PIN_RESET);
}

void CS_RESET(void){
  // Reset chip select (CS)
  HAL_GPIO_WritePin(SPI4_CS_GPIO_Port, SPI4_CS_Pin, GPIO_PIN_SET);
}

void MAX7219_SendByte(uint8_t address, uint8_t data){
  //
  SPI_BUF_TX[0] = address;
  SPI_BUF_TX[1] = data;

  CS_SET();
  HAL_SPI_Transmit(&hspi4, (uint8_t*)SPI_BUF_TX, 2, 10);
  CS_RESET();
}

void MAX7219_Clear(void){
  //
  uint8_t i = SEGMENTS;
  do{MAX7219_SendByte(i, MAX7219_CodeB_blank);
  } while (--i);
}

void MAX7219_Init(void){
  //
  MAX7219_SendByte(MAX7219_DECODE_MODE, DECODE_MODE_DISABLE);
  MAX7219_SendByte(MAX7219_SCAN_LIMIT, SEGMENTS - 1);
  MAX7219_SendByte(MAX7219_INTENSITY, 0x0F);
  MAX7219_SendByte(MAX7219_DISPLAY_TEST, DISABLE);
  MAX7219_SendByte(MAX7219_SHUTDOWN, ENABLE);
  MAX7219_Clear();
}

