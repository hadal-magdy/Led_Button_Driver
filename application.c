/* 
 * File:   application.c
 * Author: hadal magdy
 *
 * Created on April 16, 2025, 12:32 AM
 */

#include "application.h"
#define _XTAL_FREQ 8000000 

led_t led1 = {
    .port_name = PORTC_INDEX,
    .pin = GPIO_PIN0,
    .led_status = GPIO_LOW
};
led_t led2 = {
    .port_name = PORTC_INDEX,
    .pin = GPIO_PIN1,
    .led_status = GPIO_LOW
};

button_t btn_high = {
    .button_pin.port = PORTD_INDEX,
    .button_pin.pin = GPIO_PIN0,
    .button_pin.direction = GPIO_DIRECTION_INPUT,
    .button_pin.logic = GPIO_LOW,
    .button_connection = BUTTON_ACTIVE_HIGH,
    .button_state = BUTTON_RELEASED
};

button_t btn_low = {
    .button_pin.port = PORTD_INDEX,
    .button_pin.pin = GPIO_PIN1,
    .button_pin.direction = GPIO_DIRECTION_INPUT,
    .button_pin.logic = GPIO_HIGH,
    .button_connection = BUTTON_ACTIVE_LOW,
    .button_state = BUTTON_RELEASED
};

button_state_t btn_high_status = BUTTON_RELEASED;
button_state_t btn_low_status = BUTTON_RELEASED;

button_state_t btn_high_valid_status = BUTTON_RELEASED;
button_state_t btn_high_last_valid_status = BUTTON_RELEASED;

led_status_t led1_status = LED_OFF;

uint32 btn_high_valid = 0;
uint32 ProgramSelected = 0;

Std_ReturnType ret = E_NOT_OK;

void program1() {
    led_on(&led1);
    __delay_ms(500);
    led_off(&led1);
    __delay_ms(500);
}

void program2() {
    for (int i = 0; i < 2; i++) {
        led_on(&led1);
        __delay_ms(500);
        led_off(&led1);
        __delay_ms(500);
    }
}

void program3() {
    for (int i = 0; i < 3; i++) {
        led_on(&led1);
        __delay_ms(500);
        led_off(&led1);
        __delay_ms(500);
    }
}

int main(int argc, char** argv) {
    application_init();
    while (1) {
        ret = button_read_state(&btn_high, &btn_high_status);
        if (BUTTON_PRESSED == btn_high_status) {
            btn_high_valid++;
            if (btn_high_valid > 500) {
                btn_high_valid_status = BUTTON_PRESSED;
            }
        } else {
            btn_high_valid = 0;
            btn_high_valid_status = BUTTON_RELEASED;

        }
        if (btn_high_valid_status != btn_high_last_valid_status) {
            btn_high_last_valid_status = btn_high_valid_status;
            if (BUTTON_PRESSED == btn_high_valid_status) {
                if(3 == ProgramSelected){
                    ProgramSelected = 0;
                }
                ProgramSelected++;
                switch(ProgramSelected){
                    case 1: program1(); break;
                    case 2: program2(); break;
                    case 3: program3(); break;
                    default: break;
                }
                //it was for magic button
                /*if(LED_OFF == led1_status){
                    led_on(&led1);
                    led1_status = LED_ON;
                }
                else{
                    led_off(&led1);
                    led1_status = LED_OFF;

                }*/
            }
        }
    }
    return (EXIT_SUCCESS);
}

void application_init() {
    ret = led_init(&led1);
    ret = led_init(&led2);

    ret = button_init(&btn_high);
    ret = button_init(&btn_low);
}

