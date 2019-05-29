#include "Geolocalisation2.h"


int main()
{
	char latitude[15];
	char longitude[15];
	char altitude[15];
	char satellite[3];
	char HDOP[5];
	char fixe;
	GPS* unGPS = new GPS();
	Geolocalisation* leGPS = new Geolocalisation(unGPS);	
	leGPS->localiser();
	leGPS->getLatitude(latitude);
	cout << latitude << endl;
	leGPS->getLongitude(longitude);
	cout << longitude << endl;
	leGPS->getAltitude(altitude);
	cout << altitude << endl;
	leGPS->getSatellite(satellite);
	cout << satellite << endl;
	leGPS->getHDOP(HDOP);
	cout << HDOP << endl;
	leGPS->getFixe(fixe);
	cout << fixe << endl;
	
}
