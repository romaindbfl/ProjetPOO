#ifndef JEU_HPP
#define JEU_HPP

#include <iostream>
#include "joueur.hpp"
#include "groupier.hpp"
#include "regle.hpp"

void deroulement_partie(Joueur &joueur, Groupier &groupier);
void deroulement_split(Joueur &joueur, Joueur &joueur_split, Groupier &groupier);
void initialisation();

#endif