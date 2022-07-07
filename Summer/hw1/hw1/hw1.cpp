//
//  hw1.cpp
//  hw1
//
//  Created by Ziqian Zhang on 2022/6/1.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

bool isInVector(vector<int>& aVector, int aNum){
    for (size_t i = 0; i < aVector.size(); i++){
        if (aVector[i] == aNum){
            return true;
        }
    }
    return false;
}

void makeUnique(vector<int>& v1, vector<int>& v2){
    for (size_t i = 0; i < v1.size(); i++){
        v2.push_back(v1[i]);
        for (size_t j = 0; j < v2.size() - 1; j++){
            if (v1[i] == v2[j]){
                v2.pop_back();
            }
        }
    }
}

void fillVectFromFile(ifstream& ifs, vector<int>& numVector){
    string fileName;
    cout << "Enter a file name: " << endl;
    cin >> fileName;
    ifs.open(fileName);
    if (!ifs) {
        cerr << "Fail to open the file." << endl;
        exit(1);
    } else {
        int read;
        while (ifs >> read){
            numVector.push_back(read);
        }
    }
}

void writeIntoFile(ofstream& output, vector<int>& uniqInt){
    for(size_t i = 0; i < uniqInt.size(); i++){
        output << uniqInt[i] << ' ';
    }
}

int main() {
    vector<int> intFromFile;
    ifstream integers;
    fillVectFromFile(integers, intFromFile);
    vector<int> uniqInt;
    makeUnique(intFromFile, uniqInt);
    ofstream output("uniq.ints.txt");
    writeIntoFile(output, uniqInt);
}
