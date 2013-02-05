#include <91M55800.H>

//Initialisation et démarrage du RTC

void init_RTC(void)
{
  RTC_MR = 11;
  RTC_HMR = 0;
  RTC_TIMR = 


}


void start_RTC(void)
{
  RTC_MR = 10;
}
