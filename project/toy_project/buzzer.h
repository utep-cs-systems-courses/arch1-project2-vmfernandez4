#ifndef buzzer_included
#define buzzer_included

// Notes
#define a 300
#define b 450
#define c 550
#define d 650
#define e 800
#define f 415
#define g 440

void buzzer_init();
void timer_delay(unsigned int milliSeconds);
void buzzer_set_period(short cycles);

void songOne();

#endif // included
