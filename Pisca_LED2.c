#include <masp430g2553.h> // Outra solução para a Questão 1

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
    int i;
    char OUT[] = {CHP1 + CHP2,
                  CHP1 + CHP2,
                  CHP2 + CHP3,
                  CHP2 + CHP3,
                  CHP1 + CHP3,
                  CHP1 + CHP3};
                  
    char IN[] = {CHP1, CHP2,
                 CHP2, CHP3,
                 CHP1, CHP3}
                 
    WDTCTL = WDTPW | WDTHOLD;
    
    while(1)
    {
        for(i = 0; i < 6; i++)
        {
            Charlie_On(OUT[i], IN[i]);
        }
    }
    return 0;
}
