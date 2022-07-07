//
//  hw02.cpp
//  hw02: a game of warriors' battles
//
//  Created by Ziqian Zhang on 2022/2/7.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Warrior{
    
    // constructor
    
    Warrior(const string& theName, int theStrength)
    : name(theName), strength(theStrength){}
    
    string name;
    int strength;
};

void openFile(ifstream& warriorStream);
void displayWarriors(const vector<Warrior>& warriors);
size_t findWarrior(const string& name, const vector<Warrior>& warriors);
void battle(Warrior& warrior1, Warrior& warrior2);
void update(Warrior& warrior1, Warrior& warrior2, vector<Warrior>& warriors);

int main() {
    ifstream warriorStream;
    openFile(warriorStream);
    
    // store the Warrior struct
    vector<Warrior> warriors;
    string command;
    
    // read the file token by token
    while(warriorStream >> command){
        if (command == "Warrior"){
            string name;
            int strength;
            warriorStream >> name >> strength;
            Warrior newWarrior(name, strength);
            // pass the warrior information into vector
            warriors.push_back(newWarrior);
        } else if (command == "Status"){
            displayWarriors(warriors);
        } else {
            // command == battle
            string name1, name2;
            warriorStream >> name1 >> name2;
            Warrior& warrior1 = warriors[findWarrior(name1, warriors)];
            Warrior& warrior2 = warriors[findWarrior(name2, warriors)];
            battle(warrior1, warrior2);
            update(warrior1, warrior2, warriors);
        }
    }
    
    warriorStream.close();
    
}

// open the file and output error message if faild to open it
void openFile(ifstream& warriorStream){
    warriorStream.clear();
    warriorStream.open("warriors.txt");
    if (!warriorStream){
        cerr << "Failed to open warriors.txt" << endl;
        exit(1);
    }
}

// display the number of the existing warriors and their information
void displayWarriors(const vector<Warrior>& warriors){
    cout << "There are: " << warriors.size() << " warriors" << endl;
    for (const Warrior& curr_warrior : warriors){
        cout << "Warriors: " << curr_warrior.name << ", strength: "
        << curr_warrior.strength << endl;
    }
}

// find the index of the two battled warriors
// output error message if the warrior has not been defined
size_t findWarrior(const string& name, const vector<Warrior>& warriors){
    for (size_t i = 0; i <= warriors.size(); ++i){
        if (warriors[i].name == name){
            return i;
        }
    }
    cerr << "Cannot find the warrior " << name << " ";
    return warriors.size() + 1;
}

// determine the losing strength during a battle
// output the according messages in different cases
void battle(Warrior& warrior1, Warrior& warrior2){
    
    cout << warrior1.name << " battles " << warrior2.name << endl;
    
    // first check if the battled warriors are alive or dead
    // and output the result
    if (warrior1.strength == 0 && warrior2.strength == 0){
        cout << "Oh, NO! They're both dead! Yuck!" << endl;
    } else if (warrior1.strength == 0 && warrior2.strength != 0){
        cout << "He's dead, " << warrior2.name << endl;
    } else if (warrior1.strength != 0 && warrior2.strength == 0){
        cout << "He's dead, " << warrior1.name << endl;
    }
    
    // the battle rule that let the warriors lose their strength
    // and the output result
    else if (warrior1.strength > warrior2.strength){
        warrior1.strength -= warrior2.strength;
        warrior2.strength = 0;
        cout << warrior1.name << " defeats " << warrior2.name << endl;
    } else if (warrior1.strength == warrior2.strength){
        warrior1.strength = 0;
        warrior2.strength = 0;
        cout << "Mutual Annihilation: " << warrior1.name << " and "
        << warrior2.name << "die at each other's hands" << endl;
    } else if (warrior1.strength < warrior2.strength){
        warrior2.strength -= warrior1.strength;
        warrior1.strength = 0;
        cout << warrior2.name << " defeats " << warrior1.name << endl;
    }
}

// updating the new strength information after battling
void update(Warrior& warrior1, Warrior& warrior2, vector<Warrior>& warriors){
    // traverse the warrior list to find the warriors need to be modified
    for (Warrior& curr_warrior : warriors) {
            if (curr_warrior.name == warrior1.name) {
                curr_warrior = warrior1;
            } else if (curr_warrior.name == warrior2.name) {
                curr_warrior = warrior2;
            }
        }
}
