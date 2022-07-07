//
//  main.cpp
//  rec02: Structs, Vectors and Functions
//  Sorting Hydrocarbon formula
//
//  Created by Ziqian Zhang on 2022/2/4.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Hydrocarbon{
    vector<string> namelist;
    int H_num;
    int C_num;
};

void openFile(ifstream& HCfile);
void fillVector();
void sorting();
void display();

int main() {
    ifstream HCfile;
    openFile(HCfile);
    
    vector<Hydrocarbon> HClist;
}

void openFile(ifstream& HCfile){
    string file_name;
    bool file_find = false;
    
    do{
        cout << "Enter a file name: " << endl;
        cin >> file_name;
        HCfile.open(file_name);
        
        if (!HCfile){
            HCfile.clear();
        }
        
        file_find = true;
        
    } while(!file_find);
}
