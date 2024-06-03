#ifndef DECHIFFRAGE_HPP
#define DECHIFFRAGE_HPP

#include <iostream>
#include <string>
#include <fstream> 
#include <cctype>
#include <stdexcept> 
using namespace std;


class Dechiffrement {
public:
    virtual string Dechiffrer(string message, string cle) = 0;
};

class DechiffrementCesar : public Dechiffrement {
private:
    int decalage;

public:
    DechiffrementCesar(int _decalage) : decalage(_decalage) {}

    string Dechiffrer(string message, string cle) override;
};

class DechiffrementParSubstitution : public Dechiffrement {
public:
    string Dechiffrer(string message, string cleInverse) override;

    string inverserCleSubstitution(string cle);
};

#endif