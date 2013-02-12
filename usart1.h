/*
usart1.h
Crée par Matthieu Biache et Quentin Viotto le 11 février 2013
Derniere modification: Biache Matthieu 11 février 2013
Fichier de descritpion usart1
*/

#ifndef __USART1_H
#define __USART1_H

#include <91M55800.h>
#include <string.h>

#include "global.h"
#include "constante.h"

void fct_init_USART1(void); //Fonction d'initialisation de l'USART1
void fct_loadchar_USART1(char Character); //Fonction de démarrage de l'USART1
void fct_initscreen_USART1(void);
void fct_clearscreen_USART1(void);
void fct_writeline1_USART1(char* Chaine);
void fct_writeline2_USART1(char* Chaine);

#endif
