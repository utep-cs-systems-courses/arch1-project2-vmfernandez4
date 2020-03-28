#include <msp430.h>
#include "led.h"
#include "switches.h"

unsigned char wait = 1;

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
  led_update();
}

void led_update(){
  if (switch_state_changed) {
    char ledFlags = 0; /* by default, no LEDs on */
    unsigned int i;   //Delay variable

    if(sw4_state_down){
     ledFlags |= sw4_state_down ? LED_GREEN : 0;
     ledFlags |= sw4_state_down ? 0 : LED_RED;
    }

    if(sw2_state_down){
      ledFlags |= sw2_state_down ? LED_RED : 0;
      ledFlags |= sw2_state_down ? 0 : LED_GREEN;
    }

    if(sw1_state_down){
      ledFlags |= sw1_state_down ? LED_GREEN : 0;
      ledFlags |= sw1_state_down ? 0 : LED_RED;

      ledFlags |= sw1_state_down ? LED_RED : 0;
      ledFlags |= sw1_state_down ? 0 : LED_GREEN;
    }

    if(sw3_state_down){
      if (wait){
        wait = 0;
      }else {
        wait = 1;
      }

      // while(loop){
      for(int j = 0; j < 10; j++){
        P1OUT ^= LED_RED;
        for(i = 0; i < 60000; i++);
        P1OUT ^= LED_GREEN;
        for(i = 0; i < 60000; i++);
        P1OUT &= LED_RED;
      }

      P1OUT &= LED_RED;
      P1OUT &= LED_GREEN;
      // }
    }

    if(wait){
    }else {
        P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
        P1OUT |= ledFlags;         // set bits for on leds
    }
  }
  switch_state_changed = 0;
}

void led_tgg_hard(int red, int green){
     P1OUT &= (0xff - LEDS);
    char ledFlags = 0; /* by default, no LEDs on */

      ledFlags |= red ? LED_RED : 0;
      ledFlags |= green ? 0 : LED_GREEN;

      P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
      P1OUT |= ledFlags;         // set bits for on leds

}