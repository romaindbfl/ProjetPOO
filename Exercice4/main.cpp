#include <iostream>
#include <string>
using namespace std;

// La classe chiffrement va servir de point de départ, et d'autres classes axées sur un chiffrement particulier
// seront ajoutées afin d'ajuster le type de chiffrement

class Chiffrement
{
protected:
    string message;
    int decalage;

public:
    virtual string Chiffrer(string message, int decalage) = 0;
};

class ChiffrementCesar : public Chiffrement
{
public:
    string Chiffrer(string message, int decalage) override
    {
        string messageChiffre = "";
        for (char c : message)
        {
            //isalpha : verifie si le caractere est dans l'alphabet
            if (isalpha(c))
            {
                // isupper : verifie si le caractère est une lettre majuscule
                char base = isupper(c) ? 'A' : 'a';
                c = (c - base + decalage) % 26 + base;
            }
            messageChiffre += c;
        }
        return messageChiffre;
    }
};

int main()
{
    ChiffrementCesar chiffrementCesar;

    string message;
    int decalage;
    cout << "Entrez le message a chiffrer : ";
    getline(cin, message);
    cout << "Entrez le decalage souhaite : ";
    cin >> decalage;

    string messageChiffre = chiffrementCesar.Chiffrer(message, decalage);
    cout << "Message chiffre : " << messageChiffre << endl;

    return 0;
}
