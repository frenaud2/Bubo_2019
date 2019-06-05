#ifndef DEF_HORODATAGE
#define DEF_HORODATAGE

#include <vector>
#include <algorithm>
#include "GPS.h"

class Horodatage
{

			GPS *leGPS ;
			char date [6];
			char heure [6];
		public :
			Horodatage(GPS *unGPS);
			Horodatage();
			int dater();
			void setVCond(bool vCond);
		private :
			int extraireDateRMC(string leChamps[200]);
			int extraireHeureRMC(string leChamps[200]);
		public: void setDate(char aDate[6]);
		public: void setHeure(char aHeure[6]);

		public: void getHeure(char aHeure[6]);
		public: void getDate(char aDate[6]);
};

#endif
