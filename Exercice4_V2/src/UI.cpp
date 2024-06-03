#include "header/UI.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <limits>

void InterfaceUtilisateur::demarrer() {
    cout << "Bienvenue dans l'application de chiffrement et de déchiffrement de messages !" << endl;
    cout << "1. Chiffrement César\n2. Chiffrement par Substitution\n3. Déchiffrement César\n4. Déchiffrement par Substitution\n5. Chiffrer à partir d'un fichier\n6. Quitter" << endl;

    int choix;
    cout << "Choisissez une option : ";

    // Vérification que la saisie est un nombre entre 1 et 6 et n'est pas un caractère alphabétique
    while (!(cin >> choix) || choix < 1 || choix > 6) {
        cin.clear(); // Effacer les drapeaux d'erreur de cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorer le reste de la ligne
        cerr << "Option invalide ! Veuillez choisir une option entre 1 et 6." << endl;
        cout << "Choisissez une option : ";
    }

    InterfaceUtilisateur interface; // Création d'un objet InterfaceUtilisateur
    switch (choix) {
        case 1:
            interface.demonstrationChiffrementCesar();
            break;
        case 2:
            interface.demonstrationChiffrementSubstitution();
            break;
        case 3:
            interface.demonstrationDechiffrementCesar();
            break;
        case 4:
            interface.demonstrationDechiffrementSubstitution();
            break;
        case 5:
            interface.chiffrerFichier();
            break;
        case 6:
            cout << "Au revoir !" << endl;
            exit(0);
        default:
            cerr << "Option invalide !" << endl;
            exit(1);
    }
}
void InterfaceUtilisateur::demonstrationChiffrementCesar() {
    int decalage;
    cout << "Entrez le décalage pour le chiffrement de César : ";
    cin >> decalage;
    while (cin.fail()) {
        cerr << "Entrée invalide ! Veuillez entrer un nombre entier." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrez le décalage pour le chiffrement de César : ";
        cin >> decalage;
    }

    string message;
    cout << "Entrez le message à chiffrer : ";
    cin.ignore();
    getline(cin, message);

    ChiffrementCesar chiffrement(decalage);
    string texteChiffre = chiffrement.chiffrer(message);
    cout << "Message chiffré : " << texteChiffre << endl;

    string nomFichier;
    cout << "Voulez-vous enregistrer le message chiffré dans un fichier ? (Oui/Non) : ";
    cin >> nomFichier;
    if (nomFichier == "Oui" || nomFichier == "oui") {
        cout << "Entrez le nom du fichier : ";
        cin >> nomFichier;

        // Sauvegarde du décalage dans le fichier
        ecrireFichier(nomFichier, texteChiffre + "\nClé de déchiffrement : " + to_string(decalage));
        cout << "Message chiffré enregistré dans le fichier " << nomFichier << endl;
    }
}

void InterfaceUtilisateur::demonstrationChiffrementSubstitution() {
    string cle;
    cout << "Entrez la clé de chiffrement par substitution : ";
    cin >> cle;

    while (cle.length() != 26) {
        cerr << "Clé invalide ! Veuillez entrer une clé de substitution de longueur 26." << endl;
        cout << "Entrez la clé de chiffrement par substitution : ";
        cin >> cle;
    }

    string message;
    cout << "Entrez le message à chiffrer : ";
    cin.ignore();
    getline(cin, message);

    ChiffrementSubstitution chiffrement(cle);
    string texteChiffre = chiffrement.chiffrer(message);
    cout << "Message chiffré : " << texteChiffre << endl;

    string nomFichier;
    cout << "Voulez-vous enregistrer le message chiffré dans un fichier ? (Oui/Non) : ";
    cin >> nomFichier;
    if (nomFichier == "Oui" || nomFichier == "oui") {
        cout << "Entrez le nom du fichier : ";
        cin >> nomFichier;

        // Sauvegarde de la clé de chiffrement dans le fichier
        ecrireFichier(nomFichier, texteChiffre + "\nClé de déchiffrement : " + cle);
        cout << "Message chiffré enregistré dans le fichier " << nomFichier << endl;
    }
}

