#ifndef _PHONETICFINDER_H
#define _PHONETICFINDER_H

#include "iostream"

using namespace std;

namespace phonetic {
string find(string, const char[]);
void setsChecksMap();
bool isWordEqual(string);
bool lengthEqual();
void resizeStr();
bool searchForChanges();
bool testUpperLower(); 
bool testMixLetters();
}  // namespace phonetic

#endif