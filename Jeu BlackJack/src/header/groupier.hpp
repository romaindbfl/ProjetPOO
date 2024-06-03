#ifndef GROUPIER_HPP
#define GROUPIER_HPP

#include <cstdlib>
#include <ctime>
#include "joueur.hpp"
#include "carte.hpp"
#include <vector>

class Groupier : public Joueur
{
public:
    Groupier();
    void distribuer_cartes(Joueur &joueur, int nombre_de_cartes);
};

#endif
