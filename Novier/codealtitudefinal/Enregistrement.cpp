/* Sans calcul d'identifiant*/
#include <exception>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

#include "Enregistrement.h"
#include "Collecteur.h"
#include "Lampadaire.h"
#include "Galerie.h"
#include "Geolocalisation.h"
#include "Ampoule.h"
#include "Horodatage.h"
#include "GPS.h"
#include"Logger.h" //x
//Logger *monLogger=new Logger();


Enregistrement::Enregistrement(string aIdRaspberry, GPS * unGPS) {
//monLogger->saveLog("tes");
	horodatage = new Horodatage(unGPS);
	geolocalisation = new Geolocalisation(unGPS);
	ampoule = new Ampoule();
	lampadaire = new Lampadaire();
	galerie=new Galerie();
}


Enregistrement::Enregistrement(GPS * unGPS) {
	horodatage = new Horodatage(unGPS);
	geolocalisation = new Geolocalisation(unGPS);
	ampoule = new Ampoule();
	_identifiant="";
	lampadaire = new Lampadaire();
	galerie=new Galerie();
}


Enregistrement::Enregistrement(int aId, string aAlbedo, string aFluxLum, string aIdRaspberry, string aTypeAmpoule, string aTypeLampadaire, string aHauteur, double aLatitude, double aLongitude, double aAltitude, int aNbImages, string aAgglo, string aRue, int aUlor, string aDate, string aNotes, int puissance){
  	 horodatage = new Horodatage();
        geolocalisation = new Geolocalisation();
        ampoule = new Ampoule();
        this->_identifiant=aIdRaspberry;
        lampadaire = new Lampadaire();
        galerie=new Galerie();

//il faut instancier et mettre les attributs de enregistrer dans les attributs private de enregistrement.h:

	char Latitude[10];
	char Longitude[10];
    char Altitude[4];

	ID=aId;

	lampadaire->setAlbedo(aAlbedo) ;                         //dans lampadaire.h

	lampadaire->setHauteur(aHauteur);                       //dans lampadaire.h

	lampadaire->setULOR(aUlor);                             //dans lampadaire.h

	lampadaire->setType(aTypeLampadaire);                   //dans lampadaire.h

	ampoule->setIntensiteLumineuse(aFluxLum);                  // ampoule.h

	ampoule->setType(aTypeAmpoule);                             //  ampoule.h

	ampoule->setPuissance(puissance);                        //dans ampoule.h

	int recup= sprintf(Latitude,"%f",aLatitude);		//conversion du double en char
	//cout<<"donnée de  sprintf pour la latitude : "<<recup<<endl;

	geolocalisation->setLatitude(Latitude);                    // dans geolocalisation.h

	int recup2= sprintf(Longitude,"%f", aLongitude);                   //Conversion du double en char
	//cout<<"donneé de sprintf pour la longitude : "<<recup2<<endl;

    	geolocalisation->setLongitude(Longitude);  // dans geolocalisation.h
        
	int recup3= sprintf(Altitude,"%f", aAltitude);                   //Conversion du double en char
	//cout<<"donneé de sprintf pour l'altitude: "<<recup3<<endl;

    	geolocalisation->setAltitude(Altitude);               // dans geolocalisation.h
        
        
        

    	galerie->setNbrePhotos(aNbImages);                      //dans galerie.h


	_agglomeration=aAgglo;                                  // enregistrement.h

	_rue =aRue;                                             // enregistrement.h


	const char* X;   //cree la variable X de type const char *
	X=aDate.c_str();      // fait une conversion de aDate qui est de type string en const char*

	char Date[6];   // On cree un tableau "Date" de 6
	strcpy( Date, X); //on convertit X qui est de type const char * en Date qui est de type char*

        horodatage->setDate(Date);                              //dans horodatage.h


	_notes=aNotes;                                      // enregistrement.h


}

Enregistrement::Enregistrement( string aAlbedo, string aFluxLum, string aIdRaspberry, string aTypeAmpoule, string aTypeLampadaire, string aHauteur, double aLatitude, double aLongitude, double aAltitude, int aNbImages, string aAgglo, string aRue, int aUlor, string aDate, string aNotes, int aPuissance){
  	 horodatage = new Horodatage();
        geolocalisation = new Geolocalisation();
        ampoule = new Ampoule();
        _identifiant="";
        lampadaire = new Lampadaire();
        galerie=new Galerie();
		_identifiant = aIdRaspberry;

//il faut instancier et mettre les attributs de enregistrer dans les attributs private de enregistrement.h:

char Latitude[10];
char Longitude[10];
char Altitude[4];


	lampadaire->setAlbedo(aAlbedo) ;                         //dans lampadaire.h

	lampadaire->setHauteur(aHauteur);                       //dans lampadaire.h

	lampadaire->setULOR(aUlor);                             //dans lampadaire.h

	lampadaire->setType(aTypeLampadaire);                   //dans lampadaire.h

	ampoule->setIntensiteLumineuse(aFluxLum);                  // ampoule.h

	ampoule->setType(aTypeAmpoule);                             //  ampoule.h

	int recup= sprintf(Latitude,"%f",aLatitude);		//conversion du double en char

	geolocalisation->setLatitude(Latitude);                    // dans geolocalisation.h

        

	int recup2= sprintf(Longitude,"%f", aLongitude);                   //Conversion du double en char

    geolocalisation->setLongitude(Longitude);               // dans geolocalisation.h

    int recup3= sprintf(Altitude,"%f",aAltitude);		//conversion du double en char

	geolocalisation->setAltitude(Altitude);

    galerie->setNbrePhotos(aNbImages);                      //dans galerie.h

	_agglomeration=aAgglo;                                  // enregistrement.h

	_rue =aRue;                                             // enregistrement.h


	const char* X;   //cree la variable X de type const char *
	X=aDate.c_str();      // fait une conversion de aDate qui est de type string en const char*

	char Date[6];   // On cree un tableau "Date" de 6
	strcpy( Date, X); //on convertit X qui est de type const char * en Date qui est de type char*

        horodatage->setDate(Date);                              //dans horodatage.h

	_notes=aNotes;                                      // enregistrement.h


	ampoule->setPuissance(aPuissance);                        //dans ampoule.h

}


