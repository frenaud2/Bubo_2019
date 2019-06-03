#ifndef CONFIG_H
#define CONFIG_H
#include <iostream>
#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <Poco/Util/XMLConfiguration.h>
using namespace Poco::Util;
using namespace std;
class Config {
public:
    Config();
    Config(const Config& orig);
    virtual ~Config();
    string getdestinataire();
    string getexpediteur();
    string getclientmessagerie();
    int getport();
    string getnomdecompte();
    string getmotdepasse();
    string getsujet();
    string getlienbdd();
    string getnomfichierbdd();
    void lirevaleurattributs();
    
private:
    string destinataire;
    string expediteur;
    string clientmessagerie;
    int port;
    string nomdecompte;
    string motdepasse;
    string sujet;
    string lienbdd="/home/snir2g2/Bureau/Enregistrement.db";
    string nomfichierbdd ="Enregistrement.db";
};

#endif /* CONFIG_H */

