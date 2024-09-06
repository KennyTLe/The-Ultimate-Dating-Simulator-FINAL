#ifndef SHY_H
#define SHY_H
#include "Character.h"
using namespace std;

class Shy : public Character {
   public:
    Shy(string _name);

    //string getFileName();
    void PrintAll();
    void FirstDate();
    void SecondDate();
    void ThirdDate();
    private:
      string fileName = "shy.txt";

    
};

#endif