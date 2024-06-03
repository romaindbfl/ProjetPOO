// chiffrement.cpp
#include "header/Chiffrement.hpp"

ChiffrementCesar::ChiffrementCesar(int decalage) : decalage(decalage) {}

string ChiffrementCesar::chiffrer(const string& message) const {
    string resultat = message;
    for (char& c : resultat) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base + decalage) % 26 + base;
        }
    }
    return resultat;
}

string ChiffrementCesar::dechiffrer(const string& texteChiffre) const {
    string resultat = texteChiffre;
    for (char& c : resultat) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base - decalage + 26) % 26 + base; // Utilisation de +26 pour gérer les décalages négatifs
        }
    }
    return resultat;
}

ChiffrementSubstitution::ChiffrementSubstitution(const string& cle) : cle(cle) {}

string ChiffrementSubstitution::chiffrer(const string& message) const {
    string resultat = message;
    for (char& c : resultat) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = cle[c - base];
        }
    }
    return resultat;
}

string ChiffrementSubstitution::dechiffrer(const string& texteChiffre) const {
    string resultat = texteChiffre;
    for (char& c : resultat) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = find(cle.begin(), cle.end(), c) - cle.begin() + base;
        }
    }
    return resultat;
}