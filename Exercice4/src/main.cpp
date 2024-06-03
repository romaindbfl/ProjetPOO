#include "header/Chiffrage.hpp"
#include "header/Dechiffrage.hpp"

int main() {
    ChiffrementCesar chiffrementCesar;
    ChiffrementParSubstitution chiffrementSubstitution;
    DechiffrementCesar dechiffrementCesar(0); // Le décalage sera initialisé plus tard
    DechiffrementParSubstitution dechiffrementSubstitution;

    char choixMode;
    cout << "Voulez-vous traiter un fichier (f) ou utiliser la console (c) ? ";
    cin >> choixMode;

    if (choixMode == 'f') {
        string inputFile;
        string outputFile;
        char choix;
        
        // Demander à l'utilisateur de choisir entre chiffrement et déchiffrement
        cout << "Voulez-vous chiffrer (c) ou déchiffrer (d) un fichier ? ";
        cin >> choix;
        cin.ignore(); // Ignorer le caractère de retour à la ligne restant dans le buffer

        // Demander à l'utilisateur de saisir le chemin du fichier à traiter
        cout << "Entrez le chemin du fichier : ";
        getline(cin, inputFile);

        // Lire le contenu du fichier
        ifstream input(inputFile);
        if (!input.is_open()) {
            cerr << "Impossible d'ouvrir le fichier." << endl;
            return 1;
        }

        // Lire le contenu du fichier dans la chaîne message
        string message;
        getline(input, message);
        input.close();

        // Chiffrement ou déchiffrement du message...
        if (choix == 'c') {
            cout << "Choisissez le type de chiffrement : " << endl;
            cout << "1. Chiffrement de César" << endl;
            cout << "2. Chiffrement par substitution" << endl;
            int choixChiffrement;
            cin >> choixChiffrement;
            cin.ignore(); // Ignorer le caractère de retour à la ligne restant dans le buffer

            if (choixChiffrement == 1) {
                // Chiffrement de César
                message = chiffrementCesar.Chiffrer(message, "");
            } else if (choixChiffrement == 2) {
                // Chiffrement par substitution
                cout << "Entrez la clé de substitution (exemple : ABCDEFGHIJKLMNOPQRSTUVWXYZ) : ";
                string cle;
                getline(cin, cle);
                message = chiffrementSubstitution.Chiffrer(message, cle);
            } else {
                cerr << "Choix de chiffrement invalide." << endl;
                return 1;
            }
        } else if (choix == 'd') {
            cout << "Choisissez le type de déchiffrement : " << endl;
            cout << "1. Déchiffrement de César" << endl;
            cout << "2. Déchiffrement par substitution" << endl;
            int choixDechiffrement;
            cin >> choixDechiffrement;
            cin.ignore(); // Ignorer le caractère de retour à la ligne restant dans le buffer

            if (choixDechiffrement == 1) {
                // Déchiffrement de César
                cout << "Entrez le décalage pour le déchiffrement de César : ";
                string cle;
                getline(cin, cle);
                try {
                    int decalage = stoi(cle);
                    dechiffrementCesar = DechiffrementCesar(decalage);
                    message = dechiffrementCesar.Dechiffrer(message, "");
                } catch (const invalid_argument &) {
                    cerr << "Le décalage de déchiffrement de César doit être un nombre entier." << endl;
                    return 1;
                }
            } else if (choixDechiffrement == 2) {
                // Déchiffrement par substitution
                cout << "Entrez la clé de substitution (exemple : ABCDEFGHIJKLMNOPQRSTUVWXYZ) : ";
                string cle;
                getline(cin, cle);
                string cleInverse = dechiffrementSubstitution.inverserCleSubstitution(cle);
                message = dechiffrementSubstitution.Dechiffrer(message, cleInverse);
            } else {
                cerr << "Choix de déchiffrement invalide." << endl;
                return 1;
            }
        } else {
            cerr << "Choix invalide." << endl;
            return 1;
        }

        // Demander à l'utilisateur de saisir le chemin du fichier de sortie
        cout << "Entrez le chemin du fichier de sortie : ";
        getline(cin, outputFile);

        // Écrire le résultat dans un fichier
        ofstream output(outputFile);
        if (!output.is_open()) {
            cerr << "Impossible de créer le fichier de sortie." << endl;
            return 1;
        }

        // Écrire le message chiffré ou déchiffré dans le fichier de sortie
        output << message;
        output.close();

        cout << "Opération terminée avec succès. Veuillez vérifier le fichier de sortie." << endl;

    } else if (choixMode == 'c') {
        // Traitement en console...
        string message;
        string cle;
        char choix;

        cout << "Voulez-vous chiffrer (c) ou déchiffrer (d) un message ? ";
        cin >> choix;
        cin.ignore(); // Ignorer le caractère de retour à la ligne restant dans le buffer

        cout << "Entrez le message : ";
        getline(cin, message);

        if (choix == 'c') {
            cout << "Choisissez le type de chiffrement : " << endl;
            cout << "1. Chiffrement de César" << endl;
            cout << "2. Chiffrement par substitution" << endl;
            int choixChiffrement;
            cin >> choixChiffrement;
            cin.ignore(); // Ignorer le caractère de retour à la ligne restant dans le buffer

            if (choixChiffrement == 1) {
                // Chiffrement de César
                message = chiffrementCesar.Chiffrer(message, "");
            } else if (choixChiffrement == 2) {
                // Chiffrement par substitution
                cout << "Entrez la clé de substitution (exemple : ABCDEFGHIJKLMNOPQRSTUVWXYZ) : ";
                getline(cin, cle);
                message = chiffrementSubstitution.Chiffrer(message, cle);
            } else {
                cerr << "Choix de chiffrement invalide." << endl;
                return 1;
            }
        } else if (choix == 'd') {
            cout << "Choisissez le type de déchiffrement : " << endl;
            cout << "1. Déchiffrement de César" << endl;
            cout << "2. Déchiffrement par substitution" << endl;
            int choixDechiffrement;
            cin >> choixDechiffrement;
            cin.ignore(); // Ignorer le caractère de retour à la ligne restant dans le buffer

            if (choixDechiffrement == 1) {
                // Déchiffrement de César
                cout << "Entrez le décalage pour le déchiffrement de César : ";
                getline(cin, cle);
                try {
                    int decalage = stoi(cle);
                    dechiffrementCesar = DechiffrementCesar(decalage);
                    message = dechiffrementCesar.Dechiffrer(message, "");
                } catch (const invalid_argument &) {
                    cerr << "Le décalage de déchiffrement de César doit être un nombre entier." << endl;
                    return 1;
                }
            } else if (choixDechiffrement == 2) {
                // Déchiffrement par substitution
                cout << "Entrez la clé de substitution (exemple : ABCDEFGHIJKLMNOPQRSTUVWXYZ) : ";
                getline(cin, cle);
                string cleInverse = dechiffrementSubstitution.inverserCleSubstitution(cle);
                message = dechiffrementSubstitution.Dechiffrer(message, cleInverse);
            } else {
                cerr << "Choix de déchiffrement invalide." << endl;
                return 1;
            }
        } else {
            cerr << "Choix invalide." << endl;
            return 1;
        }

        cout << "Résultat : " << message << endl;
    } else {
        cerr << "Mode invalide." << endl;
        return 1;
    }

    return 0;
}