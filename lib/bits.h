#ifndef BITS_H_
#define BITS_H_

#define	set_bit(y,bit)	(y|=(1<<bit))	//coloca em 1 o bit x da vari�vel Y
#define	clr_bit(y,bit)	(y&=~(1<<bit))	//coloca em 0 o bit x da vari�vel Y
#define cpl_bit(y,bit) 	(y^=(1<<bit))	//troca o estado l�gico do bit x da vari�vel Y
#define tst_bit(y,bit) 	(y&(1<<bit))	//retorna 0 ou 1 conforme leitura do bit

#endif /* BITS_H_ */
