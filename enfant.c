//
// Created by Xan Delayat on 26/11/2025.
//

#include "enfant.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "enfant.h"

//initialiser tout les enfants à des positions différentes chacun
void initialiserEnfants(Enfants enfants, Foret foret) {
    int i;
    for (i=0; i < NOMBRE_ENFANTS; i++) {
        initialiserEnfant(&enfants[i], foret);
    }
}

//initialiser un enfant à une position au hasard
void initialiserEnfant(Enfant *enfant, Foret foret){
    int x, y;
    do {
        x = rand()%FORET_LONGUEUR;
        y = rand()%FORET_HAUTEUR;
    } while(foret[y][x] != FORET_SOL);
    (*enfant).x = x;
    (*enfant).y = y;
    (*enfant).etat = VIVANT;
}

//Verification si il y a un enfant présent sur une case
Enfant *enfantPresent(Enfants enfants, int x, int y) {
    int i = 0;
    while( ((enfants[i].x != x) || (enfants[i].y != y)) && (i < NOMBRE_ENFANTS) ) {
        i++;
    }
    if (i >= NOMBRE_ENFANTS) {
        return NULL;
    } else {
        return &enfants[i];
    }
}

//déplacer les enfants sur l'affichage si ils sont vivants et grâce à initialiserEnfant()
void deplacerEnfants(Enfants enfants, Foret foret) {
    int i;
    for (i=0; i < NOMBRE_ENFANTS; i++) {
        if (enfants[i].etat == VIVANT) {
            initialiserEnfant(&enfants[i], foret);
        }
    }
}

//déplacer les enfants au niveau des coordonnées, vérif si obstacle ou pas, si oui recharge une valeur random
void deplacerEnfant(Enfant *enfant, Foret foret) {
    int x, y;

    Orientation orientation;
    orientation = rand() % 4;

    //(*enfant).x = x;
    //(*enfant).y = y;

    x = (*enfant).x;
    y = (*enfant).y;

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

    if (foret[y][x] != FORET_SOL) {
        (*enfant).x = x;
        (*enfant).y = y;
    }
}
