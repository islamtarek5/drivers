/********************************************************************************************************************************************/
/*                                              Author      : Islam Tarek                                                                   */
/*                                              SW Module   : Atmega32 GPIO                                                                 */
/*                                              Last Update : 13/7/2022                                                                     */
/********************************************************************************************************************************************/

/* Includes */
#include "gpio.h"

/* Global variables */
gpio_reg_t* GPIO_ARR[GPIO_MAX] = {GPIO_A_REG, GPIO_B_REG, GPIO_C_REG, GPIO_D_REG};

/**
 * @brief This function is used to set pin or a collection of pin as output
 * @param gpio_x : Determine which port to be used 
 * @param pin_x  : Determine which pin to be configured
 * @return Thes state of API (DRIVER_OK if everything ok and status of Error if there is an error)
 */
driver_err_t gpio_set_pin_output(gpio_t gpio_x, gpio_pin_t pin_x)
{
    if(gpio_x >= GPIO_A && gpio_x < GPIO_MAX)
    {
        GPIO_ARR[gpio_x]->DDR |= pin_x;
    }
    else
    {
        return DRIVER_ERR_OUT_OF_RANGE;
    }
    return DRIVER_OK;
}

/**
 * @brief This function is used to set pin or a collection of pin as input with floating
 * @param gpio_x : Determine which port to be used 
 * @param pin_x  : Determine which pin to be configured
 * @return Thes state of API (DRIVER_OK if everything ok and status of Error if there is an error)
 */
driver_err_t gpio_set_pin_input(gpio_t gpio_x, gpio_pin_t pin_x)
{
    if(gpio_x >= GPIO_A && gpio_x < GPIO_MAX)
    {
        GPIO_ARR[gpio_x]->DDR  &= ~pin_x;
        GPIO_ARR[gpio_x]->PORT &= ~pin_x;
    }
    else
    {
        return DRIVER_ERR_OUT_OF_RANGE;
    }
    return DRIVER_OK;
}

/**
 * @brief This function is used to set pin or a collection of pin as input with pull up
 * @param gpio_x : Determine which port to be used 
 * @param pin_x  : Determine which pin to be configured
 * @return Thes state of API (DRIVER_OK if everything ok and status of Error if there is an error)
 */
driver_err_t gpio_set_pin_input_pu(gpio_t gpio_x, gpio_pin_t pin_x)
{
    if(gpio_x >= GPIO_A && gpio_x < GPIO_MAX)
    {
        GPIO_ARR[gpio_x]->DDR  &= ~pin_x;
        GPIO_ARR[gpio_x]->PORT |=  pin_x;
    }
    else
    {
        return DRIVER_ERR_OUT_OF_RANGE;
    }
    return DRIVER_OK;
}

/**
 * @brief This function is used to set pin or a collection of pin as high output
 * @param gpio_x : Determine which port to be used 
 * @param pin_x  : Determine which pin to be configured
 * @return Thes state of API (DRIVER_OK if everything ok and status of Error if there is an error)
 */
driver_err_t gpio_set_pin_high(gpio_t gpio_x, gpio_pin_t pin_x)
{
    if(gpio_x >= GPIO_A && gpio_x < GPIO_MAX)
    {
        GPIO_ARR[gpio_x]->PORT |=  pin_x;
    }
    else
    {
        return DRIVER_ERR_OUT_OF_RANGE;
    }
    return DRIVER_OK;
}

/**
 * @brief This function is used to set pin or a collection of pin as low output
 * @param gpio_x : Determine which port to be used 
 * @param pin_x  : Determine which pin to be configured
 * @return Thes state of API (DRIVER_OK if everything ok and status of Error if there is an error)
 */
driver_err_t gpio_set_pin_low(gpio_t gpio_x, gpio_pin_t pin_x)
{
    if(gpio_x >= GPIO_A && gpio_x < GPIO_MAX)
    {
        GPIO_ARR[gpio_x]->PORT &= ~pin_x;
    }
    else
    {
        return DRIVER_ERR_OUT_OF_RANGE;
    }
    return DRIVER_OK;
}

/**
 * @brief This function is used to get pin level (high or low)
 * @param gpio_x : Determine which port to be used 
 * @param pin_x  : Determine which pin to be configured
 * @return Thes state of API (DRIVER_OK if everything ok and status of Error if there is an error)
 */
driver_err_t gpio_get_pin_level(gpio_t gpio_x, gpio_pin_t pin_x, gpio_pin_level_t* level)
{
    if(level != NULL)
    {
        if(gpio_x >= GPIO_A && gpio_x < GPIO_MAX)
        {
            *level = GPIO_ARR[gpio_x]->PIN & pin_x;
        }
        else
        {
            return DRIVER_ERR_OUT_OF_RANGE;
        }
    }
    else
    {
        return DRIVER_ERR_NULL_PTR;
    }
    return DRIVER_OK;
} 

/**
 * @brief This function is used to toggle pin state (if High convert to low and vice versa)
 * @param gpio_x : Determine which port to be used 
 * @param pin_x  : Determine which pin to be configured
 * @return Thes state of API (DRIVER_OK if everything ok and status of Error if there is an error)
 */
driver_err_t gpio_toggle_pin(gpio_t gpio_x, gpio_pin_t pin_x)
{
    if(gpio_x >= GPIO_A && gpio_x < GPIO_MAX)
    {
        GPIO_ARR[gpio_x]->PORT ^= pin_x;
    }
    else
    {
        return DRIVER_ERR_OUT_OF_RANGE;
    }
    return DRIVER_OK;
}

