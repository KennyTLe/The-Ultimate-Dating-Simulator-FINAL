#include "Shy.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

Shy::Shy(string _name) : Character(80, 15, 50, 20){
  Character::setName(_name);
}

// Prints User Stats
void Shy::PrintAll(){
  system("clear");
  cout << endl << "Name: " << Character::getName() << endl;
  cout << endl << "Character Type: Shy" << endl;
  cout << "Health: " << Character::getHealth() << endl;
  cout << "Shy Compliment: " << Character::getMove1() << " dmg" << endl;
  cout << "Bathroom Break: " << Character::getMove2() << " hp healed" << endl;
  cout << "UWU Blush (3 round charge up): " << Character::getMove3() << " dmg" << endl;
}

// Initiates The First Date
void Shy::FirstDate(){
  system("clear");

  int dateHP = 100;
  int playerHP = Character::getHealth();
  int playerM1 = Character::getMove1();
  int playerM2 = Character::getMove2();
  int playerM3 = Character::getMove3();
  int turn;
  int charge = 0;
  int healremain = 2;
  string winorlose;
  
  string reply;
  cout << "\nLevel One: Briana Lunch Date" << endl;
  cout << "(Type \"n\" - next for next line)" << endl;
  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
  cout << endl << "\n*You sit down with Briana at your table as the waiter walks away after you ordererd.*" << endl;
  cin >> reply;
  cout << endl << "  Briana: \"Hey cutie pie, I like your hair.\"" << endl;
  cin >> reply;
  cout << endl << "  You: \"uhh...thanks...\"" << endl;
  cin >> reply;
  cout << endl << "  You: \"...I'm sorry Briana, but I will have to out rizz you...\"" << endl;
  cin >> reply;
  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
  cout << "DATE BEGINS!!!" << endl;
  cin >> reply;
  
  system("clear");
  cout << endl << "BRIANA LUNCH DATE (LEVEL 1)" << endl;
  cout << endl;
  
  while (dateHP > 0) {
    // If user loses, then they are prompted with Game Over screen.
    if(playerHP <= 0){
      dateHP -= 100;
      cout << "GAME OVER" << endl;
      winorlose = "lose";
    }
    else {
      // User Prompted with what move to use
      cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
      cout << endl << "Briana's State of Rizzed (Health): " << dateHP << endl;
      cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
      cout << endl << Character::getName() << "'s State of Rizzed (Health): " << playerHP << endl;
      cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl; 
      cout << endl << "Choose your move!" << endl;
  
      cout << endl;
      cout << "1 - Shy Compliment (" << Character::getMove1() << " dmg)" << endl; 
      cout << "2 - Bathroom Break (Heals " << Character::getMove2() << " health)" << endl; 
      cout << "3 - UWU Blush (3 round charge up) (" << Character::getMove3() << " dmg)" << endl; 
  
      cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl; 
      cout << endl;
  
      //Code takes in user choice and does accordingly
      cin >> turn;
      if(turn == 3){
        if(!(charge >= 3)){
          cout << "This move is not ready yet. It has a 3 round charge up." << endl;
          cout << "Choose another option." << endl;
          cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl; 
          cin >> turn;
        }
        else if(charge >= 3){
          dateHP -= Character::getMove3();
          charge = 0;
          cout << "You did " << Character::getMove3() << " dmg!" << endl;
          cout << endl << "Briana now has " << dateHP << " health left!" << endl;
        }
      }
      if(turn == 2){
        if(healremain == 0){
          cout << "You are out of heals. Choose another option." << endl;
          cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl; 
          cin >> turn;
          if(turn == 3){
            if(!(charge >= 3)){
              cout << "This move is not ready yet. It has a 3 round charge up." << endl;
              cout << "Choose another option." << endl;
              cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl; 
              cin >> turn;
            }
            else if(charge >= 3){
              dateHP -= Character::getMove3();
              charge = 0;
              cout << "You did " << Character::getMove3() << " dmg!" << endl;
              cout << endl << "Briana now has " << dateHP << " health left!" << endl;
            }
          }
          }
        else if(healremain != 0){
          playerHP += Character::getMove2();
          healremain -= 1;
          cout << "You healed for " << Character::getMove2() << " health!" << endl;
          cout << "You have " << healremain << " heal(s) left." << endl;
          cout << endl << "Briana still has " << dateHP << " health left!" << endl;
        }
      }
      
      if(turn == 1){
        dateHP -= Character::getMove1();
        cout << "You did " << Character::getMove1() << " dmg!" << endl;
        cout << endl << "Briana now has " << dateHP << " health left!" << endl;
      }
      
    playerHP -= 10;
    charge += 1;
    cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl; 
    cout << endl << "Briana did 10 dmg back to you!" << endl;
    cout << endl << "Type \"n\" for next" << endl;
    string reply;
    cin >> reply;
    system("clear");
    } 
  }
  // User clears level and reads story dialogue
  if(playerHP > 0){
    winorlose = "win";
  }
  cout << endl << "Type \"n\" for next" << endl;
  cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
  cin >> reply;

  if(winorlose == "win"){
    cout << endl << "\n*Briana blushes in embarrassment.*" << endl;
    cin >> reply;
    cout << endl << "  Briana: \"I didn't know you could rizz like that...\"" << endl;
    cin >> reply;
    cout << endl << "  You: \"uh...thanks...\"" << endl;
    cin >> reply;
    cout << endl << "  You: \"...it was fun to rizz you...\"" << endl;
    cin >> reply;
    cout << endl << "  Briana: \"Of course! I had a lot of fun!\"" << endl;
    cin >> reply;
    cout << endl << "  You: \"I'm sorry Briana but my end goal isn't you...\"" << endl;
    cin >> reply;
    cout << endl << "  Briana: \"Oh who is it then?\"" << endl;
    cin >> reply;
    cout << endl << "  You: \"...Mr. D...\"" << endl;
    cin >> reply;
    cout << endl << "  Briana: \"Well either way, your going to have to get through Tariq first...\"" << endl;
    cin >> reply;
    system("clear");
    
    cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << endl << "BRIANA LUNCH DATE (LEVEL 1) COMPLETED!" << endl;
    cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    Character::setHealth(120);
    Character::setMove1(30);
    Character::setMove2(60);
    Character::setMove3(40);
    cout << endl << "NEW UPDATED STATS:" << endl << endl;
    cout << "Health: " << Character::getHealth() << endl;
    cout << "Shy Compliment: " << Character::getMove1() << " dmg" << endl;
    cout << "Bathroom Break: " << Character::getMove2() << " hp healed" << endl;
    cout << "UWU Blush (3 round charge up): " << Character::getMove3() << " dmg" << endl;
    cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
  }
  if(winorlose == "lose"){
    cout << "Unfortunately You Have Been Out Rizzed";
  }
}

