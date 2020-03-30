#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachines.h"
#include "switch_machine.h"

/* Switch on P1 (S2) */
void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & SWITCHES) {      /* did a button cause this interrupt? */
    P2IFG &= ~SWITCHES;      /* clear pending sw interrupts */
    switch_interrupt_handler();/* single handler for all switches */
    
    if(switch_func == 1){
      song_interrupt_handler();
    }
    /* blink with sound */
    if(switch_func == 2){
      blink_interrupt_handler();
    }
    if(switch_func == 3){
      alternate_interrupt_handler();
    }
    if(switch_func == 4){
    test_SW4_handler();
   }
  }
}
