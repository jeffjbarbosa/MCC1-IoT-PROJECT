#ifndef _EXTIRQ_H
#define _EXTIRQ_H

#ifndef F_CPU
	#define F_CPU 16000000UL
#endif

#include <avr/interrupt.h>
#include "../lib/bits.h"

void int0_hardware_init();

#endif