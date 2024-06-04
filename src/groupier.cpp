#include "header/groupier.hpp"
#include <cstdlib> // pour rand() et srand()
#include <ctime>   // pour time()

// Constructeur par defaut
Groupier::Groupier() : Joueur()
{
    this->nom = 'G'; // Par exemple, pour le groupier
    srand(time(0));  // Initialisation du generateur de nombres aleatoires
}

void Groupier::distribuer_cartes(Joueur &joueur, int nombre_de_cartes)
{
    for (int i = 0; i < nombre_de_cartes; ++i)
    {
        // Exemple simple : distribuer une carte aleatoire au joueur
        int choix = rand() % 13 + 1;
        char symbole;

        switch (choix)
        {
        case 1:
            symbole = 'A';
            if (joueur.get_score() + 11 <= 21)
            {
                choix = 11;

            }
            else
            {
                choix = 1;
            }
            break;
        case 10: // Si le choix est 10, utiliser le symbole 'X' pour le 10
            symbole = 'X';
            break;
        case 11:
            symbole = 'V';
            choix = 10;
            break;
        case 12:
            symbole = 'Q';
            choix = 10;
            break;
        case 13:
            symbole = 'K';
            choix = 10;
            break;
        default:
            symbole = '0' + choix; // pour les cartes de 2 à 9
        }

        Carte nouvelle_carte(choix, symbole);
        joueur.ajouter_carte(nouvelle_carte);

        // Afficher le message si c'est le joueur qui tire la carte
        if (joueur.get_nom() != 'G')
        {
            cout << "Vous avez tire un " << symbole << "." << endl;
        }
    }
}
