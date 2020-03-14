#include <msp430.h>
#include "switches.h"
#include "buzzer.h"

/* SWITCH on P2 (s4) */
void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & SWITCHES){
    P2IFG &= ~SWITCHES;
    switch_interrupt_handler();
  }
}
