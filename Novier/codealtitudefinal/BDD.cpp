#include <exception>
#include <string>
#include <vector>
#include <sqlite3.h> 
#include <iostream>
#include <fstream>

#include "BDD.h"
#include "Enregistrement.h"
#include "Lampadaire.h"
#include "Ampoule.h"
#include "Galerie.h"
#include "Geolocalisation.h"
#include "Horodatage.h"


using namespace std;
/* Compilation :
g++ Collecteur.cpp BDD.cpp /usr/lib/libcgicc.a -std=c++11 -o Collecteur.cgi -l sqlite3 */


std::vector<Enregistrement*> BDD::selectData(string requetesql){
	sqlite3_stmt *stmt;
	const char *pzTest;
	vector<Enregistrement*> resultat;
	vector<vector<string> > stringRecords;
	string columnName;
	int rc = sqlite3_prepare_v2(db,requetesql.c_str(), requetesql.length(), &stmt, &pzTest);
    if(!rc){
		int nbColonne = sqlite3_column_count(stmt);
		string albedo,flux, buboid, lamp, streetlight, height, town, street, date, notes;
		double latitude, longitude, altitude;
		int ulor, nbimages,power, idRecord;
        //V�rifie qu'il y a des lignes disponibles

        while(rc == SQLITE_OK || rc == SQLITE_ROW){
            //R�cup�ratiion d'une ligne
            rc = sqlite3_step(stmt);
            if(rc == SQLITE_ROW){
					vector<string> record;
					for(int i = 0; i < nbColonne; i ++)
					{

						if (sqlite3_column_text(stmt, i))
							record.push_back((char*)sqlite3_column_text(stmt, i));
						else record.push_back(" ");
						columnName = sqlite3_column_name(stmt, i);
						//Conversion en majuscule pour traitement JSON
						//for (int j=0;j<colonneName.length();j++)
						//	colonneName[j]=toupper(colonneName[j]);

						//colonneNames.push_back(columnName);
					}
					stringRecords.push_back(record);

					Enregistrement *enreg = new Enregistrement(atoi(record.at(0).c_str()), record.at(2), record.at(3), record.at(4), record.at(5), record.at(6), 
						record.at(7), atof(record.at(8).c_str()),  atof(record.at(9).c_str()),atof(record.at(10).c_str()), atoi(record.at(11).c_str()), record.at(12),record.at(13),
						 atoi(record.at(14).c_str()), record.at(15), record.at(16), atoi(record.at(1).c_str()));
                    //Mettre les valeurs dans l'objet enreg
                    //Pour r�cup (letype) sqlite3_column_text(requete, numdelacolonne)

                    //Une fois fait sauvegarder enreg dans resultat
					resultat.push_back(enreg);

            }
        }
		 	// commit
		 	
		 sqlite3_finalize(stmt);
    }
    return resultat;
}

std::vector<Enregistrement*> BDD::obtenirListeDesEnregistrements()
{
    string req = "SELECT * FROM Enregistrements ORDER BY ID DESC";
	sqlite3_stmt *stmt;
	const char *pzTest;
	vector<Enregistrement*> resultat;
	int rc = sqlite3_prepare_v2(db,req.c_str(), req.length(), &stmt, &pzTest);
    if(!rc){
		int nbColonne = sqlite3_column_count(stmt);
		string albedo,flux, buboid, lamp, streetlight, height, town, street, date, notes;
		double latitude, longitude, altitude;
		int ulor, nbimages,power, idRecord;
        //V�rifie qu'il y a des lignes disponibles

        while(rc == SQLITE_OK || rc == SQLITE_ROW){
            //R�cup�ratiion d'une ligne
            rc = sqlite3_step(stmt);
            if(rc == SQLITE_ROW){

					vector<string> record;
					for(int i = 0; i < nbColonne; i ++)
					{

						if (sqlite3_column_text(stmt, i))
							record.push_back((char*)sqlite3_column_text(stmt, i));
						else record.push_back(" ");
					}
                    //Mettre les valeurs dans l'objet enreg
					Enregistrement *enreg = new Enregistrement(atoi(record.at(0).c_str()), record.at(2), record.at(3), record.at(4), record.at(5), record.at(6), 
						record.at(7), atof(record.at(8).c_str()),  atof(record.at(9).c_str()),atof(record.at(10).c_str()), atoi(record.at(11).c_str()), record.at(12),record.at(13),
						 atoi(record.at(14).c_str()), record.at(15), record.at(16), atoi(record.at(1).c_str()));

                    //Une fois fait sauvegarder enreg dans resultat
					resultat.push_back(enreg);

            }
        }
		 	// commit
		 	
		 sqlite3_finalize(stmt);
    }
    return resultat;
}

