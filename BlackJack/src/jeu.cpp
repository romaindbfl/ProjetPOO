#include "header/jeu.hpp"

void initialisation()
{ // Creation du joueur et du groupier
    system("cls");
    cout << "Bienvenue dans le jeu de Blackjack!" << endl;
    Joueur joueur;
    Groupier groupier;

    deroulement_partie(joueur, groupier);
}

void deroulement_partie(Joueur &joueur, Groupier &groupier)
{
    Regle regle;
    int choix;

    while (true)
    {

        regle.misevalable(joueur);

        // Réinitialisation des mains du joueur et du groupier
        joueur.vider_main();
        groupier.vider_main();

        // Distribution de cartes
        groupier.distribuer_cartes(joueur, 2);   // Distribue 2 cartes au joueur
        groupier.distribuer_cartes(groupier, 2); // Distribue 2 cartes au groupier

        cout << endl;

        // Affichage des cartes du joueur
        cout << "Main du joueur : " << endl;
        joueur.afficher_main();
        cout << "Score du joueur : " << joueur.get_score() << "\n"
             << endl;

        // Affichage des cartes du groupier
        cout << "Main du groupier : " << endl;
        groupier.afficher_main_groupier();
        cout << endl;

        while (true)
        {
            // Tour du joueur
            cout << "Que souhaitez-vous faire ? (1/2/3/4/5)" << endl;
            cout << "1 - tirer une carte" << endl;
            cout << "2 - Rester" << endl;
            cout << "3 - Doubler votre mise" << endl;
            cout << "4 - Split votre jeu" << endl;
            cout << "5 - Afficher votre main votre score et la carte visible du groupier " << endl;
            cout << "Votre choix : ";
            cin >> choix;

            switch (choix)
            {
            case 1:
                system("cls");
                groupier.distribuer_cartes(joueur, 1); // Distribue 1 carte au joueur
                cout << endl
                     << "Nouvelle main du joueur : " << endl;
                joueur.afficher_main();
                cout << "Nouveau score du joueur : " << joueur.get_score() << endl;
                regle.joueur_bust(joueur, groupier);
                break;
            case 2:
                system("cls");
                cout << "Vous avez decide de rester." << endl;
                break;
            case 3:
                system("cls");
                cout << "Vous avez decide de doubler votre mise" << endl;
                joueur.set_mise(joueur.get_mise() * 2);
                cout << "Votre mise est maintenant de " << joueur.get_mise() << endl;
                groupier.distribuer_cartes(joueur, 1);
                cout << endl
                     << "Nouvelle main du joueur : " << endl;
                joueur.afficher_main();
                cout << "Nouveau score du joueur : " << joueur.get_score() << endl;
                // Si le joueur bust (score superieur à 21), le jeu doit se termine
                regle.joueur_bust(joueur, groupier);
                break;
            case 4:
                system("cls");
                if (joueur.peut_split())
                {
                    cout << "Vous avez split votre main." << endl;
                    Joueur new_joueur = joueur.split();
                    deroulement_split(joueur, new_joueur, groupier);
                }
                else
                {
                    cout << "Vous ne pouvez pas split cette main." << endl;
                    continue;
                }
                break;
            case 5:
                // Affichage des cartes du joueur
                system("cls");
                cout
                    << "Main du joueur : " << endl;
                joueur.afficher_main();
                cout << "Score du joueur : " << joueur.get_score() << "\n"
                     << endl;
                cout << "Mise du joueur : " << joueur.get_mise() << "\n"
                     << endl;
                // Affichage des cartes du groupier
                cout << "Main du groupier : " << endl;
                groupier.afficher_main_groupier();
                cout << endl;
                continue;
            default:
                system("cls");
                cout << "Choix invalide. Veuillez choisir une option valide." << endl;
                continue;
            }

            if (choix == 2 || choix == 3 || choix == 4)
            {
                break;
            }
            system("cls");
        }

        cout << endl;
        // Tour du groupier
        regle.tour_groupier(groupier, joueur);

        // Comparaison des scores pour determiner le gagnant
        regle.Gagnant(joueur, groupier);
    }
}

void deroulement_split(Joueur &joueur, Joueur &joueur_split, Groupier &groupier)
{
    Regle regle;

    cout << endl;
    cout << "Votre premiere main : " << endl;
    joueur.afficher_main();
    cout << "Score de la main 1 : " << joueur.get_score() << endl
         << endl;
    cout << "Mise sur la main 1 : " << joueur.get_mise() << endl
         << endl;
    cout << "Votre deuxieme main : " << endl;
    joueur_split.afficher_main();
    cout << "Score de la main 2 : " << joueur_split.get_score() << endl
         << endl;
    cout << "Mise sur la main 2 : " << joueur_split.get_mise() << endl
         << endl;

    while (true)
    {
        cout << "Que voulez-vous faire? (1/2/3)" << endl;
        cout << "1 - Tirer une carte" << endl;
        cout << "2 - Rester" << endl;
        cout << "3 - Afficher vos mains et celle du groupier" << endl;
        cout << "Votre choix : ";
        int choix;
        cin >> choix;

        switch (choix)
        {
        case 1:
            system("cls");
            cout << "Voulez-vous tirer une carte sur votre premiere ou deuxieme main ? (1/2)" << endl;
            int choix_split;
            cin >> choix_split;
            if (choix_split == 1)
            {
                system("cls");
                groupier.distribuer_cartes(joueur, 1);
                cout << "Nouvelle main du joueur : " << endl;
                joueur.afficher_main();
                cout << "Score du joueur : " << joueur.get_score() << endl
                     << endl;
            }
            else if (choix_split == 2)
            {
                system("cls");
                groupier.distribuer_cartes(joueur_split, 1);
                cout << "Nouvelle main du joueur : " << endl;
                joueur_split.afficher_main();
                cout << "Score du joueur : " << joueur_split.get_score() << endl
                     << endl;
            }
            break;

        case 2:
            system("cls");
            cout << "Vous restez sur vos deux mains." << endl;
            break;

        case 3:
            system("cls");
            cout << "Votre main 1 : " << endl;
            joueur.afficher_main();
            cout << "Votre main 2 : " << endl;
            joueur_split.afficher_main();
            cout << endl;
            cout << "Score de la main 1 : " << joueur.get_score() << endl;
            cout << "Score de la main 2 : " << joueur_split.get_score() << endl;
            cout << endl;
            cout << "Main du groupier : " << endl;
            groupier.afficher_main_groupier();
            cout << endl;
            continue;

        default:
            system("cls");
            cout << "Choix invalide. Veuillez choisir une option valide." << endl;
            continue;
        }

        if (choix == 2)
        {
            break;
        }
        system("cls");
    }

    // Tour du groupier
    regle.tour_groupier(groupier, joueur);

    // Comparaison des scores pour déterminer le gagnant
    regle.main1gagnant(joueur, groupier);
    regle.main2gagnant(joueur_split, groupier, joueur);

    cout << "Vos gains sont maintenant de " << joueur.get_mise_depart() << endl;
    regle.rejouer(joueur, groupier);
}
