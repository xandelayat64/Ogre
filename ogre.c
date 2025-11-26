//
// Created by Xan Delayat on 26/11/2025.
//

#include "ogre.h"
#include <stdlib.h>
#include <time.h>

//même principe que pour les Enfants mais pour 1 ogre

inline void initialiserOgre(Ogre *ogre, Foret foret) {
    int x, y;
    do {
        x = rand()%FORET_LONGUEUR;
        y = rand()%FORET_HAUTEUR;
    } while(foret[y][x] != FORET_SOL);
    (*ogre).x = x;
    (*ogre).y = y;
}

void deplacerOgre(Ogre *ogre, Foret foret, Enfant *enfant) {
    int x, y;

    Orientation orientation;
    orientation = rand() % 4;

    x = (*ogre).x;
    y = (*ogre).y;

    switch (orientation) {
        case HAUT: y--;
            break;
        case DROITE: x++;
            break;
        case BAS: y++;
            break;
        case GAUCHE: x--;
            break;
    }

    if (foret[y][x] == FORET_SOL) {
        (*ogre).x = x;
        (*ogre).y = y;
        boulotterEnfants(ogre, enfant);
    }
}

Ogre * ogrePresent(Ogre *ogre, int x, int y) {
    if ( ((*ogre).x != x) || ((*ogre).y != y)){
        return NULL;
    }
    else {
        return ogre;
    }
}

//si l'ogre est sur la même cas qu'un enfant
//et que l'enfant est vivant => enfant == MORT
void boulotterEnfants(Ogre *ogre, Enfants enfants) {
    for (int i = 0; i < NOMBRE_ENFANTS; i++) {
        if ((*ogre).x == enfants[i].x && (*ogre).y == enfants[i].y && enfants[i].etat == VIVANT) {
            enfants[i].etat = MORT;
        }
    }
}