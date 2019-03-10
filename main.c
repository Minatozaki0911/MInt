#include <msp430.h> 

#define P2Button (BIT1+BIT2+BIT3+BIT4)

void init(void);

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer //xoa la bay mau nha <3
	init();
	return 0;
}

void init(void)
{
    BCSCTL1=CALBC1_1MHZ;
    DCOCTL=CALDCO_1MHZ;

    P1OUT=0x00;
    P1DIR=0xF7;
    P1REN=0x08;
    P1SEL=0x00;
    P1SEL2=0x00;
    P1IE|=BIT3;

    P2OUT=0x00;
    P2DIR=0x00;
    P2REN=P2Button;
    P2SEL=0x00;
    P2SEL2=0x00;
    P2IE=P2Button;
}

#pragma vector=PORT1_VECTOR
__interrupt void P1_ISR()
{
    /* nhap code cua m */
    P1IFG=0x00;
}

#pragma vector=PORT2_VECTOR
__interrupt void P2_ISR()
{
    /* nhap code cua m */
    P2IFG=0x00;
}
