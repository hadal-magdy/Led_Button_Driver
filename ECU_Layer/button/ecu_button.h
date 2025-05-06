/* 
 * File:   ecu_button.h
 * Author: Administrator
 *
 * Created on May 3, 2025, 8:44 PM
 */

#ifndef ECU_BUTTON_H
#define	ECU_BUTTON_H

/*Section : Includes*/

#include "ecu_button_config.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/*Section : Macro Declarations*/

/*Section : Macro Functions Declarations*/

/*Section : Data Type Declarations*/
typedef enum{
    BUTTON_PRESSED = 0,
    BUTTON_RELEASED
}button_state_t;

typedef enum{
    BUTTON_ACTIVE_HIGH,
    BUTTON_ACTIVE_LOW
}button_active_t;

typedef struct{
    pin_config_t button_pin;
    button_state_t button_state;
    button_active_t button_connection;
}button_t;

/*Section : Function Declarations*/

/**
 * @brief Initialize the assigned pin to input
 * @param btn pointer to the button configurations
 * @return Status of the function
 *          (E_OK) : done successfully
 *          (E_NOT_OK) : has issue 
 **/
Std_ReturnType button_init(const button_t *btn);
/**
 * @brief Initialize the assigned pin to input
 * @param btn pointer to the button configurations
 * @return Status of the function
 *          (E_OK) : done successfully
 *          (E_NOT_OK) : has issue 
 **/
Std_ReturnType button_read_state(const button_t *btn, button_state_t *btn_state);

#endif	/* ECU_BUTTON_H */

