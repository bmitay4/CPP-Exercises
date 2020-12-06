#include "PhoneticFinder.hpp"

#include <bits/stdc++.h>

#include <tr1/unordered_map>

using namespace phonetic;

unordered_map<char, string> setsMap;
string globalValue, globalWord;
string testedWord;

// Struct conatins the error message
struct MyException : public std::exception {
    const string valueStr =
        "Did not find the word '" + globalValue + "' in the text";
    const char* what() const throw() { return valueStr.data(); }
};
// Main function
string phonetic::find(string text, string value) {
    std::istringstream iss(text);
    std::vector<std::string> results(std::istream_iterator<std::string>{iss},
                                     std::istream_iterator<std::string>());
    globalValue = value;
    setsChecksMap();

    for (std::string word : results) {
        globalWord = word;
        if (isWordEqual(word)) return globalWord;
        if (lengthEqual() && searchForChanges()) return globalWord;
    }
    throw MyException();
}
// Build a map contains all sets
void phonetic::setsChecksMap() {
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
// Verify if the string contains simply the given word
bool phonetic::isWordEqual(string str) {
    if ((str.compare(globalValue)) == 0) return true;
    return false;
}
bool phonetic::lengthEqual() {
    if (globalWord.length() == globalValue.length()) return true;
    return false;
}
// If both of the words are the same, look for the differents by map
bool phonetic::searchForChanges() {
    if (testUpperLower()) return true;
    if (testMixLetters()) return true;
    return false;
}
// Look for upper/lower differents
bool phonetic::testUpperLower() {
    resizeStr();
    unsigned i;
    char wordChar, valueChar;

    for (i = 0; i < globalWord.length(); ++i) {
        wordChar = globalWord.at(i);
        valueChar = globalValue.at(i);

        if (wordChar != valueChar) {
            if (toupper(wordChar) == valueChar ||
                tolower(wordChar) == valueChar)
                testedWord[i] = valueChar;
        } else
            testedWord[i] = wordChar;
    }
    if (isWordEqual(testedWord)) return true;
    return false;
}
// Look for a mismatch
bool phonetic::testMixLetters() {
    unsigned i, j;
    char wordChar, valueChar, tempChar;
    string tempStr;

    for (i = 0; i < globalWord.length(); ++i) {
        wordChar = globalWord.at(i);
        valueChar = globalValue.at(i);

        if (!testedWord[i]) {
            auto search = setsMap.find(tolower(valueChar));

            if (search != setsMap.end()) {
                tempStr = search->second;

                for (j = 0; j < tempStr.length(); ++j) {
                    tempChar = tempStr.at(j);
                    if (wordChar == tempChar || tolower(wordChar) == tempChar)
                        testedWord[i] = valueChar;
                }
            }
        }
    }
    if (isWordEqual(testedWord)) return true;
    return false;
}
// Reset and resize the global string
void phonetic::resizeStr() {
    testedWord = "";
    testedWord.resize(globalWord.length());
}