/*
usart1.c
Crée par Matthieu Biache et Quentin Viotto le 11 février 2013
Derniere modification: 12 février 2013
*/

#include "usart1.h"

//Initialisation et démarrage de l'USART

void fct_init_USART(int Id_Usart)
{
  if(Id_Usart)
  {
    US1_CR = US_RSTTX
          |US_RXDIS
          |US_TXEN;
    US1_MR = US_CHRL_8
          |US_PAR_NO
          |US_NBSTOP_1
          |US_CHMODE_NORMAL;
  }
  else
  {
    US0_CR = US_RSTTX
          |US_RXDIS
          |US_TXEN;
    US0_MR = US_CHRL_8
          |US_PAR_NO
          |US_NBSTOP_1
          |US_CHMODE_NORMAL;
  }
}

void _fct_loadchar_USART(int Id_Usart, char Character)
{
  if(Id_Usart)
  {
    while(!(US1_CSR & US_ENDTX));
    US1_THR = (int) Character;
  }
  else
  {
    while(!(US0_CSR & US_ENDTX));
    US0_THR = (int) Character;
  }
}

void _fct_loadvaleur_USART(int Id_Usart, int Valeur)
{
  if(Id_Usart)
  {
    while(!(US1_CSR & US_ENDTX));
    US1_THR = Valeur;
  }
  else
  {
    while(!(US1_CSR & US_ENDTX));
    US0_THR = Valeur;
  }
}

void fct_initscreen_USART(int Id_Usart)
{
	_fct_loadvaleur_USART(Id_Usart, 0xA0);
}

void fct_clearscreen_USART(int Id_Usart)
{
	_fct_loadvaleur_USART(Id_Usart, 0xA3);
	_fct_loadvaleur_USART(Id_Usart, 0x01);
}

void fct_writeline_USART(int Id_Usart, char* Chaine, int Ligne)
{
	int indice=0;

	_fct_loadvaleur_USART(Id_Usart, 0xA1);
	_fct_loadvaleur_USART(Id_Usart, 0x00);
	_fct_loadvaleur_USART(Id_Usart, Ligne);
  
	_fct_loadvaleur_USART(Id_Usart, 0xA2);
  
	while(indice!=strlen(Chaine))
	{
		fct_loadchar_USART(Id_Usart, Chaine[indice]);
		indice++;
	}
  
	_fct_loadvaleur_USART(Id_Usart, 0x00);
	}
}

void fct_write_USART(int Id_Usart, char Character, int Ligne, int Colonne)
{
	_fct_loadvaleur_USART(Id_Usart, 0xA1);
	_fct_loadvaleur_USART(Id_Usart, Colonne);
	_fct_loadvaleur_USART(Id_Usart, Ligne);

	_fct_loadvaleur_USART(Id_Usart, 0xA2);
	_fct_loadchar_USART(Id_Usart, Character);
	_fct_loadvaleur_USART(Id_Usart, 0x00);
}
