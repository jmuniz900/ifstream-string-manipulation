#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

//n = 6 <---- amount of people on file.

struct PERSON{
public:  char name[20];
  float balance;
};

void display(PERSON (&personArray)[10], int &nPeople);
void FindRichest(PERSON (&personArray)[10], int &nPeople);
void Deposit(string &name, PERSON (&personArray)[10], int &nPeople);

void display(PERSON (&personArray)[10], int &nPeople){

    cout << "Name      " << "Balance  " << endl;
    cout << "--------------------------" << endl;
    for(int i = 0; i < nPeople; i++){
      for(int j = 0; j < 20; j++)
        cout << personArray[i].name[j];
    cout << " " << personArray[i].balance << endl;
    }
}
void FindRichest(PERSON (&personArray)[10], int &nPeople){
  float tmp = personArray[0].balance;

  for(int i = 0; i < nPeople; i++){
    while(tmp < personArray[i].balance){
      tmp = personArray[i].balance;
      }
    }
      cout << "The person with the highest balance is ";
    for(int i = 0; i < nPeople; i++){
      for(int j = 0; j < 20; j++){
        if(tmp == personArray[i].balance){
          cout << personArray[i].name[j];
        }
      }
    }
    cout << endl;
}
void Deposit(string &name, PERSON (&personArray)[10], int &nPeople){


}

int main(){
  fstream file;

  string firstName;
  string lastName;
  string fullName;

  int mPeople = 6;
  char charName[20];
  int i = 0;

  float mAccount;
  PERSON person[10];

  file.open("data.txt");
  if(file.is_open()){
    while(file.eof() == false){
      file >> firstName >> lastName >> mAccount;
      fullName = firstName + " " + lastName;

    //  cout << fullName << " " << mAccount << endl;
    //  for(int i = 0; i < 10; i++){
        strcpy(charName, fullName.c_str());
      for(int a = 0; a < fullName.length(); a++){
        person[i].name[a] = charName[a];
      }
        person[i].balance = mAccount;

        i++;
    // }
      }
    file.close();
  }
  else
    cout << "File couldn't open!" << endl;

    display(person, mPeople);
    cout << endl << endl;
    FindRichest(person, mPeople);
    cout << endl;

    string name;
    Deposit()

 /* cout << person[0].balance << endl;
    for(int j = 0; j < 20; j++)
    cout << person[2].name[j] << " " << endl; */

    return 0;
}
