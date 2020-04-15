#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"
#include <time.h>

/* alternate state of led by pressing SW3*/
/*char switch_leds() 
{  
  static char state = 0;

  switch(state){
  case 0:
    red_on = 0;
    green_on =1;
    state = 1;
    break;
  case 1:
    red_on = 1;
    green_on = 0;
    state = 2;
    delay2(50);
    break;
  case 2:
    red_on = 0;
    green_on = 1;
    state = 3;
    delay2(30);
    break;
  case 3:
    red_on = 1;
    green_on = 0;
    state = 4;
    delay2(50);
    break;
  case 4:
    red_on = 0;
    green_on = 1;
    state = 5;
    delay2(80);
    break;
  case 5:
    red_on = 1;
    green_on = 0;
    state = 6;
    delay2(50);
    break;
  case 6:
    green_on = 0;
    state = 7;
    }
}
*/
