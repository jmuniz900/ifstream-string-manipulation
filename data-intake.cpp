#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "data-intake.h"

using namespace std;

//n = 6 <---- amount of people on file.

int main(){
  fstream file;

  string firstName;
  string lastName;
  string fullName;

  float mAccount;
  PERSON person[6];

  file.open("data.txt");
  if(file.is_open()){
    while(file.eof() == false){
      file >> firstName >> lastName >> mAccount;
      fullName = firstName + " " + lastName;

      // cout << fullName << " " << salary << endl;
      for(int i = 0; i < 6; i++){
      //  cin.get(person[i].name[i], fullName.c_str());
        person[i].balance = mAccount;
      }
      }
  }
  else
    cout << "File couldn't open!" << endl;

/*cout << "    Name     " << "Balance" << endl;
cout << "_____________________________" << endl;
for(int j = 0; j < 20; j++){
  cout << people << endl;
} */
    return 0;
}
