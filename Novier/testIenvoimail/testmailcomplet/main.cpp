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
#include "parsexml.h"
#include "Config.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Mail* unmail = new Mail();
    for (int i=0;i<2;i++){
    unmail->envoimail();
    }

    
    return 0;
}

