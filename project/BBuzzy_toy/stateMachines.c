#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"
#include <time.h>
#include "switch_leds_assembly.h"

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
void delay2(int sec){
  unsigned long int count = 32767,i,j;

  for(i = 0; i<sec; i++)
    for(j = 0; j<count; j++);
}
void alternate()/* alternate between red & green */
{
    led_changed = switch_leds();
    led_update();
}


/* test sw4 */
/* create one more song */
char sw4_button(){
  static char state = 0;

  switch(state){
  case 0:
    red_on = 0;
    buzzer_set_period(500,2);
    state = 1;
    break;
  case 1:
    green_on = 1;
    buzzer_set_period(200,4);
    state = 2;
    break;
  case 2:
    red_on = 1;
    buzzer_set_period(350,1);
    state = 3;
    break;
  case 3:
    green_on = 0;
    buzzer_set_period(600,2);
    state = 4;
    break;
  case 4:
    red_on = 0;
    buzzer_set_period(750,4);
    state = 5;
    break;
  case 5:
    green_on = 1;
    buzzer_set_period(200,2);
    state = 6;
    break;
  case 6:
    red_on = 1;
    buzzer_set_period(450,1);
    state = 7;
    break;
  case 7:
    green_on = 0;
    buzzer_set_period(600,4);
    state = 8;
    break;
  case 8:
    red_on = 0;
    buzzer_set_period(10000,1);
    state = 9;
    break;
  case 9:
    buzzer_set_period(0,0);
    state = 10;
    break;
  }
}

void test_sw4(){
  led_changed = sw4_button();
  led_update();
}
