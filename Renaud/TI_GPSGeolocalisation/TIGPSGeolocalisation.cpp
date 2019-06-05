// compilation g++ TIGPSHorodatage.cpp Horodatage.cpp GPS.cpp ../serialib/serialib.cpp -o TIGPSHorodatage  -std=c++14 -lpthread

#include "Geolocalisation.h"
using namespace std;

int main()
{
	char latitude[15];
	char longitude[15];
	char altitude[15];
	char satellite[3];
	char HDOP[5];
	char date [6];
	char heure [6];
	char fix;
	bool fin;
	GPS* unGPS = new GPS();
	//test Geo et Horo
	Geolocalisation* laGeolocalisation = new Geolocalisation(unGPS);
	laGeolocalisation->setVCond(fin);
	laGeolocalisation->localiser();
	
	laGeolocalisation->getLatitude(latitude);
	cout << latitude << endl;
	laGeolocalisation->getLongitude(longitude);
	cout << longitude << endl;
	laGeolocalisation->getAltitude(altitude);
	cout << altitude << endl;
	laGeolocalisation->getSatellite(satellite);
	cout << satellite << endl;
	laGeolocalisation->getHDOP(HDOP);
	cout << HDOP << endl;	
	fix = laGeolocalisation-> getFix();
	cout << fix << endl;
	
}
