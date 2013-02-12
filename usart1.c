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

void _fct_loadchar_USART1(char Character)
{
  while(!((US1_CSR & US_ENDTX)>>4))
  {
  }
  US1_THR = (int) Character;
}

void _fct_loadvaleur_USART1(int Valeur)
{
  while(!((US1_CSR & US_ENDTX)>>4))
  {
  }
  US1_THR = Valeur;
}

void fct_initscreen_USART1(void)
{
  _fct_loadvaleur_USART1(0xA0);
}

void fct_clearscreen_USART1(void)
{
  _fct_loadvaleur_USART1(0xA3);
  _fct_loadvaleur_USART1(0x01);
}

void fct_writeline_USART1(char* Chaine, int Ligne)
{
  int indice=0;
  
  _fct_loadvaleur_USART1(0xA1);
  _fct_loadvaleur_USART1(0x00);
  _fct_loadvaleur_USART1(Ligne);
  
  _fct_loadvaleur_USART1(0xA2);
  
  while(indice!=strlen(Chaine))
  {
    fct_loadchar_USART1(Chaine[indice]);
    indice++;
  }
  
  _fct_loadvaleur_USART1(0x00);
}

void fct_write_USART1(char Character, int Ligne, int Colonne)
{
  _fct_loadvaleur_USART1(0xA1);
  _fct_loadvaleur_USART1(Colonne);
  _fct_loadvaleur_USART1(Ligne);

  _fct_loadvaleur_USART1(0xA2);
  _fct_loadchar_USART1(Character);
  _fct_loadvaleur_USART1(0x00);
}
