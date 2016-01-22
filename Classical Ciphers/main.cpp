//
//  main.cpp
//  Classical Ciphers
//
//  Created by Prakhar Jain on 13/01/16.
//  Copyright © 2016 Prakhar Jain. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include "Stallings_Standard.hpp"
#include "Letter_Frequency.hpp"
#include "Caesar.hpp"
#include "Vigenere.hpp"
#include "Hill.hpp"
#include "Playfair.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    // Convert Unformatted Plaintext to formatted one
    ifstream in("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/pg19645.txt");
    ofstream plaintext("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/plaintext.txt");
    convert_to_standard(in, plaintext);
    
    
    // Plaintext Letter Frequency
    ifstream pt("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/plaintext.txt");
    ofstream freq("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/plaintext frequency.txt");
    letterFrequency(pt, freq);
    
    
    
    
    // Caesar Cipher Encrypt
    Caesar caesarcipher(2);
    pt.clear();
    pt.seekg(0, ios::beg);
    ofstream ct1_1("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/caesar ciphertext.txt");
    caesarcipher.encrypt(pt, ct1_1);
    
    
    
    
    // Caesar Cipher Letter Frequency
    ifstream ct1_2("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/caesar ciphertext.txt");
    ofstream freq1("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/caesar frequency.txt");
    letterFrequency(ct1_2, freq1);
    
    
    
    // Caesar Cipher Decrypt
    ifstream ct1_3("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/caesar ciphertext.txt");
    ofstream pt1_3("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/decrypted plaintext.txt");
    caesarcipher.decrypt(ct1_3, pt1_3);
    
    
    
    
    
    
    
    
    
    // Vigenere Cipher Encrypt
    pt.clear();
    pt.seekg(0, ios::beg);
    ofstream ct2_1("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/vigenere ciphertext.txt");
    Vigenere vigenerecipher("DECEPTIVE");
    vigenerecipher.encrypt(pt, ct2_1);
    
    
    
    // Vigenere Cipher Letter Frequency
    ifstream ct2_2("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/vigenere ciphertext.txt");
    ofstream freq2("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/vigenere frequency.txt");
    letterFrequency(ct2_2, freq2);
    
    
    
    // Vigenere Cipher Decrypt
    ifstream ct2_3("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/vigenere ciphertext.txt");
    ofstream pt2_3("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/decrypted plaintext.txt");
    vigenerecipher.decrypt(ct2_3, pt2_3);
    
    
    
    
    
    
    
    
    // Playfair Cipher Encrypt
    pt.clear();
    pt.seekg(0, ios::beg);
    ofstream ct4_1("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/playfair ciphertext.txt");
    char key[5][5] = { {'M','O','N','A','R'},{'C','H','Y','B','D'},{'E','F','G','I','K'},{'L','P','Q','S','T'},{'U','V','W','X','Z'} };
    Playfair playfaircipher(key);
    playfaircipher.encrypt(pt, ct4_1);
    
    
    // Playfair Letter Frequency
    ifstream ct4_2("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/playfair ciphertext.txt");
    ofstream freq4("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/playfair frequency.txt");
    letterFrequency(ct4_2, freq4);
    
    
    //Playfair Cipher Decrypt
    ifstream ct4_3("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/playfair ciphertext.txt");
    ofstream pt4_3("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/decrypted plaintext.txt");
    playfaircipher.decrypt(ct4_3, pt4_3);
    
    
    
    
    
    
    
    // Hill Cipher Encrypt
    pt.clear();
    pt.seekg(0, ios::beg);
    ofstream ct3_1("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/hill ciphertext.txt");
    ifstream input("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/input.txt");
    int **A;
    int order;
    input >> order;
    A = new int*[order];
    for (int i = 0; i < order; i++) {
        A[i] = new int[order];
    }
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++)
            input >> A[i][j];
    }
    Hill hillcipher = Hill(order, A);
    hillcipher.encrypt(pt, ct3_1);
    
    
    
    // Hill Cipher Letter Frequency
    ifstream ct3_2("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/hill ciphertext.txt");
    ofstream freq3("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/hill frequency.txt");
    letterFrequency(ct3_2, freq3);
    
    
    
    // Hill Cipher Decrypt
    ifstream ct3_3("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/hill ciphertext.txt");
    ofstream pt3_3("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/decrypted plaintext.txt");
    
    hillcipher.decrypt(ct3_3, pt3_3);
    
    
    return 0;
}
