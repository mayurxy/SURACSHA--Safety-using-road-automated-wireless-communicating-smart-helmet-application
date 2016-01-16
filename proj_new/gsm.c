
#include <avr/io.h>
#include <inttypes.h>
#include <avr/interrupt.h>

//#ifndef F_CPU
	#define F_CPU 16000000UL
//#endif

#include <util/delay.h>

#include "lcd.h"
#include "UART_128.h"
#include "gsm.h"


unsigned char checkok()
{
	
	LCD(0,0,"inok");
	unsigned char reply[2]={'0','0'};
	while(USART_REC_1()!='O');
	LCD(0,0,"loopkhatam");
	reply[0]='O';
	LCD(0,0,"orecived");
	reply[1]=USART_REC_1();
	LCD(0,0,"subok");
	LCDGotoXY(0,1);
	LCDData(reply[0]);
	LCDData(reply[1]);
	
	if (reply[0]=='O'&&reply[1]=='K')
	{
		return 1; 
	}
	else
	{
		return 0;	
	}
	
}

unsigned char sms(unsigned char *num,unsigned char *msg)
{
	/*unsigned char cmd[]={'P','K','+','C','M','G','F','=','1'};
	int k=0;
	for(k=0;k<9;k++)
	{
		USART_TRANS_1(cmd[k]);		
	}*/
	/*USART_TRANS_1(13);
	if (checkok()==1)
	{
	USART_TRANS_STRING_1("AT+CMGS=");
	USART_TRANS_1('"');
			
	while(*num)
	USART_TRANS_1(*num++);
	
	USART_TRANS_1('"');
	USART_TRANS_1(13);
	while(USART_REC_1()!='>');
	
			while(*msg)
			USART_TRANS_1(*msg++);
			USART_TRANS_1(26);
	}	
	else
	{
		
		return 0;
	
	}*/
}


/*
unsigned char call(unsigned char *number)
{
	stringuart1("ATD");
	
			
	while(*number)
	uart_1_Transmit(*number++);
	uart_1_Transmit(';');
	uart_1_Transmit(13);
	LCD(0,0,"Dialling");
	_delay_ms(10);
	if (checkok()==1)
	{
		return 1;
	}
	else
	return 0;
}

*/