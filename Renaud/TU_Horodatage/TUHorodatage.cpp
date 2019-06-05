#include "Horodatage.h"

using namespace std;

int main()
{
	
	char date [6];
	char heure [6];
	bool fin;
	GPS* unGPS = new GPS();
	Horodatage* lHorodatage = new Horodatage(unGPS);
	lHorodatage->setVCond(fin);
	//test Geo et Horo
	
	
	lHorodatage->dater();
	cout<<"dater completed OK"<<endl;

	lHorodatage->getHeure(heure);
	cout << heure << endl;
	lHorodatage->getDate(date);
	cout << string(date,6) << endl;
}

