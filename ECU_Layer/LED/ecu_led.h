/* 
 * File:   ecu_led.h
 * Author: hadal magdy
 *
 * Created on April 17, 2025, 9:02 PM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H

/*Section : Includes*/

#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "ecu_led_config.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/*Section : Macro Declarations*/

/*Section : Macro Functions Declarations*/

/*Section : Data Type Declarations*/
typedef enum{
    LED_OFF,
    LED_ON
}led_status_t;

typedef struct{
    uint8 port_name : 4;
    uint8 pin : 3;
    uint8 led_status : 1; 
}led_t;

/*Section : Function Declarations*/
Std_ReturnType  led_init(const led_t *led);
Std_ReturnType  led_on(const led_t *led);
Std_ReturnType  led_off(const led_t *led);
Std_ReturnType  led_toggle(const led_t *led);

#endif	/* ECU_LED_H */

