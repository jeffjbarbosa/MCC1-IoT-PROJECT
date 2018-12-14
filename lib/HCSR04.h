#ifndef _HCSR04_H
#define _HCSR04_H

#ifndef F_CPU
	#define F_CPU 16000000UL
#endif

#include <avr/interrupt.h>
#include "../lib/timer.h"
#include "../lib/extirq.h"

void set_trigger();
uint16_t wait_echo();
void wait_trigger();

#endif