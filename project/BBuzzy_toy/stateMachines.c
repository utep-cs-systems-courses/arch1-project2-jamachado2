#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"
#include <time.h>

/* alternate state of led by pressing SW3*/
char switch_leds() 
{  
  static char state = 0;

  switch(state){
  case 0:
    red_on = 0;
    green_on =1;
    state = 1;
    buzzer_set_period(5000,1);
    break;
  case 1:
    red_on = 1;
    green_on = 0;
    state = 2;
    delay2(50);
    buzzer_set_period(6000,4);
    break;
  case 2:
    red_on = 0;
    green_on = 1;
    state = 3;
    delay2(30);
    buzzer_set_period(4000,2);
    break;
  case 3:
    red_on = 1;
    green_on = 0;
    state = 4;
    buzzer_set_period(7000,4);
    delay2(50);
    break;
  case 4:
    red_on = 0;
    green_on = 1;
    state = 5;
    buzzer_set_period(4000,1);
    delay2(80);
    break;
  case 5:
    red_on = 1;
    green_on = 0;
    state = 6;
    buzzer_set_period(4000, 3);
    delay2(50);
    break;
  case 6:
    green_on = 0;
    state = 7;
    buzzer_set_period(0,0);
    }
}
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
char sw4_button(){
  static char state = 0;

  switch(state){
  case 0:
    red_on = 0;
    green_on =1;
    state = 1;
  }
}

void test_sw4(){
  led_changed = sw4_button();
  led_update();
}
