#ifndef _HCSR04_H
#define _HCSR04_H

#ifndef F_CPU
	#define F_CPU 16000000UL
#endif

#include <avr/interrupt.h>
#include "../lib/timer.h"
#include "../lib/extirq.h"

void HCSR04_hardware_init();
void set_trigger(volatile uint16_t counter);
void wait_trigger(volatile uint16_t counter);

#endif