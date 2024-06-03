#include "header/Dechiffrage.hpp"

    string DechiffrementCesar::Dechiffrer(string message, string cle)  {
        string messageDechiffre = "";
        for (char c : message) {
            if (isalpha(c)) {
                char base = isupper(c) ? 'A' : 'a';
                c = (c - base - decalage + 26) % 26 + base; // Formule de déchiffrement César
            }
            messageDechiffre += c;
        }
        return messageDechiffre;
    }

    string DechiffrementParSubstitution::Dechiffrer(string message, string cleInverse) {
        string messageDechiffre = "";
        for (char c : message) {
            if (isalpha(c)) {
                char base = isupper(c) ? 'A' : 'a';
                int index = toupper(c) - 'A';
                c = cleInverse[index];
                if (islower(c)) {
                    c = tolower(c);
                } else {
                    c = toupper(c);
                }
            }
            messageDechiffre += c;
        }
        return messageDechiffre;
    }

    string DechiffrementParSubstitution::inverserCleSubstitution(string cle) {
        string cleInverse = "";
        for (char c = 'A'; c <= 'Z'; ++c) {
            size_t pos = cle.find(c);
            if (pos != string::npos) {
                cleInverse += 'A' + pos;
            }
        }
        return cleInverse;
    }


