//
//  Noble.cpp
//  hw06
//
//  Created by Ziqian Zhang on 2022/3/23.
//

#include "Noble.h"
#include "Warrior.h"

using namespace std;
namespace WarriorCraft{
    // output operator overload
    ostream& operator<<(ostream& output, const Noble& aNoble){
        output << aNoble.name << " has an army of " << aNoble.army.size() << endl;
        for (const Warrior* each : aNoble.army){
            output << *each << endl;
        }
        return output;
    }
    //constructor
    Noble::Noble(const string& theName) : name(theName), strength(0), living(true){ }
    // getters
    //get the name of the noble
    const string& Noble::getName() const{ return name; }
    // to find a specific warrior in the noble's army
    size_t Noble::findWarrior(const Warrior* aWarrior) const{
        for (size_t index = 0; index < army.size(); ++index){
            if (army[index] == aWarrior){
                return index;
            }
        }
        return army.size();
    }
    // setters
    // the setStrength method of the noble class
    void Noble::setStrength(double damage){
        if(damage == 0){
            strength = damage;
            for(Warrior* each : army){
                each->setStrength(damage);
            }
            living = false;
        }else{
            strength = strength * (1.0 - damage);
            for (Warrior* each : army){
                each->setStrength(damage);
            }
        }
    }
    // the hire method of the noble class
    bool Noble::hire(Warrior& aWarrior) {
        if(aWarrior.isHired()){
            cout << aWarrior.getName()
            << " is already hired." << endl;
            return false;
        }else if(!living){
            cout << name << "is already dead." << endl;
            return false;
        }else{
            army.push_back(&aWarrior);
            aWarrior.setHired(this);
            strength = strength + aWarrior.getStrength();
            return true;
        }
    }
    // the noble class fire method
    bool Noble::fire(Warrior& aWarrior){
        if(!living){
            cout << name << " is already dead and cannot fire anyone." << endl;
            return false;
        }else{
            size_t index = findWarrior(&aWarrior);
            cout << "You don't work for me anymore " << army[index]->getName()
             << "! -- " << name << endl;
            if (index != army.size()){
                strength = strength - army[index]->getStrength();
                army[index]->setHired(nullptr);
                while(index < army.size()){
                    army[index] = army[index + 1];
                    index++;
                    }
                army.pop_back();
                return true;
            }
        }
        cout << "The warrior is not being hired by "
            << name << endl;
        return false;
    }
    // the battle method
    void Noble::battle(Noble& aNoble){
        cout << name << " battles ";
        cout << aNoble.name << endl;
        
        // if a noble battles himself
        if (&aNoble == this){
            cout << "You can't fight with yourself, "
            << name << '.' << endl;
            return;
        }
        // check if both of them were dead
        if (!(aNoble.living) && !(living)){
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
        }
        // only the opponent is dead
        else if (!(aNoble.living)){
            cout << "He's dead, " << name << endl;
        }
        // only the challenger is dead
        else if (!(living)){
            cout << "He's dead, " <<
            aNoble.name << endl;
        }
        else if (strength > aNoble.strength){
            double damage = aNoble.strength / strength;
            cout << name << " defeats "
            << aNoble.name << endl;
            setStrength(damage);
            aNoble.setStrength(0);
        }
        // the aNoble is stronger than the challenger
        else if (strength < aNoble.strength){
            double damage = strength / aNoble.strength;
            cout << aNoble.name << " defeats "
            << name << endl;
            setStrength(0);
            aNoble.setStrength(damage);
        }
        // they are equally strong
        else if (strength == aNoble.strength){
            cout << "Mutual Annihilation: " << name;
            cout << " and " << aNoble.name << " die at each other's hands\n";
            setStrength(0);
            aNoble.setStrength(0);
        }
    }
    // set the strength of the noble after a warrior runs away
    void Noble::afterFlee(Warrior* runAway){
        size_t idx = findWarrior(runAway);
        cout << army[idx]->getName()
        << " flees in terror, abandoning his lord, "
        << name << endl;
        while (idx < army.size()){
            army[idx] = army[idx + 1];
            idx++;
        }
        army.pop_back();
        strength = strength - runAway->getStrength();
        return;
    }
}

