/************************************************************************************************
Copyright (c) <year>, <copyright holders>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

/** \brief Brief description of the file
 **
 ** Full file description
 **
 ** \addtogroup name Module denomination
 ** \brief Brief description of the module
 ** @{ */

/* === Headers files inclusions =============================================================== */

#include "../inc/gpio.h"

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

typedef struct {
    int pin; /**< PIN GPIO */
} gpio_ctx_t;

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================== */
void gpio_write_impl(int state, void * ctx) {
    gpio_ctx_t * gpio = (gpio_ctx_t *)ctx;
    printf("GPIO%d <- %d\n", gpio->pin, state);
}

int gpio_read_impl(void * ctx) {
    gpio_ctx_t * gpio = (gpio_ctx_t *)ctx;
    printf("Leyendo GPIO%d\n", gpio->pin);
    return 1; // Simulamos que siempre está en HIGH
}

int main() {
    gpio_ctx_t pin13 = {.pin = 13};

    gpio_t gpio = {.write = gpio_write_impl, .read = gpio_read_impl, .ctx = &pin13, .state = 0};

    gpio_write(&gpio, 1);
    int valor = gpio_read(&gpio);
    printf("Estado leído de GPIO: %d\n", valor);

    return 0;
}

/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */