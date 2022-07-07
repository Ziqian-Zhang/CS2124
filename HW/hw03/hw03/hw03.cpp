//
//  hw03.cpp
//  hw03: Warrior Game with weapon, OOP
//
//  Created by Ziqian Zhang on 2022/2/16.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Warrior{
    
    class Weapon;
    friend ostream& operator <<(ostream& os, const Warrior& warrior);
    friend ostream& operator <<(ostream& os, const Weapon& weapon);
    
public:
    // Constructor
    Warrior(const string& name, const string& weaponName, int strength):
    name(name), weapon(weaponName, strength){}
    
    const string getName() const{
        return name;
    }
    
    int getStrength() const{
        return weapon.getStrength();
    }
    
    void setStrength(int strength){
        weapon.setStrength(strength);
    }
    
    // a method for battle
    // modify the strength of the battled warriors
    void battle(Warrior& enemy){
        cout << name << " battles " << enemy.name << endl;
        if (getStrength() == 0 && enemy.getStrength() == 0){
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
        } else if (getStrength() == 0 && enemy.getStrength() > 0){
            cout << "He's dead, " << enemy.name << endl;
        } else if (getStrength() > 0 && enemy.getStrength() == 0){
            cout << "He's dead, " << name << endl;
        } else if (getStrength() == enemy.getStrength()){
            setStrength(0);
            enemy.setStrength(0);
            cout << "Mutual Annihilation: " << name << " and "
            << enemy.name << " die at each other's hands" << endl ;
        } else if (getStrength() > enemy.getStrength()){
            setStrength(getStrength() - enemy.getStrength());
            enemy.setStrength(0);
            cout << name << " defeats " << enemy.name << endl;
        } else {
            enemy.setStrength(enemy.getStrength() - getStrength());
            setStrength(0);
            cout << enemy.name << " defeats " << name << endl;
        }
    }
private:
    // nesting the definition of the Weapon class inside the Warrior class
    class Weapon{
        friend ostream& operator <<(ostream& os, const Weapon& weapon);
    public:
        Weapon(const string& weaponName, int theStrength):
        weaponName(weaponName), strength(theStrength){}
        
        int getStrength() const{
            return strength;
        }
        
        void setStrength(int theStrength){
            strength = theStrength;
        }
        
    private:
        string weaponName;
        int strength;
    };
    
    string name;
    Weapon weapon;
};

ostream& operator <<(ostream& os, const Warrior& warrior){
    os << "Warrior: " << warrior.name << ", " << warrior.weapon;
    return os;
}

ostream& operator <<(ostream& os, const Warrior::Weapon& weapon){
    os << "weapon: " << weapon.weaponName << ", " << weapon.strength << endl;
    return os;
}

void displayWarriors(const vector<Warrior>& warriors);
size_t findWarrior(const string& name, vector<Warrior> warriors);

int main() {
    // open file
    ifstream warriorFile("warriors.txt");
    if (! warriorFile){
        cerr << "failed to open the file." << endl;
        exit(1);
    }
    
    string command;
    vector<Warrior> warriors;
    
    // read the file token by token
    while(warriorFile >> command){
        if (command == "Warrior"){
            string name, weaponName;
            int strength;
            warriorFile >> name >> weaponName >> strength;
            warriors.emplace_back(name, weaponName, strength);
        } else if (command == "Status"){
            displayWarriors(warriors);
        } else {
            string name1, name2;
            warriorFile >> name1 >> name2;
            size_t index1 = findWarrior(name1, warriors);
            size_t index2 = findWarrior(name2, warriors);
            warriors[index1].battle(warriors[index2]);
        }
    }
    
    warriorFile.close();
}

// display the number of the existing warriors and their information
void displayWarriors(const vector<Warrior>& warriors){
    cout << "There are : " << warriors.size() << " warriors" << endl;
    for (const Warrior& curr_warrior: warriors){
        cout << curr_warrior;
    }
}

// find the index of the two battled warriors
size_t findWarrior(const string& name, vector<Warrior> warriors){
    for (size_t i = 0; i < warriors.size(); ++i){
        if (warriors[i].getName() == name){
            return i;
        }
    }
    
    return warriors.size();
}
