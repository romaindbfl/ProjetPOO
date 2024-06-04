#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include "carte.hpp"
#include <vector>

class Joueur
{
protected:
    vector<Carte> mains[2];
    int scores[2];
    char nom;
    int main_index;
    int mise;
    int mise_depart;

public:
    Joueur();
    void ajouter_carte(const Carte &carte);
    void ajouter_carte(const Carte &carte, int index);
    void afficher_main() const;
    void afficher_main(int index) const;
    int get_score() const;
    int get_score(int index) const;
    void set_score(int score, int index);
    char get_nom() const;
    void afficher_main_groupier() const;
    bool peut_split() const;
    void set_main_index(int index);
    int get_main_index() const;
    int get_mise() const;
    void set_mise(int mise);
    int get_mise_depart() const;
    void set_mise_depart(int rajout);
    void set_mise_departJeu(int perte);
    void vider_main();
};

#endif
