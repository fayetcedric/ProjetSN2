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
}

void fct_loadvaleur_USART1(int Valeur)
{
  while(!((US1_CSR & US_ENDTX)>>4))
  {
  }
  US1_THR = (int) Character;
}

void fct_initscreen_USART1(void)
{
  fct_loadchar_USART1(0xA0);
  flag_Fin_Fct_Usart = 1;
}

void fct_clearscreen_USART1(void)
{
  fct_loadchar_USART1(0xA3);
  fct_loadchar_USART1(0x01);
}

void fct_writeline1_USART1(char* Chaine)
{
  int indice=0;
  
  fct_loadchar_USART1(0xA1);
  fct_loadchar_USART1(0x00);
  fct_loadchar_USART1(0x01);
  
  fct_loadchar_USART1(0xA2);
  
  while(indice!=strlen(Chaine))
  {
    fct_loadchar_USART1(Chaine[indice]);
    indice++;
  }
}

void fct_writeline2_USART1(char* Chaine)
{
  int indice=0;
  
  fct_loadchar_USART1(0xA1);
  fct_loadchar_USART1(0x00);
  fct_loadchar_USART1(0x02);
  
  fct_loadchar_USART1(0xA2);
  
  while(indice!=strlen(Chaine))
  {
    fct_loadchar_USART1(Chaine[indice]);
    indice++;
  }
}
