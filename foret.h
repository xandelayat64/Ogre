//
// Created by Xan Delayat on 19/11/2025.
//

#include "ogreboulotteur.h"
#include "ogre.h"
#include "enfant.h"

#ifndef FORET_H_INCLUDED
#define FORET_H_INCLUDED


void afficherForet(Foret foret, Enfants enfants, Ogre *ogre);
void initialiserForet(Foret foret);
void faireVivreForet(Enfants enfants, Foret foret, Ogre *ogre);

#endif // FORET_H_INCLUDED
