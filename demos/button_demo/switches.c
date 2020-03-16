#include <msp430.h>
#include "switches.h"
#include "led.h"

char switch_state_down, switch_state_down1, switch_state_changed; /* effectively boolean */

static char 
switch_update_interrupt_sense()
{
  char p1val = P2IN; /* P1IN */
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p1val & SWITCHES);	/* if switch up, sense down */ /* P1IES */
  P2IES &= (p1val | ~SWITCHES);	/* if switch down, sense up */ /* P1IES */
  return p1val;
}

void 
switch_init()			/* setup switch */
{
  /*  chage bits 0, 1, 2, 3 */
  P2REN |= SWITCHES;		/* P1REN */ /* enables resistors for switches */
  P2IE = SWITCHES;		/* P1IE*/ /* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* P1OUT */ /* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* P1DIR */ /* set switches' bits for input */
  switch_update_interrupt_sense();
  led_update();
}

void
switch_interrupt_handler()
{
  char p1val = switch_update_interrupt_sense();
  
  switch_state_down = (p1val & BIT0) ? 0 : 1; /* 0 when SW1 is up */
  switch_state_changed = 1;
  
  switch_state_down1 = (p1val & BIT1) ? 0 : 1;
  switch_state_changed = 1;
  
  led_update();
}
