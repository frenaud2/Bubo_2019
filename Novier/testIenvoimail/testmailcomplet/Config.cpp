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
    AbstractConfiguration *cfg = new XMLConfiguration("mail.xml");
    destinataire = cfg->getString("destinataire");
    expediteur = cfg->getString("expediteur");
    clientmessagerie = cfg->getString("clientmessagerie");
    port = cfg->getInt("port");
    nomdecompte = cfg->getString("nomdecompte");
    motdepasse = cfg->getString("motdepasse");
    sujet= cfg->getString("sujet");
    nomfichierbdd=cfg->getString("nomfichierbdd");
    lienbdd=cfg->getString("lienbdd");
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