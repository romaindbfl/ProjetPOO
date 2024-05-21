#include <iostream>
#include <string>
#include <cctype>
using namespace std;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Chiffrement ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class Chiffrement
{
protected:
    string message;
    int decalage;

public:
    virtual string Chiffrer(string message, string cle) = 0;
};

class ChiffrementCesar : public Chiffrement
{
public:
    string Chiffrer(string message, string cle) override
    {
        do
        {
            cout << "Entrez le decalage pour le chiffrement de cesar : ";
            getline(cin, cle);
        } while (!estNombreEntier(cle));

        decalage = stoi(cle);

        string messageChiffre = "";
        for (char c : message)
        {
            if (isalpha(c))
            {
                char base = isupper(c) ? 'A' : 'a';
                c = (c - base + decalage) % 26 + base;
            }
            messageChiffre += c;
        }
        return messageChiffre;
    }

    static bool estNombreEntier(string cle) {
        if (cle.empty()) {
            return false;
        }

        for (char c : cle) {
            if (!isdigit(c)) {
                return false;
            }
        }
        return true;
    }
};

class ChiffrementParSubstitution : public Chiffrement {
public:
    string Chiffrer(string message, string cle) override
    {
        while (!estBonneTaille(cle)) {
            cerr << "La cle de substitution doit contenir exactement 26 caracteres." << endl;
            getline(cin, cle);       
        }

        string messageChiffre = "";
        for (char c : message)
        {
            if (isalpha(c))
            {
                char base = isupper(c) ? 'A' : 'a';
                int index = c - base;
                c = toupper(cle[index]);
            }
            messageChiffre += c;
        }
        return messageChiffre;
    }

    bool estBonneTaille(string cle) {
        return cle.size() == 26;
    }

    string inverserCleSubstitution(string cle) {
        string cleInverse = "";
        for (char c = 'A'; c <= 'Z'; ++c) {
            size_t pos = cle.find(c);
            if (pos != string::npos) {
                cleInverse += 'A' + pos;
            }
        }
        return cleInverse;
    }
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Dechiffrement ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class Dechiffrement {
public:
    virtual string Dechiffrer(string message, string cle) = 0;
};

class DechiffrementCesar : public Dechiffrement 
{
public:
    string Dechiffrer(string message, string cle) override
    {
        if (cle.empty()) {
            return message; // Retourne le message chiffré sans déchiffrement
        }

        int decalage;
        try
        {
            decalage = stoi(cle);
        }
        catch (const invalid_argument &)
        {
            cerr << "La cle de chiffrement doit etre un nombre entier." << endl;
            return "";
        }

        string messageDechiffre = "";
        for (char c : message)
        {
            if (isalpha(c))
            {
                char base = isupper(c) ? 'A' : 'a';
                c = (c - base - decalage + 26) % 26 + base;
            }
            messageDechiffre += c;
        }
        return messageDechiffre;
    }
};

class DechiffrementParSubstitution : public Dechiffrement 
{
public:
    ChiffrementParSubstitution chiffrementSubstitution;

    string Dechiffrer(string message, string cle) override
    {
        string cleInverse = chiffrementSubstitution.inverserCleSubstitution(cle);

        string messageDechiffre = "";
        for (char c : message)
        {
            if (isalpha(c))
            {
                char base = isupper(c) ? 'A' : 'a';
                int index = toupper(c) - 'A';
                c = cleInverse[index];
                if (islower(c))
                {
                    c = tolower(c);
                }
                else
                {
                    c = toupper(c);
                }
            }
            messageDechiffre += c;
        }
        return messageDechiffre;
    }
};


int main()
{
    ChiffrementCesar chiffrementCesar;
    ChiffrementParSubstitution chiffrementSubstitution;

    DechiffrementCesar dechiffrementCesar;
    DechiffrementParSubstitution dechiffrementSubstitution;

    string message;
    string cle;
    cout << "Entrez le message a chiffrer : ";
    getline(cin, message);

    string messageChiffreCesar = chiffrementCesar.Chiffrer(message, cle);
    cout << "Message chiffre avec Cesar : " << messageChiffreCesar << endl;
    cout << "Message dechiffre avec Cesar : " << dechiffrementCesar.Dechiffrer(messageChiffreCesar, cle) << endl;

    cout << "Entrez la cle de substitution (exemple : ABCDEFGHIJKLMN): ";
    getline(cin, cle);
    string messageChiffreSubstitution = chiffrementSubstitution.Chiffrer(message, cle);
    cout << "Message chiffre avec Substitution : " << messageChiffreSubstitution << endl;
    cout << "Message dechiffre avec Substitution : " << dechiffrementSubstitution.Dechiffrer(messageChiffreSubstitution, cle) << endl;
    return 0;
}