void Enregistrement::getDonneesCommunes() {
	throw "Not yet implemented";
}

//void Enregistrement::calculerIdentifiant(char heure[6],char date[6]) {
//
//	for (int i=0;i<6;i++)
//	_identifiant=_identifiant+date[i];
//	for (int i=0;i<6;i++)
//	_identifiant=_identifiant+heure[i];
//}
//
///*string Enregistrement::creerIdentifiant() {
//	char heure [6];
//	char date [6];
//
//	horodatage->dater(heure,date);
//	this->calculerIdentifiant(heure,date);
//}*/

int Enregistrement::caracteriserAmpoule(float aIntensiteLumineuse) {
	aIntensiteLumineuse = ampoule->mesurerILux();
	return 0;
}


void Enregistrement::getPosition(char aLatitude[10], char aLongitude[10])
 {

	geolocalisation->getLatitude(aLatitude);
	geolocalisation->getLongitude(aLongitude);

}

void Enregistrement::setPosition(char aLatitude[10], char aLongitude[10])
 {

	geolocalisation->getLatitude(aLatitude);
	geolocalisation->getLongitude(aLongitude);

}

int Enregistrement::localiser() {
/*
	char aLatitude_[10]; 
	char aLongitude[10];
	int erreur = 1;

	erreur = geolocalisation->localiser(aLatitude_,aLongitude,);
	if (erreur>0) horodatage->dater();
	return erreur;
*/
}

int Enregistrement::localiserSF() {
/*
	char aLatitude_[10]; 
	char aLongitude[10];
        char aAltitude[4];
	int erreur = 1;

	erreur = geolocalisation->localiserSF(aLatitude_,aLongitude,aAltitude);
	if (erreur>0) horodatage->dater();
	return erreur;
*/
}

int Enregistrement::localiser(char aLatitude_[10], char aLongitude[10], GPS * unGPS)
{
/*
	geolocalisation = new Geolocalisation(unGPS);
	return geolocalisation->localiser(aLatitude_,aLongitude,aAltitude);
*/
}

int Enregistrement::getIdentifiant() {
	return ID;
}


void Enregistrement::setAgglomeration(string aAgglomeration) {
	this->_agglomeration = aAgglomeration;
}

string Enregistrement::getAgglomeration() {
	return this->_agglomeration;
}

void Enregistrement::setNotes(string aNotes) {
	this->_notes = aNotes;
}

string Enregistrement::getNotes() {
	return this->_notes;
}

void Enregistrement::setRue(string aRue) {
	this->_rue = aRue;
}

string Enregistrement::getRue() {
	return this->_rue;
}

void Enregistrement::setAmpoule(string type, string intensiteLumineuse, int puissance){
    ampoule->setIntensiteLumineuse(intensiteLumineuse);
    ampoule->setPuissance(puissance);
    ampoule->setType(type);
}

void Enregistrement::setLampadaire(string type, string hauteur, int ulor, string albedo)
{
    lampadaire->setType(type);
    lampadaire->setHauteur(hauteur);
    lampadaire->setULOR(ulor);
    lampadaire->setAlbedo(albedo);    
}

void Enregistrement::setGalerie(int nbrePhotos)
{
    galerie->setNbrePhotos(nbrePhotos);
}


void Enregistrement::setHorodatage(char date[6])
{
    horodatage->setDate(date);
    
}

void Enregistrement::setGeolocalisation(char aLatitude_[10], char aLongitude[10], char aAltitude[4])
{
    geolocalisation->setLatitude(aLatitude_);
    geolocalisation->setLongitude(aLongitude);
    geolocalisation->setAltitude(aAltitude);
}
/////////////////////////get Compos�s//////////////////////////////
void Enregistrement::getAmpoule(string &type, string &intensiteLumineuse, int &puissance){
	type = this->ampoule->getType();
	intensiteLumineuse = this->ampoule->getIntensiteLumineuse();
	puissance = this->ampoule->getPuissance();
}

void Enregistrement::getLampadaire(string &type, string &hauteur, int &ulor, string &albedo)
{
	type = this->lampadaire->getType();
	hauteur = this->lampadaire->getHauteur();
	ulor = this->lampadaire->getULOR();
	albedo = this->lampadaire->getAlbedo();
}

void Enregistrement::getGalerie(int &nbrePhotos)
{
	nbrePhotos = this->galerie->getNbrePhotos();
}


void Enregistrement::getHorodatage(char date[6])
{
	this->horodatage->getDate(date);	
 
}

void Enregistrement::getGeolocalisation(char aLatitude_[10], char aLongitude[10], char aAltitude[4])
{
/*
	this->geolocalisation->getLatitude(aLatitude_ );
	this->geolocalisation->getLongitude(aLongitude);
    this->geolocalisation->getAltitude(aAltitude);
*/
}
string Enregistrement::getBuboID()
{
	return this->_identifiant;
}
