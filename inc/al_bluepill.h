/* Copyright 2023, Adan Lema <adanlema@hotmail.com> */

#ifndef AL_BLUEPILL_H
#define AL_BLUEPILL_H

/*==================[inclusions]=============================================*/
#include <stdint.h>
#include <stm32f1xx.h>
#include "stm32f103xb.h"
/*==================[macros]=================================================*/

#define MODE_INPUT    0b00
#define MODE_OUT2MHz  0b10
#define MODE_OUT10MHz 0b01
#define MODE_OUT50MHz 0b11
#define CNF_0         0b00 << 2
#define CNF_1         0b01 << 2
#define CNF_2         0b10 << 2
#define CNF_3         0b11 << 2

#define ENABLE_PORT   1
#define ENABLE_PIN    1
#define ENABLE_FUNC   1
#define ENABLE_MASK   ENABLE_PIN

#define RESET_PORT    1
#define RESET_PIN     1
#define RESET_FUNC    1
#define RESET_MASK    RESET_PIN

#define LCD_0_PORT    1
#define LCD_0_PIN     1
#define LCD_0_FUNC    1
#define LCD_0_MASK    LCD_0_PIN

#define CH1_PORT      GPIOA
#define CH1_PIN       0
#define CH1_FUNC      (MODE_INPUT | CNF_1) << CH1_PIN
#define CH1_BIT       8
#define CH1_MASK      1 << CH1_BIT

#define CH2_PORT      GPIOA
#define CH2_PIN       4
#define CH2_FUNC      (MODE_INPUT | CNF_1) << CH2_PIN
#define CH2_BIT       9
#define CH2_MASK      1 << CH2_BIT

/*==================[typedef]================================================*/

/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/
void BluePillInit(void);

/** @ doxygen end group definition */
/** @ doxygen end group definition */
/** @ doxygen end group definition */
/*==================[end of file]============================================*/
#endif