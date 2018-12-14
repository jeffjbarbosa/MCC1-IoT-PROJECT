#ifndef _EXTIRQ_H
#define _EXTIRQ_H

#include <avr/interrupt.h>
#include "../lib/bits.h"

//void irq_hardware_init(uint8_t pin_rows, uint8_t * pin_change);
void int0_hardware_init();
uint8_t interrupt_int0();

#endif