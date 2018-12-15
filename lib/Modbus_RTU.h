/*
 * Modbus_RTU.h
 *
 * Created: 12/7/2018 12:25:05 AM
 *  Author: jack
 */ 


#ifndef MODBUS_RTU_H_
#define MODBUS_RTU_H_

#include "def_principais.h"
#include "avr_usart.h"

#define addr 0x15

//typedef struct pacote_RTU pacote_RTU_t;

void envia_pacote(uint8_t *pkg);

uint16_t CRC16_2(uint8_t *buf, int len);

#endif /* MODBUS_RTU_H_ */