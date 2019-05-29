

#include "GPS.h"

GPS::GPS(){

}



int GPS::lirePosition()
{
	serialib LS;
	int err; 
	char Buffer[500];
	char nbreSatellite[3];
	int intSatellite;

	//err = ouverture(LS);
		err=LS.Open(DEVICE_PORT,9600);  

	if(err>0)     	
	{
	int j =0;
	while(j==0){
	
		
	do
		{
		
			do
				{
					
					err=LS.ReadString(Buffer,'\n',500,5000);
	
			
					std::vector<char> GPGGA={'$','G','P','G','G','A'};
				if (Buffer[3] == GPGGA[3] 
				&& Buffer[4] == GPGGA[4] && Buffer[5] == GPGGA[5])
						{
				
							j=1;
							string gga(Buffer);
							istringstream trame(gga);
							string mot; 
							for(int i=0;i<=12;i++){ 
								//retour a la ligne a chaque virgule
								( std::getline( trame, mot, ',' ) ); 
								champsGGA[i] = mot ; 
							}
				
							strcpy(fixe, champsGGA[6].c_str());	
							
							strcpy(nbreSatellite, champsGGA[7].c_str());
							intSatellite = atoi(nbreSatellite);
					
						}
					}
					while(intSatellite < 5);
         		
		}
		while(fixe[0] == '0');
	}
			/*strcpy(latitude, messageGGA[2].c_str());
		
			strcpy(nord, messageGGA[3].c_str());
		
			strcpy(longitude, messageGGA[4].c_str());
			
			strcpy(est, messageGGA[5].c_str());
			
			strcpy(satellite, messageGGA[7].c_str());
			
			strcpy(altitude, messageGGA[9].c_str());
*/

	}
	else return err;
	
}
void GPS::getChampsGGA(string leChampsGGA[200]){
	
	  for (int i=0;i<10;i++){

	leChampsGGA[i] = champsGGA[i];
	  
}
}

int GPS::lireHeure()
{
	serialib LS;
	int port; 
	char Buffer[500];
	char validite[2];
	int j = 0;
	while(j==0){
		do
		{
		port=LS.ReadString(Buffer,'\n',500,5000);
		std::vector<char> GPRMC={'$','G','P','R','M','C'};
		if (Buffer[3] == GPRMC[3] && Buffer[4] == GPRMC[4] && Buffer[5] == GPRMC[5])
			{
				
				j=1;
				string rmc(Buffer);
			istringstream trame(rmc);
			string mot; 
			for(int i=0;i<=12;i++){ 
			( std::getline( trame, mot, ',' ) ); 
     
			champsRMC[i] = mot; 
			
			strcpy(validite, champsRMC[2].c_str());

		}
	} 
}
while(validite[0] != 'A');
}
strcpy(heure_char, champsRMC[1].c_str());
	
	
strcpy(date_char, champsRMC[9].c_str());
}

/*bool GPS::verifierCheksum(){
string mot; 
std::getline( trame, mot, '*' );
ChampsGGA[i] = mot;

}
*/
		
