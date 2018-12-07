/*
 * Modbus_RTU.c
 *
 * Created: 12/7/2018 12:25:46 AM
 *  Author: jack
 */ 

#include "../lib/def_principais.h"
#include "../lib/Modbus_RTU.h"

struct pacote_RTU {
	unsigned char addr;		//1 byte	endereco do dispositivo
	unsigned char cmd;		//1 byte	comando [1] -> escrita, [0] -> leitura
	unsigned short reg;		//2 bytes big endian	registrador fonte ou destino
	unsigned short data;	//2 bytes big endian	dado da escrita ou numero de registradores a serem lidos
	unsigned short crc;		//2 bytes big endian
};

void envia_pacote(pacote_RTU_t *array_pacote, int tam_pacote){
	
}