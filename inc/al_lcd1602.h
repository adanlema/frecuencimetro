#ifndef AL_LCD_H
#define AL_LCD_H

/*==================[inclusions]=============================================*/
#include "al_gpio.h"
#include "al_bsp.h"
#include <stdint.h>
/*==================[macros]=================================================*/

/*==================[typedef]================================================*/
typedef void (*lcd_clear_t)(void);
typedef void (*lcd_on_t)(char *, const uint8_t);

typedef struct lcd_s * lcd_t;
typedef struct lcd_driver_s {
    lcd_clear_t clear;
    lcd_on_t    write;
} * lcd_driver_t;
/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/
lcd_t LcdCreate(board_t board, lcd_driver_t driver);
void  LcdWrite(lcd_t lcd, const char * cadena, const uint32_t size, const uint8_t fila,
               const uint8_t columna);
void  LcdClear(lcd_t lcd, uint32_t size);
void  LcdRefresh(lcd_t lcd);
/** @ doxygen end group definition */
/** @ doxygen end group definition */
/** @ doxygen end group definition */
/*==================[end of file]============================================*/
#endif