#include "../lib/extirq.h"

/*
#define ROWS_REG 0x07
#define PIN1_REG 0x7f

static volatile pin2_prev = 0xff;
static volatile pin1_prev = 0x7f;
static volatile pin0_prev = 0xff;
*/

static volatile uint8_t pd_flag = 0x00;

uint8_t interrupt_int0(){
    if(pd_flag == 2){
        pd_flag = 0;
        return 1;
    }else{
        return 0;
    }
}

void int0_hardware_init(){
    DDRD &= ~(0x02);
    PORTD |= 0x02;

    SET_BIT(EICRA, ISC01);
    SET_BIT(EICRA, ISC00);

    SET_BIT(EIMSK, INT0);
}

ISR(INT0_vect){
    pd_flag = 2;
}

/*
void irq_hardware_init(uint8_t pin_rows, uint8_t * pin_change){
    PCICR |= (ROWS_REG & pin_rows);

    if(TST_BIT(PCICR, PCIE2)){
        DDRD |= pin_change[2];
        PORTD |= pin_change[2];
    }

    if(TST_BIT(PCICR, PCIE1)){
        DDRC |= (PIN1_REG & pin_change[1]);
        PORTC |= (PIN1_REG & pin_change[1]);
    }

    if(TST_BIT(PCICR, PCIE0)){
        DDRB |= pin_change[0];
        PORTB |= pin_change[0];
    }

    PCMSK2 = pin_change[2];
    PCMSK1 = (PIN1_REG & pin_change[1]);
    PCMSK0 = pin_change[0];    
}

ISR(PCINT0_vect){
    uint8_t pin_changed;

    pin_changed = PIND ^ pin2_prev;
    pin2_prev = PIND;

    if(pin_changed & (1 << PIND7)){
        pd_flag = pd_flag | (1 << PIND7); 
    }
    if(pin_changed & (1 << PIND6)){
        
    }
    if(pin_changed & (1 << PIND5)){
        
    }
    if(pin_changed & (1 << PIND4)){
        
    }
    if(pin_changed & (1 << PIND3)){
        
    }
    if(pin_changed & (1 << PIND2)){
        
    }
    if(pin_changed & (1 << PIND1)){
        
    }
    if(pin_changed & (1 << PIND0)){
        
    }

    pin_changed = PINC ^ pin1_prev;
    pin1_prev = PINC;

    if(pin_changed & (1 << PINC6)){
        
    }
    if(pin_changed & (1 << PINC5)){
        
    }
    if(pin_changed & (1 << PINC4)){
        
    }
    if(pin_changed & (1 << PINC3)){
        
    }
    if(pin_changed & (1 << PINC2)){
        
    }
    if(pin_changed & (1 << PINC1)){
        
    }
    if(pin_changed & (1 << PINC0)){
        
    }

    pin_changed = PINB ^ pin0_prev;
    pin0_prev = PINB;

    if(pin_changed & (1 << PINB7)){
        
    }
    if(pin_changed & (1 << PINB6)){
        
    }
    if(pin_changed & (1 << PINB5)){
        
    }
    if(pin_changed & (1 << PINB4)){
        
    }
    if(pin_changed & (1 << PINB3)){
        
    }
    if(pin_changed & (1 << PINB2)){
        
    }
    if(pin_changed & (1 << PINB1)){
        
    }
    if(pin_changed & (1 << PINB0)){
        
    }
    
}
*/