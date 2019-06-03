/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: snir2g2
 *
 * Created on 3 juin 2019, 11:09
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
    unmail->envoimail();

    
    return 0;
}
