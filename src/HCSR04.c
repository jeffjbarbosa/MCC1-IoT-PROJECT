#include "HCSR04.h"

#define TOP_T 20
#define SETUP_T 0xC2
#define TOP_E 4
#define SETUP_E 0x02
#define MAX_E 11600 
#define WAIT 30000

static volatile uint16_t counter = 0;

void set_trigger(){
    timer0_hardware_init(TOP_T, SETUP_T);
}

uint16_t wait_echo(){
    while((interrupt_int0() == 0) && (counter < MAX_E)){}
    return counter<<1;
}

void wait_trigger(){
    while(counter <= WAIT){}
}

ISR(TIM0_COMPA_vect){
    if(counter > WAIT){
        counter = -1;
    }else if(OCIE0A == TOP_T && counter == 1){
        timer0_hardware_init(TOP_E, SETUP_E);
        counter = -1;
    }

    counter++;
}