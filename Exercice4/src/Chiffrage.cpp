#include "header/Chiffrage.hpp"

    int Chiffrement::getDecalage() const { return decalage; }


    string ChiffrementCesar::Chiffrer(string message, string cle)  {
        while (true) {
            cout << "Entrez le décalage pour le chiffrement de César : ";
            getline(cin, cle);
            try {
                decalage = stoi(cle);
                break; // Sort de la boucle si la conversion est réussie
            } catch (const invalid_argument &) {
                cerr << "Le décalage de chiffrement doit être un nombre entier." << endl;
            }
        }

        string messageChiffre = "";
        for (char c : message) {
            if (isalpha(c)) {
                char base = isupper(c) ? 'A' : 'a';
                c = (c - base + decalage) % 26 + base;
            }
            messageChiffre += c;
        }
        return messageChiffre;
    }

    string ChiffrementParSubstitution::Chiffrer(string message, string cle)  {
        while (!estBonneTaille(cle)) {
            cerr << "La clé de substitution doit contenir exactement 26 caractères." << endl;
            getline(cin, cle);       
        }

        string messageChiffre = "";
        for (char c : message) {
            if (isalpha(c)) {
                char base = isupper(c) ? 'A' : 'a';
                int index = c - base;
                c = toupper(cle[index]);
            }
            messageChiffre += c;
        }
        return messageChiffre;
    }

    bool ChiffrementParSubstitution::estBonneTaille(string cle) {
        return cle.size() == 26;
    }
