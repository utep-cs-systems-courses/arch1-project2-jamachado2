#include <msp430.h>
#include "stateMachines.h"
#include "switch_machine.h" // to control switches 
#include "switches.h"
#include "buzzer.h"
#include "blink.h"
#include "song.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){/* 250 interrupts/sec */
   static char blink_count = 0;
   switch_interrupt_handler();

   if(switch_state_down){
     if(++blink_count == 125){
       sound_state();
       delay(4);
       blink_count = 0;       
     }
   }
   if(switch_state_down2){
     if (++blink_count == 125) {
    state_advance();
    blink_count = 0;
    }
   }
   if(switch_state_down3){
     if(++blink_count == 125){
       alternate();
       blink_count = 0;
     }
   }
   if(switch_state_down4){
     if(++blink_count == 125){

       blink_count = 0;
     }
   }
}
