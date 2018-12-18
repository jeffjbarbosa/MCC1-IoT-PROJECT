#include "../lib/HCSR04.h"

#define TOP_E 4
#define SETUP_E 0x02
#define TRG_HIGH 10
#define WAIT 60000

void HCSR04_hardware_init(){
	DDRD |= 0x40;
	CLR_BIT(PORTD, PD6);
	int0_hardware_init();
	timer0_hardware_init(TOP_E, SETUP_E);
}

void set_trigger(volatile uint16_t counter){
	SET_BIT(PORTD, PD6);
	while(counter < TRG_HIGH){}
	CLR_BIT(PORTD, PD6);
}

void wait_trigger(volatile uint16_t counter){
    while(counter < WAIT){}
}

