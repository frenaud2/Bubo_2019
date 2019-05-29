#include "Geolocalisation.h"

using namespace std;


Geolocalisation::Geolocalisation(GPS *unGPS)
{
        this->leGPS = unGPS;
}

Geolocalisation::Geolocalisation()
{

}

/*int Geolocalisation::localiser()
{
leGPS->lirePosition();
leGPS->getChampsGGA(leChamps);	
	

}*/

float Geolocalisation::calculLongitude()
{
	char longdegres[2];
	char longminute[8];
	float longdegre;
	float longmin;
	float resultatLongitude;
	//char  lat[15];
	//char  N[2];
	char longi[15];
	char E[2];
	//char fix[2];
	//char satel[3];
	//char alti[5];
	
	string leChamps[200];
	
	leGPS->lirePosition();
	
	leGPS->getChampsGGA(leChamps);
		
	for (int i=0; i<=10;i++)
	{
	cout << leChamps[i] << endl;
	}
	//strcpy(lat, leChamps[2].c_str());
		
	//strcpy(N, leChamps[3].c_str());
	
	strcpy(longi, leChamps[4].c_str());
			
	strcpy(E, leChamps[5].c_str());
			
	//strcpy(fix, leChamps[6].c_str());
			
	//strcpy(satel, leChamps[7].c_str());
			
	//strcpy(alti, leChamps[9].c_str());
	
	for(int y = 0; y<=2; y++)
		{
			longdegres[y] = longi[y];
		}
			
		for(int y = 3; y<=9; y++)
		{
			//on utilise -3 car il faut qu'on aille au debut du tableau
			longminute[y-3] = longi[y];

		}
		
		//transformation de longdegre en float
		longdegre =atof(longdegres);
		//transformation de longminute en float
		longmin =atof(longminute);
		
		//calcul de la latitude
		longmin =longmin/60;
		resultatLongitude = longdegre+longmin;
		cout << resultatLongitude << endl;
		return resultatLongitude;
		
}

float Geolocalisation::calculLatitude()
{
	char latdegres[2];
	char latminute[8];	
	float latdegre;
	float latmin;
	float resultatLatitude;
	char lat[15];
	char N[2];
	
	string leChamps[200];

	leGPS->lirePosition();
	leGPS->getChampsGGA(leChamps);

	strcpy(lat, leChamps[2].c_str());
		
	strcpy(N, leChamps[3].c_str());




	
		
		
		//calcul latitude
		
			for(int y = 0; y<=1; y++)
		{
			//on met les degres dans le tableau latdegres
			latdegres[y] = lat[y];
		}

			//on met les minutes dans le tableau latminute
		for(int y = 2; y<=8; y++)
		{
			latminute[y-2] = lat[y];

		}
	
		
		
		//transformation de latdegre en float
		latdegre =atof(latdegres);
		//transformation de latminute en float
		latmin =atof(latminute);
		//calcul de la latitude
		latmin =latmin/60;
		resultatLatitude = latdegre+latmin;	
		cout << resultatLatitude <<endl;
		return resultatLatitude;
	
	
	
	
	
	
}




