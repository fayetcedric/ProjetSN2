/*
lib_main.h
Crée par Cédric Fayet le 11 février 2013
Derniere modification:
*/

#include "constante.h"
#include "global.h"

#ifndef __LIB_MAIN_H
#define LIB_MAIN_H

void  fct_init_VariablesGlobales(); // Fonctions initialisant les variables globales

void fct_init_AIC();

void fct_init_TimerDuMain();
void fct_start_TimerDuMain();
void fct_irq_IncremCptTimer0();

#endif
