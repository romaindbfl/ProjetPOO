#ifndef CARTE_HPP
#define CARTE_HPP

#include <iostream>
using namespace std;

class Carte
{
protected:
    int valeur;
    char symbole;

public:
    Carte(int valeur, char symbole);
    int get_valeur() const;
    char get_symbole() const;
    int set_valeur(int valeur);
    void afficher() const;
};

class As : public Carte
{
public:
    As();
};

class Deux : public Carte
{
public:
    Deux();
};

class Trois : public Carte
{
public:
    Trois();
};

class Quatre : public Carte
{
public:
    Quatre();
};

class Cinq : public Carte
{
public:
    Cinq();
};

class Six : public Carte
{
public:
    Six();
};

class Sept : public Carte
{
public:
    Sept();
};

class Huit : public Carte
{
public:
    Huit();
};

class Neuf : public Carte
{
public:
    Neuf();
};

class Dix : public Carte
{
public:
    Dix();
};

class Valet : public Carte
{
public:
    Valet();
};

class Reine : public Carte
{
public:
    Reine();
};

class Roi : public Carte
{
public:
    Roi();
};

#endif