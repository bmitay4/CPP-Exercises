#include "PhoneticFinder.hpp"

#include <bits/stdc++.h>

#include <tr1/unordered_map>

using namespace phonetic;
unordered_map<char, char> setsMap;

string phonetic::find(string text, const char value[]) {
    std::istringstream iss(text);
    std::vector<std::string> results(std::istream_iterator<std::string>{iss},
                                     std::istream_iterator<std::string>());
    for (std::string word : results) {
        if (isEqual(word, value)) return word;
    }
    setsChecks();
    return "---";
}
// Verify if the string contains simply the given word
bool phonetic::isEqual(string word, string value) {
    if ((word.compare(value)) == 0)
        return true;
    else
        return false;
}
// Build a map contains all sets
void phonetic::setsChecks() {
    // v,w
    setsMap.insert({'v', 'w'});
    // b,f,p
    setsMap.insert({'b', 'f'});
    setsMap.insert({'b', 'p'});
    // g,j
    setsMap.insert({'g', 'j'});
    // c,k,q
    setsMap.insert({'c', 'k'});
    setsMap.insert({'c', 'q'});
    // s,z
    setsMap.insert({'s', 'z'});
    // d,t
    setsMap.insert({'d', 't'});
    // o,u
    setsMap.insert({'o', 'u'});
    // i,y
    setsMap.insert({'i', 'y'});
}
