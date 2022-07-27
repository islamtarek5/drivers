/********************************************************************************************************************************************/
/*                                              Author      : Islam Tarek                                                                   */
/*                                              SW Module   : HT66F489 GPIO                                                                 */
/*                                              Last Update : 27/7/2022                                                                     */
/********************************************************************************************************************************************/

/* Includes */
#include "gpio.h"

/**
 * @brief This function is used to set pin or a collection of pin as output
 * @param gpio_x : Determine which port to be used 
 * @param pin_x  : Determine which pin to be configured
 * @return The state of API (DRIVER_OK if everything ok and status of Error if there is an error)
 */
driver_err_t gpio_set_pin_output(gpio_t gpio_x, gpio_pin_t pin_x)
{
    switch(gpio_x)
    {
    case GPIO_A:
        _pac &= ~pin_x;
        break;
    case GPIO_B:
        _pbc &= ~pin_x;
        break;
    case GPIO_C:
        _pcc &= ~pin_x;
        break;
    case GPIO_D:
        _pdc &= ~pin_x;
        break;
    default:
        return DRIVER_ERR_OUT_OF_RANGE;
    }
    return DRIVER_OK;
}

/**
 * @brief This function is used to set pin or a collection of pin as input with floating
 * @param gpio_x : Determine which port to be used 
 * @param pin_x  : Determine which pin to be configured
 * @return The state of API (DRIVER_OK if everything ok and status of Error if there is an error)
 */
driver_err_t gpio_set_pin_input(gpio_t gpio_x, gpio_pin_t pin_x)
{
    switch(gpio_x)
    {
    case GPIO_A:
        _pac |= pin_x;
        _papu &= ~pin_x;
        break;
    case GPIO_B:
        _pbc |= pin_x;
        _pbpu &= ~pin_x;
        break;
    case GPIO_C:
        _pcc |= pin_x;
        _pcpu &= ~pin_x;
        break;
    case GPIO_D:
        _pdc |= pin_x;
        _pdpu &= ~pin_x;
        break;
    default:
        return DRIVER_ERR_OUT_OF_RANGE;
    }
    return DRIVER_OK;
}

/**
 * @brief This function is used to set pin or a collection of pin as input with pull up
 * @param gpio_x : Determine which port to be used 
 * @param pin_x  : Determine which pin to be configured
 * @return The state of API (DRIVER_OK if everything ok and status of Error if there is an error)
 */
driver_err_t gpio_set_pin_input_pu(gpio_t gpio_x, gpio_pin_t pin_x)
{
    switch(gpio_x)
    {
    case GPIO_A:
        _pac |= pin_x;
        _papu |= pin_x;
        break;
    case GPIO_B:
        _pbc |= pin_x;
        _pbpu |= pin_x;
        break;
    case GPIO_C:
        _pcc |= pin_x;
        _pcpu |= pin_x;
        break;
    case GPIO_D:
        _pdc |= pin_x;
        _pdpu |= pin_x;
        break;
    default:
        return DRIVER_ERR_OUT_OF_RANGE;
    }
    return DRIVER_OK;
}
/**
 * @brief This function is used to set pin or a collection of pin as high output
 * @param gpio_x : Determine which port to be used 
 * @param pin_x  : Determine which pin to be configured
 * @return The state of API (DRIVER_OK if everything ok and status of Error if there is an error)
 */
driver_err_t gpio_set_pin_high(gpio_t gpio_x, gpio_pin_t pin_x)
{
    switch(gpio_x)
    {
    case GPIO_A:
        _pa |= pin_x;
        break;
    case GPIO_B:
        _pb |= pin_x;
        break;
    case GPIO_C:
        _pc |= pin_x;
        break;
    case GPIO_D:
        _pd |= pin_x;
        break;
    default:
        return DRIVER_ERR_OUT_OF_RANGE;
    }
    return DRIVER_OK;
}

/**
 * @brief This function is used to set pin or a collection of pin as low output
 * @param gpio_x : Determine which port to be used 
 * @param pin_x  : Determine which pin to be configured
 * @return The state of API (DRIVER_OK if everything ok and status of Error if there is an error)
 */
driver_err_t gpio_set_pin_low(gpio_t gpio_x, gpio_pin_t pin_x)
{
    switch(gpio_x)
    {
    case GPIO_A:
        _pa &= ~pin_x;
        break;
    case GPIO_B:
        _pb &= ~pin_x;
        break;
    case GPIO_C:
        _pc &= ~pin_x;
        break;
    case GPIO_D:
        _pd &= ~pin_x;
        break;
    default:
        return DRIVER_ERR_OUT_OF_RANGE;
    }
    return DRIVER_OK;
}

/**
 * @brief This function is used to get pin level (high or low)
 * @param gpio_x : Determine which port to be used 
 * @param pin_x  : Determine which pin to be configured
 * @return The state of API (DRIVER_OK if everything ok and status of Error if there is an error)
 */
