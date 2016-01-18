
#include <avr/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

unsigned char hh = 0;
unsigned char mm = 0;
unsigned char ss = 0;

unsigned char encode(unsigned char digit);

int main(void){	
	DDRB = 0b11111111;
	DDRC = 0b00111111;
	PORTC = 0b11111111;
	while(1){
		
		PORTB = encode(hh/10);
		PORTC = ~0x01;
		_delay_ms(100);
		PORTB = encode(hh%10); 
		PORTC = ~0x02;
		_delay_ms(100);
		PORTB = encode(mm/10);
		PORTC = ~0x04;
		_delay_ms(100);
		PORTB = encode(mm%10); 
		PORTC = ~0x08;
		_delay_ms(100);
		PORTB = encode(ss/10); 
		PORTC = ~0x10;
		_delay_ms(100);
		PORTB = encode(ss%10);
		PORTC = ~0x20;
		_delay_ms(100);
		
		ss++,mm++,hh++;
		if(hh > 12){
			hh = 0;
		}
		
	}
return 0;
}

unsigned char encode(unsigned char digit){
	unsigned char SegVal;
	switch(digit){
		case 0: SegVal = 0b00111111;
				break;
		case 1: SegVal = 0b00000110;
				break;
		case 2: SegVal = 0b01011011;
				break;
		case 3:	SegVal = 0b01001111;
				break;
		case 4: SegVal = 0b01100110;
				break;
		case 5: SegVal = 0b01101101;
				break;
		case 6: SegVal = 0b01111101;
				break;
		case 7: SegVal = 0b00000111;
				break;
		case 8: SegVal = 0b01111111;
				break;
		case 9: SegVal = 0b01101111;	
	}
	return SegVal;
}
