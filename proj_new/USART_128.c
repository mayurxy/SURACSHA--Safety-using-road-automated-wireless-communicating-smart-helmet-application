/*
 * USART_128.c
 *
 * Created: 4/15/2014 7:58:18 AM
 *  Author: The King
 */ 
#include "avr/io.h"
#include "mydefs.h"
#include <avr/interrupt.h>
#include "lcd.h"
#include "UART_128.h"


void USART_INIT(unsigned int val)
{
	//clr(DDRE,0);
	//set(DDRE,1);
	//set(DDRF,1);
	//set(PORTF,1);
	//UCSR1B=(1<<RXEN1|(1<<RXCIE1));
	clr(DDRD,2);
	set(DDRD,3);
	//if(val==1)
	//{
		//UCSR0B|=(1<<RXCIE0);
		//UCSR1B|=(1<<RXCIE1);
		//UCSR1A&=~(1<<RXC1);
	//}
	//else if(val==2)
	//{
		//UCSR0B|=(1<<TXCIE0);
		//UCSR1B|=(1<<TXCIE1);		
	//}
	//UCSR0B|=((1<<RXEN0)|(1<<TXEN0));
	//UCSR0C|=(1<<UCSZ01)|(1<<UCSZ00);
	
	UCSR1B|=((1<<RXEN1)|(1<<TXEN1));
	UCSR1C|=(1<<UCSZ11)|(1<<UCSZ10);
	/*UBRRL=415;
	UBRRH=415>>8;*/
	//UBRR0L=0x67;
	//UBRR0H=0;
	
	UBRR1L=0x67;
	UBRR1H=0;
}

unsigned char USART_REC()
{
	while(!(UCSR0A&(1<<RXC0)));
	return UDR0;
}

unsigned char USART_REC_1()
{	
	int count=0;
	while(!(UCSR1A&(1<<RXC1)));
	return UDR1;
}

void USART_TRANS(unsigned char data)
{
	UDR0=data;
	while(!(UCSR0A&(1<<TXC0)));
}

void USART_TRANS_1(unsigned char data)
{
	UDR1=data;
	while(!(UCSR1A&(1<<TXC1)));
}

void USART_TRANS_STRING_1(unsigned char*string)
{
	while(*string)
	{
		USART_TRANS_1(*string);
		string++;
	}
}

