#ifndef NORMAL_H
#define NORMAL_H
#include "Character.h"
using namespace std;

class Normal : public Character {
   public:
    Normal(string _name);

    //string getFileName();
    void PrintAll();
    void FirstDate();
    void SecondDate();
    void ThirdDate();
    private:
      string fileName = "normal.txt";

    
};

#endif