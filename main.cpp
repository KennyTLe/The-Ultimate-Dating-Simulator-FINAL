#include "Character.h"
#include "LightSkin.h"
#include "Shy.h"
#include "Normal.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

//creates save file
void safeFile(Character *user, string classType){
  ofstream os;
  os.open("saveFile.txt");
  os << classType << endl;
  os << user->getMove2() << endl;
  os << user->getName();
}

//loads the save file
void loadFile(Character *&user, string& classType){
  ifstream ss;
  ss.open("saveFile.txt");
  int temp;
  string cT, _name;
  ss >> cT;
  classType = cT;

  ss >>temp;
  ss.ignore();
  getline(ss, _name);

  //save file for lightskin class
  if(classType == "lightskin"){
    user = new LightSkin(_name);
    user->setMove2(temp);
    if(temp == 50){
      user->setMove1(5);
      user->setHealth(120);
      user->setMove3(40);
    }
    else if(temp == 60){
      user->setMove1(10);
      user->setHealth(180);
      user->setMove3(80);
    }
    else if(temp == 75){
      user->setMove1(20);
      user->setHealth(250);
      user->setMove3(120);
    }
  }
  //save file for shy class
  else if(classType == "shy"){
    user = new Shy(_name);
    user->setMove2(temp);
    if(temp == 50){
      user->setMove1(15);
      user->setHealth(80);
      user->setMove3(20);
    }
    else if(temp == 60){
      user->setMove1(30);
      user->setHealth(120);
      user->setMove3(40);
    }
    else if(temp == 75){
      user->setMove1(50);
      user->setHealth(180);
      user->setMove3(60);
    }
  }
  //save file for normal class
  else if(classType == "normal"){
    user = new Normal(_name);
    user->setMove2(temp);
    if(temp == 50){
      user->setMove1(10);
      user->setHealth(100);
      user->setMove3(25);
    }
    else if(temp == 60){
      user->setMove1(20);
      user->setHealth(150);
      user->setMove3(50);
    }
    else if(temp == 75){
      user->setMove1(40);
      user->setHealth(225);
      user->setMove3(80);
    }
  }
}

