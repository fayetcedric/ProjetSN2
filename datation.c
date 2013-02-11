#include "datation.h"

//Initialisation et démarrage du RTC

void fct_init_RTC(void)
{
  int value_Heures_Dizaines=value_Heures/10;
  int value_Heures_Unites=value_Heures%10;
  int value_Minutes_Dizaines=value_Minutes/10;
  int value_Minutes_Unites=value_Minutes%10;
  int value_Secondes_Dizaines=value_Secondes/10;
  int value_Secondes_Unites=value_Secondes%10;

  RTC_MR = (1<<0);
  RTC_HMR = (0<<0);
  RTC_TIMR = (0<<22)
            |(value_Heures_Dizaines<<20)
            |(value_Heures_Unites<<16)
            |(value_Minutes_Dizaines<<12)
            |(value_Minutes_Unites<<8)
            |(value_Secondes_Dizaines<<4)
            |(value_Secondes_Unites<<0);
}

void fct_start_RTC(void)
{
  RTC_MR = (0<<0);
}

void fct_read_RTC(void)
{
  int value_Heures_Dizaines=(RTC_TIMR & 3<<20);
  int value_Heures_Unites=(RTC_TIMR & 15<<16);
  int value_Minutes_Dizaines=(RTC_TIMR & 7<<12);
  int value_Minutes_Unites=(RTC_TIMR & 15<<8);
  int value_Secondes_Dizaines=(RTC_TIMR & 7<<4);
  int value_Secondes_Unites=(RTC_TIMR & 15<<0);
  
  value_Heures=value_Heures_Dizaines*10 + value_Heures_Unites;
  value_Minutes=value_Minutes_Dizaines*10 + value_Minutes_Unites;
  value_Secondes=value_Secondes_Dizaines*10 + value_Secondes_Unites;
}
