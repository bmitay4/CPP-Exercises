//Strings are arrays as well, but there are some addons we can use on strings
//We'll use the cstring library, as well
#include <iostream>
#include <cstring>
using namespace std;

//Functions Decleration
int myStrLen(char *str);
void reverseString(char *str);
int searchInString(char *str, char a);

int searchInString(char *str, char a){
  int index = 0;
  char *sptr = str;
  while(*sptr != 0){
    if(*sptr == a)
      return index;
    index++;
    sptr++;
  }
  return -1;
}

void reverseString(char *str){
  int length = myStrLen(str);
  while(length > 0){
    cout << str[length];
    length--;
  }
  cout << endl;
}
int myStrLen(char *str){
  int count = 0;
  while(*str != 0){
    count++;
    str++;
  }
  return count;
}
int main(){
  char str[] = "Hello World";
  cout << str << ", Length: " << strlen(str) << endl;

  //Now lets try our function
  cout << str << ", Length: " << myStrLen(str) << endl;

  //Reverse and prints the string
  cout << "String reversed: ";
  reverseString(str);

  //Search for a letter (o) in a strings
  char letter = 'o';
  int ans = searchInString(str, letter);
  if(ans != -1)
    cout << letter << " Found in "<< str << "!, at index " << ans << endl;
  else
    cout << "Not Found :(" << endl;
  return 0;
}
