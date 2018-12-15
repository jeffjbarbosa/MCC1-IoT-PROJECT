/*
 * Modbus_RTU.c
 *
 * Created: 12/7/2018 12:25:46 AM
 *  Author: jack
 */ 

#include "../lib/Modbus_RTU.h"

/*struct pacote_RTU {
	uint8_t addr;		//1 byte	endereco do dispositivo
	uint8_t cmd;		//1 byte	comando [1] -> escrita, [0] -> leitura
	uint8_t reg_high;		//2 bytes big endian	registrador fonte ou destino
	uint8_t reg_low;
	uint8_t data_high;
	uint8_t data_low;
	uint8_t crc_high;
	uint8_t crc_low;
};
*/
void envia_pacote(uint8_t *pkg){
	int i;
	
	for (i=0; i < 8; i++)
		USART_tx(pkg[i]);

	//for (i=0; i < 8;i++)
	//	rx_pkg[i] = USART_rx();
}

uint16_t CRC16_2(uint8_t *buf, int len)
{
	uint32_t crc = 0xFFFF;
	int i;

	for (i = 0; i < len; i++)
	{
		crc ^= (uint16_t)buf[i];          // XOR byte into least sig. byte of crc

		for (int i = 8; i != 0; i--) {    // Loop over each bit
			if ((crc & 0x0001) != 0) {      // If the LSB is set
				crc >>= 1;                    // Shift right and XOR 0xA001
				crc ^= 0xA001;
			}
			else                            // Else LSB is not set
			crc >>= 1;                    // Just shift right
		}
	}
	// Note, this number has low and high bytes swapped, so use it accordingly (or swap bytes)
	return crc;
}

ISR(USART_RX_vect)
{
	
}