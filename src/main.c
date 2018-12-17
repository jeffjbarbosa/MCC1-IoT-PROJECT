/*
 * MCC1-IoT-PROJECT.c
 *
 * Created: 12/1/2018 11:25:28 PM
 * Author : jack
 */

#include "../lib/avr_usart.h"
#include "../lib/timer.h"
#include "../lib/Modbus_RTU.h"
#include "../lib/HCSR04.h"
#include "../lib/Motor_de_Passos.h"

uint8_t rx_pkg[16],i;

void f_stateA(void);
void f_stateB(void);
void f_stateC(void);
void f_stateD(void);

/* Definição dos estados */
typedef enum {
	STATE_A,
	STATE_B,
	STATE_C,
	STATE_D,
	NUM_STATES
} state_t;

/* Definição da estrutura mantenedora do vetor de estados */
typedef struct {
	state_t myState;
	void (*func)(void);
}fsm_t;

/* Mapeamento entre estado e funções */
fsm_t myFSM[] = {
	{ STATE_A, f_stateA },
	{ STATE_B, f_stateB },
	{ STATE_C, f_stateC },
	{ STATE_D, f_stateD },

};

/* Estado atual */
volatile state_t curr_state = STATE_A;

int main(void)
{	
	//USART_Init(B9600);
    //uint8_t pacote[8] = {0x15, 0x01, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00};
		
	sei();

    while (1) 
    {	
		// chamada da funcao referente ao estado atual da FSM
		(*myFSM[curr_state].func)();
    }
}

// OBS: escolher qual interrupcao deve mudar o estado atual da FSM
ISR(USART_RX_vect)
{	
	for (i=0; i < 8;i++)
		rx_pkg[i] = USART_rx();
	
	// switch case para mudar o estado atual da FSM
	switch (curr_state)
	{
		case STATE_A:
		curr_state = STATE_B;
		break;
		
		case STATE_B:
		curr_state = STATE_C;
		break;
		
		case STATE_C:
		curr_state = STATE_D;
		break;
		
		case STATE_D:
		curr_state = STATE_A;
		break;
		
		default:
		break;
	}
	
}

// implementacao das funcoes da fsm
void f_stateA(void){
	// implementar o que deve ser feito nesse estado
}

void f_stateB(void){
	// implementar o que deve ser feito nesse estado
}

void f_stateC(void){
	// implementar o que deve ser feito nesse estado
}

void f_stateD(void){
	// implementar o que deve ser feito nesse estado
}