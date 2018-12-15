#include "../lib/timer.h"

#define MOD_REG 0xC0
#define PRE_REG 0x07

/*
    TCCR0A = |COM0A1|COM0A0|  X  |  X  |  -  |  -  | WGM01|WGM00|
    TCCR0B = |   X  |   X  |  -  |  -  |WGM02| CS02|  CS01| CS00|
    TIMSK0 = |   -  |   -  |  -  |  -  |  -  |  X  |OCIE0A|  X  |

*/
void timer0_hardware_init(uint8_t top, uint8_t mode_prescale){
    // Valor de TOP:
    OCR0A = top;
    // Modo CTC
    CLR_BIT(TCCR0B, WGM02);
    SET_BIT(TCCR0A, WGM01);
    CLR_BIT(TCCR0A, WGM00);
	// Ligar fonte de clock:
	TCCR0B = TCCR0B | (PRE_REG & mode_prescale);
	// Configuração de mudança de estado: 
    TCCR0A = TCCR0A | (MOD_REG & mode_prescale);
    // Habilitação de IRQ: 
    SET_BIT(TIMSK0, OCIE0A);
}



void timer1_hardware_init(uint16_t top, uint8_t prescale){
    // Valor de TOP:
    OCR1A = top;
    // Modo CTC:
    CLR_BIT(TCCR1B, WGM13);
    SET_BIT(TCCR1B, WGM12);
    CLR_BIT(TCCR1A, WGM11);
    CLR_BIT(TCCR1A, WGM10);
    // Ligar fonte de clock:
    TCCR1B = TCCR1B | (PRE_REG & prescale);
    // Configuração de mudança de estado:
    CLR_BIT(TCCR1A, COM1A1);
    SET_BIT(TCCR1A, COM1A0);
    CLR_BIT(TCCR1A, COM1B1);
    SET_BIT(TCCR1A, COM1B0); 
    // Habilitação de IRQ:
    SET_BIT(TIMSK1, OCIE1A);
    SET_BIT(TIMSK1, OCIE1B);
}

/*
    TCCR2A = |COM2A1|COM2A0|  X  |  X  |  -  |  -  | WGM21|WGM20|
    TCCR2B = |   X  |   X  |  -  |  -  |WGM22| CS22|  CS21| CS20|
    TIMSK2 = |   -  |   -  |  -  |  -  |  -  |  X  |OCIE2A|  X  |

*/
void timer2_hardware_init(uint8_t top, uint8_t mode_prescale){
    // Valor de TOP:
    OCR2A = top;
    // Modo CTC:
    CLR_BIT(TCCR2B, WGM22);
    SET_BIT(TCCR2A, WGM21);
    CLR_BIT(TCCR2A, WGM20);
	// Ligar fonte de clock:
	TCCR2B = TCCR2B | (PRE_REG & mode_prescale);
	// Configuração de mudança de estado:
    TCCR2A = TCCR2A | (MOD_REG & mode_prescale);
    // Habilitação de IRQ: 
    SET_BIT(TIMSK2, OCIE2A);
}