//
//  Playfair.cpp
//  Classical Ciphers
//
//  Created by Prakhar Jain on 15/01/16.
//  Copyright © 2016 Prakhar Jain. All rights reserved.
//

#include "Playfair.hpp"
#include "Stallings_Standard.hpp"
#include <cctype>

using namespace std;
Playfair::Playfair(char dc) {
    int ch = 'A';
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            this->key[i][j] = char(ch);
            ch++;
        }
    }
    doublechar = dc;
}

Playfair::Playfair(char key[5][5], char dc) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            this->key[i][j] = key[i][j];
        }
    }
    doublechar = dc;
}

int Playfair::get2playfairplchars(string pt, char& ch1, char& ch2) {
    static int i = 0;
    
    ch1 = ch2 = '%';
    
    while (i < pt.length()) {
        if (!isspace(pt[i++])) {
            ch1 = pt[i-1];
            break;
        }
    }
    
    while (i < pt.length()) {
        if (!isspace(pt[i++])) {
            ch2 = pt[i-1];
            break;
        }
    }
    
    if (ch1 == '%' || ch2 == '%')
        return -1;
    
    if (ch1 == ch2) {
        ch2 = doublechar;
        i--;
    }
    //assuming i and j in single box
    if (ch1 == 'j')
        ch1 = 'i';
    if (ch2 == 'j')
        ch2 = 'i';
    return 1;
}
int Playfair::get2playfaircipchars(string ct, char& ch1, char& ch2) {
    static int i = 0;
    
    ch1 = ch2 = '%';
    
    while (i < ct.length()) {
        if (!isspace(ct[i++])) {
            ch1 = ct[i-1];
            break;
        }
    }
    
    while (i < ct.length()) {
        if (!isspace(ct[i++])) {
            ch2 = ct[i-1];
            break;
        }
    }
    
    if (ch1 == '%' || ch2 == '%')
        return -1;
    return 1;
}































void Playfair::encrypt(ifstream& plaintext, ofstream& ciphertext) {
    string pt, ciptext;
    pt = convert_stream_to_string(plaintext);
    char ch1, ch2;
    while (get2playfairplchars(pt, ch1, ch2) != -1) {
        int posx1 = 0, posy1 = 0;
        int posx2 = 1, posy2 = 1;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (this->key[i][j] == toupper(ch1)) {
                    posx1 = i;
                    posy1 = j;
                    break;
                }
            }
        }
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (this->key[i][j] == toupper(ch2)) {
                    posx2 = i;
                    posy2 = j;
                    break;
                }
            }
        }
        if (posy1 == posy2) {
            ciptext += key[(posx1+1)%5][posy1];
            ciptext += key[(posx2+1)%5][posy2];
        }
        else if (posx1 == posx2) {
            ciptext += key[posx1][(posy1+1)%5];
            ciptext += key[posx2][(posy2+1)%5];
        }
        else {
            ciptext += key[posx1][posy2];
            ciptext += key[posx2][posy1];
        }
    }
    int i = 0;
    int j = 0;
    while (i < pt.length()) {
        if (isspace(pt[i]))
            ciphertext << pt[i];
        else
            ciphertext << ciptext[j++];
        i++;
    }
}

void Playfair::decrypt(ifstream& ciphertext, ofstream& plaintext) {
    char ch1, ch2;
    string ct, pltext;
    ct = convert_stream_to_string(ciphertext);
    while (get2playfaircipchars(ct, ch1, ch2) != -1) {
        int posx1 = 0, posy1 = 0;
        int posx2 = 1, posy2 = 1;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (this->key[i][j] == ch1) {
                    posx1 = i;
                    posy1 = j;
                    break;
                }
            }
        }
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (this->key[i][j] == ch2) {
                    posx2 = i;
                    posy2 = j;
                    break;
                }
            }
        }
        // not handled case when deciphered character 2 is actually 'x'
        char dec1, dec2;
        if (posy1 == posy2) {
            dec1 = char(tolower(key[(posx1-1+5)%5][posy1]));
            dec2 = char(tolower(key[(posx2-1+5)%5][posy2]));
            if (dec2 == 'x')
                pltext += dec1;
            else {
                pltext += dec1;
                pltext += dec2;
            }
        }
        else if (posx1 == posx2) {
            dec1 = char(tolower(key[posx1][(posy1-1+5)%5]));
            dec2 = char(tolower(key[posx2][(posy2-1+5)%5]));
            if (dec2 == 'x')
                pltext += dec1;
            else {
                pltext += dec1;
                pltext += dec2;
            }
        }
        else {
            dec1 = char(tolower(key[posx1][posy2]));
            dec2 = char(tolower(key[posx2][posy1]));
            if (dec2 == 'x')
                pltext += dec1;
            else {
                pltext += dec1;
                pltext += dec2;
            }
        }
    }
    int i = 0;
    int j = 0;
    while (i < ct.length()) {
        if (isspace(ct[i])) {
            plaintext << ct[i];
        }
        else
            plaintext << pltext[j++];
        i++;
    }
}