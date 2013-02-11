/*
usart.h
Crée par Matthieu Biache et Quentin Viotto le 11 février 2013
Derniere modification: Biache Matthieu 11 février 2013
Fichier de descritpion usart
*/

#ifndef __USART_H
#define __USART_H

#include <91M55800.h>

#include "global.h"
#include "constante.h"

void fct_init_USART(void); //Fonction d'initialisation de l'USART
void fct_start_USART(void); //Fonction de démarrage de l'USART

#endif
