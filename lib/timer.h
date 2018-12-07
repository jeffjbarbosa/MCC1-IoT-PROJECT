#ifndef _TIMER_H
#define _TIMER_H

#ifndef F_CPU
	#define F_CPU 16000000UL
#endif

#include <avr/interrupt.h>
#include "../lib/bits.h"

void timer0_hardware_init(uint8_t top, uint8_t prescale);
void timer1_hardware_init(uint16_t top, uint8_t prescale);
void timer2_hardware_init(uint8_t top, uint8_t prescale);

#endif