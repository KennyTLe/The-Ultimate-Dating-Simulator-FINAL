#include "Character.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

Character::Character(){
  health = 0;
  move1 = 0;
  move2 = 0;
  move3 = 0;
  name = "Unknown";
}
Character::Character(int hp, int m1, int m2, int m3){
  health = hp;
  move1 = m1;
  move2 = m2;
  move3 = m3;
  name = "Unknown";
}
Character::Character(string _name){
  health = 0;
  move1 = 0;
  move2 = 0;
  move3 = 0;
  name = _name;
}

//Get user inputted choices
string Character::getName(){
   return name;
}
int Character::getHealth(){
   return health;
}
int Character::getMove1(){
   return move1;
}
int Character::getMove2(){
   return move2;
}
int Character::getMove3(){
   return move3;
}

//Set user inputted choices
void Character::setName(string _name){
   name = _name;
}
void Character::setHealth(int _health){
   health = _health;
}
void Character::setMove1(int _move1){
   move1 = _move1;
}
void Character::setMove2(int _move2){
   move2 = _move2;
}
void Character::setMove3(int _move3){
   move3 = _move3;
}

//Output user inputted choices
void Character::printName(){
  cout << endl << "Name: " << name << "\n" << endl;
}
