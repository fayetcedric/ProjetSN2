/*
usart1.c
Crée par Matthieu Biache et Quentin Viotto le 11 février 2013
Derniere modification: 11 février 2013
*/

#include "usart1.h"

//Initialisation et démarrage de l'USART

void fct_init_USART1(void)
{
  US1_CR = US_RSTTX
          |US_RXDIS
          |US_TXEN;
  US1_MR = US_CHRL_8
          |US_PAR_NO
          |US_NBSTOP_1
          |US_CHMODE_NORMAL;
}

void fct_loadchar_USART1(char Character)
{
  US1_TPR = (int) Character;
  flag_LCD_CaractereLoad = !((US1_CSR & US_TXRDY)>>1);
}