int main() {
  int startUp;
  string name;
  Character *user;
  string yesorno;
  string classType;
  
  //select menu option
  cout << endl << "THE ULTIMATE DATING SIMULATOR!\n" << endl;
  cout << "1 - New Game\n" << "2 - Load Game\n" << "3 - Quit Game\n" << endl;
  cin >> startUp;
  
if(startUp == 1) {
  system("clear");
  
  //User is prompted with a question upon their name.
  cout << "\nWelcome to THE ULTIMATE DATING SIMULATOR!" << endl;
  cout << "\nFirst, what is your name?" << endl;
  cin.ignore();
  getline(cin, name);
  cout << endl << "Name: " << name << "\n" << endl;

  //User is prompted with a question upon their character type.
  cout << "\nWhat will be your RIZZ type?" << endl;
  cout << endl << "1 - Light Skin Rizz" << endl;
  cout << endl << "2 - Shy Rizz" << endl;
  cout << endl << "3 - Normal Rizz" << endl;
  string type;
  cin >> type;

  system("clear");
  // User selects their RIZZ type
  if(type == "1"){ 
    classType = "lightskin";
    cout << endl << "RIZZ Type: " << type << " - Light Skin" << "\n" << endl;
    cout << endl << "Type 1 - Light Skin (120 hp) Moveset:" << endl;
    cout << "Smooth Compliment - 5 dmg" << endl;
    cout << "Handheld Mirror Check - heals 50 health" << endl;
    cout << "Light Skin Stare (3 round charge up) - 40 dmg" << endl;
    cout << endl << "Are you sure you want to continue with this class?(Yes or No)" << endl;
  }
  else if(type == "2"){ 
    classType = "shy";
    cout << endl << "RIZZ Type: " << type << " - Shy" << "\n" << endl;
    cout << endl << "Type 2 - Shy (80 hp) Moveset:" << endl;
    cout << "Shy Compliment - 15 dmg" << endl;
    cout << "Bathroom Break - heals 50 health" << endl;
    cout << "UWU Blush (3 round charge up) - 20 dmg" << endl;
    cout << endl << "Are you sure you want to continue with this class?(Yes or No)" << endl;
  }
  else if(type == "3"){ 
    classType = "normal";
    cout << endl << "RIZZ Type: " << type << " - Normal" << "\n" << endl;
    cout << endl << "Type 3 - Normal (100 hp) Moveset:" << endl;
    cout << "Normal Compliment - 10 dmg" << endl;
    cout << "Change Topic - heals 50 health" << endl;
    cout << "Tease (3 round charge up) - 25 dmg" << endl;
    cout << endl << "Are you sure you want to continue with this class? (Yes or No)" << endl;
  }
  else {
    while(!((type == "1") || (type == "2") || (type == "3"))){
      cout << endl << "... That's literally not an option, try again.\n" << endl;
      cin >> type;
    }
    if(type == "1"){ 
      classType = "lightskin";
      cout << endl << "RIZZ Type: " << type << " - Light Skin" << "\n" << endl;
      cout << endl << "Type 1 - Light Skin (120 hp) Moveset:" << endl;
      cout << "Smooth Compliment - 5 dmg" << endl;
      cout << "Handheld Mirror Check - heals 50 health" << endl;
      cout << "Light Skin Stare (3 round charge up) - 40 dmg" << endl;
      cout << endl << "Are you sure you want to continue with this class?(Yes or No)" << endl;
    }
    else if(type == "2"){ 
      classType = "shy";
      cout << endl << "RIZZ Type: " << type << " - Shy" << "\n" << endl;
      cout << endl << "Type 2 - Shy (80 hp) Moveset:" << endl;
      cout << "Shy Compliment - 15 dmg" << endl;
      cout << "Bathroom Break - heals 50 health" << endl;
      cout << "UWU Blush (3 round charge up) - 20 dmg" << endl;
      cout << endl << "Are you sure you want to continue with this class?(Yes or No)" << endl;
    }
    else if(type == "3"){ 
      classType = "normal";
      cout << endl << "RIZZ Type: " << type << " - Normal" << "\n" << endl;
      cout << endl << "Type 3 - Normal (100 hp) Moveset:" << endl;
      cout << "Normal Compliment - 10 dmg" << endl;
      cout << "Change Topic - heals 50 health" << endl;
      cout << "Tease (3 round charge up) - 25 dmg" << endl;
      cout << endl << "Are you sure you want to continue with this class? (Yes or No)" << endl;
    }
  }

  cin >> yesorno;
  system("clear");
  // User can reselect their type if they want to
  while(!((yesorno == "YES") || (yesorno == "Yes") || (yesorno == "yes"))){
    if((yesorno == "NO") || (yesorno == "No") || (yesorno == "no")){
      cout << "\nWhat will be your RIZZ type?" << endl;
      cout << endl << "1 - Light Skin Rizz" << endl;
      cout << endl << "2 - Shy Rizz" << endl;
      cout << endl << "3 - Normal Rizz" << endl;
      cin >> type;
    
      system("clear");
      
      if(type == "1"){ 
        classType = "lightskin";
        cout << endl << "RIZZ Type: " << type << " - Light Skin" << "\n" << endl;
        cout << endl << "Type 1 - Light Skin (120 hp) Moveset:" << endl;
        cout << "Smooth Compliment - 5 dmg" << endl;
        cout << "Handheld Mirror Check - heals 50 health" << endl;
        cout << "Light Skin Stare (3 round charge up) - 40 dmg" << endl;
        cout << endl << "Are you sure you want to continue with this class?(Yes or No)" << endl;
      }
      else if(type == "2"){ 
        classType = "shy";
        cout << endl << "RIZZ Type: " << type << " - Shy" << "\n" << endl;
        cout << endl << "Type 2 - Shy (80 hp) Moveset:" << endl;
        cout << "Shy Compliment - 15 dmg" << endl;
        cout << "Bathroom Break - heals 50 health" << endl;
        cout << "UWU Blush (3 round charge up) - 20 dmg" << endl;
        cout << endl << "Are you sure you want to continue with this class?(Yes or No)" << endl;
      }
      else if(type == "3"){ 
        classType = "normal";
        cout << endl << "RIZZ Type: " << type << " - Normal" << "\n" << endl;
        cout << endl << "Type 3 - Normal (100 hp) Moveset:" << endl;
        cout << "Normal Compliment - 10 dmg" << endl;
        cout << "Change Topic - heals 50 health" << endl;
        cout << "Tease (3 round charge up) - 25 dmg" << endl;
        cout << endl << "Are you sure you want to continue with this class? (Yes or No)" << endl;
      }
      else {
        while(!((type == "1") || (type == "2") || (type == "3"))){
          cout << endl << "... That's literally not an option, try again.\n" << endl;
          cin >> type;
        }
        if(type == "1"){ 
          classType = "lightskin";
          cout << endl << "RIZZ Type: " << type << " - Light Skin" << "\n" << endl;
          cout << endl << "Type 1 - Light Skin (120 hp) Moveset:" << endl;
          cout << "Smooth Compliment - 5 dmg" << endl;
          cout << "Handheld Mirror Check - heals 50 health" << endl;
          cout << "Light Skin Stare (3 round charge up) - 40 dmg" << endl;
          cout << endl << "Are you sure you want to continue with this class?(Yes or No)" << endl;
        }
        else if(type == "2"){ 
          classType = "shy";
          cout << endl << "RIZZ Type: " << type << " - Shy" << "\n" << endl;
          cout << endl << "Type 2 - Shy (80 hp) Moveset:" << endl;
          cout << "Shy Compliment - 15 dmg" << endl;
          cout << "Bathroom Break - heals 50 health" << endl;
          cout << "UWU Blush (3 round charge up) - 20 dmg" << endl;
          cout << endl << "Are you sure you want to continue with this class?(Yes or No)" << endl;
        }
        else if(type == "3"){ 
          classType = "normal";
          cout << endl << "RIZZ Type: " << type << " - Normal" << "\n" << endl;
          cout << endl << "Type 3 - Normal (100 hp) Moveset:" << endl;
          cout << "Normal Compliment - 10 dmg" << endl;
          cout << "Change Topic - heals 50 health" << endl;
          cout << "Tease (3 round charge up) - 25 dmg" << endl;
          cout << endl << "Are you sure you want to continue with this class? (Yes or No)" << endl;
        }
      }
      cin >> yesorno;
    }
    else {
      while(!((yesorno == "YES") || (yesorno == "Yes") || (yesorno == "yes") || (yesorno == "NO") || (yesorno == "No") || (yesorno == "no"))){
        cout << endl << "It's a Yes or No question... please try again.\n" << endl;
        cin >> yesorno;
      }
      if((yesorno == "YES") || (yesorno == "Yes") || (yesorno == "yes")){
      cout << endl;
    } 
      else if((yesorno == "NO") || (yesorno == "No") || (yesorno == "no")){
        cout << "\nWhat will be your RIZZ type?" << endl;
        cout << endl << "1 - Light Skin Rizz" << endl;
        cout << endl << "2 - Shy Rizz" << endl;
        cout << endl << "3 - Normal Rizz" << endl;
        cin >> type;
      
        system("clear");
        
        if(type == "1"){ 
          classType = "lightskin";
          cout << endl << "RIZZ Type: " << type << " - Light Skin" << "\n" << endl;
          cout << endl << "Type 1 - Light Skin (120 hp) Moveset:" << endl;
          cout << "Smooth Compliment - 5 dmg" << endl;
          cout << "Handheld Mirror Check - heals 50 health" << endl;
          cout << "Light Skin Stare (3 round charge up) - 40 dmg" << endl;
          cout << endl << "Are you sure you want to continue with this class?(Yes or No)" << endl;
        }
        else if(type == "2"){ 
          classType = "shy";
          cout << endl << "RIZZ Type: " << type << " - Shy" << "\n" << endl;
          cout << endl << "Type 2 - Shy (80 hp) Moveset:" << endl;
          cout << "Shy Compliment - 15 dmg" << endl;
          cout << "Bathroom Break - heals 50 health" << endl;
          cout << "UWU Blush (3 round charge up) - 20 dmg" << endl;
          cout << endl << "Are you sure you want to continue with this class?(Yes or No)" << endl;
        }
        else if(type == "3"){ 
          classType = "normal";
          cout << endl << "RIZZ Type: " << type << " - Normal" << "\n" << endl;
          cout << endl << "Type 3 - Normal (100 hp) Moveset:" << endl;
          cout << "Normal Compliment - 10 dmg" << endl;
          cout << "Change Topic - heals 50 health" << endl;
          cout << "Tease (3 round charge up) - 25 dmg" << endl;
          cout << endl << "Are you sure you want to continue with this class? (Yes or No)" << endl;
        }
        else {
          while(!((type == "1") || (type == "2") || (type == "3"))){
            cout << endl << "... That's literally not an option, try again.\n" << endl;
            cin >> type;
          }
          if(type == "1"){ 
            classType = "lightskin";
            cout << endl << "RIZZ Type: " << type << " - Light Skin" << "\n" << endl;
            cout << endl << "Type 1 - Light Skin (120 hp) Moveset:" << endl;
            cout << "Smooth Compliment - 5 dmg" << endl;
            cout << "Handheld Mirror Check - heals 50 health" << endl;
            cout << "Light Skin Stare (3 round charge up) - 40 dmg" << endl;
            cout << endl << "Are you sure you want to continue with this class?(Yes or No)" << endl;
          }
          else if(type == "2"){ 
            classType = "shy";
            cout << endl << "RIZZ Type: " << type << " - Shy" << "\n" << endl;
            cout << endl << "Type 2 - Shy (80 hp) Moveset:" << endl;
            cout << "Shy Compliment - 15 dmg" << endl;
            cout << "Bathroom Break - heals 50 health" << endl;
            cout << "UWU Blush (3 round charge up) - 20 dmg" << endl;
            cout << endl << "Are you sure you want to continue with this class?(Yes or No)" << endl;
          }
          else if(type == "3"){
            classType = "normal";
            cout << endl << "RIZZ Type: " << type << " - Normal" << "\n" << endl;
            cout << endl << "Type 3 - Normal (100 hp) Moveset:" << endl;
            cout << "Normal Compliment - 10 dmg" << endl;
            cout << "Change Topic - heals 50 health" << endl;
            cout << "Tease (3 round charge up) - 25 dmg" << endl;
            cout << endl << "Are you sure you want to continue with this class? (Yes or No)" << endl;
          }
        }
        cin >> yesorno;
      }
    }
  }
  system("clear");

  // User selected type gets saved
  if(type == "1"){
    user = new LightSkin(name);
  }
  if(type == "2"){
    user = new Shy(name);
  }
  if(type == "3"){
    user = new Normal(name);
  }

  // User is shown their stats before they begin
  user->PrintAll();
  cout << endl << "Type \"Start\" to begin!" << endl;
  string begin;
  cin >> begin;

  // After user chooses to start, the first level begins
  while(!((begin == "start") || (begin == "Start"))){
    cout << "Not an option, try again." << endl;
  }
  if((begin == "start") || (begin == "Start")){
    user->FirstDate();
  }

  //Second Date continue or save?
  cout << endl << "Do you want to continue to the next date?" << endl;
  cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
  cout << endl << "1 - Continue to next date (Auto Saves)" << endl;
  cout << endl << "2 - Save and Quit Game" << endl;
  cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
  cin >> begin;
  if(begin == "1"){
    safeFile(user, classType);
    user->SecondDate();
  }
  else if(begin == "2"){
    safeFile(user, classType);
    system("clear");
  return 0;
  }
  else{
    while(!(begin == "1" || (begin == "2"))){
      cout << endl << "Not an option, please try again." << endl;
      
      cout << endl << "Do you want to continue to the next date?" << endl;
      cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
      cout << endl << "1 - Continue to next date (Auto Saves)" << endl;
      cout << endl << "2 - Save and Quit Game" << endl;
      cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
      string begin;
      cin >> begin;
      if(begin == "1"){
        safeFile(user, classType);
        user->SecondDate();
      }
      else if(begin == "2"){
        safeFile(user, classType);
        system("clear");
      return 0;
      }
    }
  }
  
// Third Date continue or save?
  cout << endl << "Do you want to continue to the next date?" << endl;
  cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
  cout << endl << "1 - Continue to next date (Auto Saves)" << endl;
  cout << endl << "2 - Save and Quit Game" << endl;
  cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
  cin >> begin;
  if(begin == "1"){
    safeFile(user, classType);
    user->ThirdDate();
  }
  else if(begin == "2"){
    safeFile(user, classType);
    system("clear");
  return 0;
  }
  else{
    while(!(begin == "1" || (begin == "2"))){
      cout << endl << "Not an option, please try again." << endl;
      
      cout << endl << "Do you want to continue to the next date?" << endl;
      cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
      cout << endl << "1 - Continue to next date (Auto Saves)" << endl;
      cout << endl << "2 - Save and Quit Game" << endl;
      cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
      string begin;
      cin >> begin;
      if(begin == "1"){
        safeFile(user, classType);
        user->ThirdDate();
      }
      else if(begin == "2"){
        safeFile(user, classType);
        system("clear");
      return 0;
      }
    }
  }
}

  
else if(startUp == 2) {
  loadFile(user, classType);
  //IF USER LOAD IS ON DATE 1
  if(user->getMove2() == 50){
    // User is shown their stats before they begin
    user->PrintAll();
    cout << endl << "Type \"Start\" to begin!" << endl;
    string begin;
    cin >> begin;

    // After user chooses to start, the first level begins
    while(!((begin == "start") || (begin == "Start"))){
      cout << "Not an option, try again." << endl;
    }
    if((begin == "start") || (begin == "Start")){
      user->FirstDate();
    }
    //Second Date continue or save?
    cout << endl << "Do you want to continue to the next date?" << endl;
    cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << endl << "1 - Continue to next date (Auto Saves)" << endl;
    cout << endl << "2 - Save and Quit Game" << endl;
    cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cin >> begin;
    if(begin == "1"){
      safeFile(user, classType);
      user->SecondDate();
    }
    else if(begin == "2"){
      safeFile(user, classType);
      system("clear");
    return 0;
    }
    else{
      while(!(begin == "1" || (begin == "2"))){
        cout << endl << "Not an option, please try again." << endl;
        
        cout << endl << "Do you want to continue to the next date?" << endl;
        cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
        cout << endl << "1 - Continue to next date (Auto Saves)" << endl;
        cout << endl << "2 - Save and Quit Game" << endl;
        cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
        string begin;
        cin >> begin;
        if(begin == "1"){
          safeFile(user, classType);
          user->SecondDate();
          // Third Date continue or save?
          cout << endl << "Do you want to continue to the next date?" << endl;
          cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
          cout << endl << "1 - Continue to next date (Auto Saves)" << endl;
          cout << endl << "2 - Save and Quit Game" << endl;
          cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
          string begin;
          cin >> begin;
          if(begin == "1"){
            safeFile(user, classType);
            user->ThirdDate();
          }
          else if(begin == "2"){
            safeFile(user, classType);
            system("clear");
          return 0;
          }
          else{
            while(!(begin == "1" || (begin == "2"))){
              cout << endl << "Not an option, please try again." << endl;
              
              cout << endl << "Do you want to continue to the next date?" << endl;
              cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
              cout << endl << "1 - Continue to next date (Auto Saves)" << endl;
              cout << endl << "2 - Save and Quit Game" << endl;
              cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
              string begin;
              cin >> begin;
              if(begin == "1"){
                safeFile(user, classType);
                user->ThirdDate();
              }
              else if(begin == "2"){
                safeFile(user, classType);
                system("clear");
              return 0;
              }
            }
          }
        }
        else if(begin == "2"){
          safeFile(user, classType);
          system("clear");
        return 0;
        }
      }
    }
    
  // Third Date continue or save?
    cout << endl << "Do you want to continue to the next date?" << endl;
    cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << endl << "1 - Continue to next date (Auto Saves)" << endl;
    cout << endl << "2 - Save and Quit Game" << endl;
    cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cin >> begin;
    if(begin == "1"){
      safeFile(user, classType);
      user->ThirdDate();
    }
    else if(begin == "2"){
      safeFile(user, classType);
      system("clear");
    return 0;
    }
    else{
      while(!(begin == "1" || (begin == "2"))){
        cout << endl << "Not an option, please try again." << endl;
        
        cout << endl << "Do you want to continue to the next date?" << endl;
        cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
        cout << endl << "1 - Continue to next date (Auto Saves)" << endl;
        cout << endl << "2 - Save and Quit Game" << endl;
        cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
        string begin;
        cin >> begin;
        if(begin == "1"){
          safeFile(user, classType);
          user->ThirdDate();
        }
        else if(begin == "2"){
          safeFile(user, classType);
          system("clear");
        return 0;
        }
      }
    }
  }

  // IF USER LOAD IS ON DATE 2
  else if(user->getMove2() == 60){
    //Second Date continue or save?
    user->PrintAll();
    cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << endl << "Do you want to continue to the next date?" << endl;
    cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << endl << "1 - Continue to next date (Auto Saves)" << endl;
    cout << endl << "2 - Save and Quit Game" << endl;
    cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    string save;
    cin >> save;
    if(save == "1"){
      safeFile(user, classType);
      user->SecondDate();
      // Third Date continue or save?
      cout << endl << "Do you want to continue to the next date?" << endl;
      cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
      cout << endl << "1 - Continue to next date (Auto Saves)" << endl;
      cout << endl << "2 - Save and Quit Game" << endl;
      cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
      string begin;
      cin >> begin;
      if(begin == "1"){
        safeFile(user, classType);
        user->ThirdDate();
      }
      else if(begin == "2"){
        safeFile(user, classType);
        system("clear");
      return 0;
      }
      else{
        while(!(begin == "1" || (begin == "2"))){
          cout << endl << "Not an option, please try again." << endl;
          
          cout << endl << "Do you want to continue to the next date?" << endl;
          cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
          cout << endl << "1 - Continue to next date (Auto Saves)" << endl;
          cout << endl << "2 - Save and Quit Game" << endl;
          cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
          string begin;
          cin >> begin;
          if(begin == "1"){
            safeFile(user, classType);
            user->ThirdDate();
          }
          else if(begin == "2"){
            safeFile(user, classType);
            system("clear");
          return 0;
          }
        }
      }
    }
    else if(save == "2"){
      safeFile(user, classType);
      system("clear");
    return 0;
    }
    else{
      while(!(save == "1" || (save == "2"))){
        cout << endl << "Not an option, please try again." << endl;

        user->PrintAll();
        cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
        cout << endl << "Do you want to continue to the next date?" << endl;
        cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
        cout << endl << "1 - Continue to next date (Auto Saves)" << endl;
        cout << endl << "2 - Save and Quit Game" << endl;
        cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
        string save;
        cin >> save;
        if(save == "1"){
          safeFile(user, classType);
          user->SecondDate();
          // Third Date continue or save?
          cout << endl << "Do you want to continue to the next date?" << endl;
          cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
          cout << endl << "1 - Continue to next date (Auto Saves)" << endl;
          cout << endl << "2 - Save and Quit Game" << endl;
          cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
          string begin;
          cin >> begin;
          if(begin == "1"){
            safeFile(user, classType);
            user->ThirdDate();
          }
          else if(begin == "2"){
            safeFile(user, classType);
            system("clear");
          return 0;
          }
          else{
            while(!(begin == "1" || (begin == "2"))){
              cout << endl << "Not an option, please try again." << endl;
              
              cout << endl << "Do you want to continue to the next date?" << endl;
              cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
              cout << endl << "1 - Continue to next date (Auto Saves)" << endl;
              cout << endl << "2 - Save and Quit Game" << endl;
              cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
              string begin;
              cin >> begin;
              if(begin == "1"){
                safeFile(user, classType);
                user->ThirdDate();
              }
              else if(begin == "2"){
                safeFile(user, classType);
                system("clear");
              return 0;
              }
            }
          }
        }
        else if(save == "2"){
          safeFile(user, classType);
          system("clear");
        return 0;
        }
      }
    }
  }
  else if(user->getMove2() == 75){
    // Third Date continue or save?
    user->PrintAll();
    cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << endl << "Do you want to continue to the next date?" << endl;
    cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << endl << "1 - Continue to next date (Auto Saves)" << endl;
    cout << endl << "2 - Save and Quit Game" << endl;
    cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    string save;
    cin >> save;
    if(save == "1"){
      safeFile(user, classType);
      user->ThirdDate();
    }
    else if(save == "2"){
      safeFile(user, classType);
      system("clear");
    return 0;
    }
    else{
      while(!(save == "1" || (save == "2"))){
        cout << endl << "Not an option, please try again." << endl;

        user->PrintAll();
        cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
        cout << endl << "Do you want to continue to the next date?" << endl;
        cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
        cout << endl << "1 - Continue to next date (Auto Saves)" << endl;
        cout << endl << "2 - Save and Quit Game" << endl;
        cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
        string save;
        cin >> save;
        if(save == "1"){
          safeFile(user, classType);
          user->ThirdDate();
        }
        else if(save == "2"){
          safeFile(user, classType);
          system("clear");
        return 0;
        }
      }
    }
  }
  
}
  
else if(startUp == 3) {
  system("clear");
  return 0;
}
  
}
