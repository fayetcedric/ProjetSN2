/*
usart1.c
Crée par Matthieu Biache et Quentin Viotto le 11 février 2013
Derniere modification: 12 février 2013
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
  while(!((US1_CSR & US_ENDTX)>>4))
  {
  }
  US1_THR = (int) Character;
  flag_LCD_CaractereLoad = !((US1_CSR & US_TXRDY)>>1);
}

void fct_initscreen_USART1(void)
{
  while(!((US1_CSR & US_ENDTX)>>4))
  {
  }
  US1_THR = 0xA0;
  flag_LCD_CaractereLoad = !((US1_CSR & US_TXRDY)>>1)
}

void fct_clearscreen_USART1(void)
{
  while(!((US1_CSR & US_ENDTX)>>4))
  {
  }
  US1_THR = 0xA3;
  flag_LCD_CaractereLoad = !((US1_CSR & US_TXRDY)>>1)
  while(!((US1_CSR & US_ENDTX)>>4))
  {
  }
  US1_THR = 0x01;
  flag_LCD_CaractereLoad = !((US1_CSR & US_TXRDY)>>1)
}

void fct_writeline1_USART1(char* Chaine)
{
  int indice=0;
  
  while(!((US1_CSR & US_ENDTX)>>4))
  {
  }
  US1_THR = 0xA1;
  flag_LCD_CaractereLoad = !((US1_CSR & US_TXRDY)>>1)
  while(!((US1_CSR & US_ENDTX)>>4))
  {
  }
  US1_THR = 0x00;
  flag_LCD_CaractereLoad = !((US1_CSR & US_TXRDY)>>1)
  while(!((US1_CSR & US_ENDTX)>>4))
  {
  }
  US1_THR = 0x01;
  flag_LCD_CaractereLoad = !((US1_CSR & US_TXRDY)>>1)
  while(!((US1_CSR & US_ENDTX)>>4))
  {
  }
  US1_THR = 0xA2;
  flag_LCD_CaractereLoad = !((US1_CSR & US_TXRDY)>>1)
  
  while(indice!=strlen(Chaine))
  {
    fct_loadchar_USART1(Chaine[indice]);
    indice++;
  }
}

void fct_writeline2_USART1(char* Chaine)
{
  int indice=0;
  
  while(!((US1_CSR & US_ENDTX)>>4))
  {
  }
  US1_THR = 0xA1;
  flag_LCD_CaractereLoad = !((US1_CSR & US_TXRDY)>>1)
  while(!((US1_CSR & US_ENDTX)>>4))
  {
  }
  US1_THR = 0x00;
  flag_LCD_CaractereLoad = !((US1_CSR & US_TXRDY)>>1)
  while(!((US1_CSR & US_ENDTX)>>4))
  {
  }
  US1_THR = 0x02;
  flag_LCD_CaractereLoad = !((US1_CSR & US_TXRDY)>>1)
  while(!((US1_CSR & US_ENDTX)>>4))
  {
  }
  US1_THR = 0xA2;
  flag_LCD_CaractereLoad = !((US1_CSR & US_TXRDY)>>1)
  
  while(indice!=strlen(Chaine))
  {
    fct_loadchar_USART1(Chaine[indice]);
    indice++;
  }
}
