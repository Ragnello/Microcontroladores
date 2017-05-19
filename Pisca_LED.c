#include <msp430g2553.h> //Questão 1 Charlie-plex

// Código que acenderá todos os leds

#define CHP1 BIT0
#define CHP2 BIT1
#define CHP3 BIT2
#define CHP_S (CHP1 + CHP2 + CHP3) //Todos os CHP's juntos
#define CHP_CLR P1OUT &= ~(CHP_S)// Zerar o POUT antes de trocar as saídas

void Charlie_On(char CHP_OUT, CHP_ON)
{
    P1OUT &= ~CHP_S;
    P1DIR = &= ~CHP_S;
    P1DIR |= CHP_OUT;
    P1OUT = CHP_ON;
}

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;
    
    while(1)
    {
        Charlie_On(CHP2, CHP1); //Liga D1
        Charlie_On(CHP1, CHP2); //Liga D2
        Charlie_On(CHP2, CHP3); //Liga D3
        Charlie_On(CHP3, CHP2); //Liga D4
        Charlie_On(CHP1, CHP3); //Liga D5
        Charlie_On(CHP3, CHP1); //Liga D6
    }
    return 0;
}
