/* Copyright 2023, Adan Lema <adanlema@hotmail.com> */

#ifndef AL_BSP_H
#define AL_BSP_H

/*==================[inclusions]=============================================*/
#include "al_gpio.h"
#include <stdint.h>
/*==================[macros]=================================================*/

/*==================[typedef]================================================*/
typedef struct board_s {
    DigitalInput_t  CH1;
    DigitalOutput_t lcd_rs;
    DigitalOutput_t lcd_en;
    lcd_t           lcd;
} * board_t;
/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/
board_t BoardCreate();
/** @ doxygen end group definition */
/** @ doxygen end group definition */
/** @ doxygen end group definition */
/*==================[end of file]============================================*/
#endif