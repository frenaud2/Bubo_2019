
#include "GPS.h"

GPS::GPS(){

}



int GPS::lirePosition()
{
	/*serialib LS;
	int err; 
	char Buffer[500];
	
	//err = ouverture(LS);
		err=LS.Open(DEVICE_PORT,4
		* 00110...
		* 800);  
	
	if(err>0)     	
	{
	int j =0;
	while(j==0){
		 
		
	do
		{
			err=LS.ReadString(Buffer,'\n',500,5000);
			//cout << err << endl;
			
			std::vector<char> GPGGA={'$','G','P','G','G','A'};
		//	cout << "1" << endl;
			if (Buffer[3] == GPGGA[3] && Buffer[4] == GPGGA[4] && Buffer[5] == GPGGA[5])
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
				
			}
         		
		}
		while(fixe[0] != '1');
	}
			/*strcpy(latitude, messageGGA[2].c_str());
		
			strcpy(nord, messageGGA[3].c_str());
		
			strcpy(longitude, messageGGA[4].c_str());
			
			strcpy(est, messageGGA[5].c_str());
			
			strcpy(satellite, messageGGA[7].c_str());
			
			strcpy(altitude, messageGGA[9].c_str());
*/

	champsGGA[0] = "$GPGGA";
	champsGGA[1] = "124943.000";
	cout << "Entrer la Latitude ( DDmm.mmmmm )" << endl;
	cin >> champsGGA[2]; //= "4336.9458";
	cout << "Nord ou Sud (N ou S)" << endl;
	cin >> champsGGA[3]; //= "N";
	cout << "Entrer la Longitude ( DDDDD.mmmm " << endl;
	cin >>champsGGA[4]; //= "00118.5670";
	cout << "Ouest ou Est (W ou E)"<< endl;
	cin >>champsGGA[5]; //= "E";
	champsGGA[6] = "1";
	cout << "Entrer le nombre de sattelites" << endl;
	cin >>champsGGA[7]; //= "05";
	cout << "Entrer la Précision" << endl;
	cin >>champsGGA[8]; //= "2.1";
	cout << "Entrer l'altitude" << endl;
	cin >>champsGGA[9]; //= "175.6";
	
	
}
void GPS::getChampsGGA(string leChampsGGA[200]){
	
	  for (int i=0;i<10;i++){
	leChampsGGA[i] = champsGGA[i];
	
}
}

int GPS::lireHeure()
{
	/*serialib LS;
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
*/

	champsRMC[0] = "$GPRMC";
	cout << "donner l'heure dans le format ( hhmmss.sss )" << endl;
	cin >> champsRMC[1]; //= "053740.000"; //hhmmss.sss
	
	champsRMC[2] = "A"; 
	
	champsRMC[3] = "2503.6319"; 
	
	champsRMC[4] = "N"; 
	
	champsRMC[5] = "12136.0099"; 
	champsRMC[6] = "E";
	
	champsRMC[7] = "2.69"; 
	champsRMC[8] = "79.65"; 
	
	cout << "donner la date dans le format ( jjmmaa )" << endl;
	cin >> champsRMC[9]; //= "100106";  //qqmmaa
	champsRMC[10] = "0"; 
	champsRMC[11] = "0"; 
	champsRMC[12] = "A"; 
}

void GPS::getChampsRMC(string leChampsRMC[200]){
	
	for (int i=0;i<10;i++){
		leChampsRMC[i] = champsRMC[i];
	}
}

void GPS::setVCond(bool vCond){
	//this->vCond = vCond;
}

thread GPS::activerRechercheGGA(){
	return thread([this]{
		
		lirePosition();
		
	} );
}

thread GPS::activerRechercheRMC(){
	return thread([this]{
		
		lireHeure();
	
		
	} );
}
	
