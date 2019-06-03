 /*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Internet.cpp
 * Author: snir2g2
 * 
 * Created on 18 avril 2019, 13:40
 */

#include "Internet.h"

Internet::Internet() {
}

Internet::Internet(const Internet& orig) {
}

Internet::~Internet() {
}

int Internet::pinginternet() {
    int erreur = 0;
	// lance la commande puis ouvre un tube -w100 pour le timeout et -c2 pour recevoir 2 reponse
    if (!(output = popen("ping -w100  -c2 8.8.8.8", "r"))) {
        erreur = 1;
    }
    return erreur;

}

bool Internet::testinternet() {
    unsigned int i;
    char donnee[300];
    
    this->pinginternet();
    std::string message("nreachable");
    // %C car trame contient des espaces
    // on lit les 250 premiers caractères et on les mets dans la variables donnee
    i = fscanf(output, "%250c", donnee);
    string donnee1 = donnee;
    //cout<<toto1<<endl;
    std::size_t found = donnee1.find(message);
    //si on parcours toto1 sans trouver "nreachable" alors found=npos
    if (found != std::string::npos || donnee1 =="") {
        return false;
    } else {
        return true;
    }
    pclose(output);
}

