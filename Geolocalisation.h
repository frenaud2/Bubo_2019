#include <stdio.h>
#include <iostream>
#include "serialib/serialib.h"
#include <iomanip>
#include <sstream> 
#include <string>
#include <vector>
#include <cstring>
#include "GPS.h"

class Geolocalisation
{
        private :
                GPS *leGPS;
	
	char longitude[15];
	char latitude[15];
	char altitude[5];
	char nord[2];
	char est[2];
	char fixe[2];
	char satellite[3];
	


	

	

		public : 		
				
				Geolocalisation(GPS *unGPS);
				Geolocalisation();
				char trouverLongitude();
				char* getlongitude();
				float calculLongitude();
				float calculLatitude();
				int localiser();
				
				char* getlatitude();
				string recupererGGA;
				float calculAltitude();
				
};		
