//
// Created by Xan Delayat on 26/11/2025.
//

#ifndef OGRE_OGREBOULOTTEUR_H
#define OGRE_OGREBOULOTTEUR_H

#define FORET_LONGUEUR 40
#define FORET_HAUTEUR 20
#define FORET_SOL ' '
#define FORET_ARBRE '♣'         //ASCII: 5
#define FORET_DENSITE 10
#define NOMBRE_ENFANTS 10
#define FORET_ENFANT 'O' //'☺'      //ASCII: 1
#define FORET_OGRE 'X'   //'☻'      //ASCII: 2
#define FORET_MORT '+'

typedef char Foret[FORET_HAUTEUR][FORET_LONGUEUR];

typedef enum Etat {VIVANT, MORT} Etat;

typedef struct Enfant {
    int x, y;
    Etat etat;
} Enfant;

typedef Enfant Enfants[NOMBRE_ENFANTS];

typedef enum Orientation {HAUT, DROITE, BAS, GAUCHE} Orientation;

typedef struct Ogre {
    int x, y;
} Ogre;

#endif //OGRE_OGREBOULOTTEUR_H