#ifndef _HCSR04_H
#define _HCSR04_H

#include <avr/interrupt.h>
#include "../lib/bits.h"
#include "../lib/timer.h"
#include "../lib/extirq.h"

void set_trigger();
uint16_t wait_echo();
void wait_trigger();

#endif