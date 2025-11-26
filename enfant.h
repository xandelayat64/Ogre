//
// Created by Xan Delayat on 26/11/2025.
//

#ifndef ENFANT_H_INCLUDED
#define ENFANT_H_INCLUDED

#include "ogreboulotteur.h"
void initialiserEnfants(Enfants enfants, Foret foret);
void initialiserEnfant(Enfant *enfant, Foret foret);
Enfant *enfantPresent(Enfants enfants, int x, int y);
void deplacerEnfants(Enfants enfants, Foret foret);
void deplacerEnfant(Enfant *enfant, Foret foret);

#endif // ENFANT_H_INCLUDED