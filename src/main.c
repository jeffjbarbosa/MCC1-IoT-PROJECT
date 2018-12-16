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

int main(void)
{	
	//USART_Init(B9600);
    //uint8_t pacote[8] = {0x15, 0x01, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00};
		
	sei();

    while (1) 
    {	
		
    }
}

ISR(USART_RX_vect)
{	
	for (i=0; i < 8;i++)
		rx_pkg[i] = USART_rx();
}