vector<Enregistrement*> obtenirListeDesLampadairesProches(double latitude,double longitude, double altitude)
{


}


std::vector<Enregistrement> BDD::obtenirDonneesEnregistrement(double latitude,double longitude,double altitude)
{
   /*char* req = "SELECT * FROM Enregistrements WHERE latitude BETWEEN "+(latitude - 0.00005)+" AND "+(latitude + 0.00005)+" AND longitude BETWEEN "+(longitude - 0.00005)+ " AND " +(latitude + 0.0005);
   return selectData(req);*/
   //Fait appel a la methode plus haut
}

Enregistrement BDD::obtenirDonneesEnregistrement(string aLatitude, string aLongitude, string aAltitude)
{

}


Enregistrement* BDD::sauvegarderDonneesEnregistrement(Enregistrement *enregistrement,string identifiantCollecteur) //test unitaire
{

	char *zErrMsg = 0;
	int  rc;
	string typeA;
  	string typeL;
	string hauteur;
	int ULOR;
	int puissance;
	string  albedo;
	string fluxLum;
	int nbrePhotos;
	char date [7];
	char heure;
	char longitude[10];
	char latitude[10];
        char altitude[4];
	//string identifiantE;
	string  agglomeration;
	string  rue;
	string notes;



	enregistrement->getLampadaire(typeL,hauteur,ULOR,albedo);
	enregistrement->getAmpoule(typeA,fluxLum,puissance);
	enregistrement->getGalerie(nbrePhotos);
	enregistrement->getHorodatage(date);
    string laDate=string(date,6);

    enregistrement->getGeolocalisation(latitude,longitude,altitude);

    string laLongitude=string(longitude);

    string laLatitude=string(latitude);
    
    string laAltitude=string(altitude);


	agglomeration = enregistrement->getAgglomeration();
	rue = enregistrement->getRue();
	notes=enregistrement->getNotes();

	/*---------------------------------*/

	sqlite3_stmt *stmt;
	const char *pzTest;

	std::string sql="INSERT INTO Enregistrements(power,albedo,flux,buboid,lamp,streetlight,height,latitude,longitude,altitude,nbimages,town,street,ulor,date,notes) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
	rc = sqlite3_prepare(db, sql.c_str(), sql.length(), &stmt, &pzTest);

	if( rc == SQLITE_OK ) 
	{
			// bind the value
		sqlite3_bind_int(stmt, 1, puissance); 
		sqlite3_bind_text(stmt, 2, albedo.c_str(),albedo.length(), 0);
		sqlite3_bind_text(stmt, 3, fluxLum.c_str(),fluxLum.length(),0);
		sqlite3_bind_text(stmt, 4, identifiantCollecteur.c_str(), identifiantCollecteur.length(), 0);
		sqlite3_bind_text(stmt, 5, typeA.c_str(), typeA.length(), 0);
		sqlite3_bind_text(stmt, 6, typeL.c_str(), typeL.length(), 0);
		sqlite3_bind_text(stmt,7, hauteur.c_str(),hauteur.length(), 0);
		sqlite3_bind_text(stmt, 8,laLatitude.c_str(), laLatitude.length(), 0);
		sqlite3_bind_text(stmt, 9,laLongitude.c_str(), laLongitude.length(), 0);
                sqlite3_bind_text(stmt, 10,laAltitude.c_str(), laAltitude.length(), 0);
		sqlite3_bind_int(stmt, 11, nbrePhotos);
		sqlite3_bind_text(stmt, 12 ,agglomeration.c_str(), agglomeration.length(), 0);
		sqlite3_bind_text(stmt, 13 ,rue.c_str(), rue.length(), 0);
		sqlite3_bind_int(stmt, 14, ULOR);
		sqlite3_bind_text(stmt,15, laDate.c_str(), 6, 0);
		sqlite3_bind_text(stmt,16, notes.c_str(), notes.length(), 0);

		// commit
		sqlite3_step(stmt);
//		 	sqlite3_finalize(stmt);
	}
	sqlite3_finalize(stmt);

/// Recherche du dernier enregistrement cr�� pour rafra�chissement automatique
    sql = "SELECT * FROM Enregistrements ORDER BY ID DESC LIMIT 1  ";
    rc = sqlite3_prepare_v2(db,sql.c_str(), sql.length() ,&stmt,NULL);			//|prepare la requete

    if(!rc)
    {
        int nbColonne=sqlite3_column_count(stmt);
        //recuperation d'une ligne
        rc = sqlite3_step(stmt);

        if(rc == SQLITE_ROW)
        {
            vector<string> record;
            for(int i = 0; i < nbColonne; i++)
            {
                if (sqlite3_column_text(stmt, i)) 
					record.push_back((char*)sqlite3_column_text(stmt,i));
                else record.push_back(" ");
            }
            // Mettre les valeurs dans l'objet enreg
           enregistrement = new Enregistrement(atoi(record.at(0).c_str()),record.at(2),record.at(3),record.at(4),record.at(5),record.at(6),record.at(7),atof(record.at(8).c_str()),atof(record.at(9).c_str()),atof(record.at(10).c_str()),atoi (record.at(11).c_str()),record.at(12),record.at(13),atoi(record.at(14).c_str()), record.at(15),record.at(16),atoi(record.at(1).c_str()));
        }
    }
    	sqlite3_finalize(stmt);
    	sqlite3_close(db);

	
		return enregistrement;

}


