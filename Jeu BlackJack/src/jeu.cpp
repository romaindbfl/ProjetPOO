#include "header/jeu.hpp"

void deroulement_partie()
{
    system("cls");
    // Creation du joueur et du groupier
    Joueur joueur;
    Groupier groupier;
    int choix, mise;
    char rejouer = 'o';

    cout << "Bienvenue dans le jeu de Blackjack!" << endl;

    while (rejouer == 'o')
    {
        system("cls");

        // Affichage des gains de départ
        cout << "Vos gains de depart sont de " << joueur.get_mise_depart() << " euros.\n"
             << endl;

        cout << "Quelle est votre mise de depart?" << endl;
        cin >> mise;
        joueur.set_mise(mise);
        cout << "Vous avez choisi de miser " << joueur.get_mise() << " euros." << endl;
        cout << endl;

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

        // Si le joueur bust (score superieur à 21), le jeu doit se terminer
        if (joueur.get_score() > 21)
        {
            cout << "Le joueur a depasse 21. Le joueur perd." << endl;
            joueur.set_mise_departJeu(joueur.get_mise());
            cout << "Vos gains sont maintenant de " << joueur.get_mise_depart() << endl;
            cout << "Voulez-vous rejouer? (O/N)" << endl;
            cin >> rejouer;
            continue;
        }

        // Affichage des cartes du groupier
        cout << "Main du groupier : " << endl;
        groupier.afficher_main_groupier();
        cout << endl;

        while (true)
        {
            // Tour du joueur
            cout << "Souhaitez-vous : 1. tirer une carte, 2. Rester, 3. Doubler votre mise, 4. Split votre jeu, 5. Afficher votre main, votre score et la carte visible du groupier" << endl;
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

                // Si le joueur bust (score superieur à 21), le jeu doit se terminer
                if (joueur.get_score() > 21)
                {
                    cout << "Le joueur a depasse 21. Le joueur perd." << endl;
                    joueur.set_mise_departJeu(joueur.get_mise());
                    cout << "Vos gains sont maintenant de " << joueur.get_mise_depart() << endl;
                    cout << "Voulez-vous rejouer? (O/N)" << endl;
                    cin >> rejouer;
                    continue;
                }

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
                break;
            case 4:
                system("cls");
                if (joueur.peut_split())
                {
                    joueur.split();
                    cout << "Vous avez split votre main." << endl;
                }
                else
                {
                    system("cls");
                    cout << "Vous ne pouvez pas split cette main." << endl;
                    continue;
                }
                break;
            case 5:
                system("cls");
                // Affichage des cartes du joueur
                cout << "Main du joueur : " << endl;
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
                cout << "Choix invalide. Veuillez choisir une option valide." << endl;
                continue;
            }
            if (choix == 2)
            {
                break;
            }
        }
        cout << endl;
        // Tour du groupier
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

            // Si le groupier bust (score superieur à 21), le jeu doit se terminer
            if (groupier.get_score() > 21)
            {
                cout << "Le groupier a depasse 21. Le joueur gagne." << endl;
                joueur.set_mise_depart(joueur.get_mise());
                cout << "Vos gains sont maintenant de " << joueur.get_mise_depart() << endl;
                cout << "Voulez-vous rejouer? (O/N)" << endl;
                cin >> rejouer;
                continue;
            }
        }

        // Comparaison des scores pour determiner le gagnant
        if (joueur.get_score() > groupier.get_score() && joueur.get_score() <= 21)
        {
            cout << endl;
            cout << "Score du joueur : " << joueur.get_score() << endl;
            cout << "Le joueur gagne." << endl;
            joueur.set_mise_depart(joueur.get_mise());
            cout << "Vos gains sont maintenant de " << joueur.get_mise_depart() << endl;
        }
        else if (groupier.get_score() <= 21 && groupier.get_score() >= joueur.get_score())
        {
            cout << endl;
            cout << "Score du joueur : " << joueur.get_score() << endl;
            cout << "Le groupier gagne." << endl;
            joueur.set_mise_departJeu(joueur.get_mise());
            cout << "Vos gains sont maintenant de " << joueur.get_mise_depart() << endl;
        }
        else if (groupier.get_score() == joueur.get_score())
        {
            cout << endl;
            cout << "Score du joueur : " << joueur.get_score() << endl;
            cout << "C'est une egalite." << endl;
            cout << "Vos gains restent inchange." << endl;
        }

        cout << endl;
        cout << "Voulez-vous rejouer? (O/N)" << endl;
        cin >> rejouer;
    }
}
