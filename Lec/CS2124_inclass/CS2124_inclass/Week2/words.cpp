//
//  words.cpp
//  CS2124_inclass
//
//  Created by Z.Q. Zhang on 2022/1/31.
//

/*
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Word{
    string token;
    vector<int> positions;
};

//bool isWordInVector(const string& token, const vector<Word>& words){
//    for (const Word& w: words){
//        if(w.token == token) return true;
//    }
//    return false;
//}

size_t findWordInVector(const string& token, const vector<Word>& words){
    for (size_t index = 0; index != words.size(); ++index){
        if(words[index].token == token){
            return index;
        }
    }
    return words.size();
}

int main(){
    ifstream textStream("jabberwocky");
    if (!textStream){
        cerr << "failed to open jabberwocky\n";
        exit(1);
    }
    
    vector<Word> words;
    
    int counter = 0;
    string token;
    while(textStream >> token){
        // is it in the vector
        // if not, then add a new Word for that token
        // Otherwise modify the Word that's in the collection
        size_t where = findWordInVector(token, words);
        if (where != words.size()){
            words[where].positions.push_back(counter);
        } else {
            Word aWord;
            aWord.token = token;
            aWord.positions.push_back(counter);
            words.push_back(aWord);
        }
        ++counter;
    }
}
*/
