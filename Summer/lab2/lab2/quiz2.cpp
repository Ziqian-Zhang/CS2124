//
//  quiz2.cpp
//  lab2
//
//  Created by Ziqian Zhang on 2022/6/1.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Car{
    friend ostream& operator<<(ostream& os, const Car& aCar){
        os << "Make: " << aCar.make << endl;
        os << "Model: " << aCar.model << endl;
        os << "License: ";
        if (aCar.license == 0){
            os << "N/A" << endl;
        } else { os << aCar.license << endl;}
        os << "Efficiency Rating: " << aCar.efficiencyRate << endl;
        return os;
    }
public:
    Car(): make("(unspecified)"), model("(unspecified)"), license(0), gasTank(15), efficiencyRate(25){}
    Car(const string& make, const string& model, int license = 0, int gas = 15, int efficiencyRate = 25): make(make), model(model), license(license), gasTank(gas), efficiencyRate(efficiencyRate){}
    Car(const string& make, int license = 0, int gas = 15, int efficiencyRate = 25): make(make), model("(unspecified)"), license(license), gasTank(gas), efficiencyRate(efficiencyRate){}
    
    void setLicense(int num){
        license = num;
    }
    
    double drive(){
        if (gasTank > 0){
            double mile = rand() % 25 + 1;
            gasTank -= mile / efficiencyRate;
            return mile;
        } else {
            cout << "No Gas!" << endl;
            return 0;
        }
    }
    
    double getGas(){
        if(gasTank < 0){return 0;}
        else {return gasTank;}
    }
private:
    string make;
    string model;
    int license;
    double gasTank;
    int odometer;
    int efficiencyRate;
};

int main(){
    // Car(make, model, licensePlate, gas, effRating)
    Car cA;
    Car cB("makeCB");
    Car c1("make1", "model1", 123, 15); // effRating should be set to 25 default
    Car c2("make2", 456, 1, 20);
    
    // either display with function OR overload output operator
//    displayCar(cA);
//    displayCar(cB);
//    displayCar(c1);
//    displayCar(c2);
    
    cout << cA;
    cout << cB;
    cout << c1;
    cout << c2;
    
    c2.setLicense(1010);
    cout << "Change license of c2...\n";
//    displayCar(c2);
    cout << c2;

    cout << "--NOTE: results for the following will vary due to rand()!--\n\n";
    
    cout << "Drive c1...\n";
    int milesDriven = c1.drive();
    cout << "c1 drove " << milesDriven << " miles\n";
    cout << "c1 has " << c1.getGas() << " gallons left\n";

    cout << endl;

    cout << "Drive c2...\n";
    milesDriven = c2.drive();
    cout << "c2 drove " << milesDriven << " miles\n";
    cout << "c2 has " << c2.getGas() << " gallons left\n";

    cout << endl;

    cout << "Drive c2...\n";
    milesDriven = c2.drive();
    cout << "c2 drove " << milesDriven << " miles\n";
    cout << "c2 has " << c2.getGas() << " gallons left\n";

}
