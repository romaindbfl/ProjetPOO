#include "header/joueur.hpp"

// Constructeur par défaut
Joueur::Joueur() : nom('1'), main_index(0)
{
    scores[0] = 0;
    scores[1] = 0;
    mise = 0;
    mise_depart = 100;
}

void Joueur::ajouter_carte(const Carte &carte)
{
    ajouter_carte(carte, main_index);
}

int Joueur::get_mise_depart() const
{
    return mise_depart;
}

void Joueur::set_mise_depart(int rajout)
{
    mise_depart += rajout * 1.5;
}

void Joueur::set_mise_departJeu(int perte)
{
    mise_depart -= perte;
}

void Joueur::ajouter_carte(const Carte &carte, int index)
{
    mains[index].push_back(carte);
    scores[index] += carte.get_valeur();
}

void Joueur::afficher_main() const
{
    afficher_main(main_index);
}

void Joueur::afficher_main(int index) const
{
    for (const auto &carte : mains[index])
    {
        carte.afficher();
    }
    cout << endl;
}

void Joueur::afficher_main_groupier() const
{
    mains[0].front().afficher();
}

int Joueur::get_score() const
{
    return get_score(main_index);
}

int Joueur::get_score(int index) const
{
    int score = 0;
    for (const auto &carte : mains[index])
    {
        int valeur = carte.get_valeur();
        score += valeur;
    }
    return score;
}

void Joueur::set_score(int score, int index)
{
    scores[index] = score;
}

char Joueur::get_nom() const
{
    return nom;
}

bool Joueur::peut_split() const
{
    return mains[0].size() == 2 && mains[0][0].get_valeur() == mains[0][1].get_valeur();
}

void Joueur::set_main_index(int index)
{
    main_index = index;
}

int Joueur::get_main_index() const
{
    return main_index;
}

int Joueur::get_mise() const
{
    return mise;
}

void Joueur::set_mise(int mise)
{
    this->mise = mise;
}

void Joueur::vider_main()
{
    for (auto &main : mains)
    {
        main.clear();
    }
    scores[0] = 0;
    scores[1] = 0;
    main_index = 0;
}

Joueur Joueur::split()
{
    Joueur new_joueur;
    new_joueur.ajouter_carte(mains[0].back(), 0);
    mains[0].pop_back();
    scores[0] = mains[0][0].get_valeur(); // Met à jour le score après le split
    new_joueur.set_mise(mise);            // Le nouveau joueur a la même mise de départ

    return new_joueur;
}