driver_err_t gpio_get_pin_level(gpio_t gpio_x, gpio_pin_t pin_x, gpio_pin_level_t* level)
{
    if(level != NULL)
    {
        switch(gpio_x)
        {
        case GPIO_A:
            *level = _pa & pin_x;
            break;
        case GPIO_B:
            *level = _pb & pin_x;
            break;
        case GPIO_C:
            *level = _pc & pin_x;
            break;
        case GPIO_D:
            *level = _pd & pin_x;
            break;
        default:
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
 * @return The state of API (DRIVER_OK if everything ok and status of Error if there is an error)
 */
driver_err_t gpio_toggle_pin(gpio_t gpio_x, gpio_pin_t pin_x)
{
    switch(gpio_x)
    {
    case GPIO_A:
        _pa ^= pin_x;
        break;
    case GPIO_B:
        _pb ^= pin_x;
        break;
    case GPIO_C:
        _pc ^= pin_x;
        break;
    case GPIO_D:
        _pd ^= pin_x;
        break;
    default:
        return DRIVER_ERR_OUT_OF_RANGE;
    }
    return DRIVER_OK;
}

/**
 * @brief Enable wake-up the microcontroller by GPIO method
 * @param pin_x : Determine which pin to be used to wake-up the microcontroller
 */
void gpio_enable_wake_up(gpio_pin_t pin_x)
{
    _pawu  |= pin_x;
}

/**
 * @brief Disable wake-up the microcontroller by GPIO method
 * @param pin_x : Determine which pin to be used to wake-up the microcontroller
 */
void gpio_disable_wake_up(gpio_pin_t pin_x)
{
    _pawu  &= ~pin_x;
}

/**
 * @brief The function is used to set the output source current for each pin
 * @param gpio_x : Determine which port to be used   
 * @param pin_x  : Determine which pin to be used
 * @param current: Determine the source current  
 * @return The state of API (DRIVER_OK if everything ok and status of Error if there is an error)
 */
driver_err_t gpio_set_src_current(gpio_t gpio_x, gpio_pin_t pin_x, src_current_t current)
{
    switch (gpio_x)
    {
    case GPIO_A:
        if(pin_x == PIN_3)
        {
            _iohr0 &= 0b00111111;            
            _iohr0 |= (current << 6);
        }
        else if (pin_x == PIN_2)
        {
            _iohr0 &= 0b11001111;            
            _iohr0 |= (current << 4);
        }
        else if (pin_x == PIN_1)
        {
            _iohr0 &= 0b11110011;            
            _iohr0 |= (current << 2);
        }
        else if (pin_x == PIN_0)
        {
            _iohr0 &= 0b11111100;            
            _iohr0 |= current;
        }
        else if(pin_x == PIN_7)
        {
            _iohr1 &= 0b00111111;            
            _iohr1 |= (current << 6);
        }
        else if (pin_x == PIN_6)
        {
            _iohr1 &= 0b11001111;            
            _iohr1 |= (current << 4);
        }
        else if (pin_x == PIN_5)
        {
            _iohr1 &= 0b11110011;            
            _iohr1 |= (current << 2);
        }
        else if (pin_x == PIN_4)
        {
            _iohr1 &= 0b11111100;            
            _iohr1 |= current;
        }
        else
        {
            return DRIVER_ERR_OUT_OF_RANGE;
        }
        break;

    case GPIO_B:
        if(pin_x >= PIN_4 && pin_x <= PIN_7)
        {
            _iohr2 &= 0b11110011;
            _iohr2 |= (current << 2);
        }
        else if(pin_x >= PIN_0 && pin_x <= PIN_3)  
        {
            _iohr2 &= 0b11111100;            
            _iohr2 |= current;
        }
        else
        {
            return DRIVER_ERR_OUT_OF_RANGE;
        }
        break;

    case GPIO_C:
        if(pin_x >= PIN_4 && pin_x <= PIN_7)
        {
            _iohr2 &= 0b00111111;
            _iohr2 |= (current << 6);
        }
        else if(pin_x >= PIN_0 && pin_x <= PIN_3)  
        {
            _iohr2 &= 0b11001111;
            _iohr2 |= (current << 4);
        }
        else
        {
            return DRIVER_ERR_OUT_OF_RANGE;
        }
        break;

    case GPIO_D:
        if(pin_x == PIN_4 || pin_x == PIN_5)
        {
            _iohr3 &= 0b11110011;
            _iohr3 |= (current << 2);
        }
        else if(pin_x >= PIN_0 && pin_x <= PIN_3)  
        {
            _iohr3 &= 0b11111100;            
            _iohr3 |= current;
        }
        else
        {
            return DRIVER_ERR_OUT_OF_RANGE;
        }
        break;

    default:
        return DRIVER_ERR_OUT_OF_RANGE;
    }

    return DRIVER_OK;
}