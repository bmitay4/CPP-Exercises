#include "iostream"
using namespace std;

void myfun(string &a) { a.at(6) = 's'; }

int main() {
    string s = "good moring all";
    s.at(3) = 'a';
    cout << s << endl;

    myfun(s);
    cout << s << endl;
    return 0;
}