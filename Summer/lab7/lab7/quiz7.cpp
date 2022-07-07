//
//  quiz7.cpp
//  lab7
//
//  Created by Ziqian Zhang on 2022/6/24.
//

#include <iostream>

using namespace std;

class Vehicle{
private:
    int* vin;
    double* gasMileage;
public:
    Vehicle(int* v = new int(0), double* gasM = new double(2.0)){
        vin = v;
        gasMileage = gasM;
    }
    void display() const {
        cout << "vehicle ID number: " << *vin << " gas mileage: " << *gasMileage << endl;
    }
    int getVin() const { return *vin; }
    double getGasMileage() const { return *gasMileage; }
    void setVin(int num){ *vin = num; }
    void setGasMileage(double num){ *gasMileage = num; }
    virtual double calcGasUsed(double drivenMiles){ return (*gasMileage) * drivenMiles; }
    virtual void drive(){
        double mile = rand() % 25 + 1;
        cout << "gas mileage : " << *gasMileage << " driven miles: " << mile << " GasUsed: " << calcGasUsed(mile) << endl;
    }
};

class SUV : public Vehicle{
private:
    bool* fourWDStatus;
    double* fourWDGasMileage;
public:
    SUV(int* v = new int(0), double* gasM = new double(2.0), bool* sts = new bool(false), double* fWDGas = new double(2.5)): Vehicle(v, gasM){
        fourWDStatus = sts;
        fourWDGasMileage = fWDGas;
    }
    void display() const {
        Vehicle::display();
        cout << "Four Wheel Drive status: " << *fourWDStatus << " fourWDGasMileage: " << *fourWDGasMileage << endl;
    }
    bool getFourWDStatus() { return *fourWDStatus; }
    double getFourWDGasMileage() const { return *fourWDGasMileage; }
    void setFourWDStatus(bool status){ *fourWDStatus = status; }
    void setFourWDGasMileage(double num){ *fourWDGasMileage = num; }
    double calcGasUsed(double drivenMiles){
        if (*fourWDStatus){
            cout << "(in 4X4 model) ";
            return (*fourWDGasMileage) * drivenMiles;
        } else {
            cout << "(not in 4X4 model) ";
            return Vehicle::calcGasUsed(drivenMiles);
        }
    }
    void drive(){
        double mile = rand() % 25 + 1;
        if (*fourWDStatus){
        cout << "gas mileage : " << *fourWDGasMileage << " driven miles: " << mile << " GasUsed: " << calcGasUsed(mile) << endl;
        } else {
            Vehicle::drive();
        }
    }
};

int main(){
    Vehicle v1;
    SUV s1(new int(1), new double(2.0), new bool(false), new double(3.0));
    SUV s2(new int(2), new double(2.0), new bool(true), new double(3.0));
//    Not working if putting three vehicles into one array.
//    It seems that pointers point to Vehicle objects can only access Vehicle class stuff.
    
    Vehicle arr[3] = {v1, s1, s2};
    for (int i = 0; i < 3; i++){
        arr[i].drive();
    }
    
    cout << "*****************" << endl;
//    Working if driving the three vehicles separately
    v1.drive();
    s1.drive();
    s2.drive();
}
