//
//  hw06_single.cpp
//  hw06
//
//  Created by Ziqian Zhang on 2022/3/23.
//
/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Noble;
class Warrior{
    friend ostream& operator <<(ostream& os, const Warrior& aWarrior);
public:
    // constructor
    Warrior(const string& theName, double theStrength);
    //getter
    // check if the warrior is already hired by a noble
    bool isHired() const;
    // get the name of the warrior
    const string& getName() const;
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
    string name;
    double strength;
    Noble* boss;
};


class Noble{
    // output operator overload
    friend ostream& operator<<(ostream& output, const Noble& aNoble);
public:
    // constructor
    Noble(const string& theName);
    //getters
    //get the name of the noble
    const string& getName() const;
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
    string name;
    vector <Warrior*> army;
    double strength;
    bool living;
};

int main() {
    Noble art("King Arthur");
    Noble lance("Lancelot du Lac");
    Noble jim("Jim");
    Noble linus("Linus Torvalds");
    Noble billie("Bill Gates");

    Warrior cheetah("Tarzan", 4);
    Warrior sky("Leia", 6);
    Warrior wizard("Merlin", 9);
    Warrior jaffa("Teal'c", 9);
    Warrior theGovernator("Conan", 12);
    Warrior nimoy("Spock", 15);
    Warrior lawless("Xena", 20);
    Warrior mrGreen("Hulk", 8);
    Warrior dylan("Hercules", 3);

    jim.hire(nimoy);
    lance.hire(theGovernator);
    art.hire(jaffa);
    art.hire(cheetah);
    art.hire(wizard);
    art.hire(sky);
    lance.hire(dylan);
    linus.hire(lawless);
    billie.hire(mrGreen);
    art.hire(nimoy);

    cout << "================ Initial Status ===============" << endl;
    cout << art << endl
         << lance << endl
         << jim << endl
         << linus << endl
         << billie << endl;
    cout << "===============================================\n\n";

    art.fire(cheetah);
    wizard.runaway();
    cout << endl << art << endl;

    art.battle(lance);
    jim.battle(lance);
    linus.battle(billie);
    billie.battle(lance);

    cout << "\n================ Final Status ===============" << endl;
    cout << art << endl
         << lance << endl
         << jim << endl
         << linus << endl
         << billie << endl;

    // Tarzan and Merlin should be unemployed
    cout << "Tarzan's Hire Status: " << boolalpha
         << cheetah.isHired() << endl;
    cout << "Merlin's Hire Status: " << boolalpha
         << wizard.isHired() << endl;
    cout << "===============================================\n\n";
}

ostream& operator <<(ostream& os, const Warrior& aWarrior){
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

// Noble Code

// output operator overload
ostream& operator<<(ostream& output, const Noble& aNoble){
    output << aNoble.name << " has an army of " << aNoble.army.size() << endl;
    for (const Warrior* each : aNoble.army){
        output << *each << endl;
    }
    return output;
}
//constructor
Noble::Noble(const string& theName) : name(theName), strength(0), living(true){}

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
        cout << "You don't work for me anymore " << army[index]->getName() << "! -- "
         << name << endl;
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
*/
