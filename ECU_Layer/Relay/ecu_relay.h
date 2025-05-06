/* 
 * File:   ecu_relay.h
 * Author: Administrator
 *
 * Created on May 6, 2025, 9:11 PM
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H

/*Section : Includes*/
#include "ecu_relay_config.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/*Section : Macro Declarations*/
#define RELAY_ON_STATUS     0x01U
#define RELAY_OFF_STATUS    0x00U 
/*Section : Macro Functions Declarations*/

/*Section : Data Type Declarations*/
typedef struct{
    uint8 relay_port : 4;
    uint8 relay_pin : 3;
    uint8 relay_status : 1;
}relay_t;
/*Section : Function Declarations*/
Std_ReturnType relay_init(const relay_t *_relay);
Std_ReturnType relay_on(const relay_t *_relay);
Std_ReturnType relay_off(const relay_t *_relay);
#endif	/* ECU_RELAY_H */

