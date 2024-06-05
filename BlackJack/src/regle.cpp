#include "header/regle.hpp"

void Regle::misevalable(Joueur &joueur)
{
    int mise;
    if (joueur.get_mise_depart() == 0)
    {
        system("cls");
        cout << "Vous n'avez plus d'argent a miser." << endl;
        exit(0);
    }
    else
    { // Affichage des gains de depart
        cout << "Vos gains de depart sont de " << joueur.get_mise_depart() << " euros.\n"
             << endl;

        cout << "Quelle est votre mise de depart ?" << endl;
        cin >> mise;
        if (mise < 5 || mise > 300)
        {
            system("cls");
            cout << "La mise doit etre comprise entre 5 et 300 euros." << endl;
            misevalable(joueur);
        }
        else
        {
            joueur.set_mise(mise);
            cout << "Vous avez choisi de miser " << joueur.get_mise() << " euros." << endl;
            cout << endl;
        }
    }
}

void Regle::joueur_bust(Joueur &joueur, Groupier &groupier)
{
    if (joueur.get_score() > 21)
    {
        cout << "Vous avez depasse 21. Vous avez perdu." << endl;
        joueur.set_mise_departJeu(joueur.get_mise());
        cout << "Vos gains sont maintenant de " << joueur.get_mise_depart() << endl;
        rejouer(joueur, groupier);
    }
}

void Regle::rejouer(Joueur &joueur, Groupier &groupier)
{
    Jeu jeu;
    cout << "Voulez-vous rejouer? (O/N)" << endl;
    char rejouer;
    cin >> rejouer;
    if (rejouer == 'o' || rejouer == 'O')
    {
        system("cls");
        jeu.deroulement_partie(joueur, groupier);
    }
    else
    {
        exit(0);
    }
}

void Regle::tour_groupier(Groupier &groupier, Joueur &joueur)
{
    while (true)
    {
        if (groupier.get_score() >= 17)
        {
            cout << "Le groupier reste." << endl;
            cout << "Score du groupier : " << groupier.get_score() << "\n";
            break;
        }
        else if (groupier.get_score() <= 16)
        {
            cout << "Le groupier tire." << endl;
            groupier.distribuer_cartes(groupier, 1);
            cout << "Score du groupier : " << groupier.get_score() << "\n"
                 << endl;
        }
        groupier_bust(groupier, joueur);
    }
}

void Regle::groupier_bust(Groupier &groupier, Joueur &joueur)
{
    // Si le groupier bust (score superieur à 21), le jeu doit se terminer
    if (groupier.get_score() > 21)
    {
        cout << "Le groupier a depasse 21. Vous avez gagne." << endl;
        joueur.set_mise_depart(joueur.get_mise());
        cout << "Vos gains sont maintenant de " << joueur.get_mise_depart() << endl;
        rejouer(joueur, groupier);
    }
}

void Regle::Gagnant(Joueur &joueur, Groupier &groupier)
{
    if (joueur.get_score() > groupier.get_score())
    {
        cout << endl;
        cout << "Votre score : " << joueur.get_score() << endl;
        cout << "Vous avez gagne." << endl;
        joueur.set_mise_depart(joueur.get_mise());
        cout << "Vos gains sont maintenant de " << joueur.get_mise_depart() << endl;
    }
    else if (groupier.get_score() > joueur.get_score())
    {
        cout << endl;
        cout << "Votre score : " << joueur.get_score() << endl;
        cout << "Le groupier gagne." << endl;
        joueur.set_mise_departJeu(joueur.get_mise());
        cout << "Vos gains sont maintenant de " << joueur.get_mise_depart() << endl;
    }
    else if (groupier.get_score() == joueur.get_score())
    {
        cout << endl;
        cout << "Votre score : " << joueur.get_score() << endl;
        cout << "C'est une egalite." << endl;
        cout << "Vos gains restent inchange." << endl;
    }

    rejouer(joueur, groupier);
}

void Regle::main1gagnant(Joueur &joueur, Groupier &groupier)
{
    if (joueur.get_score() > groupier.get_score())
    {
        cout << "Votre main 1 a gagne." << endl;
        joueur.set_mise_depart(joueur.get_mise());
    }
    else if (groupier.get_score() > joueur.get_score())
    {
        cout << "Votre main 1 a perdu." << endl;
        joueur.set_mise_departJeu(joueur.get_mise());
    }
    else
    {
        cout << "C'est une egalite avec votre main 1." << endl;
    }
}

void Regle::main2gagnant(Joueur &joueur_split, Groupier &groupier, Joueur &joueur)
{

    if (joueur_split.get_score() > groupier.get_score())
    {
        cout << "Votre main 2 a gagne." << endl;
        joueur.set_mise_depart(joueur_split.get_mise());
    }
    else if (groupier.get_score() > joueur_split.get_score())
    {
        cout << "Votre main 2 a perdu." << endl;
        joueur.set_mise_departJeu(joueur_split.get_mise());
    }
    else
    {
        cout << "C'est une egalite avec votre main 2." << endl;
    }
}