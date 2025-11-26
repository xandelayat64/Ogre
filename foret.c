//
// Created by Xan Delayat on 19/11/2025.
//

#include "foret.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "enfant.h"

#define FORET_SOL ' '         //no tree at this position

void afficherForet(Foret foret, Enfants enfants, Ogre *ogre) {
    int x, y;
    system("CLS");      //clear la console avant de procéder à l'affichage

    //affichage de tout les éléments
    for(y=0; y < FORET_HAUTEUR; y++){
        for(x=0; x < FORET_LONGUEUR; x++) {
            if (ogrePresent(ogre, x, y)) {
                printf("%c", FORET_OGRE);      //si ogre à x,y pos. l'afficher
            } else {
                Enfant *enfant = enfantPresent(enfants, x, y);
                if (enfant == NULL) {                   //si enfant non existant à cette case
                    printf("%c", foret[y][x]);      //si pas d'enfant à x,y pos. afficher un arbre
                } else {
                    if ((*enfant).etat == MORT) {         //si enfant == MORT afficher la tombe
                        printf("%c", FORET_MORT);
                    } else {
                        printf("%c", FORET_ENFANT);         //sinon afficher enfant
                }
            }
        }
        }
        printf("\n");
    }
}

void initialiserForet(Foret foret) {
    int h, l;
    int randomGen;
    srand(time(NULL));

    //affichage des limites de la forêt + sol de la forêt
    for (int h = 0; h < FORET_HAUTEUR; h++) {
        for (int l = 0; l < FORET_LONGUEUR; l++) {
            if (h == 0 || l == 0 || h == FORET_HAUTEUR - 1 || l == FORET_LONGUEUR - 1 || rand() % FORET_DENSITE == 0) {
                foret[h][l] = FORET_ARBRE;
            }
            else {
                foret[h][l] = FORET_SOL;
            }
            }
        }
    }

//Afficher toutes les modif à chaque instant (boucle infinie => animation)
void faireVivreForet(Enfants enfants, Foret foret, Ogre *ogre) {
    while (1) {
        afficherForet(foret, enfants, ogre);
        deplacerEnfants(enfants, foret);
        deplacerOgre(ogre, foret, enfants);
    }
}
