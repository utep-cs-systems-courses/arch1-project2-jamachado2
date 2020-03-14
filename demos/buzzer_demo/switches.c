#include <msp430.h>
#include "switches.h"
#include "buzzer.h"

char switch_state_down, switch_state_change;

static char
switch_update_interrupt_sense()
{
  char p1val = P2IN;
  /* UPDATE SWITCH INTERRUPT TO DETECT CHANGES FROM CURRENT BUTTONS */
  P2IES |= (p1val & SWITCHES);   /* if switch up, sense down */
  P2IES &= (p1val | ~SWITCHES);  /* if switch down, sense up */
  return p1val;
}

void
switch_init(){
  P1REN |= SWITCHES;     /* enables resistors for switches */
  P2IE = SWITCHES;       /* enable interrupts from switches */
  P2OUT |= SWITCHES;     /* pull-ups for switches */
  P2DIR &= ~SWITCHES;    /* set switches' bits for inputs */

  switch_update_interrupt_sense();
  buzzer_set_period(SW1);
  /** should I add the other switches here ? */
}

void
switch_interrupt_handler()
{
  char p1val = switch_update_interrupt_sense();
  switch_state_down = (p1val & SW1) ? 0 : 1; /* 0 when sw1 is up */
  switch_state_change = 1;

  switch_state_down = (p1val & SW2) ? 1 : 0;
  switch_state_change = 0;
  buzzer_set_period(p1val);

  /* to shut the fuck up the noise */
  
}
