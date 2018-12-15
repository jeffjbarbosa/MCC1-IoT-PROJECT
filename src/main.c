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

int main(void)
{	
	USART_Init(B9600);
    uint8_t pacote[8] = {0x15, 0x01, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00};

    while (1) 
    {	
		// test usart
		envia_pacote(pacote);
		_delay_ms(1000);
		
    }
}