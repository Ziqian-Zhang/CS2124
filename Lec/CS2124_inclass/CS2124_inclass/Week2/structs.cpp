//
//  structs.cpp
//  CS2124_inclass
//
//  Created by Z.Q. Zhang on 2022/1/31.
//

/*
#include "structs.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Motorcycle{
    string model;
    int cc;
};

void displayMotorcycle(const Motorcycle& mot){
    cout << mot.model << ' ' << mot.cc << endl;
}

void displayBikes(const vector<Motorcycle>& bikes){
    for (const Motorcycle& mot : bikes){
        displayMotorcycle(mot);
    }
}

int main(){
    Motorcycle myBike;
    cout << myBike.model << ' ' << myBike.cc << endl;
    
    myBike.model = "VStrom";
    myBike.cc = 650;
    cout << myBike.model << ' ' << myBike.cc << endl;
    
    displayMotorcycle(myBike);
    
    Motorcycle bike2{ "softail", 1746 };
    
    ifstream bikeStream("bikes.txt");
    if (!bikeStream){
        cerr << "failed to open bikes.txt\n";
        exit(1);
    }
    
    vector<Motorcycle> bikes;
    
    
    string model;
    int cc;
    while (bikeStream >> model >> cc){
//        Motorcycle aBike;
//        aBike.model = model;
//        aBike.cc = cc;
        Motorcycle aBike{ model, cc };
        bikes.push_back(aBike);
    }
     
    
    
    Motorcycle aBike;
    while (bikeStream >> aBike.model >> aBike.cc){
        bikes.push_back(aBike);
    }
    
    
    for (const Motorcycle& mot : bikes){
        displayMotorcycle(mot);
    }
    
}

*/
