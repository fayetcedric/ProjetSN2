/*
lib_main.c
Crée par Cédric Fayet le 11 février 2013
Derniere modification:
*/

#include"lib_main.h"

void  fct_init_VariablesGlobales()
{
  extern int flag_DemandeUtilisateur = 0;

  //Initialement on affecte toutes les variables globales à zéro.
  extern int value_Temperature=0;
  extern int value_VitesseVent=0;
  extern int value_Pluviometrie=0;
  
  extern int value_Heures=0;
  extern int value_Minutes=0;
  extern int value_Secondes=0;
}

void fct_init_TimerDuMain()
{
    APMC_PCER=(1<<TC0_ID);
    TC0_RC=TIME_PERIOD_TIMERDUMAIN;
}

