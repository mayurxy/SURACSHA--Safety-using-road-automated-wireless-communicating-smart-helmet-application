/*
 * lcd_test.c
 *
 * Created: 25-06-2013 22:18:05
 *  Author: Mayur
 */ 

#include <avr/io.h>
//#ifndef F_CPU
	#define F_CPU 16000000UL
//#endif
#include <avr/interrupt.h>
#include "lcd.h"
//#include "gyro.h"
#include "gsm.h"
//#include "GPS.h"
#include "UART_128.h"
#include <util/delay.h>

extern float X_angle,Y_angle, Z_angle;

void init_all()
{
	//TWI_init_master();
	_delay_ms(100);
	
	_delay_ms(1000);
	InitLCD(0);
	_delay_ms(50);
	LCDClear();
	_delay_ms(10);
	Init_LED();
	_delay_ms(50);
	sei();
}

int main(void)
{
	USART_INIT(1);
	sei();
	glow4();
	//init_all();
	off4();
	//USART_TRANS_STRING_1("akkkkk");
	//USART_TRANS_1('A');
	glow1();
	unsigned char cmd[]={'P','K','+','C','M','G','F','=','1'};
	int k=0;
	for(k=0;k<9;k++)
	{
		USART_TRANS_1(cmd[k]);		
	}
	//sms("9503139115","Accident");
	/*while(1)
	{
		int k=0;
		for(k=0;k<12;k++)
		{
			LCDGotoXY(k,0);
			LCDData(lati[k]);
			LCDGotoXY(k,1);
			LCDData(longi[k]);
		}		
	}
	while(1)
    {
		
        LCD(0,0,"VIT");
		_delay_ms(500);
		LCDClear();
		_delay_ms(10);
		LCD(0,0,"SURACSHA");
		_delay_ms(100);
		LCDClear();
		_delay_ms(100);
	
	
		while (1)
		{
//	  LCDvar(0,0 , X_angle  , 5);	
	//_delay_ms(30);
// 	  LCDvar(1,1,Y_angle,5);		  
// 		_delay_ms(30);
		  //LCDvar(1,0,Z_angle,5 );
		//_delay_ms(30);  
		 //LCD(0,0,Z_angle);
		
		if (Y_angle > 75 || Y_angle < -75)
		{_delay_ms(50);
			LCDClear();
			_delay_ms(70);
		LCD(0,0,"accident");
		glow1();
		glow4();
		_delay_ms(50);
		off1();
		off4();
		
		}		
		else
		{_delay_ms(70);
			LCDClear();
			_delay_ms(70);
		LCD(0,0,"normal");
		glow2();
		glow3();
		_delay_ms(50);
		off2();
		off3();

		}
				
		}		
	}*/
}