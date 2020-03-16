#include <msp430.h>
#include "led.h"
#include "switches.h"

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
  led_update();
}

void led_update(){
  if (switch_state_changed) {
    char ledFlags = 0; /* by default, no LEDs on */

    if(switch_state_down){
      ledFlags |= switch_state_down ? 1 : LED_GREEN;
      ledFlags |= switch_state_down ? LED_RED : 0;
    }
    
    if(switch_state_down1){
      ledFlags |= switch_state_down1 ? 0 : LED_RED;
      ledFlags |= switch_state_down1 ? LED_GREEN : 1; 
    }
    
    P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags;         // set bits for on leds
  }
  switch_state_changed = 0;
}

