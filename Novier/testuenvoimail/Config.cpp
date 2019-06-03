/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   config.cpp
 * Author: snir2g2
 * 
 * Created on 16 avril 2019, 17:17
 */

#include "Config.h"

    Config::Config() {
}

Config::Config(const Config& orig) {
}

Config::~Config() {
}

void Config::lirevaleurattributs()
{
    cout<<"donner l'adresse du destinataire"<<endl;
    cin>>destinataire;
    cout<<"donner l'adresse de l'expéditeur"<<endl;
    cin>>expediteur;
    cout<<"donner l'adresse du client de messagerie utilisé"<<endl;
    cin>>clientmessagerie;
    cout<<"donner le port utilisé"<<endl;
    cin>>port;
    cout<<"donner le nom de compte utilisé"<<endl;
    cin>>nomdecompte;
    cout<<"donner le mot de passe utilisé"<<endl;
    cin>>motdepasse;
    cout<<"donner le sujet du mail"<<endl;
    cin>>sujet;
}
string Config::getdestinataire()
{
    return this->destinataire;
}
string Config::getclientmessagerie()
{
    return this->clientmessagerie;
}
string Config::getexpediteur()
{
    return this->expediteur;
}
int Config::getport()
{
    return this->port;
}
string Config::getnomdecompte()
{
    return this->nomdecompte;
}
string Config::getmotdepasse()
{
    return this->motdepasse;
}
string Config::getsujet()
{
    return this->sujet;
}
string Config::getnomfichierbdd()
{
    return this->nomfichierbdd;
}
string Config::getlienbdd()
{
    return this->lienbdd;
}
