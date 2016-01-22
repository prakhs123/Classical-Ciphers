//
//  Letter_Frequency.cpp
//  Classical Ciphers
//
//  Created by Prakhar Jain on 13/01/16.
//  Copyright © 2016 Prakhar Jain. All rights reserved.
//

#include "Letter_Frequency.hpp"
#include <cctype>
#include <vector>
using namespace std;

bool fun(pair<char, double> T1, pair<char, double> T2) {
    return T1.second > T2.second;
}

void letterFrequency(ifstream& text, ofstream& frequencytable) {
    long table[128] = {0};
    long count = 0;
    char ch;
    while (text >> ch) {
        if (isalpha(ch)) {
            table[ch]++;
            count++;
        }
    }
    vector<long> frequencies (table, table + 128);
    vector< pair<char,double> > rel_frequency;
    int i = 0;
    for (vector<long>::iterator it = frequencies.begin(); it != frequencies.end(); it++) {
        rel_frequency.push_back(make_pair(char(i),(double)*it/count*100));
        i++;
    }
    sort(rel_frequency.begin(), rel_frequency.end(), fun);
    i = 1;
    frequencytable << "=====================RELATIVE FREQUENCY=====================" << endl << endl;
    for (vector<pair<char, double>> :: iterator it = rel_frequency.begin(); it != rel_frequency.end(); it++){
        if ((*it).second > 0) {
            frequencytable << i << " " << (*it).second << endl;
            i++;
        }
    }
}