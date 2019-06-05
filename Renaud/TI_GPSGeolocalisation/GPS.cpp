

#include "GPS.h"

GPS::GPS(){
	vCond=false;
}



int GPS::lirePosition()
{
	serialib LS;
	int err; 
	char Buffer[500];
	char nbreSatellite[3];
	int intSatellite;
	std::vector<char> GPGGA={'$','G','P','G','G','A'};

	int j =0;
	while(j==0){
		
		do
		{
			//ouverture du port
			err=LS.Open(DEVICE_PORT0,SPEED);  
			if (err<=0) err=LS.Open(DEVICE_PORT1,SPEED);
			if (err<=0) err=LS.Open(DEVICE_PORT2,SPEED);
			if (err<=0) err=LS.Open(DEVICE_PORT3,SPEED);
			//cout<<"err = "<<err<<endl;
			if(err<=0)  return err; 
			do
			{
			//lecture des données de la variable Buufer j'usqu'au 
			//retour a la ligne, de 500 caractère max et 5 seconde max
			err=LS.ReadString(Buffer,'\n',500,5000);
			//for (int i=0;i<err;i++)
			//{
			//	cout<<Buffer[i];
			//}
			
			}
			//on fait cette boucle tant qu'on a pas la trame GGA
			while (Buffer[4] != GPGGA[4] );
			LS.Close();

			if (Buffer[3] == GPGGA[3] && Buffer[4] == 
                                GPGGA[4] && Buffer[5] == GPGGA[5])
			{
				if (verifierCheksum(Buffer))
				{
					string gga(Buffer);
					//cout<<gga<<endl;
					istringstream trame(gga);
					string mot; 
					for(int i=0;i<=12;i++){ 
						//retour a la ligne a 
                                           //chaque virgule
                                         ( std::getline
                                                 ( trame, mot, ',' ) ); 
						champsGGA[i] = mot ; 
					}
					j=j+1;
				//champsGGA[6]='0';//// AAAAAA Sortir : fait 
                                       // pour TU de Geolocalisation
					strcpy(fix, champsGGA[6].c_str());
				}
			}
 		}
		while((fix[0] == '0')&&(!vCond));
		vCond=false;
	}
	
}

void GPS::getChampsGGA(string leChampsGGA[200]){
	
	for (int i=0;i<10;i++){
		leChampsGGA[i] = champsGGA[i];
	}
}

void GPS::getChampsRMC(string leChampsRMC[200]){
	
	for (int i=0;i<10;i++){
		leChampsRMC[i] = champsRMC[i];
	}
}

void GPS::setVCond(bool vCond){
	this->vCond = vCond;
}

int GPS::lireHeure()
{
	serialib LS;
	int err; 
	char Buffer[500];
	char validite[2];
	int j = 0;
	std::vector<char> GPRMC={'$','G','P','R','M','C'};
	while(j==0){
		do
		{
			err=LS.Open(DEVICE_PORT0,SPEED);  
			if (err<=0) err=LS.Open(DEVICE_PORT1,SPEED);
			if (err<=0) err=LS.Open(DEVICE_PORT2,SPEED);
			if (err<=0) err=LS.Open(DEVICE_PORT3,SPEED);
			//cout<<"err = "<<err<<endl;
			if(err<=0)  return err;  	
			do
			{
				err=LS.ReadString(Buffer,'\n',500,5000);

				//for (int i=0;i<err;i++)
				//{
				//	cout<<Buffer[i];
				//}
			}
			while (Buffer[3] != GPRMC[3] );
			LS.Close();
			if (Buffer[3] == GPRMC[3] && Buffer[4] == 
                                GPRMC[4] && Buffer[5] == GPRMC[5])
			{
				
				j=1;
				string rmc(Buffer);
				istringstream trame(rmc);
				string mot; 
				for(int i=0;i<=12;i++)
				{ 
					std::getline( trame, mot, ',' ) ; 
     
					champsRMC[i] = mot; 
			
				}
				strcpy(validite, champsRMC[2].c_str());
			} 
		}
		while((validite[0] != 'A')&&(!vCond));
	}
	

}

bool GPS::verifierCheksum(char Buffer[500]){
	short Checksum=0;
	char leChecksum[2];
	/*le checksum pr�c�d� du signe * repr�sente le OR exclusif de tous 
	les caract�res compris entre $ et * (sauf les bornes $ et *). */
	int i=1; //position du Buffer qui correspond au caract�re qui suit le $
	do
	{
		Checksum = Checksum^Buffer[i];
		i=i+1;
	} while(Buffer[i]!='*');


/*le checksum est transform� en hexad�cimal puis en ASCII pour comparaison
� celui de la trame re�ue*/
	sprintf(leChecksum, "%X",Checksum);
	if ((leChecksum[1]!=Buffer[i+2]) || (leChecksum[0]!=Buffer[i+1])) 
            return false;
	else return true;
	
}

thread GPS::activerRechercheGGA(){
	return thread([this]{
		//do{
		lirePosition();
		//sleep(1);
		//}while(1);
	} );

}	

thread GPS::activerRechercheRMC(){
	return thread([this]{
		
		lireHeure();
	
		
	} );
}
