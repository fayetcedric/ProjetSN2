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
    
    TC0_CMR=TIME_PERIOD_TIMERDUMAIN|
            TC_WAVE|
            TC_CPCTRG;
            
    TC0_IER=TC_CPCS;
}

void fct_init_AIC()
{
  AIC_SMR6=AIC_PRIOR|
           AIC_SRCTYPE_INT_EDGE_TRIGGER;
           
  AIC_SVR6=(int)fct_irq_IncremCptTimer0;
  AIC_IECR=(1<<TC0_ID);
}

void fct_start_TimerDuMain()
{
  TC0_CCR=TC_CLKEN|
          TC_SWTRG;
}

void fct_irq_IncremCptTimer0()
{
  if(cpt_TIMER0 == 0xFFFF)cpt_TIMER0=0;
  cpt_TIMER0++;
}
