#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

static short freq(unsigned char note);

void buzzer_init()
{
  /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
  */

  timerAUpmode();/* used to drive speaker */
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;/* enable output to speaker (P2.6) */
}

void buzzer_set_period(short cycles, char freq) /* buzzer clock = 2MHz.  (period of 1k results in 2kHz tone) */
{
  CCR0 = cycles;
  CCR1 = cycles >> freq;/* change frequency */
}

/* is this all I need ? */
static short freq(unsigned char note)
{/*
  if(note == 0){
    return 0000;
    }*/
  // C# 
  if(note == 1){
    return 17.32;
  }
  // F 0
  if(note == 2){
    return 21.83;
  }
  // G# 1
  if(note == 3){
    return 51.91;
  }
  // G# 0
  if (note == 4){
    return 25.96;
  }
  // mute
  return 0;
}

void add_sound(unsigned char i){
  buzzer_set_period(freq(i), 1);
}
