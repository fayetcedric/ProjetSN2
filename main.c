#include "contante.h"
#include "global.h"

#include "lib_main.h"

/* Constantes globales : */
int flag_DemandeUtilisateur = 0;
int flag_DemandeTemperature = 0;
int flag_DemandeVitesseVent = 0;
int flag_DemandePluviometrie = 0;

int value_Temperature; // Température est comprise entre -55° et 150°
int value_VitesseVent;
int value_Pluviometrie;

int cpt_ChienDeGarde;

void main(void)
{
	/* Initialisation des fonctions du main : */
	
	initTIMER_Main();
	
	/* Boucle de travail : */
	while(1)
	{
		cpt_ChienDeGarde = 0;
		
		if(flag_Pluviometrie)
		{
				
		}
		
		if(flag_DemandeVitesseVent)
		{
				
		}
		
		if(flag_DemandeTemperature)
		{
				
		}
		
		if(flag_DemandeUtilisateur)
		{
				
		}
	}
}

// fAIRE 
