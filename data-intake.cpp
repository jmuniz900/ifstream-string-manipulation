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

    cout << "Name          " << "Balance  " << endl;
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
<<<<<<< HEAD


=======
  float addMoney;
  char tmpName[20];
  string tmpName2;
  int counter = 0;

  cout << name << ", how much would you like to deposit? " << endl;
  cin >> addMoney;
  cout << endl;

strcpy(tmpName, name.c_str());

while(counter < nPeople){
  //for(int i = 0; i < nPeople; i++){
    for(int j = 0; j < name.length(); j++ ){
      if(tmpName[j] == personArray[counter].name[j]){
          personArray[counter].balance += addMoney;
      }
    counter++;
    }
  }
  cout << "Now your new balance is: " << personArray[counter].balance;
  cout << endl;
>>>>>>> e06d8816bda381f9b4ab42e658f940f9e20e60ba
}

int main(){
  fstream file;

  string firstName;
  string lastName;
  string fullName;
  string inputName;

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
<<<<<<< HEAD
    cout << endl;

    string name;
    Deposit()
=======
    cout << "Enter your full name to deposit money: ";
    getline(cin, inputName);
    cout << endl;
    Deposit(inputName, person, mPeople);
>>>>>>> e06d8816bda381f9b4ab42e658f940f9e20e60ba

 /* cout << person[0].balance << endl;
    for(int j = 0; j < 20; j++)
    cout << person[2].name[j] << " " << endl; */

    return 0;
}
