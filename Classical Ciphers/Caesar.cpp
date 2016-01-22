//
//  Caesar.cpp
//  Classical Ciphers
//
//  Created by Prakhar Jain on 13/01/16.
//  Copyright © 2016 Prakhar Jain. All rights reserved.
//

#include "Caesar.hpp"
#include <cctype>

using namespace std;
Caesar::Caesar(int key) {
    this->key = key;
}
Caesar::Caesar() {
    this->key = 0;
}
void Caesar::setkey(int k) {
    this->key = k;
}
void Caesar::encrypt(ifstream& plaintext, ofstream& ciphertext) {
    char ch;
    while (plaintext >> noskipws >> ch) {
        if (islower(ch)) {
            ch = char(((ch + this->key - 'a') % 26) + 'a');
            ciphertext << char(toupper(ch));
        }
        else
            ciphertext << ch;
    }
}
void Caesar::decrypt(ifstream& ciphertext, ofstream& plaintext) {
    char ch;
    while (ciphertext >> noskipws >> ch) {
        if (isupper(ch)) {
            ch = char( ((ch - 'A' - this->key) + 26) % 26 + 'A');
            plaintext << char(tolower(ch));
        }
        else
            plaintext << ch;
    }
}