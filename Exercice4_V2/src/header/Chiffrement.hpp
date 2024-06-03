#ifndef CHIFFREMENT_HPP
#define CHIFFREMENT_HPP

#include <string>
#include <algorithm> 
using namespace std;

class Chiffrement {
public:
    virtual string chiffrer(const string& message) const = 0;
    virtual string dechiffrer(const string& texteChiffre) const = 0;
    virtual ~Chiffrement() {}
};

class ChiffrementCesar : public Chiffrement {
private:
    int decalage;
public:
    ChiffrementCesar(int decalage);
    virtual string chiffrer(const string& message) const override;
    virtual string dechiffrer(const string& texteChiffre) const override;
};

class ChiffrementSubstitution : public Chiffrement {
private:
    string cle;
public:
    ChiffrementSubstitution(const string& cle);
    virtual string chiffrer(const string& message) const override;
    virtual string dechiffrer(const string& texteChiffre) const override;
};

#endif