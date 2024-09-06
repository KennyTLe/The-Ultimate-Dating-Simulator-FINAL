#ifndef LIGHTSKIN_H
#define LIGHTSKIN_H
#include "Character.h"
using namespace std;

class LightSkin : public Character {
   public:
    LightSkin(string _name);

    //string getFileName();
    void PrintAll();
    void FirstDate();
    void SecondDate();
    void ThirdDate();
    private:
      string fileName = "lightskin.txt";

    
};

#endif