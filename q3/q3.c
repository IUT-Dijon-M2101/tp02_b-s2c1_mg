#include "iq.h"
#include "it.h"
#define byte unsigned char
/* variables globale */
byte *trisb = 0xf93 ;
byte *portb = 0xf81 ;
byte *trisd = 0xf95 ;
byte *portd = 0xf83 ;
int i=0;
int nb=0;
void affiche_7seg(byte);
/* interruption sur front montant RB0 */
void it_int0()
{
	if(i<9)i++;
	else i = 0;
}
/* interruption sur front montant RB1 */
void it_int1()
{
	if(i>0)i--;
	else i = 9;
}
void it_tmr0()
{
	if(i<9)i++;
	else i = 0;
	delayms(1000);
}
void affiche_7seg(byte val)
{
	byte
	tab_7seg[]={0b00111111,0b00000110,0b01011011,0b01001111,
	0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,
	0b01101111};
	*portd=tab_7seg[val];
}

void main(void)
{
	init_it_tmr0();
	*trisd = 0 ;
	*trisb = 0xff;
	init_it_int0();
	init_it_int1();
	while(1){
		affiche_7seg(i);
	}
}