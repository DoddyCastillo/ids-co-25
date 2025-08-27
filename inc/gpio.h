/************************************************************************************************
Copyright (c) <2025>, <Doddy Castillo C.>

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

#ifndef GPIO_H
#define GPIO_H

/** \brief Brief description of the file
 **
 ** Full file description
 **
 ** \addtogroup name Module denomination
 ** \brief Brief description of the module
 ** @{ */

/* === Headers files inclusions ================================================================ */
#include <stdbool.h>
#include <stdint.h>
/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

/* === Public data type declarations =========================================================== */

/**
 * @typedef gpio_write_fn
 * @brief Tipo de función para escritura en un pin GPIO.
 *
 * Esta es una función de callback que permite escribir un valor lógico
 * en un pin GPIO abstracto, según el contexto proporcionado.
 *
 * @param state Valor lógico a escribir: normalmente 0 (LOW) o 1 (HIGH).
 * @param ctx Puntero al contexto del GPIO o estructura que contiene información adicional
 *            necesaria para implementar la escritura (como dirección base, número de pin, etc.).
 *
 * @note Esta función no retorna nada. Se espera que la implementación maneje
 *       los errores internamente o mediante mecanismos de logging si es necesario.
 */

 typedef void(*gpio_write_fn)(int state, void *ctx);

/**
 * @typedef gpio_read_fn
 * @brief Tipo de función para lectura de un pin GPIO.
 *
 * Esta es una función de callback que permite leer el estado lógico de
 * un pin GPIO abstracto, utilizando un contexto determinado.
 *
 * @param ctx Puntero al contexto del GPIO (estructura con la información
 *            necesaria para acceder al pin, como registros, dirección base, etc.).
 * @return int El valor lógico leído del pin GPIO: 0 (LOW) o 1 (HIGH).
 *
 * @note El valor retornado debe interpretarse como un nivel lógico.
 *       El comportamiento en caso de error o contexto inválido depende de la implementación.
 */
typedef int(*gpio_read_fn)(void *ctx);


/**
 * @struct gpio_t
 * @brief Abstracción de un pin GPIO con estado interno y funciones de acceso.
 *
 * Esta estructura encapsula el acceso a un pin GPIO, manteniendo su estado lógico
 * más reciente y las funciones de lectura/escritura desacopladas del hardware.
 */
typedef struct {
    gpio_write_fn write; /**< Callback para escritura en el GPIO */
    gpio_read_fn  read;  /**< Callback para lectura desde el GPIO */
    void *ctx;           /**< Contexto asociado (datos del hardware o simulador) */
    int state;           /**< Estado lógico actual del pin (0: LOW, 1: HIGH) */
} gpio_t;

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */


/**
* @brief Escribe un valor lógico en el GPIO y actualiza su estado.
*
* @param gpio Puntero a la estructura gpio_t
* @param state Valor lógico a escribir (0 o 1)
*/
void gpio_write(gpio_t *gpio, int state);


/**
* @brief Lee el valor del GPIO y actualiza su estado.
*
* @param gpio Puntero a la estructura gpio_t
* @return int Valor leído (0 o 1)
*/
int gpio_read(gpio_t *gpio);



/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

/** @} End of module definition for doxygen */

#endif /* TEMPLATE_H */