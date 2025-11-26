//
// Created by Xan Delayat on 26/11/2025.
//

#ifndef OGRE_OGRE_H
#define OGRE_OGRE_H

#include "ogreboulotteur.h"

void initialiserOgre(Ogre *ogre, Foret foret);
void deplacerOgre(Ogre *ogre, Foret foret, Enfant *enfant);
Ogre *ogrePresent(Ogre *ogre , int x, int y);
void boulotterEnfants(Ogre *ogre, Enfants enfants);

#endif //OGRE_OGRE_H