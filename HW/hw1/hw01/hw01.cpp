//
//  hw01.cpp
//  hw01: Caesar Cypher; decrypt the given text encrypted by Caesar Cypher
//
//  Created by Ziqian Zhang on 2022/2/1.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void decryptStr(string& curr_line, int steps);
char decryptChar(char letter, int steps);

int main() {
    
    // open the encrypted file
    ifstream encrypt("encrypted.txt");
    if (!encrypt) {
        cerr << "failed to open the file." << endl;
        exit(1);
    }
    
    // read the number of steps
    int steps;
    encrypt >> steps;
    
    // read the lines into the vector
    string line;
    vector<string> lines;
    while (getline(encrypt, line)){
        lines.push_back(line);
    }
    encrypt.close();
    
    // print the decrypted text in the reverse order
    for (size_t i = 0; i < lines.size(); ++i){
        string curr_line = lines[lines.size() - 1 - i];
        decryptStr(curr_line, steps);
        cout << curr_line << endl;
    }
}

// pass the lines to be modified
void decryptStr(string& curr_line, int steps){
    for (char& letter: curr_line){
        letter = decryptChar(letter, steps);
    }
}

// decrypt the passed lines, check the characters one by one
char decryptChar(char letter, int steps){
    // check if the letter is a lower-case letter and decrypt it
    if (letter >= 'a' && letter <= 'z'){
        letter -= steps;
        
        // the edge case
        if (letter < 'a'){
            letter += 26;
        }
    }
    return letter;
}
