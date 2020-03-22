#include "PhoneticFinder.hpp"

#include <bits/stdc++.h>

#include <tr1/unordered_map>

using namespace phonetic;
unordered_multimap<char, string> setsMap;

string phonetic::find(string text, const char value[]) {
    std::istringstream iss(text);
    std::vector<std::string> results(std::istream_iterator<std::string>{iss},
                                     std::istream_iterator<std::string>());
    setsMapChecks();
    for (std::string word : results) {
        if (isWordEqual(word, value))
            return word;
        else if (word.length() == strlen(value))
            if (searchForChanges(word, value)) return word;
    }
    string tempValue = value;
    throw std::invalid_argument("Did not find the word '" + tempValue +"' in the text");
}const char *std::exception::what() const noexcept

// Verify if the string contains simply the given word
bool phonetic::isWordEqual(string word, string value) {
    if ((word.compare(value)) == 0)
        return true;
    else
        return false;
}
// Build a map contains all sets
void phonetic::setsMapChecks() {
    // v,w
    setsMap.insert({'v', "w"});
    setsMap.insert({'w', "v"});
    // b,f,p
    setsMap.insert({'b', "fp"});
    setsMap.insert({'f', "pb"});
    setsMap.insert({'p', "bf"});
    // g,j
    setsMap.insert({'g', "j"});
    setsMap.insert({'j', "g"});

    // c,k,q
    setsMap.insert({'c', "kq"});
    setsMap.insert({'k', "cq"});
    setsMap.insert({'q', "kc"});
    // s,z
    setsMap.insert({'s', "z"});
    setsMap.insert({'z', "s"});
    // d,t
    setsMap.insert({'d', "t"});
    setsMap.insert({'t', "d"});
    // o,u
    setsMap.insert({'o', "u"});
    setsMap.insert({'u', "o"});
    // i,y
    setsMap.insert({'i', "y"});
    setsMap.insert({'y', "i"});
}
// If both of the words are the same, look for the differents by map
bool phonetic::searchForChanges(string word, string value) {
    if (verifyUpperLowerChar(word, value)) return true;
    if (isLettersMixed(word, value)) return true;
    return false;
}
// Look for upper/lower differents
bool phonetic::verifyUpperLowerChar(string word, string value) {
    unsigned i;

    for (i = 0; i < word.length(); ++i) {
        if (word.at(i) != value.at(i)) {
            if (islower(word.at(i)) && isupper(value.at(i))) {
                word.at(i) = toupper(word.at(i));
            } else if (islower(value.at(i)) && isupper(word.at(i))) {
                word.at(i) = tolower(word.at(i));
            }
        }
    }
    if (isWordEqual(word, value)) return true;
    return false;
}
// Look for a mismatch
bool phonetic::isLettersMixed(string word, string value) {
    unsigned k;

    for (k = 0; k < word.length(); ++k) {
        if (word.at(k) != value.at(k)) {
            auto search = setsMap.find(value.at(k));
            if (search != setsMap.end()) {
                string tempValue = search->second;
                unsigned i;

                for (i = 0; i < tempValue.length(); ++i) {
                    if (word.at(k) == tempValue.at(i)) return true;
                }
            } else
                return false;
        }
    }
    return false;
}