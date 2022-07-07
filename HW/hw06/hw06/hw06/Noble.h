//
//  Noble.hpp
//  hw06
//
//  Created by Ziqian Zhang on 2022/3/23.
//

#ifndef Noble_hpp
#define Noble_hpp

#include <ostream>
#include <string>
#include <iostream>
#include <vector>

namespace WarriorCraft{
    class Warrior;
    // Noble class is here
    class Noble{
        // output operator overload
        friend std::ostream& operator<<(std::ostream& output,
                                        const Noble& aNoble);
    public:
        // constructor
        Noble(const std::string& theName);
        //getters
        //get the name of the noble
        const std::string& getName() const;
        // get a specific warrior in the army
        size_t findWarrior(const Warrior* aWarrior) const;
        // setters
        // set the new strength of the noble
        void setStrength(double damage);
        //other methods
        //hiring a warior
        bool hire(Warrior& aWarrior);
        // fire a warrior
        bool fire(Warrior& aWarrior);
        // battling with another noble
        void battle(Noble& aNoble);
        // set the strength of a noble after a warrior runs away
        void afterFlee(Warrior* runAway);
        
    private:
        std::string name;
        std::vector <Warrior*> army;
        double strength;
        bool living;
    };
}

#endif /* Noble_hpp */

