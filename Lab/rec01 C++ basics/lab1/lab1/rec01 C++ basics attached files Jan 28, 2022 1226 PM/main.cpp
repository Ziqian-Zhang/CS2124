//
//  main.cpp
//  lab1
//
//  Created by Z.Q. Zhang on 2022/1/28.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    return 0;
//}

using namespace std;

void display(vector<int> someVector){
    for(int each_num : someVector){
        cout << each_num << endl;
    }
}

// Task 16. Function to modify the vector, using indices

void doubleInt(vector<int>& someVector){
    for(size_t index = 0; index < someVector.size(); ++index){
        someVector[index] = someVector[index] * 2;
    }
    display(someVector);
}

// Task 17. Function to modify the vector, using a ranged for

void doubleInt2(const vector<int>& someVector){
    for(int each_num: someVector){
        each_num = each_num * 2;
    }
    display(someVector);
}

//
// main
//
int main() { // Yes, it has to have an int for the return type
    //
    // Output
    //

    // Task 1. Printing hello ...  No use of "using namespace"
    
    std::cout << "hello" << endl;

    // Task 2  Printing hello ...  Using "using namespace"

    cout << "hello" << endl;
    
    //int x;
    
    int y = 17;
    int z = 2000000017;
    double pie = 3.14159;
    
    cout << sizeof y << endl;
    cout << sizeof z << endl;
    cout << sizeof pie << endl;
    
    //x = "felix";
    
    if (y >= 10 && y <= 20){
        cout << "y is between 10 and 20" << endl;
    } else {
        cout << "y is not between 10 and 20" << endl;
    }
    
    for (int i = 10; i <= 20; ++i){
        cout << i << " ";
    }
    cout << endl;
    int i = 10;
    while (i <= 20){
        cout << i << " ";
        ++i;
    }
    cout << endl;
    
    int j = 10;
    do{
        cout << j << " ";
        ++j;
    } while (j <= 20);
    cout << endl;
    
//    bool file_open = false;
//    ifstream ifs;
//    string file_name;
//    while(!file_open){
//        cout << "Enter file name:" << endl;
//        cin >> file_name;
//        ifs.open(file_name);
//        if (ifs){
//            file_open = true;
//        }
//    }
//
//    if (file_open){
//        string result;
//        while(ifs >> result){
//            cout << result << ' ';
//        }
//        ifs.close();
//    }
//    cout << endl;
//
//    ifstream numbers("integers.txt");
//    if (!numbers){
//        cerr << "failed to open integers";
//        exit(1);
//    }
//
//    int nums;
//    vector<int> collection;
//    int sum = 0;
//
//    while(numbers >> nums){
//        collection.push_back(nums);
//    }
//    numbers.close();
//
//    for (size_t i = 0; i < collection.size(); ++i){
//            sum += collection[i];
//    }
//    cout << "sum is:" << sum << endl;
    
    
//    ifstream mix("mixed.txt");
//    if (!mix){
//        cerr << "failed to open mixed";
//        exit(1);
//    }
//
//    int elem;
//    vector<int> collection2;
//    int sum2 = 0;
//
//    while(numbers >> elem){
//        collection2.push_back(nums);
//    }
//    mix.close();
//
//    for (size_t i = 0; i < collection2.size(); ++i){
//            sum2 += collection[i];
//    }
//    cout << "sum is:" << sum2 << endl;
    
//    vector<int> even;
//    for (int i = 10; i <= 100; i += 2){
//        even.push_back(i);
//    }
//
//    // Task 13 Displaying the vector THREE times
//    //         a) using the indices,
//
//    for(size_t index = 0; index < even.size(); ++index){
//        cout << even[index] << endl;
//    }
    
//    int index = 0;
//    while(index < even.size()){
//        cout << even[index] << endl;
//        ++index;
//    }
//
//    for(int each_num : even){
//        cout << each_num << endl;
//    }
    
//    for(size_t index_3 = even.size(); index_3 > 0; index_3--){
//            cout << even[index_3 - 1] << endl;
//        }
    
    vector<int> v{1,2,3,4};
    display(v);
    doubleInt(v);
    doubleInt2(v);
}
