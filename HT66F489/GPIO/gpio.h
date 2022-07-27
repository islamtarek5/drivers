/********************************************************************************************************************************************/
/*                                              Author      : Islam Tarek                                                                   */
/*                                              SW Module   : HT66F489 GPIO                                                                 */
/*                                              Last Update : 27/7/2022                                                                     */
/********************************************************************************************************************************************/
#ifndef HT66F489_GPIO_GPIO_H_
#define HT66F489_GPIO_GPIO_H_

/* Includes */
#include "../HT66F489_include.h"

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

/* Output source current*/
typedef uint8_t src_current_t;

/* Power is 3 volt*/
#define SRC_CURRNET_1_5_uA_3_V      0b11      /*  1.5 micro Ampere @ 3.0 volt  */
#define SRC_CURRNET_2_0_uA_3_V      0b10      /*  2.0 micro Ampere @ 3.0 volt  */
#define SRC_CURRNET_3_0_uA_3_V      0b01      /*  3.0 micro Ampere @ 3.0 volt  */ 
#define SRC_CURRNET_6_0_uA_3_V      0b00      /*  6.0 micro Ampere @ 3.0 volt  */ 

/* Power is 5 volt */
#define SRC_CURRNET_3_6_uA_5_V      0b11      /*  3.6 micro Ampere @ 5.0 volt  */
#define SRC_CURRNET_6_0_uA_5_V      0b10      /*  6.0 micro Ampere @ 5.0 volt  */
#define SRC_CURRNET_8_0_uA_5_V      0b01      /*  8.0 micro Ampere @ 5.0 volt  */
#define SRC_CURRNET_18_0_uA_5_V     0b00      /*  18.0 micro Ampere @ 5.0 volt */

/* APIs */
driver_err_t gpio_set_pin_output    (gpio_t gpio_x, gpio_pin_t pin_x);
driver_err_t gpio_set_pin_input     (gpio_t gpio_x, gpio_pin_t pin_x);
driver_err_t gpio_set_pin_input_pu  (gpio_t gpio_x, gpio_pin_t pin_x);
driver_err_t gpio_set_pin_high      (gpio_t gpio_x, gpio_pin_t pin_x);
driver_err_t gpio_set_pin_low       (gpio_t gpio_x, gpio_pin_t pin_x);
driver_err_t gpio_get_pin_level     (gpio_t gpio_x, gpio_pin_t pin_x, gpio_pin_level_t* level); 
driver_err_t gpio_toggle_pin        (gpio_t gpio_x, gpio_pin_t pin_x);
void gpio_enable_wake_up            (gpio_pin_t pin_x);
void gpio_disable_wake_up           (gpio_pin_t pin_x);
driver_err_t gpio_set_src_current   (gpio_t gpio_x, gpio_pin_t pin_x, src_current_t current);
#endif