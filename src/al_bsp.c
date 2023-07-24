/* Copyright 2023, Adan Lema <adanlema@hotmail.com> */

/*==================[inclusions]=============================================*/
#include "al_bsp.h"
/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

static void LcdInit(void) {
    RCC->APB2ENR |= (0b11 << 2);
    GPIOA->CRL = 0x22222222;
    GPIOB->CRL = (GPIOB->CRL & ~(0xFF << 0)) | (0x22 << 0);
    GPIOB->BRR |= (0b11 << 0);
    delay_ms(100);
    // SET
    GPIOA->BRR |= 0xff;
    GPIOA->BSRR |= 0b111000;
    GPIOB->BSRR |= (1 << 0);
    delay_ms(100);
    GPIOB->BRR |= (1 << 0);
    GPIOA->BRR |= 0xff;
    // DISPLAY ON/OFF
    GPIOA->BSRR |= 0b1100; // 0b1111
    GPIOB->BSRR |= (1 << 0);
    delay_ms(100);
    GPIOB->BRR |= (1 << 0);
    GPIOA->BRR |= 0xff;
    lcd_clear();
}

static void comando_RS(bool rs) {
    if (rs)
        GPIOB->BSRR |= (1 << 1);
    else
        GPIOB->BRR |= (1 << 1);
}
static void comando_EN(uint8_t delay) {
    GPIOB->BSRR |= (1 << 0);
    delay_ms(delay);
    GPIOB->BRR |= (1 << 0);
}
static void bits_NULL(void) {
    GPIOA->BRR |= (0xff);
}

static void lcd_escribir_byte(unsigned char Data) {
    comando_RS(true);
    bits_NULL();
    GPIOA->BSRR |= Data;
    comando_EN(1);
}
static void lcd_comand_escribir(unsigned char Data, uint8_t delay) {
    comando_RS(false);
    bits_NULL();
    GPIOA->BSRR |= Data;
    comando_EN(delay);
}

void lcd_clear(void) {
    GPIOB->BRR |= (1 << 1);
    GPIOA->BRR |= (0xff);
    GPIOA->BSRR |= 1;
    GPIOB->BSRR |= (1 << 0);
    delay_ms(1);
    GPIOB->BRR |= (1 << 0);
    GPIOA->BRR |= 0xff;
}

void lcd_escribir(const char * Data, unsigned char fila, unsigned char col) {
    unsigned char cursor = 0x00;
    if (fila)
        cursor = 0xc0;
    else
        cursor = 0x80;
    cursor += col;
    lcd_comand_escribir(cursor, 1);
    while (*Data != '\0') {
        lcd_escribir_byte(*Data);
        Data++;
    }
}
/*==================[external functions definition]==========================*/
board_t BoardCreate() {
}

/** @ doxygen end group definition */
/** @ doxygen end group definition */
/** @ doxygen end group definition */
/*==================[end of file]============================================*/