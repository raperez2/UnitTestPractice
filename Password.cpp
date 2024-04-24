#include "Password.h"
#include <string>
#include <cctype>
#include <vector>

using std::string;
using std::vector;

/*
  Sets the first password in the list to "ChicoCA-95929"
*/
Password::Password(){
  pass_history.push_back("ChicoCA-95929");
}

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

//The function receives a string, checks for at least one Uppercase letter and a single Lowercase letter.
//and any ASCII characters are allowed.
bool Password::has_mixed_case(string phrase){
  bool upper = false, lower = false;
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

void Password::set(string phrase){
  if(phrase.length() >=8 && phrase.length() <=20){
    if(has_mixed_case(phrase) && count_leading_characters(phrase) <= 3){
      int index = sizeof(pass_history);
      if(pass_history[index-1] != phrase){
        pass_history.push_back(phrase);
      }
    }
  }
}

bool Password::authenticate(string phrase){
  bool result = false;
  int index = sizeof(pass_history);
  if(phrase == pass_history.back()){
    result = true;
  }
  return result;
}
