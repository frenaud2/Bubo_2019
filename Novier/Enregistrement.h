#include <exception>
#include <string>
#include "Lampadaire.h"
#include "Ampoule.h"
#include "Galerie.h"
#include "Geolocalisation.h"
#include "Horodatage.h"

#include "GPS.h"
using namespace std;

#ifndef __Enregistrement_h__
#define __Enregistrement_h__


	class Enregistrement
	{
		/**
		 * identifiant d'enregistrement basé sur l'instant exact de mesure
		 */
		private: string _identifiant;
		private: string _agglomeration;
		private: string _rue;
		private: string _notes;
				 int ID;
		private: Lampadaire* lampadaire;
		private: Galerie* galerie;
		private: Geolocalisation* geolocalisation;
		private: Ampoule* ampoule;
		private: Horodatage* horodatage;

		public: Enregistrement(string aIdRaspberry, GPS * unGPS) ;
				Enregistrement( GPS * unGPS);
				Enregistrement(int aId, string aAlbedo, string aFluxLum, string aIdRaspberry, string aTypeAmpoule, string aTypeLampadaire, string aHauteur, double aLatitude,  double aLongitude, int aNbImages, string aAgglo, string aRue, int aUlor, string aDate, string aNotes, int puissance);

				Enregistrement(string aAlbedo, string aFluxLum, string aIdRaspberry, string aTypeAmpoule, string aTypeLampadaire, string aHauteur, double aLatitude, double aLongitude,  int aNbImages, string aAgglo, string aRue, int aUlor, string aDate, string aNotes,int aPuissance);

		/// <summary>
		/// Cette méthode permet de récupérer les données réutilisables pour un nouvel enregistrement.
		/// </summary>
		public: void getDonneesCommunes();

		//public: void calculerIdentifiant(char heure[6],char date[6]);

		//public: string creerIdentifiant();

		public: int caracteriserAmpoule(float aIntensiteLumineuse);

		/// <summary>
		/// Cette méthode permet d'extraire la latitude et la longitude sous la forme d'un tableau de 10 caractères ASCII. Elles seront exprimées en degrés
		/// (avec 6 chiffres après la virgule) et issues d'un filtrage sur 10 valeurs
		/// Exemple d'une adresse dans la ville de Plougastel-Daoulas :
		/// Latitude = 48.347487°
		/// Longitude = -4.465502°
		/// Le symbole ° n'est pas contenu dans le tableau.
		/// <returns> Valeurs de retour :
		/// ALERTE = -2 : Signifie que le GPS n'était pas prêt lors de la capture et à transmis le caractère 'V' dans le deuxième champs après l'identifiant.
		/// ERREURCHECKSUM = -3 : Le Checksum de la trame capturée est erroné
		/// ECHECCAPTURE = -4 : La trame RMC n'a pas été capturée dans la salve capturée</returns> 
		/// </summary>
		public: int localiser() ;

		/// <summary>
		/// Cette méthode permet d'extraire la latitude et la longitude sous la forme d'un tableau de 10 caractères ASCII. Elles seront exprimées en degrés 
		/// (avec 6 chiffres après la virgule). Elles ne seront pas filtrées.
		/// Exemple d'une adresse dans la ville de Plougastel-Daoulas :
		/// Latitude = 48.347487°
		/// Longitude = -4.465502°
		/// Le symbole ° n'est pas contenu dans le tableau.
		/// <returns> Valeurs de retour :
		/// ALERTE = -2 : Signifie que le GPS n'était pas prêt lors de la capture et à transmis le caractère 'V' dans le deuxième champs après l'identifiant.
		/// ERREURCHECKSUM = -3 : Le Checksum de la trame capturée est erroné
		/// ECHECCAPTURE = -4 : La trame RMC n'a pas été capturée dans la salve capturée</returns> 
		/// </summary>
		public: int localiserSF() ;

		public: int localiser(char aLatitude_[10], char aLongitude[10], GPS * unGPS) ;

		public: void getPosition(char aLatitude[], char aLongitude[]);
		public: int getIdentifiant();
		public: string getBuboID();
		public: void setPosition(char aLatitude[], char aLongitude[]); //pour rÃ©cupÃ©rer valeurs GPS de l'IHM
		public: void setAgglomeration(string aAgglomeration);

		public: string getAgglomeration();

		public: void setNotes(string aNotes);

		public: string getNotes();

		public: void setRue(string aRue);

		public: string getRue();

				void setLampadaire(string type, string hauteur, int ulor,string albedo);
				void setGalerie(int nbrePhotos);
				void setGeolocalisation(char aLatitude_[10], char aLongitude[10]);
				void setHorodatage(char date[6]);
				void setAmpoule(string type,string intensiteLumineuse,int puissance);
				void getAmpoule(string &type, string  &intensiteLumineuse, int &puissance);

				void getLampadaire(string &type, string &hauteur, int &ulor, string  &albedo);
				void getGalerie(int &nbrePhotos);

				void getHorodatage(char date[6]);

		/// <summary>
		/// Cette méthode permet de récupérer les coordonnées d'un enregistrement.
		///	Les informations sont alors retournées dans les deux paramètres : 
		/// <param> premier paramètre = latitude</param>
		/// <param> second paramètre = longitude </param>
		/// </summary>		
				void getGeolocalisation(char aLatitude_[10], char aLongitude[10]);


	};


#endif
