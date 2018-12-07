/*
 * Modbus_RTU.h
 *
 * Created: 12/7/2018 12:25:05 AM
 *  Author: jack
 */ 


#ifndef MODBUS_RTU_H_
#define MODBUS_RTU_H_

#include <avr/io.h>
#include "def_principais.h"

typedef struct pacote_RTU pacote_RTU_t;

#define NUM_BYTES 8

void envia_pacote(pacote_RTU_t *array_pacote, int tam_pacote);



#endif /* MODBUS_RTU_H_ */