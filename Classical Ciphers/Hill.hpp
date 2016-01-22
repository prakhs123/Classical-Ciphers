//
//  Hill.hpp
//  Classical Ciphers
//
//  Created by Prakhar Jain on 13/01/16.
//  Copyright © 2016 Prakhar Jain. All rights reserved.
//

#ifndef Hill_hpp
#define Hill_hpp

#include <iostream>
#include <fstream>

class Hill {
    int order;
    int **key;
    int GetMinor(int **src, int **dest, int row, int col, int order);
    int CalcDeterminant( int **mat, int order);
    void MatrixInversion(int **A, int order, int **Y);
    void extended_euclid(int a, int b, int& s, int& t, int &g);
public:
    Hill();
    Hill(int order, int **key);
    void setKey(int order, int **key);
    void encrypt(std::ifstream& plaintext, std::ofstream& ciphertext);
    void decrypt(std::ifstream& ciphertext, std::ofstream& plaintext);
    ~Hill();
};

#endif /* Hill_hpp */
