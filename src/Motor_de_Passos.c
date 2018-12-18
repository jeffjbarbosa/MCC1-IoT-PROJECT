/*
 * Motor_de_Passos.c
 *
 * Created: 12/16/2018 2:35:52 PM
 *  Author: jack
 */ 

#include "../lib/Motor_de_Passos.h"

uint8_t passos[] = {PASSO_1,PASSO_2,PASSO_3,PASSO_4};

void motor_init(){
	// pinos PB0:3 como saida
	DDRB = 0x0f;
}

// rotaciona motor 90 graus anti-horario (sentido==0) ou horario (sentido==1)
void rotacao_180_graus(uint8_t sentido){
	int i;
	uint8_t j=0;
	if (sentido == HORARIO)
	{
		for (i=0;i<1024;i++){
			PORTB = (PORTB & 0xf0) | (0x0f & passos[j]);
			j++;
			if(j>=4) j=0;
			_delay_ms(10);
		}
	}
	else
	{
		j=1;
		for (i=0;i<1024;i++){
			j--;
			PORTB = (PORTB & 0xf0) | (0x0f & passos[j]);
			if(j==0) j=4;
			_delay_ms(10);
		}
	}
}

// rotaciona motor 45 graus anti-horario (sentido==0) ou horario (sentido==1)
void rotacao_90_graus(uint8_t sentido){
	int i;
	uint8_t j=0;
	if (sentido == HORARIO)
	{
		for (i=0;i<512;i++){
			PORTB = (PORTB & 0xf0) | (0x0f & passos[j]);
			j++;
			if(j>=4) j=0;
			_delay_ms(10);
		}
	}
	else
	{
		j=1;
		for (i=0;i<512;i++){
			j--;
			PORTB = (PORTB & 0xf0) | (0x0f & passos[j]);
			if(j==0) j=4;
			_delay_ms(10);
		}
	}
}