void InterfaceUtilisateur::demonstrationDechiffrementCesar() {
    int decalage;
    cout << "Entrez le décalage utilisé pour le chiffrement de César : ";
    cin >> decalage;

    string texteChiffre;
    cout << "Entrez le message chiffré : ";
    cin.ignore();
    getline(cin, texteChiffre);

    ChiffrementCesar chiffrement(decalage);
    string texteDechiffre = chiffrement.dechiffrer(texteChiffre);
    cout << "Message déchiffré : " << texteDechiffre << endl;
}

void InterfaceUtilisateur::demonstrationDechiffrementSubstitution() {
    string cle;
    cout << "Entrez la clé de chiffrement par substitution utilisée : ";
    cin >> cle;

    string texteChiffre;
    cout << "Entrez le message chiffré : ";
    cin.ignore();
    getline(cin, texteChiffre);

    ChiffrementSubstitution chiffrement(cle);
    string texteDechiffre = chiffrement.dechiffrer(texteChiffre);
    cout << "Message déchiffré : " << texteDechiffre << endl;
}

string InterfaceUtilisateur::lireFichier(const string& nomFichier) {
    ifstream fichier(nomFichier);
    if (!fichier) {
        cerr << "Erreur lors de la lecture du fichier." << endl;
        exit(1);
    }
    string contenu((istreambuf_iterator<char>(fichier)), istreambuf_iterator<char>());
    fichier.close();
    return contenu;
}

void InterfaceUtilisateur::chiffrerFichier() {
    string nomFichierEntree;
    cout << "Entrez le nom et chemin du fichier contenant le texte à chiffrer : ";
    cin >> nomFichierEntree;

    string contenu = lireFichier(nomFichierEntree);

    string texteChiffre; // Déclaration de texteChiffre dans la portée appropriée
    string cle; // Déclaration de la clé de chiffrement ou du décalage

    cout << "Choisissez le type de chiffrement : " << endl;
    cout << "1. Chiffrement César\n2. Chiffrement par Substitution" << endl;
    int choixChiffrement;
    cin >> choixChiffrement;
    while (choixChiffrement != 1 && choixChiffrement != 2) {
        cerr << "Option invalide ! Veuillez choisir 1 pour le chiffrement César ou 2 pour le chiffrement par substitution." << endl;
        cout << "Choisissez le type de chiffrement : " << endl;
        cout << "1. Chiffrement César\n2. Chiffrement par Substitution" << endl;
        cin >> choixChiffrement;
    }

    switch (choixChiffrement) {
        case 1: {
            int decalage;
            cout << "Entrez le décalage pour le chiffrement de César : ";
            cin >> decalage;
            while (cin.fail()) {
                cerr << "Entrée invalide ! Veuillez entrer un nombre entier." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Entrez le décalage pour le chiffrement de César : ";
                cin >> decalage;
            }
            ChiffrementCesar chiffrementCesar(decalage);
            texteChiffre = chiffrementCesar.chiffrer(contenu); // Assignation de texteChiffre ici
            cle = to_string(decalage); // Stockage du décalage comme clé de déchiffrement
            cout << "Message chiffré : " << texteChiffre << endl;
            break;
        }
        case 2: {
            cout << "Entrez la clé de chiffrement par substitution : ";
            cin >> cle;
            while (cle.length() != 26) {
                cerr << "Clé invalide ! Veuillez entrer une clé de substitution de longueur 26." << endl;
                cout << "Entrez la clé de chiffrement par substitution : ";
                cin >> cle;
            }
            ChiffrementSubstitution chiffrementSubstitution(cle);
            texteChiffre = chiffrementSubstitution.chiffrer(contenu); // Assignation de texteChiffre ici
            cout << "Message chiffré : " << texteChiffre << endl;
            break;
        }
        default:
            cerr << "Option invalide !" << endl;
            exit(1);
    }

    string nomFichierSortie;
    cout << "Entrez le nom du fichier pour enregistrer le message chiffré : ";
    cin >> nomFichierSortie;

    // Écrivez le texte chiffré et la clé de chiffrement/déchiffrement dans le fichier de sortie
    ecrireFichier(nomFichierSortie, texteChiffre + "\nClé de déchiffrement : " + cle);
    cout << "Message chiffré enregistré dans le fichier " << nomFichierSortie << endl;
}

void InterfaceUtilisateur::ecrireFichier(const string& nomFichier, const string& contenu) {
    ofstream fichier(nomFichier);
    if (!fichier) {
        cerr << "Erreur lors de l'écriture dans le fichier." << endl;
        exit(1);
    }
    fichier << contenu;
    fichier.close();
}
