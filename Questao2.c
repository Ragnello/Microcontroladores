#include <msp430g2553.h>

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
    unsigned int i;
    WDTCTL = WDTPW | WDTHOLD;
    
    while(1){
        for(i = 0; i < 0xFFFF; i++)
        {
            Charlie_On(CHP1 + CHP2, CHP1);
            Charlie_On(CHP1 + CHP2, CHP2);
        }
        for(i = 0; i < 0xFFFF; i++)
        {
            Charlie_On(CHP2 + CHP3, CHP2);
            Charlie_On(CHP1 + CHP2, CHP3);
        }
        for(i = 0; i < 0xFFFF; i++)
        {
            Charlie_On(CHP1 + CHP3, CHP1);
            Charlie_On(CHP1 + CHP3, CHP3);
        }
    }
    
    return 0;
}
