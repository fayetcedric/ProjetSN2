#include "datation.h"


//Initialisation et démarrage du RTC

void fct_init_RTC(void)
{
  int value_DH;  //Variable locale pour les dizaines d'heures
  int value_UH;	//Variable locale pour les unités d'heures
  int value_DM;	//Variable locale pour les dizaines de minutes
  int value_UM;	//Variable locale pour les unités de minutes
  int value_DS;	//Variable locale pour les dizaines de secondes
  int value_US;	//Variable locale pour les unités de secondes

  RTC_MR = (1<<0);
  RTC_HMR = (0<<0);
  RTC_TIMR = (0<<22)|(value_DH<<20)|(value_UH<<16)|(value_DM<<12)|(value_UM<<8)|(value_DS<<4)|(value_US<<0);
}


void fct_start_RTC(void)
{
  RTC_MR = (0<<0);
}

void fct_read_RTC(void)
{
  value_Heures=(RTC_TIMR)*10 + RTC_TIMR
  value_Minutes=
  value_Secondes=
}
