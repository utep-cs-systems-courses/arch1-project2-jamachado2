#include <msp430.h>
#include "buzzer.h"
#include "led.h" 
#include "song.h"
#include <time.h>

/* idea: have two leds that change slow with a sound, 
   click again and change faster one last to stop */

char change_note_redgreen()/* always toggle! */ 
{
  static char note = 0;
  
  switch (note) {
  case 0:
    red_on = 1; 
    delay(10);
    buzzer_set_period(4000, 2); //F
    note = 1;
    green_on = 1;
    break;
    case 1:
    red_on = 0;
    buzzer_set_period(5000, 2); //F
    green_on = 0;
    note = 2;
    delay(10);
    break;
  case 2:
    red_on = 1;
    delay(10);
    buzzer_set_period(4000, 2); //F
    green_on = 0;
    note = 3;
    break;
  case 3:
    red_on = 0;
    buzzer_set_period(6000, 1); // C#
    green_on = 1;
    note = 4;
    delay(1);
    break;
  case 4:
    red_on = 1;
    delay(1);
    buzzer_set_period(4000, 2); //F
    green_on = 0;
    note = 5;
    break;
  case 5:
    red_on = 0;
    delay(1);
    buzzer_set_period(5000, 3); // G# 1 
    green_on = 1;
    note = 6;
    break;
  case 6:
    red_on = 1;
    delay(1);
    buzzer_set_period(3000, 4); // G#
    green_on = 0;
    note = 7;
    break;
  case 7:
    red_on = 0;
    delay(3);
    buzzer_set_period(3000,4); //C
    green_on = 1;
    note = 8;
    break;
  case 8:
    red_on = 1;
    delay(3);
    buzzer_set_period(5000,1); //G
    green_on = 0;
    note = 9;
    break;
  case 9:
    red_on = 0;
    delay(3);
    buzzer_set_period(4000,7); //F
    green_on = 1;
    note = 10;
    break;
  case 10:
    buzzer_set_period(0,0);
    note = 11;
    break;
   }
  return 1;/* always changes an led */
}

void delay(int sec){
  unsigned long int count = 32767,i,j;
  
    for(i = 0; i<sec;i++)
      for(j=0;j<count;j++);
}

void sound_state(){
  led_changed = change_note_redgreen();
  led_update();
}


