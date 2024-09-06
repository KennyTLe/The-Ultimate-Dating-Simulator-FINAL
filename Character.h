#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
using namespace std;

class Character{
   public:
      Character();
      Character(int hp, int m1, int m2, int m3);
      Character(string _name);
      virtual void PrintAll()=0;    //set the stats
      virtual void FirstDate()=0;   //set the firstdate
      virtual void SecondDate()=0;  //set the seconddate
      virtual void ThirdDate()=0;   //set the thirddate

      string getName();             // return the name
      int getHealth();              // return the health
      int getMove1();               // return the move1
      int getMove2();               // return the move2
      int getMove3();               // return the move3

      void setName(string _name);   // set the name
      void setHealth(int);          // set the health
      void setMove1(int);           // set the move1
      void setMove2(int);           // set the move2
      void setMove3(int);           // set the move3

      void printName();             // print the name

   private:
      string name;
      int health;
      int move1;
      int move2;
      int move3;
};

#endif