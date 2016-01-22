//
//  Stallings_Standard.cpp
//  Classical Ciphers
//
//  Created by Prakhar Jain on 13/01/16.
//  Copyright © 2016 Prakhar Jain. All rights reserved.
//

#include "Stallings_Standard.hpp"

using namespace std;

void convert_to_standard(ifstream& unformatted_pt, ofstream& plaintext) {
    char ch;
    while (unformatted_pt >> noskipws >> ch)  {
        if (isspace(ch))
            plaintext << ch;
        else if (isupper(ch)) {
            ch = tolower(ch);
            plaintext << ch;
        }
        else if (islower(ch)) {
            plaintext << ch;
        }
        // else skip all characters
    }
}

string convert_stream_to_string(ifstream& stream) {
    string input;
    string line;
    while (getline(stream,line)) {
        input += line + "\n";
    }
    return input;
}