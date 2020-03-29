#include <cstring>
#include <iostream>
using namespace std;

int main() {

    string text;
    text.resize(3);
    text[0] = '1';
    text[2] = '3';

    for(int i = 0; i < 3; i++){
    if(!text[i]) text[i] = '7';
    cout << text[i] << endl;
    }
    return 0;
}
