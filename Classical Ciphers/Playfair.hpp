//
//  Playfair.hpp
//  Classical Ciphers
//
//  Created by Prakhar Jain on 15/01/16.
//  Copyright © 2016 Prakhar Jain. All rights reserved.
//

#ifndef Playfair_hpp
#define Playfair_hpp
#include <iostream>
#include <fstream>
class Playfair {
    char key[5][5];
    int get2playfairplchars(std::string pt, char& c1, char& c2);
    int get2playfaircipchars(std::string ct, char& ch1, char& ch2);
    char doublechar;
public:
    Playfair(char dc = 'X');
    Playfair(char key[5][5], char dc = 'X');
    void encrypt(std::ifstream& plaintext, std::ofstream& ciphertext);
    void decrypt(std::ifstream& ciphertext, std::ofstream& plaintext);
};

#endif /* Playfair_hpp */
