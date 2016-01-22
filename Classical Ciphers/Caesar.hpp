//
//  Caesar.hpp
//  Classical Ciphers
//
//  Created by Prakhar Jain on 13/01/16.
//  Copyright © 2016 Prakhar Jain. All rights reserved.
//

#ifndef Caesar_hpp
#define Caesar_hpp

#include <iostream>
#include <fstream>

class Caesar {
    int key;
public:
    Caesar();
    Caesar(int k);
    void setkey(int k);
    void encrypt(std::ifstream& plaintext, std::ofstream& ciphertext);
    void decrypt(std::ifstream& ciphertext, std::ofstream& plaintext);
};
#endif /* Caesar_hpp */