//////////////////////////////////////////

// Initiates The Second Date
void Shy::SecondDate(){
  system("clear");

  int dateHP = 200;
  int playerHP = Character::getHealth();
  int playerM1 = Character::getMove1();
  int playerM2 = Character::getMove2();
  int playerM3 = Character::getMove3();
  int turn;
  int charge = 0;
  int healremain = 2;
  string winorlose;
  
  string reply;
  cout << "\nLevel Two: Tariq Zoo Date" << endl;
  cout << "(Type \"n\" - next for next line)" << endl;
  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
  cout << endl << "\n*You and Tariq meet up at the Zoo entrance.*" << endl;
  cin >> reply;
  cout << endl << "  You: \"um...hi Tariq\"" << endl;
  cin >> reply;
  cout << endl << "  Tariq: \"...\"" << endl;
  cin >> reply;
  cout << endl << "  You: \"...hello Tariq?\"" << endl;
  cin >> reply;
  cout << endl << "  Tariq: \"Sorry, I'm a little slow at responding.\"" << endl;
  cin >> reply;
  cout << endl << "  You: \"Oh that's okay, are you nervous?\"" << endl;
  cin >> reply;
  cout << endl << "  You: \"...because I'm really nervous too...\"" << endl;
  cin >> reply;
  cout << endl << "  Tariq: \"Yea I usually respond or type slow when I'm nervous.\"" << endl;
  cin >> reply;
  cout << endl << "  Tariq: \"Well, unfortunately, your not gunna out rizz me...\"" << endl;
  cin >> reply;
  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
  cout << "DATE BEGINS!!! (Type \"n\" for next)" << endl;
  cin >> reply;
  
  system("clear");
  cout << endl << "TARIQ ZOO DATE (LEVEL 2)" << endl;
  cout << endl;
  
  while (dateHP > 0) {
    // If user loses, then they are prompted with Game Over screen.
    if(playerHP <= 0){
      dateHP -= 200;
      cout << "GAME OVER" << endl;
      winorlose = "lose";
    }
    else {
      // User Prompted with what move to use
      cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
      cout << endl << "Tariq's State of Rizzed (Health): " << dateHP << endl;
      cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
      cout << endl << Character::getName() << "'s State of Rizzed (Health): " << playerHP << endl;
      cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl; 
      cout << endl << "Choose your move!" << endl;
  
      cout << endl;
      cout << "1 - Shy Compliment (" << Character::getMove1() << " dmg)" << endl; 
      cout << "2 - Bathroom Break (Heals " << Character::getMove2() << " health)" << endl; 
      cout << "3 - UWU Blush (3 round charge up) (" << Character::getMove3() << " dmg)" << endl; 
  
      cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl; 
      cout << endl;
  
      //Code takes in user choice and does accordingly
      cin >> turn;
      if(turn == 3){
        if(!(charge >= 3)){
          cout << "This move is not ready yet. It has a 3 round charge up." << endl;
          cout << "Choose another option." << endl;
          cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl; 
          cin >> turn;
        }
        else if(charge >= 3){
          dateHP -= Character::getMove3();
          charge = 0;
          cout << "You did " << Character::getMove3() << " dmg!" << endl;
          cout << endl << "Tariq now has " << dateHP << " health left!" << endl;
        }
      }
      if(turn == 2){
        if(healremain == 0){
          cout << "You are out of heals. Choose another option." << endl;
          cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl; 
          cin >> turn;
          if(turn == 3){
            if(!(charge >= 3)){
              cout << "This move is not ready yet. It has a 3 round charge up." << endl;
              cout << "Choose another option." << endl;
              cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl; 
              cin >> turn;
            }
            else if(charge >= 3){
              dateHP -= Character::getMove3();
              charge = 0;
              cout << "You did " << Character::getMove3() << " dmg!" << endl;
              cout << endl << "Tariq now has " << dateHP << " health left!" << endl;
            }
          }
          }
        else if(healremain != 0){
          playerHP += Character::getMove2();
          healremain -= 1;
          cout << "You healed for " << Character::getMove2() << " health!" << endl;
          cout << "You have " << healremain << " heal(s) left." << endl;
          cout << endl << "Tariq still has " << dateHP << " health left!" << endl;
        }
      }
      
      if(turn == 1){
        dateHP -= Character::getMove1();
        cout << "You did " << Character::getMove1() << " dmg!" << endl;
        cout << endl << "Tariq now has " << dateHP << " health left!" << endl;
      }
      
    playerHP -= 20;
    charge += 1;
    cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl; 
    cout << endl << "Tariq did 20 dmg back to you!" << endl;
    cout << endl << "Type \"n\" for next" << endl;
    string reply;
    cin >> reply;
    system("clear");
    } 
  }
  // User clears level and reads story dialogue
  if(playerHP > 0){
    winorlose = "win";
  }
  cout << endl << "Type \"n\" for next" << endl;
  cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
  cin >> reply;

  if(winorlose == "win"){
    cout << endl << "  Tariq: \"...\"" << endl;
    cin >> reply;
    cout << endl << "  You: \"...I'm so sorry Tariq!\"" << endl;
    cin >> reply;
    cout << endl << "*Tariq is too shocked to respond...*" << endl;
    cin >> reply;
    cout << endl << "  Tariq: \"...\"" << endl;
    cin >> reply;
    cout << endl << "  You: \"...you were really good at rizzing me up too!\"" << endl;
    cin >> reply;
    cout << endl << "  Tariq: \"Yeah but no where near as good as you sadly...\"" << endl;
    cin >> reply;
    cout << endl << "*You blush in embarrassment*" << endl;
    cin >> reply;
    cout << endl << "*You run off in embarrassment*" << endl;
    cin >> reply;
    cout << endl << "  Tariq whilst you run off: \"YOU'LL NEVER OUT RIZZ ME AGAIN!!!\"" << endl;
    cin >> reply;
    system("clear");
    
    cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << endl << "TARIQ ZOO DATE (LEVEL 2) COMPLETED!" << endl;
    cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    Character::setHealth(180);
    Character::setMove1(50);
    Character::setMove2(75);
    Character::setMove3(60);
    cout << endl << "NEW UPDATED STATS:" << endl << endl;
    cout << "Health: " << Character::getHealth() << endl;
    cout << "Shy Compliment: " << Character::getMove1() << " dmg" << endl;
    cout << "Bathroom Break: " << Character::getMove2() << " hp healed" << endl;
    cout << "UWU Blush (3 round charge up): " << Character::getMove3() << " dmg" << endl;
    cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
  }
  if(winorlose == "lose"){
    cout << "Unfortunately You Have Been Out Rizzed";
  }
}

