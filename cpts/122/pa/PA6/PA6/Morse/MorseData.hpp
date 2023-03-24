//
//  MorseData.hpp
//  PA6
//
//  Created by Benjamin Schreiber on 3/21/23.
//

#ifndef MorseData_hpp
#define MorseData_hpp

#include <stdio.h>
#include <ostream>

// Struct for creating morse code data
struct MorseData {
    std::string morseCode{""};
    char character{'\0'};
    
    MorseData() {}
    
    MorseData(std::string _morseCode, char _character)
        : morseCode(_morseCode), character(_character)
    {}
    MorseData(char _character)
        : character(_character)
    {}
    
    friend bool operator==(const MorseData &a, const MorseData &b) {
        return a.character == b.character;
    }

    friend bool operator<(const MorseData &a, const MorseData &b) {
        return a.character < b.character;
    }

    friend bool operator>(const MorseData &a, const MorseData &b) {
        return a.character > b.character;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const MorseData &data)
    {
        os << data.character;
        return os;
    }
};

#endif /* MorseData_hpp */
