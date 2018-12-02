/*
 * MCC1-IoT-PROJECT.c
 *
 * Created: 12/1/2018 11:25:28 PM
 * Author : jack
 */

#include "../lib/def_principais.h"
#include "../lib/usart.h"

int main(void)
{	
	usart_init(MYUBRR,1,1);
   
    while (1) 
    {	
		// test usart
		usart_send_char(' ');
		usart_send_string("testando a usart!");
		usart_send_char(' ');
		
    }
}

