//
//  quiz3.cpp
//  lab3
//
//  Created by Ziqian Zhang on 2022/6/8.
//

#include <iostream>
using namespace std;


int* sorting(int* arr, size_t size){
    int* result = new int[size];
    for (size_t i = 0; i < size; i++){
        size_t min_index = i;
        for (size_t j = i + 1; j < size; j++){
            if (arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        result[i] = arr[min_index];
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
    return result;
}

int main(){
    int* data = new int[5];
    data[0] = 2;
    data[1] = 5;
    data[2] = 1;
    data[3] = 3;
    data[4] = 4;
    int* output = sorting(data, 5);
    for (int i = 0; i < 5; i++){
        cout << output[i] <<' ';
    }
}