void  BDD::execute(string requetesql)
{
	string mon_fichier = "/home/pi/testBDD.txt";
    ofstream fichier(mon_fichier.c_str(),  ios::out | ios::app  );
	char* messageError;
	int rc = sqlite3_exec(db, requetesql.c_str(), NULL, 0, &messageError);

	if(rc != SQLITE_OK)
	{
        	fichier << requetesql<< "SQL error: "<< messageError<<endl;
		sqlite3_free(messageError);
	}

	else
	{
		fichier << requetesql << "executed successfully "<<endl;
	}
}



void BDD::modifierEnregistrement(int id, int puissance, string albedo, string fluxLum, string idRaspbery, string typeAmpoule, string typeLampadaire, string hauteur, double latitude, double longitude,double altitude, int nbImages, string agglo, string rue , int ulor, string date, string notes)
{

	sqlite3_stmt *stmt;
    const char *pzTest;

			string mon_fichier = "/home/pi/testBDD.txt";
    ofstream fichier(mon_fichier.c_str(),  ios::out | ios::app  );
	std :: string sql = "UPDATE Enregistrements SET power=?, albedo=?, flux=? , buboid=?, lamp=?, streetlight=?, height=?, latitude=?, longitude=?,altitude=?, nbimages=?, town=?, street=?, ulor=?, date=?, notes=? where id=?";
 
	int rc = sqlite3_prepare(db,sql.c_str(), sql.length(), &stmt, &pzTest);
			fichier<<"after sqlite3_prepare "<<sqlite3_errmsg(db)<<endl;
	if ( rc == SQLITE_OK) {

	sqlite3_bind_int(stmt,1,puissance);
        sqlite3_bind_text(stmt,2,albedo.c_str(),albedo.length(),0);
        sqlite3_bind_text(stmt,3,fluxLum.c_str(),fluxLum.length(),0);
        sqlite3_bind_text(stmt,4,idRaspbery.c_str(),idRaspbery.length(),0);
        sqlite3_bind_text(stmt,5,typeAmpoule.c_str(),typeAmpoule.length(),0);
        sqlite3_bind_text(stmt,6,typeLampadaire.c_str(),typeLampadaire.length(),0);
        sqlite3_bind_text(stmt,7,hauteur.c_str(),hauteur.length(),0);
        sqlite3_bind_double(stmt,8,latitude);
        sqlite3_bind_double(stmt,9,longitude);
        sqlite3_bind_double(stmt,10,altitude);
        sqlite3_bind_int(stmt,11,nbImages);
        sqlite3_bind_text(stmt,12,agglo.c_str(),agglo.length(),0);
        sqlite3_bind_text(stmt,13,rue.c_str(),rue.length(),0);
        sqlite3_bind_int(stmt,14,ulor);
        sqlite3_bind_text(stmt,15,date.c_str(),6,0);
        sqlite3_bind_text(stmt,16,notes.c_str(),notes.length(),0);
        sqlite3_bind_int(stmt,17,id);


        rc =sqlite3_step(stmt);
		fichier<<"after step "<<sqlite3_errmsg(db)<<endl;
        rc=sqlite3_finalize(stmt);
		fichier<<"after sqlite3_finalize "<<sqlite3_errmsg(db)<<endl;
     }
     sqlite3_close(db);
}


