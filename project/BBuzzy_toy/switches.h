#ifndef switches_included
#define switches_included

#define SW1 BIT0/* switch1 is p1.3 */
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3
#define SWITCHES (SW1 | SW2 | SW3 | SW4)/* 4 switches on this board */

void switch_init();
void switch_interrupt_handler();

extern char switch_state_down,
            switch_state_down2,
            switch_state_down3,
            switch_state_down4,
            switch_state_changed; /* effectively boolean */

void add_sound(unsigned char i);

/* change note ? */
// extern char change_note; */

#endif // included
