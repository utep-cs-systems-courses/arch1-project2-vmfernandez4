#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"

unsigned char sound = 0;

void init_state(){
  switch_init();
  led_init();
};

void state_advance(){

    if(sw4_state_down){
        led_update();

        if(sound){
            buzzer_init();
            buzzer_set_period(1500);
        }
    }

    if(sw2_state_down){
        led_update();
        
        if(sound){
            buzzer_init();
            buzzer_set_period(500);
        }
    }

    if(sw1_state_down){
        led_update();
        
        if(sound){
            songOne();
        }
    }

    if(sw3_state_down){
        led_update();

        if(sound){
            sound = 0;
            buzzer_set_period(0);
        }else{
            sound = 1; // Enable sound      
        }
    }

};