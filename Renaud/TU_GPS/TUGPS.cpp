#include "GPS.h"

int main()
{
	
	string leChampsGGA[200];
	string leChampsRMC[200];
	GPS* leGPS = new GPS();
	
	leGPS->lirePosition();
	leGPS->getChampsGGA(leChampsGGA);
	for(int i=0; i<=10;i++){
		cout << leChampsGGA[i] << endl;
	}
	leGPS->lireHeure();
	leGPS->getChampsRMC(leChampsRMC);
	for(int i=0; i<=10;i++){
		cout << leChampsRMC[i] << endl;
	}

}

