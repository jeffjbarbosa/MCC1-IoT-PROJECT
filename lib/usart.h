#ifndef _USART_H_
#define _USART_H_

#ifndef F_CPU
#define F_CPU 16000000UL    //define a frequencia do microcontrolador - 16MHz
#endif /* ifndef F_CPU */

#include <avr/io.h>
#include "def_principais.h"
//#include "../lib/bit_utils.h"

#ifndef USART_BAUD
#define USART_BAUD 9600//57600//9600
#endif /* ifndef USART_BAUD */
#define MYUBRR F_CPU/16/USART_BAUD-1

#define   USART_HAS_DATA   bit_is_set(UCSR0A, RXC0)
#define   USART_READY      bit_is_set(UCSR0A, UDRE0)

void usart_send_char(unsigned char data);

char usart_receive_char(void);

void usart_send_string(const char *s);

void usart_send_uint16(uint16_t num);

void usart_send_buffer(uint8_t *b, uint8_t lenght);

void usart_init(uint16_t ubrr, uint8_t rx, uint8_t tx);

#endif
