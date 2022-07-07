//
//  main.cpp
//  rec13
//
//  Created by Ziqian Zhang on 2022/4/29.
//

#include <iostream>
#include <fstream>
#include <vector>      // task 1
#include <list>        // task 2
#include <algorithm>   // task 3
#include <string>      // task 21
#include <set>         // task 22
#include <map>         // task 23
using namespace std;

// task 9
void printListIter(const list<int>& alist){
//    for (list<int>::iterator iter = alist.begin(); iter != alist.end(); iter++){
//        cout << *iter << ' ';
//    }
    for (list<int>::const_iterator iter = alist.begin(); iter != alist.end(); iter++){
        cout << *iter << ' ';
    }
    cout << endl;
}

// task 10
void printListRangedF(const list<int>& alist){
    for (int curr : alist){
        cout << curr << ' ';
    }
    cout << endl;
}

// task 11
void printListAuto(const list<int>& alist){
    for (auto iter = alist.begin(); iter != alist.end(); ++++iter){
        cout << *iter << ' ';
    }
    cout << endl;
}

// task 12
list<int>::const_iterator findList(const list<int>& alist, int target){
    for (list<int>::const_iterator iter = alist.begin(); iter != alist.end(); ++iter){
        if (*iter == target){
            return iter;
        }
    }
    return alist.end();
}

// task 13
auto findAuto(const list<int>& alist, int target){
    for (auto iter = alist.begin(); iter != alist.end(); ++iter){
        if (*iter == target){
            return iter;
        }
    }
    return alist.end();
}

// task 15
bool isEven(int val){
    return val % 2 == 0;
}

// task 16
class evenCheck{
public:
    bool operator() (int val){
        return val % 2 == 0;
    }
};

// Task 19
list<int>::const_iterator ourFind(list<int>::const_iterator begin, list<int>::const_iterator end, int target){
    cout << "Our Find: " << endl;
    for (list<int>::const_iterator it = begin; it != end; it++){
        if (*it == target){
            return it;
        }
    }
    return end;
}

// Task 20
template <typename someList, typename Tar>
someList ourFindT(someList begin, someList end, Tar target){
    cout << "Our Find Using Template" << endl;
    for (someList it = begin; it != end; it++){
        if (*it == target){
            return it;
        }
    }
    return end;
}

