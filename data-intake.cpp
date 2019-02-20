#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

//n = 6 <---- amount of people on file.

struct PERSON{
  char name[20];
  float balance;
};

void display(PERSON (&personArray)[10], int &nPeople);
void FindRichest(PERSON (&personArray)[10], int &nPeople);
void Deposit(string &name, PERSON (&personArray)[10], int &nPeople);
void NewCopy(string &fileName, PERSON (&personArray)[10], int &nPeople);

void display(PERSON (&personArray)[10], int &nPeople){

    cout << "Name          " << "Balance  " << endl;
    cout << "--------------------------" << endl;
    for(int i = 0; i < nPeople; i++){
        cout << personArray[i].name;
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

  float addMoney;
  char tmpName[20];
  string tmpName2;
  int counter = 0;

  cout << name << ", how much would you like to deposit? " << endl;
  cin >> addMoney;
  cout << endl;

strcpy(tmpName, name.c_str());

while(counter < nPeople){

  tmpName2 = personArray[counter].name;
  if(name == tmpName2){
    personArray[counter].balance += addMoney;
    cout << "Now your new balance is: " << personArray[counter].balance;
    cout << endl;
  }
    counter++;
}

}
void NewCopy(string &fileName, PERSON (&personArray)[10], int &nPeople){
  fstream file;
  file.open(fileName);

  if(file.is_open()){
    for(int i = 0; i < nPeople; i++){
      //for(int j = 0; j < 20; j++){
        file << personArray[i].name;
    //  }
      file << " " << personArray[i].balance << endl;
    }
  }
  else{
    cout << "Error: Could not open file!";
  }
  file.close();
}

int main(){
  fstream file;

  string fileName = "data.txt";

  string firstName;
  string lastName;
  string fullName;
  string inputName;

  int mPeople = 0;
  //char charName[20];

  float mAccount;
  PERSON person[10];

  file.open(fileName);
  if(file.is_open()){
    while(file.eof() == false){
      file >> firstName >> lastName >> mAccount;
      fullName = firstName + " " + lastName;

    //  cout << fullName << " " << mAccount << endl;
    //  for(int i = 0; i < 10; i++){
        strcpy(person[mPeople].name, fullName.c_str());
        person[mPeople].balance = mAccount;

        mPeople++;
    // }
      }
      mPeople -= 1;
    file.close();
  }
  else
    cout << "File couldn't open!" << endl;

    display(person, mPeople);
    cout << endl << endl;
    FindRichest(person, mPeople);
    cout << endl;

    cout << "Enter your full name to deposit money: ";
    getline(cin, inputName);
    cout << endl;
    Deposit(inputName, person, mPeople);

    NewCopy(fileName, person, mPeople);


 /* cout << person[0].balance << endl;
    for(int j = 0; j < 20; j++)
    cout << person[2].name[j] << " " << endl; */

    return 0;
}
