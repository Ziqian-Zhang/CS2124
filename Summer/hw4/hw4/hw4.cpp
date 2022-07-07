//
//  main.cpp
//  hw4
//
//  Created by Ziqian Zhang on 2022/6/13.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void reverseStr(char* str){
    int length = 0;
    char* front = str;
    char* rear = str;
    while(*rear != '\0'){
        rear++;
        length++;
    }
    rear--;
    for (int i = 0; i < length/2; i++){
        char temp= *front;
        *front = *rear;
        *rear = temp;
        front++;
        rear--;
    }
}

void enlargeSortedArray(int* arr, int size, int num){
    int* oldArr = arr;
    arr = new int[size * 2];
    for (int i = 0; i < size; i++){
        arr[i] = oldArr[i];
    }
    arr[size] = num;
    for(int i = 0; i < size + 1; i++){
        int min_index = i;
        for(int j = i; j < size + 1; j++){
            if (arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        int swap = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = swap;
    }
    delete [] oldArr;
}

int main() {
    vector<int> grades;
    int num;
    cout << "Enter grades: ";
    while (num != -1){
        cin >> num;
        if (num != -1){
           grades.push_back(num);
        }
    }
    int minimumGrade = 0;

    int maximumGrade = grades[0];
    for (size_t i = 0; i < grades.size(); i++){
        if (maximumGrade < grades[i]){
            maximumGrade = grades[i];
        }
    }

    int* histogram= new int[maximumGrade+1];

    for (size_t i = 0; i <= maximumGrade; i++){
        histogram[i] = 0;
    }
    for (size_t i = 0; i < grades.size(); i++){
        for (size_t j = minimumGrade; j <= maximumGrade; j++){
            if (grades[i] == j){
                if (histogram[j] == 0){
                    histogram[j] = 1;
                }else{
                    histogram[j] += 1;
                }
            }
        }
    }

    for (size_t i = 0; i <= maximumGrade; i++){
        if (histogram[i] != 0){
            cout << "Number of " << i << "'s: " << histogram[i] << endl;
        }
    }
}
