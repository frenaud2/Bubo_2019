#include "Geolocalisation2.h"

using namespace std;


Geolocalisation::Geolocalisation(GPS *unGPS)
{
        this->leGPS = unGPS;
}

Geolocalisation::Geolocalisation()
{

}
	


void Geolocalisation::calculLongitude(string leChamps[200])
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
	
	
	
		
	for (int i=0; i<=10;i++)
	{
	//cout << leChamps[i] << endl;
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
		if(calculEst(leChamps) == 'E')
		{
	}else{
		resultatLongitude = resultatLongitude *-1;
	}
		sprintf(longitude, "%f",resultatLongitude );
		
		
}

void Geolocalisation::calculLatitude(string leChamps[200])
{
	
	char latdegres[2];
	char latminute[8];	
	float latdegreF;
	string latdegreS;
	float latmin;
	float resultatLatitude;
	char lat[15];
	char N[2];
	
	

	

	strcpy(lat, leChamps[2].c_str());
		
	strcpy(N, leChamps[3].c_str());



	
		
		
		//calcul latitude
		
			for(int y = 0; y<=1; y++)
		{
			//on met les degres dans le tableau latdegres
			latdegres[y] = lat[y];
			
		}
	
		//latdegres[2]='\0';
		latdegreS = string(latdegres,2);
		
			
			//on met les minutes dans le tableau latminute
		for(int y = 2; y<=8; y++)
		{
			latminute[y-2] = lat[y];
			//cout << latminute[y-2];

		}
	
		
		
		//transformation de latdegre en float
		//latdegre =atof(latdegres);
		
		//utilisation de flux 
		istringstream degre(latdegreS);
		
		degre>>latdegreF;
		//cout << latdegreF;
		//transformation de latminute en float
		latmin =atof(latminute);
		//cout << latmin <<endl;
		//calcul de la latitude
		latmin =latmin/60;
		resultatLatitude = latdegreF+latmin;	
		if(calculNord(leChamps) == 'N')
		{
	}else{
		resultatLatitude = resultatLatitude *-1;
	}
		sprintf(latitude, "%f",resultatLatitude );
		
		
}

void Geolocalisation::calculAltitude(string leChamps[200])
{
	char alti[4];
	int intalti;
	strcpy(alti, leChamps[9].c_str());
	intalti = atoi(alti);
	sprintf(altitude, "%d", intalti);

	
}

void Geolocalisation::calculSatellite(string leChamps[200])
{
	char nbreSatellite[3];
	int intSatellite;
	strcpy(nbreSatellite, leChamps[7].c_str());
	intSatellite = atoi(nbreSatellite);
	sprintf(satellite, "%d", intSatellite);

	
}

char Geolocalisation::calculNord(string leChamps[200])
{
	char positionNord[2];
strcpy(positionNord, leChamps[3].c_str());

nord = positionNord[0];
return nord;


}

char Geolocalisation::calculEst(string leChamps[200])
{
	char positionEst[2];
strcpy(positionEst, leChamps[5].c_str());

est = positionEst[0];
return est;


}

char Geolocalisation::calculFixe(string leChamps[200])
{
	char resultatfixe[2];
strcpy(resultatfixe, leChamps[6].c_str());
fixe = resultatfixe[0];

}

char Geolocalisation::calculHDOP(string leChamps[200])
{
	char resultatHDOP[5];
strcpy(resultatHDOP, leChamps[8].c_str());
for(int i=0;i<=5;i++){
HDOP[i] = resultatHDOP[i];

}	
	
}
	
int Geolocalisation::localiser()
{
string leChamps[200];
leGPS->lirePosition();
leGPS->getChampsGGA(leChamps);	
calculLatitude(leChamps);
calculLongitude(leChamps);
calculAltitude(leChamps);
calculSatellite(leChamps);
calculFixe(leChamps);
calculHDOP(leChamps);

}
	
void Geolocalisation::getLatitude(char alatitude[15]){
	for(int i=0 ; i<=15; i++)
	{
		alatitude[i] = latitude[i];
		
	}
}

void Geolocalisation::getLongitude(char alongitude[15]){
	for(int i=0 ; i<=15; i++)
	{
		alongitude[i] = longitude[i];
		
	}
}

void Geolocalisation::getAltitude(char aaltitude[15]){
	for(int i=0 ; i<=4; i++)
	{
		aaltitude[i] = altitude[i];
		
	}
}
void Geolocalisation::getSatellite(char asatellite[3]){
	for(int i=0; i<=2;i++)
	{
		asatellite[i] = satellite[i];
		
		
	}
}
void Geolocalisation::getHDOP(char aHDOP[5]){
	for(int i=0 ; i<=4; i++)
	{
	
	aHDOP[i] = HDOP[i];
	
	}
}
void Geolocalisation::getFixe(char afixe){
	 afixe = fixe;
	
}
	