void BDD::supprimerEnregistrement(int id){
    std::string requetesql = "DELETE FROM Enregistrements WHERE id=?";
	sqlite3_stmt *stmt;
    const char *pzTest;
	string mon_fichier = "/home/pi/testBDD.txt";
    ofstream fichier(mon_fichier.c_str(),  ios::out | ios::app  );	 
	int rc = sqlite3_prepare(db,requetesql.c_str(), requetesql.length(), &stmt, &pzTest);
			fichier<<"after DELETE sqlite3_prepare "<<sqlite3_errmsg(db)<<endl;
	if ( rc == SQLITE_OK) {

		sqlite3_bind_int(stmt,1,id);
        rc =sqlite3_step(stmt);
		fichier<<"after DELETE step "<<sqlite3_errmsg(db)<<endl;
        rc=sqlite3_finalize(stmt);
		fichier<<"after DELETE sqlite3_finalize "<<sqlite3_errmsg(db)<<endl;
      }
        sqlite3_close(db);
        //execute(requetesql);
}

bool BDD::viderTable(){
    std::string requetesql = "DROP TABLE IF EXISTS Enregistrements";
	sqlite3_stmt *stmt;
    char *zErrMsg = 0;
	string mon_fichier = "/home/pi/testBDD.txt";
    ofstream fichier(mon_fichier.c_str(),  ios::out | ios::app  );	 
	int rc = sqlite3_exec(db, requetesql.c_str(), NULL, 0, &zErrMsg);
	if( rc != SQLITE_OK ){
			fichier<<"DROP TABLE IF EXISTS  sqlite3_exec "<<zErrMsg<<endl;
			sqlite3_free(zErrMsg);
			sqlite3_close(db);
			return false;
	}
     sqlite3_close(db);
	 return true;
}

BDD::BDD()
{
	//Chemin d'accés a la base de données
	_baseDeDonnees="/home/pi/bdd/Enregistrement.db";
	int rc;
	char * zErrMsg;

	/*Ouverture d'un accés a la base de données via son chemin d'accés
	* Si le fichier n'existe pas, la fonction sqlite3_open crée une
	* autre base avec ce nom
	*/
	rc = sqlite3_open(_baseDeDonnees.c_str(), &db);
   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));

   }
   else{
      //fprintf(stdout, "Opened database successfully\n");

	sqlite3_stmt *statement; 
	string selectSql = "SELECT * FROM Enregistrements";
	sqlite3_prepare_v2(db,selectSql.c_str(), selectSql.length() ,&statement, NULL);
		int countColumn= sqlite3_column_count(statement);
	if(!countColumn)
		{
			std::string selectSql ="CREATE TABLE IF NOT EXISTS Enregistrements(id  INTEGER PRIMARY KEY AUTOINCREMENT  ,power INTEGER, albedo REAL,flux REAL, buboid TEXT NOT NULL,lamp TEXT  ,streetlight TEXT ,height REAL,latitude REAL NOT NULL,longitude REAL NOT NULL,altitude REAL NOT NULL,nbimages int ,town TEXT,street TEXT,ulor INTEGER, date TEXT, notes TEXT );";
			//Crée une table appelée Enregistrements qui a comme parametres toutes les données liées a l'enregistrement si elle existe pas deja.
			 rc = sqlite3_exec(db, selectSql.c_str(), NULL, 0, &zErrMsg);
			 if( rc != SQLITE_OK ){
				fprintf(stderr, "SQL error: %s\n", zErrMsg);
				sqlite3_free(zErrMsg);
			}
        }
	}
}


