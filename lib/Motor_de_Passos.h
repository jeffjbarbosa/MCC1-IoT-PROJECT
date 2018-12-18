/*
 * Motor_de_Passos.h
 *
 * Created: 12/16/2018 2:35:19 PM
 *  Author: jack
 */ 


#ifndef MOTOR_DE_PASSOS_H_
#define MOTOR_DE_PASSOS_H_

#include "def_principais.h"

#define ANTI_HORARIO 0
#define HORARIO		 1
#define PASSO_1		 0x03
#define PASSO_2		 0x06
#define PASSO_3		 0x0c
#define PASSO_4		 0x09

void motor_init();

void rotacao_180_graus(uint8_t sentido);

void rotacao_90_graus(uint8_t sentido);

#endif /* MOTOR_DE_PASSOS_H_ */