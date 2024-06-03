#ifndef CHIFFRAGE_HPP
#define CHIFFRAGE_HPP

#include <iostream>
#include <string>
#include <fstream> 
#include <cctype>
#include <stdexcept> 
using namespace std;

class Chiffrement {
protected:
    int decalage;

public:
    virtual string Chiffrer(string message, string cle) = 0;
    int getDecalage() const;
};

class ChiffrementCesar : public Chiffrement {
public:
    string Chiffrer(string message, string cle) override;
};

class ChiffrementParSubstitution : public Chiffrement {
public:
    string Chiffrer(string message, string cle) override;
    bool estBonneTaille(string cle);
};

#endif