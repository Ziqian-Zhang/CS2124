//
//  main.cpp
//  hw05: Noble & Warrior battle, using dynamic memory
//
//  Created by Ziqian Zhang on 2022/3/2.
//

#include <iostream>
#include <vector>
#include <ostream>
#include <fstream>

using namespace std;

// Warrior class
class Warrior{
    // output operator overload
    friend ostream& operator <<(ostream& os, const Warrior& aWarrior){
        os << "    " << aWarrior.name << ": " << aWarrior.strength;
        return os;
    }
public:
    // constructor
    Warrior(const string& theName, int theStrength) : name(theName), strength(theStrength), hired(false) { }
    // a warrior is get hired
    void setHired(bool status){ hired = status; }
    // get the noble's name who hired him
    const bool hireStatus() const { return hired; }
    // get the name of the warrior
    const string& getName() const{ return name; }
    // the warrior loses certain health after a battle
    void setStrength(double damage);
    // get the strength of the warior
    const double getStrength() const{ return strength; }
private:
    string name;
    double strength;
    bool hired;
};

class Noble{
    // output operator overload
    friend ostream& operator<<(ostream& output, const Noble& aNoble){
        output << aNoble.name << " has an army of " << aNoble.army.size() << endl;
        for (const Warrior* each : aNoble.army){
            output << *each << endl;
        }
        return output;
    }
public:
    // constructor
    Noble(const string& theName) : name(theName), strength(0), living(true){ }
    //hiring a warior
    bool hire(Warrior* aWarrior);
    // fire a warrior
    bool fire(const string& aWarrior);
    // battling with another noble
    void battle(Noble* aNoble);
    // get the name of the noble
    const string& getName() const{ return name;}
    // get the strength of the noble
    const double getStrength() const{ return strength; }
    // set the new strength of the noble
    void setStrength(double damage);
    // get the living status of a noble
    const bool livingStatus() const { return living; }
private:
    string name;
    vector <Warrior*> army;
    double strength;
    bool living;
};
// function prototype
void createNoble(const string& name, vector <Noble*>& nobles);
void createWarrior(const string& name, double strength, vector <Warrior*>& warriors);
void hireAWarrior(const string& noble, const string& warrior,
                  const vector <Noble*>& nobles, const vector <Warrior*>& warriors);
void fireAWarrior(const string& noble, const string& warrior,
                  const vector <Noble*>& nobles, const vector <Warrior*>& warriors);
void nobleBattle(const string& challenger, const string& opponent,
                 const vector <Noble*>& nobles);
void displayNobleStatus(const vector <Noble*>& nobles);
void displayWarriorStatus(const vector <Warrior*>& warriors);
void clearAll(vector <Noble*>& nobles, vector <Warrior*>& warriors);