//////////////////////////////////////////

// Initiates The Third Date
void Shy::ThirdDate(){
  system("clear");

  int dateHP = 300;
  int playerHP = Character::getHealth();
  int playerM1 = Character::getMove1();
  int playerM2 = Character::getMove2();
  int playerM3 = Character::getMove3();
  int turn;
  int charge = 0;
  int healremain = 2;
  string winorlose;
  
  string reply;
  cout << "\nFinal Date: Dan E-Date" << endl;
  cout << "(Type \"n\" - next for next line)" << endl;
  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
  cout << endl << "\n*Dan joins the discord call.*" << endl;
  cin >> reply;
  cout << endl << "  Dan: \"Hi, how you doin?\"" << endl;
  cin >> reply;
  cout << endl << "  You: \"...I'm okay\"" << endl;
  cin >> reply;
  cout << endl << "  You: \"...do you wanna watch a movie...?\"" << endl;
  cin >> reply;
  cout << endl << "  Dan: \"Alright, what movie?\"" << endl;
  cin >> reply;
  cout << endl << "  You: \"wait... before we watch a movie...\"" << endl;
  cin >> reply;
  cout << endl << "  You: \"I'm sorry Dan...but I have to out rizz you first...\"" << endl;
  cin >> reply;
  cout << endl << "  Dan: \"Out rizz me? *PFTTT* Bring it on!\"" << endl;
  cin >> reply;
  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
  cout << "DATE BEGINS!!! (Type \"n\" for next)" << endl;
  cin >> reply;
  
  system("clear");
  cout << endl << "DAN E-DATE (FINAL DATE)" << endl;
  cout << endl;
  
  while (dateHP > 0) {
    // If user loses, then they are prompted with Game Over screen.
    if(playerHP <= 0){
      dateHP -= 200;
      cout << "GAME OVER" << endl;
      winorlose = "lose";
    }
    else {
      // User Prompted with what move to use
      cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
      cout << endl << "Dan's State of Rizzed (Health): " << dateHP << endl;
      cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
      cout << endl << Character::getName() << "'s State of Rizzed (Health): " << playerHP << endl;
      cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl; 
      cout << endl << "Choose your move!" << endl;
  
      cout << endl;
      cout << "1 - Shy Compliment (" << Character::getMove1() << " dmg)" << endl; 
      cout << "2 - Bathroom Break (Heals " << Character::getMove2() << " health)" << endl; 
      cout << "3 - UWU Blush (3 round charge up) (" << Character::getMove3() << " dmg)" << endl; 
  
      cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl; 
      cout << endl;
  
      //Code takes in user choice and does accordingly
      cin >> turn;
      if(turn == 3){
        if(!(charge >= 3)){
          cout << "This move is not ready yet. It has a 3 round charge up." << endl;
          cout << "Choose another option." << endl;
          cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl; 
          cin >> turn;
        }
        else if(charge >= 3){
          dateHP -= Character::getMove3();
          charge = 0;
          cout << "You did " << Character::getMove3() << " dmg!" << endl;
          cout << endl << "Dan now has " << dateHP << " health left!" << endl;
        }
      }
      if(turn == 2){
        if(healremain == 0){
          cout << "You are out of heals. Choose another option." << endl;
          cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl; 
          cin >> turn;
          if(turn == 3){
            if(!(charge >= 3)){
              cout << "This move is not ready yet. It has a 3 round charge up." << endl;
              cout << "Choose another option." << endl;
              cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl; 
              cin >> turn;
            }
            else if(charge >= 3){
              dateHP -= Character::getMove3();
              charge = 0;
              cout << "You did " << Character::getMove3() << " dmg!" << endl;
              cout << endl << "Dan now has " << dateHP << " health left!" << endl;
            }
          }
          }
        else if(healremain != 0){
          playerHP += Character::getMove2();
          healremain -= 1;
          cout << "You healed for " << Character::getMove2() << " health!" << endl;
          cout << "You have " << healremain << " heal(s) left." << endl;
          cout << endl << "Dan still has " << dateHP << " health left!" << endl;
        }
      }
      
      if(turn == 1){
        dateHP -= Character::getMove1();
        cout << "You did " << Character::getMove1() << " dmg!" << endl;
        cout << endl << "Dan now has " << dateHP << " health left!" << endl;
      }
      
    playerHP -= 30;
    charge += 1;
    cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl; 
    cout << endl << "Dan did 30 dmg back to you!" << endl;
    cout << endl << "Type \"n\" for next" << endl;
    string reply;
    cin >> reply;
    system("clear");
    } 
  }
  // User clears level and reads story dialogue
  if(playerHP > 0){
    winorlose = "win";
  }
  cout << endl << "Type \"n\" for next" << endl;
  cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
  cin >> reply;

  if(winorlose == "win"){
    cout << endl << "  Dan: \"It was a valiant effort!\"" << endl;
    cin >> reply;
    cout << endl << "  You: \"...I'm sorry...\"" << endl;
    cin >> reply;
    cout << endl << "  Dan: \"Why are you sorry for winning?\"" << endl;
    cin >> reply;
    cout << endl << "  You: \"...oh...I'm sorry\"" << endl;
    cin >> reply;
    cout << endl << "  You: \"...oh... I mean... um...\"" << endl;
    cin >> reply;
    cout << endl << "  Dan: \"I guess your the rizz god...\"" << endl;
    cin >> reply;
    cout << endl << "*You leave the discord call in embarrassment*" << endl;
    cin >> reply;
    system("clear");
    
    cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << endl << "DAN E-DATE (LEVEL 3) COMPLETED!" << endl;
    cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

    cout << endl << "CONGRATULATIONS YOU BEAT THE ULTIMATE DATING SIMULATOR!!!" << endl;
    cout << endl << "You, " << Character::getName() << ", are the ULTIMATE RIZZ MASTER!!!" << endl;
  }
  if(winorlose == "lose"){
    cout << "Unfortunately You Have Been Out Rizzed";
  }
}