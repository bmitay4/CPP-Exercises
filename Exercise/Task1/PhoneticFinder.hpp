#ifndef _PHONETICFINDER_H
#define _PHONETICFINDER_H

#include "iostream"

using namespace std;

namespace phonetic {
string find(string text, const char[]);
void setsMapChecks();
bool isWordEqual(string word, string value);
bool searchForChanges(string word, string value);
bool verifyUpperLowerChar(string, string); 
bool isLettersMixed(string, string);
}  // namespace phonetic

#endif