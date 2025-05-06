/* 
 * File:   ecu_led.h
 * Author: hadal magdy
 *
 * Created on April 17, 2025, 9:02 PM
 
 */
#include "ecu_led.h"

/**
 * @brief Initialize the assigned pin to output
 * @param led : pointer to the led module configurations
 * @return Status of the function
 *          (E_OK) : done successfully
 *          (E_NOT_OK) : has issue 
 **/
Std_ReturnType led_init(const led_t *led) {
    Std_ReturnType ret = E_OK;
    if (NULL == led) {
        ret = E_NOT_OK;
    } else {
        pin_config_t pin_obj = {
            .port = led->port_name,
            .pin = led->pin,
            .direction = GPIO_DIRECTION_OUTPUT,
            .logic = led->led_status
        };
        gpio_pin_init(&pin_obj);
    }
    return ret;
}

/**
 * @brief turn the led on
 * @param led : pointer to the led module configurations
 * @return Status of the function
 *          (E_OK) : done successfully
 *          (E_NOT_OK) : has issue 
 **/
Std_ReturnType led_on(const led_t *led) {
    Std_ReturnType ret = E_OK;
    if (NULL == led) {
        ret = E_NOT_OK;
    } else {
        pin_config_t pin_obj = {
            .port = led->port_name,
            .pin = led->pin,
            .direction = GPIO_DIRECTION_OUTPUT,
            .logic = led->led_status
        };
        gpio_pin_write_logic(&pin_obj, GPIO_HIGH);

    }
    return ret;
}

/**
 * @brief turn the led off
 * @param led : pointer to the led module configurations
 * @return Status of the function
 *          (E_OK) : done successfully
 *          (E_NOT_OK) : has issue 
 **/
Std_ReturnType led_off(const led_t *led) {
    Std_ReturnType ret = E_OK;
    if (NULL == led) {
        ret = E_NOT_OK;
    } else {
        pin_config_t pin_obj = {
            .port = led->port_name,
            .pin = led->pin,
            .direction = GPIO_DIRECTION_OUTPUT,
            .logic = led->led_status
        };
        gpio_pin_write_logic(&pin_obj, GPIO_LOW);

    }
    return ret;
}

/**
 * @brief toggle the led
 * @param led : pointer to the led module configurations
 * @return Status of the function
 *          (E_OK) : done successfully
 *          (E_NOT_OK) : has issue 
 **/
Std_ReturnType led_toggle(const led_t *led) {
    Std_ReturnType ret = E_OK;
    if (NULL == led) {
        ret = E_NOT_OK;
    } else {
        pin_config_t pin_obj = {
            .port = led->port_name,
            .pin = led->pin,
            .direction = GPIO_DIRECTION_OUTPUT,
            .logic = led->led_status
        };
        gpio_pin_toggle_logic(&pin_obj);

    }
    return ret;
}

#include "ecu_led.h"