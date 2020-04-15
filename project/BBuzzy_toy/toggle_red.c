#include <msp430.h>
#include "blink.h"
#include "led.h"
#include "buzzer.h"

char toggle_red()/* always toggle! */ 
{
  static char state = 0;
  
  switch (state) {
  case 0:
    red_on = 1;
    buzzer_set_period(2000, 1);
    state = 1;
    //add jmp to go to default?
    //break;
    goto end;

  case 1:
    red_on = 0;
    buzzer_set_period(2000, 3);
    state = 0;
    //break;
    goto end;

  default:
    state = 0;
    red_on = 0;
  }
 end:
  return 1;/* always changes an led */
}
