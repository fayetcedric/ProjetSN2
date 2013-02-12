/*
datation.h
Crée par Matthieu Biache et Quentin Viotto le 11 février 2013
Derniere modification: Biache Matthieu 11 février 2013
Fichier de descritpion datation
*/

#ifndef __DATATION_H
#define __DATATION_H

#include <91M55800.h>

#include "global.h"

void fct_init_RTC(void); //Fonction d'initialisation du RTC
void fct_start_RTC(void); //Fonction de démarrage du RTC
void fct_read_RTC(void); //Fonction de lecture du RTC

#endif
