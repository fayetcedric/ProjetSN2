#include <91M55800.h>

#include "constante.h"
#include "global.h"

#include "lib_main.h"
#include "datation.h"
#include "USARTID.h"

 // GESTION APMC
 
void main(void)
{
	/* Initialisation */
	
	fct_init_VariablesGlobales();
	fct_init_TimerDuMain();
	fct_init_WatchDog()
	fct_init_AIC();
	fct_init_USART();
	
	fct_start_TimerDuMain();
	fct_start_WatchDog();
	
	
	/* Boucle de travail */
	while(1)
	{		
		if(!(cpt_TIMER0%TIMER0_PERIODE_CALCTEMP))
		{
			
		}
		
		if(!(cpt_TIMER0%TIMER0_PERIODE_CALCVENT))
		{
			
		}
		
		fct_restart_WatchDog();
	}
}
