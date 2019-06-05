#include "Geolocalisation.h"

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
	
	char longdegres[3];
	char longminute[8];
	float longdegre;
	float longmin;
	float resultatLongitudeF;
	string resultatLongitudeS;
	char longi[15];
	char E[2];
		
	//récupération des données du tableau leChamps dans les tableaux longi et E
	strcpy(longi, leChamps[4].c_str());
	strcpy(E, leChamps[5].c_str());
	
	//mise des degré dans le tableau longdegres
	for(int y = 0; y<=2; y++)
		{
			longdegres[y] = longi[y];
			
		}

	//transformation de longdegres en float
		
	//utilisation de flux 
	//transformation en float
	istringstream degre(string(longdegres,3));
	degre>>longdegre;
			
			//mise des minute dans le tableau longminute
		for(int y = 3; y<=9; y++)
		{
			//on utilise -3 car il faut qu'on aille au debut du tableau
			longminute[y-3] = longi[y];

		}
		
		
		//transformation de longminute en float

		//utilisation de flux 
		//transformation de minute en float
	istringstream minutes(string(longminute,8));
	minutes>>longmin;
			
		
		//calcul de la latitude
		longmin =longmin/60;
		resultatLongitudeF = longdegre+longmin;
		//vérification du signe de la longitude
		if(calculEst(leChamps) == 'E')
		{
	}else{
		//mise en négatif
		resultatLongitudeF = resultatLongitudeF *-1;
	}


	resultatLongitudeS=to_string(resultatLongitudeF);
	resultatLongitudeS.copy(longitude,resultatLongitudeS.size());		
		
}

void Geolocalisation::calculLatitude(string leChamps[200])
{
	
	char latdegres[2];
	char latminute[8];	
	double latdegreF,latminF;
	string latdegreS, resultatLatitudeS;
	double resultatLatitude;
	char lat[15];
	char N[2];
	
	//récupération des données du tableau leChamps dans les tableau lat et N
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
	for(int y = 2; y<=10; y++)
	{
		latminute[y-2] = lat[y];

	}
		
	//transformation de latdegre en float
		
	//utilisation de flux 
	//transformation de degre en float
	istringstream degre(latdegreS);
	degre>>latdegreF;

	//transformation de latminute en float
	istringstream minutes(string(latminute,8));
	minutes>>latminF;


	//conversion des minutes en degrés
	latminF =latminF/60;
	
	resultatLatitude = latdegreF+latminF;
	
	//calculdu signe
	if(calculNord(leChamps) != 'N')
	{
		resultatLatitude = resultatLatitude *-1;
	}
	resultatLatitudeS=to_string(resultatLatitude);
	resultatLatitudeS.copy(latitude,resultatLatitudeS.size());
}

void Geolocalisation::calculAltitude(string leChamps[200])
{
	char alti[4];
	int intalti;
	//récupération de données de leChamps et mise dans la variable alti
	strcpy(alti, leChamps[9].c_str());
	//transformation en int
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
return fixe;


}

char Geolocalisation::calculHDOP(string leChamps[200])
{
	char resultatHDOP[5];
strcpy(resultatHDOP, leChamps[8].c_str());
for(int i=0;i<=5;i++){
HDOP[i] = resultatHDOP[i];

}	
	
}
	
int Geolocalisation::chronometer()
{
	
	chrono::time_point<std::chrono::system_clock> start, end; 
	chrono::duration<double> elapsed_seconds;
	start = std::chrono::system_clock::now();
	do {

		end = std::chrono::system_clock::now(); 
		elapsed_seconds = end - start; 
		usleep(100000);
	}
	while((elapsed_seconds.count()<10)&&(vCond==false));

}

thread Geolocalisation::activerChrono(){
	return thread([this]{

		chronometer();
	vCond=true;
	this->setVCond(vCond);
	} );
}

int Geolocalisation::localiser()
{
	string leChamps[200];
	thread laRechercheGGA = leGPS->activerRechercheGGA();
	thread leChrono = activerChrono();
	//leGPS->lirePosition();
	laRechercheGGA.join();
	this->setVCond(true);
	leChrono.detach();
	leGPS->getChampsGGA(leChamps);
	calculLatitude(leChamps);
	calculLongitude(leChamps);
	calculAltitude(leChamps);
	calculSatellite(leChamps);
	calculFixe(leChamps);
	calculHDOP(leChamps);
	//leChrono.join();// à sortir... Sortir ligne 56 de GPS
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

void Geolocalisation::setVCond(bool vCond){
	this->vCond=vCond;
	leGPS->setVCond(vCond);
}

void Geolocalisation::setLatitude(char aLatitude[10]){

        for (int i=0;i<10;i++)
        {
                latitude[i]=aLatitude[i];
        }
}
void Geolocalisation::setLongitude(char aLongitude[10]){

        for (int i=0;i<10;i++)
        {
                longitude[i]=aLongitude[i];
        }
}

void Geolocalisation::setAltitude(char aaltitude[4]){
		for (int i=0;i<4;i++)
        {
            altitude[i]=aaltitude[i];
        }
}

