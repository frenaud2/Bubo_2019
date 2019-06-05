#include <vector>
#include <algorithm>
#include <iostream>

#include "GPS.h"
#include "Horodatage.h"

using namespace std;



int Horodatage::dater()
{
	int erreur;
	string leChamps[200];
	/* Extraction de la trame RMC */
	thread laRecherche = leGPS->activerRechercheRMC();
	laRecherche.join();
	leGPS->getChampsRMC(leChamps);
	extraireDateRMC(leChamps);
	extraireHeureRMC(leChamps);
}
int Horodatage::extraireDateRMC(string leChamps[200])
{
	char laDate[15]={'0'};
	int dateI;
	string leResultat;

	stringstream dateSS(leChamps[9]);
	dateSS>>dateI;

	if (dateSS.fail ()) 	return -1;
	strcpy(laDate, dateSS.str().c_str());
	for(int y = 0; y<=5; y++)
		{
			date[y] = laDate[y];
			
		}
	return 1;
}
int Horodatage::extraireHeureRMC(string leChamps[200])
{
	char leHeure[15]={'0'};
	int heureI;

	stringstream heureSS(leChamps[1]);
	heureSS>>heureI;

	if (heureSS.fail ()) 	return -1;
	strcpy(leHeure, heureSS.str().c_str());
	for(int y = 0; y<=5; y++)
		{
			heure[y] = leHeure[y];
			
		}
	return 1;
}

void Horodatage::setDate(char laDate[6]){
	for (int i=0;i<6;i++)
	{
		date[i]=laDate[i];
	}
}


Horodatage::Horodatage(GPS *unGPS)
{
	Horodatage::leGPS = unGPS;
}

Horodatage::Horodatage()
{
	
}

void Horodatage::getDate(char aDate[6])
{
	for (int i=0;i<6;i++)
	{
		aDate[i]=date[i];
	}
}

void Horodatage::setHeure(char aHeure[6]){
	for (int i=0;i<6;i++)
	{
		heure[i]=aHeure[i];
	}
}

void Horodatage::getHeure(char aHeure[6]){
	for (int i=0;i<6;i++)
	{
		aHeure[i]=heure[i];
	}
}

void Horodatage::setVCond(bool vCond){
	leGPS->setVCond(vCond);
}
