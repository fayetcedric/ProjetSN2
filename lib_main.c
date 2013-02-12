/*
lib_main.c
Crée par Cédric Fayet le 11 février 2013
Derniere modification: le 12 février 2013 par Cédric Fayet
*/

#include"lib_main.h"

void fct_irq_restart_all()
{
  AIC_IPR=(1<<1);
  AIC_EOICR=TC12_SR;
}

void fct_init_VariablesGlobales()
{
  flag_Telecommande_ReceptionCaractere = 0;

  //Initialement on affecte toutes les variables globales à zéro.
  value_Temperature=0;
  value_VitesseVent=0;
  value_Pluviometrie=0;
  
  value_Heures=0;
  value_Minutes=0;
  value_Secondes=0;
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

void fct_start_TimerDuMain()
{
  TC0_CCR=TC_CLKEN|
          TC_SWTRG;
}

void fct_irq_IncremCptTimer0()
{
  if(cpt_TIMER0 == 0xFFFF)cpt_TIMER0=0;
  cpt_TIMER0++;
  AIC_EOICR=TC6_SR;
}

void fct_init_AIC()
{
  // timer 0 :
  AIC_SMR6=AIC_PRIOR|
           AIC_SRCTYPE_INT_EDGE_TRIGGER;
           
  AIC_SVR6=(int)fct_irq_IncremCptTimer0;
  AIC_IECR=(1<<TC0_ID);
  
  //watchdog:
  AIC_SMR12=AIC_PRIOR|
            AIC_SRCTYPE_INT_EDGE_TRIGGER;
  AIC_SVR12=(int)fct_irq_restart_all();
  AIC_IECR=(1<<TC12_ID);
  
}

void fct_init_WatchDog()
{
  WD_OMR=WD_IRQEN|// genere une IT lorsque le watchdog est plein
         WD_RSTEN|// reinitialise le watchdog lorsque celui-ci est plein
         WD_OKEY;// permet de compter
          
  WD_CMR=CLK_WATCHDOG;// intialize the clk
  WD_CMR=(INIVALUE_WATCHDOG<<2);
}

void fct_restart_WatchDog()
{
  WD_CR=WD_RSTKEY;
}

void fct_start_WatchDog()
{
  WD_OMR=WD_WDEN;// enable watchdog
}
