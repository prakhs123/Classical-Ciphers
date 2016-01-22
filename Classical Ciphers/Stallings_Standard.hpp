//
//  Stallings_Standard.hpp
//  Classical Ciphers
//
//  Created by Prakhar Jain on 13/01/16.
//  Copyright © 2016 Prakhar Jain. All rights reserved.
//

#ifndef Stallings_Standard_hpp
#define Stallings_Standard_hpp

#include <iostream>
#include <fstream>
#include <string>

void convert_to_standard(std::ifstream& unformatted_ct, std::ofstream& ciphertext);
std::string convert_stream_to_string(std::ifstream& stream);
#endif /* Stallings_Standard_hpp */
