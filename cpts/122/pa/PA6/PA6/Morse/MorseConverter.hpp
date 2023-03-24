//
//  MorseConverter.hpp
//  PA6
//
//  Created by Benjamin Schreiber on 3/23/23.
//

#ifndef MorseConverter_hpp
#define MorseConverter_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cctype>
#include "BST.hpp"
#include "MorseData.hpp"
#include "BSTFactory.hpp"
#define morseTablePath "/Users/benjaminschreiber/wsu-2022-notes/cpts/122/pa/PA6/PA6/Morse/MorseTable.txt"

namespace MorseConverter {
    void fromFile(std::string path) {
        
        // Open file
        std::ifstream file(path);
        
        // begin bst
        BST<MorseData> bst = BSTFactory::fromMorseFile(morseTablePath);
        bst.print();
        
        // Read file
        std::string line;
        while (getline(file, line)) {

            // String stream so we can read from the line and seperate via each character
            for (const char &i : line) {
                if (i == ' ') continue;
                char upper = toupper(i);
                std::cout << bst.find({upper}).morseCode << " ";
            }
            std::cout << std::endl;
        }
        file.close();
    }
}

#endif /* MorseConverter_hpp */
