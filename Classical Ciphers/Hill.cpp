//
//  Hill.cpp
//  Classical Ciphers
//
//  Created by Prakhar Jain on 13/01/16.
//  Copyright © 2016 Prakhar Jain. All rights reserved.
//

#include "Hill.hpp"
#include "Stallings_Standard.hpp"
#include <cassert>
#include <cctype>
#include <vector>

using namespace std;
Hill::Hill() {
    this->order = 0;
    this->key = nullptr;
}

Hill::Hill(int order, int **key) {
    this->order = order;
    this->key = new int*[order];
    for (int i = 0; i < order; i++) {
        this->key[i] = new int[order];
        for (int j = 0; j < order; j++) {
            this->key[i][j] = key[i][j];
        }
    }
}
void Hill::setKey(int order, int **key) {
    this->order = order;
    this->key = new int*[order];
    for (int i = 0; i < order; i++) {
        this->key[i] = new int[order];
        for (int j = 0; j < order; j++) {
            this->key[i][j] = key[i][j];
        }
    }
}

// calculate the cofactor of element (row,col)
int Hill::GetMinor(int **src, int **dest, int row, int col, int order)
{
    // indicate which col and row is being copied to dest
    int colCount=0,rowCount=0;
    
    for(int i = 0; i < order; i++ )
    {
        if( i != row )
        {
            colCount = 0;
            for(int j = 0; j < order; j++ )
            {
                // when j is not the element
                if( j != col )
                {
                    dest[rowCount][colCount] = src[i][j];
                    colCount++;
                }
            }
            rowCount++;
        }
    }
    
    return 1;
}

// Calculate the determinant recursively.
int Hill::CalcDeterminant(int **mat, int order)
{
    // order must be >= 0
    // stop the recursion when matrix is a single element
    if( order == 1 )
        return mat[0][0];
    
    // the determinant value
    int det = 0;
    
    // allocate the cofactor matrix
    int **minor;
    minor = new int*[order-1];
    for(int i=0;i<order-1;i++)
        minor[i] = new int[order-1];
    
    for(int i = 0; i < order; i++ )
    {
        // get minor of element (0,i)
        GetMinor( mat, minor, 0, i , order);
        // the recusion is here!
        
        det += (i%2==1?-1.0:1.0) * mat[0][i] * CalcDeterminant(minor,order-1);
        //det += pow( -1.0, i ) * mat[0][i] * CalcDeterminant( minor,order-1 );
    }
    
    // release memory
    for(int i=0;i<order-1;i++)
        delete [] minor[i];
    delete [] minor;
    
    return det%26;
}
void Hill::extended_euclid(int a, int b, int& s, int& t, int &g) {
    if (b == 0) {
        g = a;
        s = 1;
        t = 0;
    }
    else {
        int g1, s1, t1;
        extended_euclid(b, a%b, s1, t1, g1);
        g = g1;
        s = t1;
        t = s1 - (a/b)*t1;
    }
}

void Hill::MatrixInversion(int **A, int order, int **Y)
{
    // get the determinant of a
    int g, s, t;
    int D = (CalcDeterminant(A, order)%26+26) % 26;
    extended_euclid(26,D,s,t,g);
    if (g != 1)
        assert(0);
    
    int det = (t%26+26)%26;
    
    // memory allocation
    int *temp = new int[(order-1)*(order-1)];
    int **minor = new int*[order-1];
    for(int i=0;i<order-1;i++)
        minor[i] = temp+(i*(order-1));
    
    for(int j=0;j<order;j++)
    {
        for(int i=0;i<order;i++)
        {
            // get the co-factor (matrix) of A(j,i)
            GetMinor(A,minor,j,i,order);
            Y[i][j] = det*CalcDeterminant(minor,order-1);
            if( (i+j)%2 == 1)
                Y[i][j] = -Y[i][j];
            Y[i][j] = (Y[i][j]%26+26)%26;
        }
    }
    
    // release memory
    //delete [] minor[0];
    delete [] temp;
    delete [] minor;
}

void Hill::encrypt(ifstream& plaintext, ofstream& ciphertext) {
    char ch[order];
    string pt, ciptext;
    pt = convert_stream_to_string(plaintext);
    int i = 0;
    int j = 0;
    while (true) {
        j = 0;
        while (i < pt.length() && j < order)
            if (islower(pt[i++]))
                ch[j++] = pt[i-1]-'a';
        if (j < order) // not enough characters
            break;
        for (int p = 0; p < order; p++) {
            int ct = 0;
            for (int q = 0; q < order; q++) {
                ct += (ch[q]*key[q][p])%26;
            }
            ct %= 26;
            ciptext += char(ct+'A');
        }
    }
    i = 0;
    j = 0;
    while (i < pt.length()) {
        if (isspace(pt[i]))
            ciphertext << pt[i];
        else
            ciphertext << ciptext[j++];
        i++;
    }
}

void Hill::decrypt(ifstream& ciphertext, ofstream& plaintext) {
    int **K_inv;
    K_inv = new int*[order];
    for (int i = 0; i < order; i++) {
        K_inv[i] = new int[order];
    }
    MatrixInversion(key, order, K_inv);
    char ch[order];
    string ct, pltext;
    ct = convert_stream_to_string(ciphertext);
    int i = 0;
    int j = 0;
    while (true) {
        j = 0;
        while (i < ct.length() && j < order)
            if (isupper(ct[i++]))
                ch[j++] = ct[i-1]-'A';
        if (j < order) // not enough characters
            break;
        for (int p = 0; p < order; p++) {
            int pt = 0;
            for (int q = 0; q < order; q++) {
                pt += (ch[q]*K_inv[q][p])%26;
            }
            pt %= 26;
            pltext += char(pt+'a');
        }
    }
    i = 0;
    j = 0;
    while (i < ct.length()) {
        if (isspace(ct[i])) {
            plaintext << ct[i];
        }
        else
            plaintext << pltext[j++];
        i++;
    }
    for (int i = 0; i < this->order; i++) {
        delete [] K_inv[i];
    }
    delete [] K_inv;
}

Hill::~Hill() {
    for (int i = 0; i < this->order; i++) {
        delete [] key[i];
    }
    delete [] key;
}