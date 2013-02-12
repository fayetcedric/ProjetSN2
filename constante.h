/*
constante.h
Crée par Cédric Fayet le 11 février 2013
Derniere modification :
Fichier contenant les différentes constantes pré-processeur
*/

#ifndef __CONSTANTE_H
#define __CONSTANTE_H

#define MODE_DEBUG 1

#define CLK_TIMERDUMAIN TC_CLKS_32 //cadence
#define TIME_PERIOD_TIMERDUMAIN 5000 //période
#define TIMER0_PERIOD_CALCTEMP 10// nb de période où on calcul température
#define TIMER0_PERIOD_CALCVENT 12// nb de période où on calcul vent

#define CLK_WATCHDOG WD_WDCLKS_MCK4096 //horloge du watchdog
#define INIVALUE_WATCHDOG 15 //le nombre de tic est codé sur 2^15, il compte  2^11 valeurs + INITVALUE_WATCHDOG (sur 4bits) * 2^12

#endif
