//
//  BSTFactory.hpp
//  PA6
//
//  Created by Benjamin Schreiber on 3/22/23.
//

#ifndef BSTFactory_hpp
#define BSTFactory_hpp

#include <stdio.h>
#include <fstream>
#include <sstream>
#include "BST.hpp"
#include "MorseData.hpp"

class BSTFactory {
private:
    BSTFactory() {}
public:
    
    static BST<MorseData> fromMorseFile(std::string filePath) {
        
        // Open file
        std::ifstream file(filePath);
        
        // begin bst
        BST<MorseData> bst;
        
        // Read file
        std::string line;
        while (getline(file, line)) {
            
            // String stream so we can read from the line and seperate via colon
            // This won't work when the file isn't formatted perfectly, but we get to ignore
            // that for this project :)
            std::stringstream ss(line);
            
            // Assemble a node
            MorseData data;
            std::string substr;
            getline(ss, substr, ':');
            data.character = substr[0];
            getline(ss, substr, ':');
            data.morseCode = substr;
            
            // Insert into tree
            bst.insert(data);
        }
        file.close();
        return bst;
    }
    
};

#endif /* BSTFactory_hpp */
