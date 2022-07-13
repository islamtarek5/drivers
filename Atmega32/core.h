/********************************************************************************************************************************************/
/*                                              Author      : Islam Tarek                                                                   */
/*                                              SW Module   : Atmega32 core                                                                 */
/*                                              Last Update : 13/7/2022                                                                     */
/********************************************************************************************************************************************/
#ifndef ATMEGA32_CORE_H_
#define ATMEGA32_CORE_H_

/* Special function input/ output register and its pins */
#define SFIOR                                       *((volatile uint8_t *)(0x50))

#define ADTS2           7 
#define ADTS1           6
#define ADTS0           5
#define ACME            3
#define PUD             2
#define PSR2            1
#define PSR10           0

/* GPIO Registers */

#define GPIO_A_BASE_ADDRESS                         0x39
#define GPIO_B_BASE_ADDRESS                         0x36
#define GPIO_C_BASE_ADDRESS                         0x33
#define GPIO_D_BASE_ADDRESS                         0x30
typedef struct 
{
    volatile uint8_t PIN;
    volatile uint8_t DDR;
    volatile uint8_t PORT;
}gpio_reg_t;

#define GPIO_A_REG                                        (gpio_reg_t *)(GPIO_A_BASE_ADDRESS)          
#define GPIO_B_REG                                        (gpio_reg_t *)(GPIO_B_BASE_ADDRESS)
#define GPIO_C_REG                                        (gpio_reg_t *)(GPIO_C_BASE_ADDRESS)
#define GPIO_D_REG                                        (gpio_reg_t *)(GPIO_D_BASE_ADDRESS)



#endif