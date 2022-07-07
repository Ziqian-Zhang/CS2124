//
//  Warrior.hpp
//  hw06
//
//  Created by Ziqian Zhang on 2022/3/23.
//

#ifndef Warrior_hpp
#define Warrior_hpp

#include <string>
#include <ostream>
#include <iostream>

namespace WarriorCraft{
    class Noble;
    class Warrior{
        friend std::ostream& operator <<(std::ostream& os,
                                         const Warrior& aWarrior);
    public:
        // constructor
        Warrior(const std::string& theName, double theStrength);
        //getter
        // check if the warrior is already hired by a noble
        bool isHired() const;
        // get the name of the warrior
        const std::string& getName() const;
        // get the strength of the warior
        double getStrength() const;
        //setters
        // a warrior is get hired, setting his boss to be a Noble
        // pointer
        void setHired(Noble* aBoss);
        // the warrior loses certain health after a battle
        void setStrength(double damage);
        // a warrior runs away
        bool runaway();

    private:
        std::string name;
        double strength;
        Noble* boss;
    };
}

#endif /* Warrior_hpp */

