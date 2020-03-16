#ifndef switches_included
#define switches_included

#include <msp430.h>

/* for some reason it only works with s4, why? */
#define SW1 BIT0                /* switch1 is p2.0 */
#define SW2 BIT1                /* switch2 is p2.1 */
#define SW3 BIT2                /* switch3 is p2.2 */
#define SW4 BIT3		/* switch1 is p2.3 */ /* BIT3 */
#define SWITCHES (BIT0 | BIT1 | BIT2 | BIT3)		/* only 1 switch on this board */

void switch_init();
void switch_interrupt_handler();

extern char switch_state_down, switch_state_down1, switch_state_changed; /* effectively boolean */

#endif // included
