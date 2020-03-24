//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"
//#include "sled.h" /* Only one led */
#include "buzzer.h"
#include "switches.h"

int main(void) {

  configureClocks();/* setup master oscillator, CPU & peripheral clocks */
  switch_init();
  led_init();
  //led_init2(); /* only one */
  enableWDTInterrupts();/* enable periodic interrupt */

  buzzer_init();
  //buzzer_set_period(0);
  delay(0);
  
  or_sr(0x18);/* CPU off, GIE on */
}
