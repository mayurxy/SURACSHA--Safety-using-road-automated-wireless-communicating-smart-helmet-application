/*
 * UART_32.h
 *
 * Created: 3/2/2013 2:08:51 AM
 *  Author: Akshay
	OK,Working
 */ 

#include "avr/io.h"
#include "mydefs.h"
#include <avr/interrupt.h>
#include "lcd.h"

#ifndef UART_128_H_
#define UART_128_H_

//extern unsigned char locx[3];
//unsigned char locy[3];
//volatile unsigned int dist[4];
//extern int data_ptr=0;

void USART_INIT(unsigned int val);
unsigned char USART_REC();
unsigned char USART_REC_1();
void USART_TRANS(unsigned char data);
void USART_TRANS_1(unsigned char data);
void USART_TRANS_STRING_1(unsigned char *string);


#endif /* UART_128_H_ */