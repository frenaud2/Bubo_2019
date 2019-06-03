/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newmain.cpp
 * Author: snir2g2
 *
 * Created on 10 avril 2019, 14:01
 */

#include <cstdlib>
#include "Mail.h"
#include "Config.h"


using namespace std;

/*
 * 
 */
    int main(int argc, char** argv) {
        Mail* unmail = new Mail();
        int tartiflette = unmail->envoimail();
        if  (tartiflette == PBSMTP){
            cout<<"problème Configuration"<<endl;
        }
        if  (tartiflette == FILENOTFOUND){
            cout<<"problème fichier non trouvé"<<endl;
        }
        if  (tartiflette == PASINTERNET){
            cout<<"problème internet"<<endl;
        }
        if  (tartiflette == PBMCLIENTMSG){
            cout<<"problème client messagerie"<<endl;
        }



        return 0;
    }

