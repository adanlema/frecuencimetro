
/* Copyright 2023, Adan Lema <adanlema@hotmail.com> */

/*==================[inclusions]=============================================*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "al_lcd1602.h"

/*==================[macros and definitions]=================================*/
struct lcd_s {
    char                memf1[16];
    char                memf2[16];
    DigitalOutput_t     reset;
    DigitalOutput_t     enable;
    struct lcd_driver_s driver[1];
};
/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/
static lcd_t LcdAllocate(void);
/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/
static lcd_t LcdAllocate(void) {
    struct lcd_s lcd    = {0};
    lcd_t        result = &lcd;
    return result;
}

/*==================[external functions definition]==========================*/

lcd_t LcdCreate(lcd_driver_t driver) {
    lcd_t self = LcdAllocate();
    if (self) {
        memset(self->memf1, 0, sizeof(self->memf1));
        memset(self->memf2, 0, sizeof(self->memf2));
        memcpy(self->driver, driver, sizeof(self->driver));
    }
    return self;
}

void LcdWrite(lcd_t lcd, const char * cadena, const uint32_t size, const uint8_t fila,
              const uint8_t columna) {
    if (fila) {
        strncpy(&lcd->memf1[columna], cadena, size);
    } else {
        strncpy(&lcd->memf2[columna], cadena, size);
    }
}

void LcdClear(lcd_t lcd, uint32_t size) {
    memset(lcd->memf1, 0, size);
    memset(lcd->memf2, 0, size);
}

void LcdRefresh(lcd_t lcd) {
    lcd->driver->clear();
    lcd->driver->write(lcd->memf1, 0);
    lcd->driver->write(lcd->memf2, 1);
}

/** @ doxygen end group definition */
/** @ doxygen end group definition */
/** @ doxygen end group definition */
/*==================[end of file]============================================*/