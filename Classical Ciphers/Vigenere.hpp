//
//  Vigenere.hpp
//  Classical Ciphers
//
//  Created by Prakhar Jain on 13/01/16.
//  Copyright © 2016 Prakhar Jain. All rights reserved.
//

#ifndef Vigenere_hpp
#define Vigenere_hpp

#include <iostream>
#include <fstream>
#include <string>

class Vigenere {
    std::string key;
public:
    Vigenere(std::string key);
    Vigenere();
    void setKey(std::string key);
    void encrypt(std::ifstream& plaintext, std::ofstream& ciphertext);
    void decrypt(std::ifstream& ciphertext, std::ofstream& plaintext);
};

#endif /* Vigenere_hpp */
