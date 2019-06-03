/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: snir2g2
 *
 * Created on 18 avril 2019, 13:39
 */

#include <cstdlib>

#include "Internet.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Internet* uninternet = new Internet();
    if (uninternet->testinternet())
    {
        cout <<"la connexion internet fonctionne"<<endl;
    }
    else 
    {
        cout <<"la connexion internet ne fonctionne pas"<<endl;
    }
            
    return 0;
}

