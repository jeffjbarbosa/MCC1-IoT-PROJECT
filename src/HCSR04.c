#include "../lib/HCSR04.h"

#define TOP_E 4
#define SETUP_E 0x02
#define TRG_HIGH 10
#define MAX_E 23200
#define WAIT 60000

static volatile uint16_t counter = 0;

void HCRS04_hardware_init(){
	DDRD |= 0x40;
	CLR_BIT(PORTD, PD6);
	int0_hardware_init();
}

void set_trigger(){
	SET_BIT(PORTD, PD6);
	timer0_hardware_init(TOP_E, SETUP_E);
}

uint16_t wait_echo(){
    while((interrupt_int0() == 0) && (counter < MAX_E)){}
    return counter;
}

void wait_trigger(){
    while(counter < WAIT){}
	counter = 0;
}

ISR(TIMER0_COMPA_vect){
	if((TST_BIT(PORTD, PD6) == 1) && (counter == TRG_HIGH)){
		CLR_BIT(PORTD, PD6);
		counter = -1;
	}

	counter++;
}