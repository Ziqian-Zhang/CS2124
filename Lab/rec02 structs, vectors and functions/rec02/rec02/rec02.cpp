//
//  rec02.cpp
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
void fillVector(ifstream& HCfile, vector<Hydrocarbon>& HClist);
size_t findFomula(const vector<Hydrocarbon>& HClist, int C, int H);
void insert(vector<Hydrocarbon>& HClist, const string& name, int C, int H);
void sorting(vector<Hydrocarbon>& HClist);
void swapVec(vector<Hydrocarbon>& HClist, size_t pos1, size_t pos2);
void display(const vector<Hydrocarbon>& HClist);
void displayName(const Hydrocarbon& hydrocarb);

int main() {
    ifstream HCfile;
    openFile(HCfile);
    
    vector<Hydrocarbon> HClist;
    fillVector(HCfile, HClist);
    sorting(HClist);
    display(HClist);
    
    HCfile.close();
}

void openFile(ifstream& HCfile){
    string file_name;
    do{
        HCfile.clear();
        cout << "Enter a file name: " << endl;
        cin >> file_name;
        HCfile.open(file_name);
    } while(!HCfile);
}

void fillVector(ifstream& HCfile, vector<Hydrocarbon>& HClist){
    string name;
    char someChar;
    int H;
    int C;
    
    while(HCfile >> name >> someChar >> C >> someChar >> H){
        insert(HClist, name, C, H);
    }
}

size_t findFomula(const vector<Hydrocarbon>& HClist, int C, int H){
    for(size_t i = 0; i < HClist.size(); ++i){
        if (HClist[i].C_num == C && HClist[i].H_num == H){
            return i;
        }
    }
    return HClist.size();
}

void insert(vector<Hydrocarbon>& HClist, const string& name, int C, int H){
    
    size_t index = findFomula(HClist, C, H);
    
    if (index != HClist.size()){
        HClist[index].namelist.push_back(name);
    } else {
        Hydrocarbon newHC;
        newHC.namelist.push_back(name);
        newHC.C_num = C;
        newHC.H_num = H;
        HClist.push_back(newHC);
    }
}

void sorting(vector<Hydrocarbon>& HClist){
    for (size_t i = 1; i < HClist.size(); ++i){
        for (size_t j = i; j > 0;  --j){
            if (HClist[j].C_num < HClist[j - 1].C_num){
                swapVec(HClist, j, j - 1);
            } else if (HClist[j].C_num == HClist[j - 1].C_num){
                if (HClist[j].H_num < HClist[j - 1].H_num){
                    swapVec(HClist, j, j - 1);
                } else {
                    break;
                }
            } else{
                break;
            }
        }
    }
}

void swapVec(vector<Hydrocarbon>& HClist, size_t pos1, size_t pos2){
    Hydrocarbon temp = HClist[pos1];
    HClist[pos1] = HClist[pos2];
    HClist[pos2] = temp;
}

void display(const vector<Hydrocarbon>& HClist){
    for (const Hydrocarbon& curr_HC: HClist){
        displayName(curr_HC);
    }
}

void displayName(const Hydrocarbon& hydrocarb){
    cout << "C" << hydrocarb.C_num << "H" << hydrocarb.H_num << " ";
    for (const string& curr_name: hydrocarb.namelist){
        cout << curr_name << " ";
    }
    cout << endl;
}
