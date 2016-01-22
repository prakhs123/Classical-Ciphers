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
    
    /* Convert Unformatted Plaintext to formatted one
     ifstream in("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/pg19645.txt");
     ofstream plaintext("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/plaintext.txt");
     convert_to_standard(in, plaintext);
     */
    
    
    
    /* Plaintext Letter Frequency
     ifstream pt("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/plaintext.txt");
     ofstream freq("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/plaintext frequency.txt");
     letterFrequency(pt, freq);
     */
    
    
    
    
    /* Caesar Cipher Encrypt
     Caesar cipher(2);
     ifstream pt("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/plaintext.txt");
     ofstream ct("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/caesar ciphertext.txt");
     cipher.encrypt(pt, ct);
     */
    
    
    
    
    /* Caesar Cipher Letter Frequency
     ifstream ct1("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/caesar ciphertext.txt");
     ofstream freq1("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/caesar frequency.txt");
     
     letterFrequency(ct1, freq1);
     */
    
    
    
    /* Caesar Cipher Decrypt
    ifstream ct("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/caesar ciphertext.txt");
    ofstream pt("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/decrypted plaintext.txt");
    Caesar cipher(2);
    cipher.decrypt(ct, pt);
     */
    
    
    
    
    
    
    
    
    
    /* Vigenere Cipher Encrypt
    ifstream pt("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/plaintext.txt");
    ofstream ct("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/vigenere ciphertext.txt");
    Vigenere cipher("DECEPTIVE");
    cipher.encrypt(pt, ct);
     */
    
    
    
    
    /* Vigenere Cipher Letter Frequency
    ifstream ct2("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/vigenere ciphertext.txt");
    ofstream freq2("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/vigenere frequency.txt");
    letterFrequency(ct2, freq2);
    */
    
    
    
    
    /* Vigenere Cipher Decrypt
    ifstream ct("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/vigenere ciphertext.txt");
    ofstream pt("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/decrypted plaintext.txt");
    Vigenere cipher("DECEPTIVE");
    cipher.decrypt(ct, pt);
     */
    
    
    
    
    
    
    
    
    
    /*Hill Cipher Encrypt
     ifstream in("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/plaintext.txt");
     ofstream ct("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/hill ciphertext.txt");
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
     Hill cipher = Hill(order, A);
     cipher.encrypt(in, ct);
    */
    
    
    
    
    /* Hill Cipher Letter Frequency
     ifstream ct3("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/hill ciphertext.txt");
     ofstream freq3("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/hill frequency.txt");
     letterFrequency(ct3, freq3);
    */
    
    
    
    /* Hill Cipher Decrypt
    ifstream ct("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/hill ciphertext.txt");
    ofstream pt("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/decrypted plaintext.txt");
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
    Hill cipher = Hill(order, A);
    cipher.decrypt(ct, pt);
    */
    
    
    
    
    
    
    
    
    
    
    
    /* Playfair Cipher Encrypt
    ifstream pt("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/plaintext.txt");
    ofstream ct("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/playfair ciphertext.txt");
    char key[5][5] = { {'M','O','N','A','R'},{'C','H','Y','B','D'},{'E','F','G','I','K'},{'L','P','Q','S','T'},{'U','V','W','X','Z'} };
    Playfair cipher(key);
    cipher.encrypt(pt, ct);
    */
    /* Playfair Letter Frequency
    ifstream ct4("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/playfair ciphertext.txt");
    ofstream freq4("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/playfair frequency.txt");
    letterFrequency(ct4, freq4);
     */
    
    ifstream ct("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/playfair ciphertext.txt");
    ofstream pt("/Users/prakharjain/Documents/Xcode/Classical Ciphers/Classical Ciphers/decrypted plaintext.txt");
    char key[5][5] = { {'M','O','N','A','R'},{'C','H','Y','B','D'},{'E','F','G','I','K'},{'L','P','Q','S','T'},{'U','V','W','X','Z'} };
    Playfair cipher(key);
    cipher.decrypt(ct, pt);
    return 0;
}
