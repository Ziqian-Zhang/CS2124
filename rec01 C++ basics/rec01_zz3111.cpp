/*
  rec01_start.cpp
  spring 2022
  jbs
*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


void display(const vector<int>& someVector);
void doubleInt(vector<int>& someVector);
void doubleInt2(vector<int>& someVector);

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

    //
    // Types and variables
    //

    // Task 3  Displaying uninitialized variable

    int x;
    
    // Task 4 Use the sizeof function to see the size in bytes of
    //        different types on your machine.

    int y = 17;
    int z = 2000000017;
    double pie = 3.14159;
    
    cout << sizeof y << endl;   // 4
    cout << sizeof z << endl;   // 4
    cout << sizeof pie << endl; // 8
    
    // Task 5  Attempt to assign the wrong type of thing to a variable

    //x = "felix"; // Semantic Issue: Assigning to 'int' from incompatible type 'const char [6]'

    //
    // Conditions
    //

    // Task 6  Testing for a range

    if (y >= 10 && y <= 20){
        cout << "y is between 10 and 20" << endl;
    } else {
        cout << "y is not between 10 and 20" << endl;
    }

    //
    // Loops and files
    //

    // Task 7  Looping, printing values 10 to 20 inclusive

    // First with a for loop
    
    for (int i = 10; i <= 20; ++i){
        cout << i << " ";
    }
    cout << endl;

    // Then with a while loop
    
    int i = 10;
    while (i <= 20){
        cout << i << " ";
        ++i;
    }
    cout << endl;

    // Finally with a do-while loop
    
    int j = 10;
    do{
        cout << j << " ";
        ++j;
    } while (j <= 20);
    cout << endl;

    // Task 8  Looping to successfully open a file, asking user for the name

    bool file_open = false;
    ifstream ifs;
    string file_name;
    while(!file_open){
        cout << "Enter file name:" << endl;
        cin >> file_name;
        ifs.open(file_name);
        if (ifs){
            file_open = true;
        }
    }

    // Task 9  Looping, reading file word by "word".

    if (file_open){
        string result;
        while(ifs >> result){
            cout << result << ' ';
        }
        ifs.close();
    }
    cout << endl;

    // Task 10 Open a file of integers, read it in, and display the sum.

    ifstream numbers("integers.txt");
    if (!numbers){
        cerr << "failed to open integers";
        exit(1);
    }
    
    int nums;
    vector<int> collection;
    int sum = 0;
    
    while(numbers >> nums){
        collection.push_back(nums);
    }
    numbers.close();
    
    for (size_t i = 0; i < collection.size(); ++i){
            sum += collection[i];
    }
    cout << "sum is:" << sum << endl;
    

    // Taks 11 Open and read a file of integers and words. Display the sum.

    ifstream mix("mixed.txt");
    if (!mix){
        cerr << "failed to open mixed";
        exit(1);
    }
    
    int elem;
    vector<int> collection2;
    int sum2 = 0;
    
    while(numbers >> elem){
        collection2.push_back(nums);
    }
    mix.close();
    
    for (size_t i = 0; i < collection2.size(); ++i){
            sum2 += collection[i];
    }
    cout << "sum is:" << sum2 << endl;

    //
    // Vectors
    //

    // Task 12 Filling a vector of ints

    vector<int> even;
    for (int i = 10; i <= 100; i += 2){
        even.push_back(i);
    }
    
    // Task 13 Displaying the vector THREE times
    //         a) using the indices,

    for(size_t index = 0; index < even.size(); ++index){
        cout << even[index] << endl;
    }
    
    //         b) using a "ranged for"

    for(int each_num : even){
        cout << each_num << endl;
    }
    
    //         c) using indices again but backwards

    for(size_t index_3 = even.size(); index_3 > 0; index_3--){
            cout << even[index_3 - 1] << endl;
        }

    // Task 14. Initialize a vector with the primes less than 20. 

    vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19};

    
}

// Task 15. Function to display a vector of ints

void display(const vector<int>& someVector){
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

void doubleInt2(vector<int>& someVector){
    for(int& each_num: someVector){
        each_num = each_num * 2;
    }
    display(someVector);
}
