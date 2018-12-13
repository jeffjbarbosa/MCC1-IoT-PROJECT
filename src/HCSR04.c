#include "HCSR04.h"

#define TOP_T 20
#define SETUP_T 0xC2
#define TOP_E 4
#define SETUP_E 0x02
#define MAX_E = 11600 
#define WAIT 30000

volatile uint8_t echo_interrupt = 0;
volatile uint16_t counter = 0;

void set_trigger(){
    timer0_hardware_init(TOP_T, SETUP_T);
    while(counter <= 5);
}

uint16_t wait_echo(){
    timer0_hardware_init(TOP_E, SETUP_E);
    while((echo_interrupt == 0) && (counter < MAX_E+6));
    return counter-6;
}

void wait_trigger(){
    while(counter <= WAIT);
}

ISR(TIM0_COMPA_vect){
    if(counter > WAIT){
        counter = 0;
    }

    counter++;
}