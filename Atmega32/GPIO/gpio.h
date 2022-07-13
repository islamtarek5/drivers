/********************************************************************************************************************************************/
/*                                              Author      : Islam Tarek                                                                   */
/*                                              SW Module   : Atmega32 GPIO                                                                 */
/*                                              Last Update : 13/7/2022                                                                     */
/********************************************************************************************************************************************/
#ifndef ATMETG32_GPIO_GPIO_H_
#define ATMEGA32_GPIO_GPIO_H_

/* Includes */
#include "../include.h"

/* GPIO ports */
typedef enum
{
    GPIO_A = 0x00,
    GPIO_B,
    GPIO_C,
    GPIO_D,
    GPIO_MAX
}gpio_t;

/* GPIO Pins */
typedef uint8_t gpio_pin_t;

#define PIN_0       0x01
#define PIN_1       0x02
#define PIN_2       0x04
#define PIN_3       0x08
#define PIN_4       0x10
#define PIN_5       0x20
#define PIN_6       0x40
#define PIN_7       0x80
#define PIN_ALL     0xff

/* GPIO pin level */
typedef uint8_t gpio_pin_level_t;

/* APIs */
driver_err_t gpio_set_pin_output    (gpio_t gpio_x, gpio_pin_t pin_x);
driver_err_t gpio_set_pin_input     (gpio_t gpio_x, gpio_pin_t pin_x);
driver_err_t gpio_set_pin_input_pu  (gpio_t gpio_x, gpio_pin_t pin_x);
driver_err_t gpio_set_pin_high      (gpio_t gpio_x, gpio_pin_t pin_x);
driver_err_t gpio_set_pin_low       (gpio_t gpio_x, gpio_pin_t pin_x);
driver_err_t gpio_get_pin_level     (gpio_t gpio_x, gpio_pin_t pin_x, gpio_pin_level_t* level); 
driver_err_t gpio_toggle_pin        (gpio_t gpio_x, gpio_pin_t pin_x);

#endif