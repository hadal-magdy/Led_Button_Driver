/* 
 * File:   ecu_button.c
 * Author: hadal magdy
 *
 * Created on April 16, 2025, 12:32 AM
 */

#include "ecu_button.h"

/**
 * @brief Initialize the assigned pin to input
 * @param btn pointer to the button configurations
 * @return Status of the function
 *          (E_OK) : done successfully
 *          (E_NOT_OK) : has issue 
 **/
Std_ReturnType button_init(const button_t *btn) {
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == btn) {
        ret = E_NOT_OK;
    } else {
        ret = gpio_pin_direction_init(&btn->button_pin);
    }
    return ret;
}

/**
 * @brief Initialize the assigned pin to input
 * @param btn pointer to the button configurations
 * @return Status of the function
 *          (E_OK) : done successfully
 *          (E_NOT_OK) : has issue 
 **/
Std_ReturnType button_read_state(const button_t *btn, button_state_t *btn_state) {
    Std_ReturnType ret = E_NOT_OK;
    logic_t pin_logic_status = GPIO_LOW;
    
    if (NULL == btn || NULL == btn_state) {
        ret = E_NOT_OK;
    } else {
        gpio_pin_read_logic(&(btn->button_pin), &pin_logic_status);
        if (BUTTON_ACTIVE_HIGH == btn->button_connection) {
            if (GPIO_HIGH == pin_logic_status) {
                *btn_state = BUTTON_PRESSED;
            } else {
                *btn_state = BUTTON_RELEASED;
            }
        } else if (BUTTON_ACTIVE_LOW == btn->button_connection) {
            if (GPIO_HIGH == pin_logic_status) {
                *btn_state = BUTTON_RELEASED;
            } else {
                *btn_state = BUTTON_PRESSED;
            }
        } else {
            /*nothing*/
        }
        ret = E_OK;
    }
    return ret;
}