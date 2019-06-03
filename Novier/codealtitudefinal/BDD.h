#include <exception>
#include <string>
#include <vector>
#include <sqlite3.h> 
using namespace std;

#ifndef __BDD_h__
#define __BDD_h__

#include "Enregistrement.h"


	class BDD
	{
		private: string _baseDeDonnees;
		private: bool _conOk;
		private: char* _msgError;
				 sqlite3 * db;

		public: BDD();
				~BDD();
		public: vector<Enregistrement*> obtenirListeDesEnregistrements();

		public: vector<Enregistrement*> obtenirListeDesLampadairesProches(double latitude,double longitude,double Altitude);

		public: vector<Enregistrement> obtenirDonneesEnregistrement(double latitude,double longitude,double Altitude);

		public: Enregistrement obtenirDonneesEnregistrement(string aLatitude, string aLongitude, string aAltitude);

		public: void supprimerEnregistrement(int aId);

				bool viderTable();

		public: Enregistrement* sauvegarderDonneesEnregistrement(Enregistrement *enregistrement,string identifiantCollecteur);

		public: void modifierEnregistrement(int id,int puissance, string albedo, string fluxLum, string idRaspbery, string typeAmpoule, string typeLampadaire, string hauteur, double latitude, double longitude, double altitude, int nbImages, string agglo, string rue, int ulor, string date,string notes);

		private: void execute(string aRequetesql);

		private: vector<Enregistrement*> selectData(string requetesql);
	};


#endif
