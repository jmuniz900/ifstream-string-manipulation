//Jose Muniz
//Section 3

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

PERSON * readData(int n);
void display(PERSON *personArray, int &nPeople);
void FindRichest(PERSON *personArray, int &nPeople);
void Deposit(string &name, PERSON *personArray, int &nPeople, float &amount);
void NewCopy(string &fileName, PERSON *personArray, int &nPeople);

PERSON * readData(int n){
  PERSON *personPtr = new PERSON[7];

  fstream file;
  string fileName = "data.txt";

  string firstName;
  string lastName;
  string fullName;

  int mPeople = 0;
  //char charName[20];

  float mAccount;

  file.open(fileName);
  if(file.is_open()){
    cout << "Successfully opened " << fileName << endl;
    while(file.eof() == false){
      file >> firstName >> lastName;
      file >> personPtr[mPeople].balance;
      fullName = firstName + " " + lastName;

        strcpy(personPtr[mPeople].name, fullName.c_str());

    //    cout << endl << "Amount of People: " << mPeople + 1 << endl;
    //  for(int i = 0; i < 6; i++){
  //      cout << personPtr[i].name << " " << personPtr[i].balance << endl;
          mPeople++;
      }
    //  cout << endl << "Amount of People: " << mPeople << endl;
      //  mPeople++;
    // }
      }
    else{
    cout << "File couldn't open!" << endl;
}
//  cout << *personPtr << endl;
    file.close();
    return personPtr;
}
void display(PERSON * personArray, int &nPeople){

    cout << "Name          " << "Balance  " << endl;
    cout << "--------------------------" << endl;
    for(int i = 0; i < nPeople; i++){
        cout << personArray[i].name;
        cout << " " << personArray[i].balance << endl;
    }
}
void FindRichest(PERSON *personArray, int &nPeople){
  float tmp = personArray[0].balance;

  for(int i = 0; i < nPeople; i++){
    while(tmp < personArray[i].balance){
      tmp = personArray[i].balance;
      }
    }
      cout << "The person with the highest balance is ";
    for(int i = 0; i < nPeople; i++){
        if(tmp == personArray[i].balance){
          cout << personArray[i].name;
        }
      }
    cout << endl;
}
void Deposit(string &name, PERSON *personArray, int &nPeople, float &amount){

//  float addMoney;
  char tmpName[20];
  string tmpName2;
  int counter = 0;

/*  cout << name << ", how much would you like to deposit? " << endl;
  cin >> addMoney;
  cout << endl;
  */

strcpy(tmpName, name.c_str());

while(counter < nPeople){

  tmpName2 = personArray[counter].name;
  if(name == tmpName2){
    personArray[counter].balance += amount;
    cout << "Now your new balance is: " << personArray[counter].balance;
    cout << endl;
  }
    counter++;
}

}
void NewCopy(string &fileName, PERSON *personArray, int &nPeople){
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
    PERSON * person = new PERSON [6];
    int mPeople = 6;
    string fileName = "data.txt";
    string inputName;
    float amountM;


    person = readData(mPeople);

    cout << endl << endl;
    display(person, mPeople);
    cout << endl << endl;
    FindRichest(person, mPeople);
    cout << endl;

    cout << "Enter your full name to deposit money: ";
    getline(cin, inputName);
    cout << inputName << ", how much would you like to deposit? " << endl;
    cin >> amountM;
    cout << endl;
    cout << endl;
    Deposit(inputName, person, mPeople, amountM);

    cout << "Enter your full name to deposit money: ";
    getline(cin, inputName);
    cout << inputName << ", how much would you like to deposit? " << endl;
    cin >> amountM;
    cout << endl;
    Deposit(inputName, person, mPeople, amountM);

    FindRichest(person, mPeople);

  /*  NewCopy(fileName, person, mPeople);


 /* cout << person[0].balance << endl;
    for(int j = 0; j < 20; j++)
    cout << person[2].name[j] << " " << endl; */

    return 0;
}
