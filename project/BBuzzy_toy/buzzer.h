#ifndef buzzer_included
#define buzzer_included

void buzzer_init();
void buzzer_set_period(short cycles, char freq);

/* to change the frequency note */
void add_sound(unsigned char note);

#endif // included
