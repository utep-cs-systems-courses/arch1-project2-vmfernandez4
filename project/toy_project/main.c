#include <msp430.h>
#include "../timerLib/libTimer.h"
#include "led.h"
#include "switches.h"
#include "statemachine.h"

void main(void) 
{  
  configureClocks();
  init_state();
  state_advance();
  or_sr(0x18);  // CPU off, GIE on
} 
