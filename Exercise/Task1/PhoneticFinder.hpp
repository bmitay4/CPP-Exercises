#ifndef _PHONETICFINDER_H
#define _PHONETICFINDER_H

#include "iostream"

using namespace std;

namespace phonetic {
string find(string text, const char[]);
bool isEqual(string word, string value);
void setsChecks();

}

#endif