/*
global.h
Crée par Cédric Fayet le 11 février 2013
Dernier modification : 
Fichier contenant les variables et fonctions globales 
*/

#ifndef __GLOBAL_H
#define GLOBAL_H

/* Fonctions globales : */

/* Constantes globales : */
extern int flag_DemandeUtilisateur;
extern int flag_DemandeTemperature;
extern int flag_DemandeVitesseVent;
extern int flag_DemandePluviometrie;

extern int value_Temperature; // Température est comprise entre -55° et 150°
extern int value_VitesseVent;
extern int value_Pluviometrie;

extern int value_Heures;
extern int value_Minutes;
extern int value_Secondes;

#endif