int main() {
    fstream nwFile("nobleWarriors.txt");
    if (!nwFile){
        cerr << "File not found." << endl;
        exit(1);
    }
    
    vector <Noble*> nobles;
    vector <Warrior*> warriors;
    
    string prefix;
    string nobleName, warriorName;
    string employer, employee;
    string challenger, opponent;
    double warriorStrength;
    
    while(nwFile >> prefix){
        if (prefix == "Noble"){
            nwFile >> nobleName;
            createNoble(nobleName, nobles);
        }else if (prefix == "Warrior"){
            nwFile >> warriorName;
            nwFile >> warriorStrength;
            createWarrior(warriorName, warriorStrength, warriors);
        }else if (prefix == "Hire"){
            nwFile >> employer;
            nwFile >> employee;
            hireAWarrior(employer, employee, nobles, warriors);
        }else if (prefix == "Fire"){
            nwFile >> employer;
            nwFile >> employee;
            fireAWarrior(employer, employee, nobles, warriors);
        }else if (prefix == "Battle"){
            nwFile >> challenger;
            nwFile >> opponent;
            nobleBattle(challenger, opponent, nobles);
        }else if (prefix == "Status"){
            cout << "Status" << endl;
            cout << "======" << endl;
            displayNobleStatus(nobles);
            displayWarriorStatus(warriors);
        }
        else if (prefix == "Clear"){
            clearAll(nobles, warriors);
        }
    }
    nwFile.close();
    return 0;
}
// definition of functions
// creating a noble
void createNoble(const string& name, vector <Noble*>& nobles){
    bool findNoble = false;
    for (const Noble* each: nobles){
        if (each->getName() == name){
            findNoble = true;
            cout << "The noble already exist." << endl;
            return;
        }
    }
    if(!findNoble){
        Noble* nobleptr = new Noble(name);
        nobles.push_back(nobleptr);
    }
}
// creating a warrior
void createWarrior(const string& name, double strength, vector <Warrior*>& warriors){
    bool findWarrior = false;
    for (const Warrior* each : warriors){
        if (each->getName() == name){
            findWarrior = true;
            cout << "The warrior already exist" << endl;
            return;
        }
    }
    if (!findWarrior){
        Warrior* warriorptr = new Warrior(name, strength);
        warriors.push_back(warriorptr);
    }
}
// a noble hires a warrior
void hireAWarrior(const string& noble, const string& warrior,
                  const vector <Noble*>& nobles, const vector <Warrior*>& warriors){
    bool nobleFind = false, warriorFind = false;
    for (Noble* eachN : nobles){
        if (eachN->getName() == noble){
            nobleFind = true;
            for (Warrior* eachW : warriors){
                if (eachW->getName() == warrior){
                    warriorFind = true;
                    eachN->hire(eachW);
                    return;
                }
            }
        }
    }
    if (!nobleFind){
        cout << noble << " doesn't exist in the list." << endl;
    }else if (!warriorFind){
        cout << "Attempting to hire using unknown warrior: "<< warrior << endl;
    }
}
// a noble fires a warrior
void fireAWarrior(const string& noble, const string& warrior,
                  const vector <Noble*>& nobles, const vector <Warrior*>& warriors){
    bool nobleFind = false;
    for (Noble* eachN : nobles){
        if (eachN->getName() == noble){
            nobleFind = true;
            if (eachN->fire(warrior)){
                cout << "You don't work for me anymore " <<
                warrior << "! -- " << noble << '.' << endl;
                return;
            }
        }
    }
    if (!nobleFind){
        cout << "Noble doesn't exist." << endl;
    }
}
// the battle between two nobles
void nobleBattle(const string& challenger, const string& opponent,
                 const vector <Noble*>& nobles){
    bool cFind = false, oFind = false;
    size_t cIndex = 0, oIndex = 0;
    for (size_t index = 0; index < nobles.size(); index++){
        if (nobles[index]->getName() == challenger){
            cFind = true;
            cIndex = index;
        }else if (nobles[index]->getName() == opponent){
            oFind = true;
            oIndex = index;
        }
        if (cFind && oFind){
            nobles[cIndex]->battle(nobles[oIndex]);
            return;
        }
    }
    if (!cFind){
        cout << challenger << " doesn't exist." << endl;
    }
    if (!oFind){
        cout << opponent << " doesn't exist." << endl;
    }
}
// the display function for the status of each noble and their army
void displayNobleStatus(const vector <Noble*>& nobles){
    cout << "Nobles:" << endl;
    if (nobles.size() == 0){
        cout << "NONE" << endl;
    }else{
        for (const Noble* each : nobles){
            cout << *each << endl;
        }
    }
}
// the display function for the status of each free warrior
void displayWarriorStatus(const vector <Warrior*>& warriors){
    bool free = false;
    cout << "Unemployed Warriors:" << endl;
    if (warriors.size() == 0){
        cout << "NONE" << endl;
    }else{
        for (const Warrior* each : warriors){
            if(!(each->hireStatus())){
                cout << *each << endl;
                free = true;
                }
        }
        if (!free){
            cout << "NONE" << endl;
        }
    }
}
// the clear function for the nobles and the warriors
void clearAll(vector <Noble*>& nobles, vector <Warrior*>& warriors){
    for (Noble* each : nobles){
        delete each;
    }
    nobles.clear();
    if (warriors.size() != 0){
        for (Warrior* each : warriors){
            delete each;
        }
        warriors.clear();
    }
}
// the noble class fire method
bool Noble::fire(const string& aWarrior){
    bool warrior = false;
    if(!living){
        cout << name << " is already dead and cannot fire anyone." << endl;
        return false;
    }else{
        for(size_t index = 0; index < army.size(); index++){
            if(army[index]->getName() == aWarrior){
                warrior = true;
                strength = strength - army[index]->getStrength();
                army[index]->setHired(false);
                while(index < army.size()){
                    army[index] = army[index + 1];
                    index++;
                    }
                break;
                }
            }
        if (warrior){
            army.pop_back();
            return true;
        }else{
            cout << "The warrior is not being hired by " << name << endl;
            return false;
        }
    }
}
// the hire method of the noble class
bool Noble::hire(Warrior* aWarrior) {
    if(aWarrior->hireStatus()){
        cout << "Attempt to hire "<< aWarrior->getName() << " by " << name << " failed" << endl;
        return false;
    }else if(!living){
        cout << name << "is already dead." << endl;
        return false;
    }else{
        army.push_back(aWarrior);
        aWarrior->setHired(true);
        strength = strength + aWarrior->getStrength();
        return true;
    }
}
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
// the setStrength method for the warrior class
void Warrior::setStrength(double damage){
    if(damage == 0){
        strength = 0;
    }else{
        strength = strength * (1.0 - damage);
    }
}
// the battle method
void Noble::battle(Noble* aNoble){
    cout << name << " battles ";
    cout << aNoble->getName() << endl;
    
    // if a noble battles himself
    if (aNoble->getName() == name){
        cout << "You can't fight with yourself, " << name << '.' << endl;
        return;
    }
    // check if both of them were dead
    if (!(aNoble->livingStatus()) && !(living)){
        cout << "Oh, NO! They're both dead! Yuck!" << endl;
    }
    // only the opponent is dead
    else if (!(aNoble->livingStatus())){
        cout << "He's dead, " << name << endl;
    }
    // only the challenger is dead
    else if (!(living)){
        cout << "He's dead, " << aNoble->getName() << endl;
    }

    // both of them are alive
    // the challenger is stronger than his opponent
    else if (strength > aNoble->getStrength()){
        double damage = aNoble->getStrength() / strength;
        cout << name << " defeats " << aNoble->getName() << endl;
        setStrength(damage);
        aNoble->setStrength(0);
    }
    // the opponent is stronger than the challenger
    else if (strength < aNoble->getStrength()){
        double damage = strength / aNoble->getStrength();
        cout << aNoble->getName() << " defeats " << name << endl;
        setStrength(0);
        aNoble->setStrength(damage);
    }
    // they are equally strong
    else if (strength == aNoble->getStrength() && living){
        cout << "Mutual Annihilation: " << name;
        cout << " and " << aNoble->getName() << " die at each other's hands\n";
        setStrength(0);
        aNoble->setStrength(0);
    }
}
