//
//  Warrior.cpp
//  hw06
//
//  Created by Ziqian Zhang on 2022/3/23.
//

#include "Warrior.h"
#include "Noble.h"

using namespace std;
namespace WarriorCraft{
    ostream& operator <<(ostream& os,
                              const Warrior& aWarrior){
        os << "    " << aWarrior.name << ": "
        << aWarrior.strength;
        return os;
    }
    Warrior::Warrior(const string& theName, double theStrength) :
    name(theName), strength(theStrength), boss(nullptr){ }
    // getters
    // check if the warrior is being hired by some noble
    bool Warrior::isHired() const {
        if (boss == nullptr){
            return false;
        }
        return true;
    }
    // get the name of the warrior
    const string& Warrior::getName() const{ return name; }
    // get the strength of the warior
    double Warrior::getStrength() const{ return strength; }
    // setters
    // a warrior is being hired
    void Warrior::setHired(Noble* aBoss){ boss = aBoss; }
    // the warrior loses certain health after a battle
    // the setStrength method for the warrior class
    void Warrior::setStrength(double damage){
        if(damage == 0){
            strength = 0;
        }else{
            strength = strength * (1.0 - damage);
        }
    }
    // a warrior quit from his noble
    bool Warrior::runaway(){
        if (boss == nullptr){
            return false;
        }
        if (strength == 0){
            return false;
        }
        boss->afterFlee(this);
        boss = nullptr;
        return true;
    }
}

