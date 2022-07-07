//
//  testPrincess.cpp

//  Cyclic Association

//  CS2124_inclass
//
//  Created by Z.Q. Zhang on 2022/3/7.
//
/*
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class FrogPrince;

class Princess{
    friend ostream& operator << (ostream& os, const Princess& princess);
    
public:
    Princess(const string& name);
    const string& getName() const;
    // removing the body, change it to the prototype
    void marries(FrogPrince& betrothed);
    
private:
    string name;
    FrogPrince* spouse;
};

class FrogPrince{
    friend ostream& operator << (ostream& os, const FrogPrince& frog);
public:
    FrogPrince(const string& name);
    void setSpouse(Princess* spousePtr);
    const string& getName() const;
private:
    string name;
    Princess* spouse;
};

// scope qualification operator: qualifying method marries to the class it belongs
void Princess::marries(FrogPrince& betrothed){
    spouse = &betrothed;
    // betrothed.spouse = this; // privacy issue
    betrothed.setSpouse(this);
    // betrothed.setSpouse(*this);
}

const string& Princess::getName() const { return name; }

Princess::Princess(const string& name) : name(name), spouse(nullptr){}

ostream& operator << (ostream& os, const Princess& princess){
    os << "Princess:" << princess.name;
    if(princess.spouse != nullptr){
        os << "; married to: " << princess.spouse->getName();
    }

    return os;
}

//
// FrogPrince Code
//
ostream& operator << (ostream& os, const FrogPrince& frog){
    os << "Frog Prince:" << frog.name;
    if(frog.spouse != nullptr){
        os << "; married to: " << frog.spouse->getName();
    }
    return os;
}

FrogPrince::FrogPrince(const string& name) : name(name), spouse(nullptr){}

void FrogPrince::setSpouse(Princess* spousePtr){
    spouse = spousePtr;
}

const string& FrogPrince::getName() const { return name; }

int main(){
    Princess snowy("Snow White");
    cout << snowy << endl;
    FrogPrince frog("Froggy");
    cout << frog << endl;
    snowy.marries(frog);
    cout << snowy << endl
    << frog << endl;
    
}
*/
