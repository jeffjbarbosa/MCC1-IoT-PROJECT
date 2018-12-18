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

#define MAX_E 23200
#define WAIT 60000

// ---------------------------------- Variáveis------------------------------------
uint8_t rx_pkg[8],i;
uint8_t pacote[8] = {0x15, 0x01, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00};
volatile uint16_t counter, data, crc;
// --------------------------------------------------------------------------------

void f_stateA(void);
void f_stateB(void);
void f_stateC(void);
void f_stateD(void);

/* Defini��o dos estados */
typedef enum {
	STATE_A,
	STATE_B,
	STATE_C,
	STATE_D,
	NUM_STATES
} state_t;

/* Defini��o da estrutura mantenedora do vetor de estados */
typedef struct {
	state_t myState;
	void (*func)(void);
}fsm_t;

/* Mapeamento entre estado e fun��es */
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
	USART_Init(B9600);
	HCSR04_hardware_init();
	motor_init();

	sei();

    while (1) 
    {	
		// chamada da funcao referente ao estado atual da FSM
		(*myFSM[curr_state].func)();
    }
}

ISR(TIMER0_COMPA_vect){
	switch (curr_state)
	{
		case STATE_A:
		break;
		
		case STATE_B:
		if(counter > MAX_E){
			data = MAX_E;
		}
		curr_state = STATE_C;
		break;
		
		case STATE_C:
		break;
		
		case STATE_D:
		break;
		
		default:
		break;
	}
	counter++;	
}

ISR(INT0_vect){
	// switch case para mudar o estado atual da FSM
	switch (curr_state)
	{
		case STATE_A:
		break;
		
		case STATE_B:
		data = counter;
		curr_state = STATE_C;
		break;
		
		case STATE_C:
		break;
		
		case STATE_D:
		break;
		
		default:
		break;
	}
}

ISR(USART_RX_vect)
{	
	for (i=0; i < 8;i++)
		rx_pkg[i] = USART_rx();
	
	// switch case para mudar o estado atual da FSM
	switch (curr_state)
	{
		case STATE_A:
		if((rx_pkg[1] == 0x01) && (rx_pkg[2] == 0) && (rx_pkg[3] == 1)){
			crc = (8 << rx_pkg[6]);
			crc = rx_pkg[7];
			if(CRC16_2(rx_pkg, 6) == crc){
				envia_pacote(rx_pkg);
				rotacao_180_graus(ANTI_HORARIO);
			}
		}
		break;

		case STATE_B:
		if((rx_pkg[1] == 0x01) && (rx_pkg[2] == 0) && (rx_pkg[3] == 1)){
			crc = (8 << rx_pkg[6]);
			crc = rx_pkg[7];
			if(CRC16_2(rx_pkg, 6) == crc){
				envia_pacote(rx_pkg);
				rotacao_180_graus(ANTI_HORARIO);
			}
		}
		break;
		
		case STATE_C:
		if((rx_pkg[1] == 0x01) && (rx_pkg[2] == 0) && (rx_pkg[3] == 1)){
			crc = (8 << rx_pkg[6]);
			crc = rx_pkg[7];
			if(CRC16_2(rx_pkg, 6) == crc){
				envia_pacote(rx_pkg);
				rotacao_180_graus(ANTI_HORARIO);
			}
		}
		crc = CRC16_2(pacote, 6);
		break;
		
		case STATE_D:
		if((pacote[6] == rx_pkg[6]) && (pacote[7] == rx_pkg[7])){
			wait_trigger(counter);
			curr_state = STATE_A;
		}else if((rx_pkg[1] == 0x01) && (rx_pkg[2] == 0) && (rx_pkg[3] == 1)){
			crc = (8 << rx_pkg[6]);
			crc = rx_pkg[7];
			if(CRC16_2(rx_pkg, 6) == crc){
				envia_pacote(rx_pkg);
				rotacao_180_graus(ANTI_HORARIO);
			} 
		}else{
			envia_pacote(pacote);
		}
		break;
		
		default:
		break;
	}
	
}

// implementacao das funcoes da fsm
void f_stateA(void){
	counter = 0;
	set_trigger(counter);
	counter = 0;
	curr_state = STATE_B;
}

void f_stateB(void){
}

void f_stateC(void){
	pacote[4] = ((data/58) >> 8);
	pacote[5] = (data/58);
	crc = CRC16_2(pacote, 6);
	pacote[6] = (crc >> 8);
	pacote[7] = crc;
	envia_pacote(pacote);
	curr_state = STATE_D;
}

void f_stateD(void){
}