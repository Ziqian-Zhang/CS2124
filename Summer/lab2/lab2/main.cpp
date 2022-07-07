//
//  main.cpp
//  lab2
//
//  Created by Z.Q. Zhang on 2022/6/1.
//
/*
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class DeliveryTruck{
    friend ostream& operator<<(ostream& os, DeliveryTruck& truck){
        os << truck.advertising << ", Packages' Weight: ";
        for (int i = 0; i < truck.packages.size(); i++){
            os << truck.packages[i] << ' ';
        }
        os << endl;
        os << "Cargo weight: "<< truck.vehicleWeight << "Truck ID: " << truck.truckID << endl;
        return os;
    }
public:
    DeliveryTruck(string something, double defaultWeight = 10, int truckID = 0)
    : advertising(something), vehicleWeight(defaultWeight), truckID(truckID){
        for (int i = 0; i < 50; i++){
            packages.push_back(0);
        }
    }
    
    void changeAd(){
        string input;
        //advertising = getline(cin, input);
    }
    
    void addPackage(ifstream& file){
        int ID;
        double weight;
        while (file >> ID >> weight){
            packages.push_back(weight);
        }
    }
    
    int getTruckID(){ return truckID; }
    
private:
    string advertising;
    vector<double> packages;
    double vehicleWeight;
    int truckID;
};

class DeliveryCompany{
public:
    DeliveryCompany();
    
    void readTruckFile(vector<int> truckNum){
        for (int i = 0; i < truckNum.size(); i++){
            if (truckNum[i] == 64){
                ifstream file1("Truck64.txt");
            } else if (truckNum[i] == 112){
                ifstream file2("Truck112.txt");
            } else if (truckNum[i] == 118){
                ifstream file3("Truck118.txt");
            }
        }
    }
private:
    vector<DeliveryTruck> trucks;
};

void menuOption(){
    int num;
    cout << "Enter menu option: " << endl;
    cin >> num;
    do {
        cout << num << endl;
    } while (num != 0);
    if (num == 1){
        DeliveryTruck someTruck("advertising");
        cout << someTruck << endl;
    }
}

int main() {
    menuOption();
    
}
 */