BDD::~BDD(){
    sqlite3_close(db);
}

//vector<Enregistrement> BDD::obtenirListeDesEnregistrements() {
//	throw "Not yet implemented";
//}
//
//Enregistrement BDD::obtenirDonneesEnregistrement(string aLatitude, string aLongitude) {
//	throw "Not yet implemented";
//}
//
//void BDD::supprimer(int aId) {
//	throw "Not yet implemented";
//}
//
//vector<Enregistrement> BDD::sauverDonneesEnregistrement(Enregistrement aEnregistrement) {
//	throw "Not yet implemented";
//}
//
//void BDD::modifierEnregistrement(Enregistrement aEnregistrement) {
//	throw "Not yet implemented";
//}
//
//void BDD::execute(char* aRequetesql) {
//	throw "Not yet implemented";
//}
//
//vector<Enregistrement> BDD::selectData(char* aRequetesql) {
//	throw "Not yet implemented";
//}
//BDD::BDD() {
//	//Chemin d'acc�s � la base de donn�es
//	_baseDeDonnees="/home/pi/Documents/Enregistrement.db";
//	int rc;
//	char * zErrMsg;
//
//	/*Ouverture d'un acc�s � la base de donn�es via son chemin d'acc�s
//	* Si le fichier n'existe pas, la fonction sqlite3_open cr�� une
//	* autre base avec ce nom
//	*/
//	rc = sqlite3_open(_baseDeDonnees.c_str(), &db);
//   if( rc ){
//      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
//
//   }else{
//      fprintf(stdout, "Opened database successfully\n");
//   }
//	sqlite3_stmt *statement; 
//	string selectSql = "SELECT title FROM list";
//	sqlite3_prepare_v2(db,selectSql.c_str(), -1, &statement, NULL);
//	int countColumn = sqlite3_column_count(statement);
//	if (!countColumn)
//	{
//		 selectSql= " CREATE TABLE IF NOT EXISTS SRCLUMI(" 
//		"ID INTEGER PRIMARY   KEY  AUTOINCREMENT,"
//		"IDENREGISTREMENT TEXT NOT NULL,"
//		"IDCOLLECTEUR TEXT NOT NULL,"
//		"LATITUDE REAL NOT NULL ,"
//		"LONGITUDE REAL NOT NULL,"
//		"LAMPTYPE TEXT  ,"
//		"ULOR INTEGER ,"
//		"AMPTYPE TEXT  ,"
//		"HAUTEUR FLOAT ,"
//		"PUISSANCE INTEGER ,"
//		"ALBEDO REAL  ,"
//		"AGGLOMERATION TEXT,"
//		"RUE TEXT,"
//		"NOTES TEXT,"
//		"FLUXLUM REAL ,"
//		"DATE TEXT ,"		
//		"NBIMAGES INT DEFAULT '0'); " ;	
//		 rc = sqlite3_exec(db, selectSql.c_str(), NULL, 0, &zErrMsg);
//		 if( rc != SQLITE_OK ){
//		fprintf(stderr, "SQL error: %s\n", zErrMsg);
//		sqlite3_free(zErrMsg);
//		}else{
//		fprintf(stdout, "Table created successfully\n");
//		}
//
//	}
//}

