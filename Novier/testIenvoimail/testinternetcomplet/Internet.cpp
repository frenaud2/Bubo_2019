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
    //int stdrbis=dup(2);
    //close(2);
    //dup(1);

    if (!(output = popen("ping -w100  -c2 8.8.8.8", "r"))) {
        erreur = 1;
    }
    //close(2);
    //dup(stdrbis);
    return erreur;

}

void Internet::testinternet() {
    unsigned int i;
    char toto[300];
    //int stdrbis = dup(2);
    //close(2);
    //dup(1);
    this->pinginternet();
    std::string message("nreachable");
    // %C car trame contient des espaces
    i = fscanf(output, "%250c", toto);
    string toto1 = toto;
    //cout<<toto1<<endl;
    std::size_t found = toto1.find(message);
    cout << "position atteinte =" << found << ", position max = " << std::string::npos << endl;
    //close(2);
    //dup(stdrbis);
    //si on parcours toto1 sans trouver "destination *****" alors found=npos
    if (found != std::string::npos || toto1 =="") {
        cout << "la connection internet ne fonctionne pas" << endl;
    } else {
        cout << "la connection internet fonctionne " << endl;
    }
    pclose(output);
}

