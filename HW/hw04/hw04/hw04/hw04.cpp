//
//  main.cpp
//  hw04: Nobles Battle with the Armies of Warriors
//
//  Created by Ziqian Zhang on 2022/2/22.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Warrior{
    // overload output operator
    friend ostream& operator<<(ostream& os, const Warrior& theWarrior){
        os << "     " << theWarrior.name << ": " << theWarrior.strength;
        return os;
    }
public:
    // constructor
    Warrior(const string& theName, double theStrength)
    : name(theName), strength(theStrength), hired(false){};
    const string& getName() const { return name; }
    double getStrength() const { return strength; }
    void setStrength(double theStrength){ strength = theStrength; }
    bool getHired() const { return hired; }
    void changeHired(){ hired = !hired; }
private:
    string name;
    double strength;
    bool hired;
};

class Noble{
    // overload output operator
    friend ostream& operator<<(ostream& os, const Noble& theNoble){
        os << theNoble.name << " has an army of " << theNoble.army.size() << endl;
        for (const Warrior* curr_ptr : theNoble.army){
            os << *curr_ptr << endl;
        }
        return os;
    }
public:
    // Constructor
    Noble(const string& theName):name(theName), army(), alive(true){};
    // get the total strength of the army
    double getArmyStrength() const {
        double total_strength = 0;
        for (const Warrior* const& curr_ptr : army){
            total_strength += curr_ptr->getStrength();
        }
        return total_strength;
    }
    
    // modify the strength of the each warrior after the battle by the ratio
    void changeArmyStrength(int winner, int loser){
        for(Warrior*& curr_ptr : army){
            double newStrength = curr_ptr->getStrength()
            * (winner - loser) / winner;
            curr_ptr->setStrength(newStrength);
        }
    }
    
    bool getStatus() const{
        return alive;
    }
    
    // make the stadus of the noble be dead,
    // and modify the strength of each warrior to zero
    void changeStatus(){
        alive = false;
        changeArmyStrength(1, 1);
    }
    
    bool hire(Warrior& aWarrior){
        // A Warrior cannot be hired away if he is already employed
        // Nobles who are dead cannot hire anyone
        if (aWarrior.getHired() || !alive){
            return false;
        }
        aWarrior.changeHired();
        army.push_back(&aWarrior);
        return true;
    }
    
    bool fire(Warrior& aWarrior){
        // Nobles who are dead cannot fire anyone
        if (!alive){
            return false;
        }
        bool fired = false;
        for (size_t i = 0; i < army.size(); ++i){
            if (army[i]->getName() == aWarrior.getName()){
                cout << "You don't work for me anymore " << aWarrior.getName()
                << "! -- " << name << "." << endl;
                aWarrior.changeHired();
                fired = true;
                // move the warriors behind the fired warrior forward
                while(i < army.size()){
                    army[i + 1] = army[i];
                    ++i;
                }
                break;
            }
            // remove the last vector
            army.pop_back();
        }
        return fired;
    }
    
    void battle(Noble& aNoble){
        cout << name << " battles " << aNoble.name << endl;
        
        if (!alive && !aNoble.alive){
            cout << "Oh, NO!  They're both dead!  Yuck!" << endl;
        } else if (!alive && aNoble.alive){
            cout << "He's dead, " << aNoble.name << endl;
        } else if (alive && !aNoble.alive){
            cout << "He's dead, " << name << endl;
        } else { // both of the nobles are alive
            double self_strength = getArmyStrength();
            double enemy_strength = aNoble.getArmyStrength();
            if (self_strength == enemy_strength){
                changeStatus();
                aNoble.changeStatus();
                cout << "Mutual Annihilation: " << name << " and "
                << aNoble.name << " die at each other's hands" << endl;
            } else if (self_strength > enemy_strength){
                changeArmyStrength(self_strength, enemy_strength);
                aNoble.changeStatus();
                cout << name << " defeats " << aNoble.name << endl;
            } else { // self_strength < enemy_strength
                aNoble.changeArmyStrength(enemy_strength, self_strength);
                changeStatus();
                cout << aNoble.name << " defeats " << name << endl;
            }
        }
    }
private:
    string name;
    vector<Warrior*> army;
    bool alive;
};

int main() {
    
    Noble art("King Arthur");
    Noble lance("Lancelot du Lac");
    Noble jim("Jim");
    Noble linus("Linus Torvalds");
    Noble billie("Bill Gates");
    
    Warrior cheetah("Tarzan", 10);
    Warrior wizard("Merlin", 15);
    Warrior theGovernator("Conan", 12);
    Warrior nimoy("Spock", 15);
    Warrior lawless("Xena", 20);
    Warrior mrGreen("Hulk", 8);
    Warrior dylan("Hercules", 3);
    
    jim.hire(nimoy);
    lance.hire(theGovernator);
    art.hire(wizard);
    lance.hire(dylan);
    linus.hire(lawless);
    billie.hire(mrGreen);
    art.hire(cheetah);
    
    cout << "==========\n"
         << "Status before all battles, etc.\n";
    cout << jim << endl;
    cout << lance << endl;
    cout << art << endl;
    cout << linus << endl;
    cout << billie << endl;
    cout << "==========\n";
    
    art.fire(cheetah);
    cout << art << endl;
    
    art.battle(lance);
    jim.battle(lance);
    linus.battle(billie);
    billie.battle(lance);

    cout << "==========\n"
         << "Status after all battles, etc.\n";
    cout << jim << endl;
    cout << lance << endl;
    cout << art << endl;
    cout << linus << endl;
    cout << billie << endl;
    cout << "==========\n";
    
}