int main() {
    // 1. Create a vector with some values and display using ranged for
    cout << "Task 1:\n";
    
    vector<int> v;
    for (int i = 10; i > 0; --i){
        v.push_back(i);
    }
    for (int curr : v){
        cout << curr << ' ';
    }

    cout << "\n=======\n";

    // 2. Initalize a list as a copy of values from the vector
    cout << "Task 2:\n";
    
    list<int> li(v.begin(), v.end());
    for (int curr: li){
        cout << curr << ' ';
    }

    cout << "\n=======\n";

    // 3. Sort the original vector.  Display both the vector and the list
    cout << "Task 3:\n";
    
    sort(&v[0], &v[v.size()]);
    for (int curr : v){
        cout << curr << ' ';
    }
    cout << endl;
    for (int curr: li){
        cout << curr << ' ';
    }

    cout << "\n=======\n";

    // 4. print every other element of the vector. ASSUMING the length is odd.
    cout << "Task 4:\n";
    
    for (size_t i = 0; i < v.size(); i++){
        if (i % 2 == 0){
            cout << v[i] << ' ';
        }
    }

    cout << "\n=======\n";

    // 5. Attempt to print every other element of the list using the
    //    same technique.
    cout << "Task 5:\n";
    
//    for (size_t idx = 0; idx < li.size(); idx++){
//        if (idx % 2 == 0){
//            cout << li[idx] << ' ';
//        }
//    }
    cout << "\n=======\n";

    //
    // Iterators
    //

    // 6. Repeat task 4 using iterators.  Do not use auto;
    cout << "Task 6:\n";
    
    vector<int>::iterator iterV;
    for (iterV = v.begin(); iterV != v.end(); iterV += 2) {
        cout << *iterV << ' ';
    }

    cout << "\n=======\n";

    // 7. Repeat the previous task using the list.  Again, do not use auto.
    //    Note that you cannot use the same simple mechanism to bump
    //    the iterator as in task 6.
    cout << "Task 7:\n";
    
    list<int>::iterator iterL;
    for (iterL = li.begin(); iterL != li.end(); ++++iterL) {
        cout << *iterL << ' ';
    }

    cout << "\n=======\n";

    // 8. Sorting a list
    cout << "Task 8:\n";

    li.sort();
    for (int curr: li){
        cout << curr << ' ';
    }
    
    cout << "\n=======\n";

    // 9. Calling the function to print the list
    cout << "Task 9:\n";
    
    printListIter(li);

    cout << "=======\n";

    // 10. Calling the function that prints the list, using ranged-for
    cout << "Task 10:\n";
    
    printListRangedF(li);

    cout << "=======\n";

    //
    // Auto
    //

    // 11. Calling the function that, using auto, prints alterate
    // items in the list
    cout << "Task 11:\n";
    
    printListAuto(li);

    cout << "=======\n";

    
    // 12.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 12:\n";
    
    cout << "find 2: ";
    if (findList(li, 2) != li.end()){
        cout << "Found" << endl;
    } else { cout << "Failed" << endl; }
    cout << "find 10: ";
    if (findList(li, 10) != li.end()){
        cout << "Found" << endl;
    } else { cout << "Failed" << endl; }
    cout << "find 20: ";
    if (findList(li, 20) != li.end()){
        cout << "Found" << endl;
    } else { cout << "Failed" << endl; }
    cout << endl;

    cout << "=======\n";

    // 13.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 13:\n";
    
    cout << "find 2: ";
    if (findAuto(li, 2) != li.end()){
        cout << "Found" << endl;
    } else { cout << "Failed" << endl; }
    cout << "find 10: ";
    if (findAuto(li, 10) != li.end()){
        cout << "Found" << endl;
    } else { cout << "Failed" << endl; }
    cout << "find 20: ";
    if (findAuto(li, 20) != li.end()){
        cout << "Found" << endl;
    } else { cout << "Failed" << endl; }
    cout << endl;

    cout << "=======\n";

    //
    // Generic Algorithms
    //

    // 14. Generic algorithms: find
    cout << "Task 14:\n";
    
    cout << "find 2: ";
    list<int>::iterator finding = find(li.begin(), li.end(), 2);
    if (finding != li.end()){
        cout << "found" << endl;
    }
    cout << "find 20: ";
    list<int>::iterator finding2 = find(li.begin(), li.end(), 20);
    if (finding2 != li.end()){
        cout << "found" << endl;
    } else { cout << "Failed" << endl; }

    cout << "=======\n";

    // 15. Generic algorithms: find_if
    cout << "Task 15:\n";
    
    vector<int>::iterator iterVe = find_if(v.begin(), v.end(), isEven);
    list<int>::iterator iterLi = find_if(li.begin(), li.end(), isEven);
    if (iterVe != v.end()){
        cout << *iterVe << endl;
    }else{
        cout << "no even in vector" << endl;
    }
    
    if (iterLi != li.end()){
        cout << *iterLi << endl;
    }else{
        cout << "no even in list" << endl;
    }

    cout << "=======\n";

    // 16. Functor
    cout << "Task 16:\n";
    
    list<int>::iterator iterF = find_if(li.begin(), li.end(), evenCheck());
    if (iterF != li.end()){
        cout << *iterF << endl;
    }else{
        cout << "no even in list" << endl;
    }

    cout << "=======\n";
    
    // 17. Lambda
    cout << "Task 17:\n";
    
    [] { cout << "Hello Lambda!"; }();
    [] (int a, int b) { cout << a + b << endl; } (4, 5);
    int result = [] (int a, int b) { return a + b; } (4, 5);
    cout << "the result is: " << result << endl;
    int result2 = [] (int a, int b) -> int { return a + b; } (4, 5);
    cout << "the result is: " << result2 << endl;
    
    list<int>::iterator iterLam = find_if(li.begin(), li.end(),
                                          [] (int val) { return val % 2 == 0; });
    if (iterLam != li.end()){
        cout << *iterLam << endl;
    }else{
        cout << "no even in list" << endl;
    }

    cout << "=======\n";

    // 18. Generic algorithms: copy to an array
    cout << "Task 18:\n";

    int* arr = new int[10];
    copy(v.begin(), v.end(), arr);
    for (int* p = arr; p < arr + 10; p++){
        cout << *p << ' ';
    }
    cout << endl;
    int* findInArr = find(arr, arr + 10, 7);
    cout << "Finding 7 in array: ";
    if (findInArr != arr + 10){
        cout << "Found" << endl;
    }else{
        cout << "Not found" << endl;
    }
    int* findInArr2 = find(arr, arr + 10, 11);
    cout << "Finding 11 in array: ";
    if (findInArr2 != arr + 10){
        cout << "Found" << endl;
    }else{
        cout << "Not found" << endl;
    }
    delete [] arr;
    cout << "=======\n";

    //
    // Templated Functions
    //

    // 19. Implement find as a function for lists
    cout << "Task 19:\n";
    
    list<int>::const_iterator ourfind = ourFind(li.begin(), li.end(), 3);
    cout << "Finding 3 using ourFind function: ";
    if (ourfind != li.end()){
        cout << "Found" << endl;
    }else{
        cout << "Not found" << endl;
    }

    cout << "=======\n";
    
    // 20. Implement find as a templated function
    cout << "Task 20:\n";

    vector<int>::const_iterator findT = ourFindT(v.begin(), v.end(), 1);
    cout << "Finding 1 in vector using templated function: ";
    if (findT != v.end()){
        cout << "Found" << endl;
    }else{
        cout << "Not found" << endl;
    }
    
    list<int>::const_iterator findLT = ourFindT(li.begin(), li.end(), 2);
    cout << "Finding 2 in list using templated function: ";
    if (findLT != li.end()){
        cout << "Found" << endl;
    }else{
        cout << "Not found" << endl;
    }
    cout << "=======\n";

    //
    // Associative collections
    //

    // 21. Using a vector of strings, print a line showing the number
    //     of distinct words and the words themselves.
    cout << "Task 21:\n";
    
    ifstream ifs("pooh-nopunc.txt");
    string curr_word;
    vector<string> collection;
    while (ifs >> curr_word) {
        if (find(collection.begin(), collection.end(), curr_word) ==
            collection.end())
            collection.push_back(curr_word);
    }
    ifs.close();
    cout << "Number of Distinct Words: " << collection.size() << endl;
    for (string word : collection){
        cout << word << ' ';
    }

    cout << "\n=======\n";

    // 22. Repeating previous step, but using the set
    cout << "Task 22:\n";
    
    ifstream ifs2("pooh-nopunc.txt");
    set<string> collection2;
    while (ifs2 >> curr_word) {
    
        collection2.insert(curr_word);
    }
    ifs2.close();
    cout << "Number of Distinct Words: " << collection2.size() << endl;
    for (const string& word : collection2){
        cout << word << ' ';
    }

    cout << "=======\n";

    // 23. Word co-occurence using map
    cout << "Task 23:\n";

    ifstream ifs3("pooh-nopunc.txt");
    map<string, vector<int>> collection3;
    int position = 0;
    while (ifs3 >> curr_word) {
        ++position;
        collection3[curr_word].push_back(position);
    }
    ifs3.close();
    cout << "Number of Distinct Words: " << collection3.size() << endl;
    for (auto entry : collection3) {
        cout << entry.first << " ";
        for (int i : entry.second) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "=======\n";
}

