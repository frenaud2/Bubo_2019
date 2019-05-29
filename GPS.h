#define DEVICE_PORT     "/dev/ttyUSB0"

#define ERREURACCESPORT -1
#include <stdio.h>
#include "../serialib/serialib.h"
#include <iostream>
#include <iomanip>
#include <sstream> 
#include <string>
#include <vector>
#include <cstring>
using namespace std;



class GPS
{
	
public : 
	GPS();
	int ouverture(serialib LS);
	int lirePosition();
	int lireHeure();
	void getChampsGGA(string champsGGA[200]);
	void getChampsRMC(string champsRMC[200]);

private :
	char fixe[2];
	string champsGGA[200];
	string champsRMC[200];
	char nord[2];
	char latitude[15];
	char longitude[15];
	char satellite[3];
	char altitude[15];
	char est[2];
	char heure_char[15];
	char date_char[15];
	bool verifierCheksum();
	

};
