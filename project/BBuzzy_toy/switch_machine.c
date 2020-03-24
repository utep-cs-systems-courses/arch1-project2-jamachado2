#include <msp430.h>
#include "switch_machine.h"
#include "led.h"
#include "switches.h"
#include "stateMachines.h" // this is the blink demo
#include "buzzer.h"

char switch_func = 1;

void blink_interrupt_handler(){
  //static char blink_count = 0;
  //switch_interrupt_handler();

  /* blink with sound */
  if(switch_state_down2){
    switch_func = 2;
  }/*if (++blink_count == 125) {
    state_advance();
    blink_count = 0;
    }*/

}

void song_interrupt_handler(){
  if(switch_state_down){
    switch_func = 1;
  }
}

void alternate_interrupt_handler(){
  if(switch_state_down3){
    switch_func = 3;
  }
}
