#ifndef UI_HPP
#define UI_HPP

#include <string>
#include <iostream>
#include "Chiffrement.hpp"

class InterfaceUtilisateur {
public:
    static void demarrer();
    static void demonstrationChiffrementCesar();
    static void demonstrationChiffrementSubstitution();
    static void demonstrationDechiffrementCesar();
    static void demonstrationDechiffrementSubstitution();
    void chiffrerFichier();
    static string lireFichier(const string& nomFichier);
    static void ecrireFichier(const string& nomFichier, const string& contenu);
};

#endif // UI_HPP
