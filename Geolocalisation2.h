#include <stdio.h>
#include <iostream>
#include "serialib/serialib.h"
#include <iomanip>
#include <sstream> 
#include <string>
#include <vector>
#include <cstdlib>
#include "GPS.h"

class Geolocalisation
{
        private :
                GPS *leGPS;
	
	char longitude[15];
	char latitude[15];
	char altitude[4];
	char nord;
	char est;
	char fixe;
	char satellite[3];
	char HDOP[5];


	

	

		public : 		
				
				Geolocalisation(GPS *unGPS);
				Geolocalisation();
				char trouverLongitude();
				void calculLongitude(string leChamps[200]);
				void calculLatitude(string leChamps[200]);
				void calculAltitude(string leChamps[200]);
				void calculSatellite(string leChamps[200]);
				char calculNord(string leChamps[200]);
				char calculEst(string leChamps[200]);
				char calculFixe(string leChamps[200]);
				char calculHDOP(string leChamps[200]);
				int localiser();
				void getLongitude(char longitude[15]);
				void getLatitude(char alatitude[15]);
				void getAltitude(char aaltitude[4]); 
				void getSatellite(char asatellite[3]);
				void getHDOP(char aHDOP[5]);
				void getFixe(char afixe);
			
				string recupererGGA;
				float calculAltitude();
				
};		
