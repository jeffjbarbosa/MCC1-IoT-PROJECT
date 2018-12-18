#include "../lib/extirq.h"

void int0_hardware_init(){
    DDRD &= ~(0x02);
    PORTD |= 0x02;

    SET_BIT(EICRA, ISC01);
    SET_BIT(EICRA, ISC00);

    SET_BIT(EIMSK, INT0);
}
