//
//  Vigenere.cpp
//  Classical Ciphers
//
//  Created by Prakhar Jain on 13/01/16.
//  Copyright © 2016 Prakhar Jain. All rights reserved.
//

#include "Vigenere.hpp"
#include <cctype>
using namespace std;
Vigenere::Vigenere() {
    this->key = "";
}
Vigenere::Vigenere(string key) {
    this->key = key;
}

void Vigenere::encrypt(std::ifstream& plaintext, std::ofstream& ciphertext) {
    char ch;
    long count = 0;
    while (plaintext >> noskipws >> ch) {
        if (islower(ch)) {
            ch = (ch - 'a' + key[count % key.length()] - 'A') % 26;
            ciphertext << char(ch+'A');
        }
        else
            ciphertext << ch;
        count++;
    }
}

void Vigenere::decrypt(std::ifstream& ciphertext, std::ofstream& plaintext) {
    char ch;
    long count = 0;
    while (ciphertext >> noskipws >> ch) {
        if (isupper(ch)) {
            ch = ((ch - 'A' - (key[count % key.length()] - 'A')) + 26) % 26;
            plaintext << char(ch+'a');
        }
        else
            plaintext << ch;
        count++;
    }
}