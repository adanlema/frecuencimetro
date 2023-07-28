/* Copyright 2023, Adan Lema <adanlema@hotmail.com>

/** \brief HAL_GPIO
 ** \brief Implementacion de las funciones de una HAL_GPIO
 ** @{ */
/*==================[inclusions]=============================================*/
#include <stdbool.h>
#include "al_gpio.h"
/*==================[macros and definitions]=================================*/
#define CANTIDAD 20

struct DigitalInput_s {
    gpio_t   port;
    uint32_t pin;
    bool     inverted;
    bool     last_state;
    bool     ocupado;
};
struct DigitalOutput_s {
    gpio_t   port;
    uint32_t pin;
    bool     ocupado;
};

/*==================[internal data declaration]==============================*/
static struct DigitalInput_s  Input[CANTIDAD]  = {0};
static struct DigitalOutput_s Output[CANTIDAD] = {0};
/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

/* Funciones para las Entradas */
DigitalInput_t DigitalInput_Create(gpio_t port, uint8_t pin, bool inverted) {
    uint8_t posicion = 0;
    for (int i = 0; (i < CANTIDAD) & (posicion == 0); i++) {
        if (Input[i].ocupado == false)
            posicion = i;
    }
    DigitalInput_t self = &Input[posicion];
    self->port          = port;
    self->pin           = pin;
    self->inverted      = inverted;
    self->ocupado       = true;
    return self;
}
bool DigitalInput_GetState(DigitalInput_t self) {
    if (self->inverted == 0)
        return (self->port->IDR & (1 << self->pin));
    else
        return !(self->port->IDR & (1 << self->pin));
}
bool DigitalInput_HasChange(DigitalInput_t self) {
    bool current_state = DigitalInput_GetState(self);
    bool resultado;
    if (current_state != self->last_state)
        resultado = true;
    else
        resultado = false;
    self->last_state = current_state;
    return resultado;
}
bool DigitalInput_HasActivate(DigitalInput_t self) {
    bool current_state = DigitalInput_GetState(self);
    bool resultado;
    if ((0 == self->last_state) & (1 == current_state))
        resultado = true;
    else
        resultado = false;
    self->last_state = current_state;
    return resultado;
}
bool DigitalInput_HasDesactivate(DigitalInput_t self) {
    bool current_state = DigitalInput_GetState(self);
    bool resultado;
    if ((1 == self->last_state) & (0 == current_state))
        resultado = true;
    else
        resultado = false;
    self->last_state = current_state;
    return resultado;
}

/* Funciones para las Salidas */
DigitalOutput_t DigitalOutput_Create(gpio_t port, uint8_t pin) {
    uint8_t posicion = 0;
    for (int i = 0; (i < CANTIDAD) & (posicion == 0); i++) {
        if (Output[i].ocupado == false)
            posicion = i;
    }
    DigitalOutput_t self = &Output[posicion];
    self->port           = port;
    self->pin            = pin;
    self->ocupado        = true;
    return self;
}

bool DigitalOutput_GetState(DigitalOutput_t self) {
    return (self->port->IDR & (1 << self->pin))
}

void DigitalOutput_Activate(DigitalOutput_t self) {
    self->port->BSRR = (1 << self->pin);
}
void DigitalOutput_Desactivate(DigitalOutput_t self) {
    self->port->BSRR = (1 << self->pin) << 16;
}
void DigitalOutput_Toggle(DigitalOutput_t self) {
    uint32_t odr     = self->port->ODR;
    self->port->BSRR = ((odr & (1 << self->pin)) << 16) | (~odr & (1 << self->pin));
}

/**  doxygen end group definition */
/*==================[end of file]============================================*/