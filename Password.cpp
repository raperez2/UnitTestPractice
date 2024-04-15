#include "Password.h"
#include <string>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 1;
  int index = 0;
  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}

/*
  The function receives a string, checks for at least one Uppercase letter and a single Lowercase letter.
  and any ASCII characters are allowed.
*/
bool Password::has_mixed_case(string phrase){
  bool upper, lower = false;
  int index = 0;
  while( index < phrase.length()-1){
    if(isupper(phrase[index])){
      upper = true;
    }else if(islower(phrase[index])){
      lower = true;
    }
    index++;
  }
  return (upper && lower);
}
