#ifndef REGLE_HPP
#define REGLE_HPP

#include <iostream>
#include "joueur.hpp"
#include "groupier.hpp"
#include "jeu.hpp"

class Regle : public Joueur, public Groupier
{
public:
    void joueur_bust(Joueur &joueur, Groupier &groupier);
    void tour_groupier(Groupier &groupier, Joueur &joueur);
    void groupier_bust(Groupier &groupier, Joueur &joueur);
    void Gagnant(Joueur &joueur, Groupier &groupier);
    void rejouer(Joueur &joueur, Groupier &groupier);
    void main1gagnant(Joueur &joueur, Groupier &groupier);
    void main2gagnant(Joueur &joueur, Groupier &groupier, Joueur &joueur_split);
    void misevalable(Joueur &joueur);
};

#endif