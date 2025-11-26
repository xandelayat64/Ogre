#include <stdio.h>
#include <stdlib.h>

#include "foret.h"

int main(void) {

    //initialisations éléments
    Foret foret;
    Enfants enfants;
    Ogre ogre;

    //affichage de la carte
    initialiserForet(foret);
    initialiserOgre(&ogre, foret);
    initialiserEnfants(enfants, foret);
    faireVivreForet(enfants, foret, &ogre);

    system("pause");    //pause the external console, any button to exit

    return 0;
}

