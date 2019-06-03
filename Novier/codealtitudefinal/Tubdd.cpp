

#include <cstdlib>
#include "BDD.h"
using namespace std;

/*
 * 
 */
int main() {
    Enregistrement* unEnregistrement= new Enregistrement("0.3","300.0","000000002ed09bce","Incandescence","Projecteur sur mat","5.0",43.614468,1.3054,43.21,0,"Colomiers","rue des coquelicots",15,"2505","pasdenote",230);
    BDD* uneBDD = new BDD();
    uneBDD->sauvegarderDonneesEnregistrement(unEnregistrement,"1234567899");
    
    return 0;
}

