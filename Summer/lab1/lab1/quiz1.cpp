//
//  quiz1.cpp
//  lab1
//
//  Created by Ziqian Zhang on 2022/5/27.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    ifstream month1("month1.txt");
    ifstream month2("month2.txt");
    vector<int> ID1;
    vector<int> ID2;
    vector<double> reading1;
    vector<double> reading2;
    int ID;
    double reading;
    double first;
    double second;
    double result;
    vector<int> outputID;
    vector<double> utilization;
    vector<int> missed;
    vector<double> missedread;
    while(month1 >> ID >> reading){
        ID1.push_back(ID);
        reading1.push_back(reading);
    }
    while(month2 >> ID >> reading){
        ID2.push_back(ID);
        reading2.push_back(reading);
    }
    if (ID1.size() >= ID2.size()){
        for (int i = 0; i < ID1.size(); i++){
            missed.push_back(ID1[i]);
            missedread.push_back(reading1[i]);
            for (int j = 0; j < ID2.size(); j++){
                if (ID1[i] == ID2[j]){
                    first = reading1[i];
                    second = reading2[j];
                    outputID.push_back(ID1[i]);
                    if (first > second){
                        result = first - second;
                    } else {
                        result = second - first;
                    }
                    utilization.push_back(result);
                    missed.pop_back();
                    missedread.pop_back();
                }
            }
        }
    } else {
        for (int i = 0; i < ID2.size(); i++){
            missed.push_back(ID2[i]);
            missedread.push_back(reading2[i]);
            for (int j = 0; j < ID1.size(); j++){
                if (ID2[i] == ID1[j]){
                    first = reading2[i];
                    second = reading1[j];
                    outputID.push_back(ID2[i]);
                    if (first > second){
                        result = first - second;
                    } else {
                        result = second - first;
                    }
                    utilization.push_back(result);
                    missed.pop_back();
                    missedread.pop_back();
                }
            }
        }
    }
    for (int i = 0; i < outputID.size(); i++){
        cout << outputID[i] << ' ' << utilization[i] << " kWh" << endl;
    }
    for (int i = 0; i < missed.size(); i++){
        cout << missed[i] << ' ' << "Only has meter reading for one month: " << missedread[i] << " kWh" << endl;
    }
}
