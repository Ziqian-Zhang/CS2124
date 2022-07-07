//
//  main.cpp
//  lab8
//
//  Created by Z.Q. Zhang on 2022/6/29.
//

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

inline void swap( int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp; }

inline void messup( int *c) {
    int save = *c;
    --c;
    *c = save; }

bool comp(int a, int b)
{
    return (a < b);
}

int findOccurrences(char* cstr, char toFind){
    if (*cstr == '\0')
        return 0;
    else if(*cstr == toFind)
        return 1 + findOccurrences(cstr + 1, toFind);
    else
        return findOccurrences(cstr + 1, toFind);
}

int main() {
//    int x = 1, y = 2, z = 3;
//    /* 1.1 what does the following print? */
//    int *a = &x, *b = &y; cout << "1.1: " << *a << " " << *b << endl;
//    /* 1.2 what does the following print? */
//    swap(a,b);
//    cout << "1.2: " << a << " " << b << endl;
//    /* 1.3 how about this? */
//    cout << "1.3: " << x << " " << y << endl;
//    /* 1.4 and that? Please also give your opinion on the code */
//    messup(&z); cout << "1.4: " << x << " " << y << " " << z << endl;
    
    // initialize a few arrays
    int A1[6] = { 0, 1, 2, 3, 4, 5 };
    int A2[6] = { 5, 4, 3, 2, 1, 0 };
    int A3[6] = { 3, 0, 3, 1, 1, -2 };
    // V is a vector that contains 5 4 3 2 1 0
    std::vector<int> V( A2, A2+6 );
    // L is a list that contains 3 0 3 1 1 -2
    std::list<int> L;
    L.push_back(3); L.push_back(0); L.push_back(3);
    L.push_back(1); L.push_back(1); L.push_back(-2);
    // S is a string that contains "A man, a plan, a canal: Panama!"
    std::string S( " A man, a plan, a canal: Panama!" );
    // 5.0  count the number of 3's in L
    assert( count( L.begin(), L.end(), 3 ) == 2);
    // As an example, your solution should say
    // assert( count( L.begin(), L.end(), 3 ) == 2);
    // 5.1  using std::find, check that V does not contain 6
    assert( std::find( V.begin(), V.end(), 6 ) == V.end() );
    // 5.2  test if L contains two adjacent identical numbers
    list<int>::iterator it1 = std::adjacent_find( L.begin(), L.end() );
    if (it1 == L.end())
      std::cout << "No adjacent number found\n";
    else
    std::cout << "Found two adjacent numbers equal to " << *it1 << "\n";
    // 5.3  find first punctuation character in S
    std::string punctuation( ":;,.!?" );
    std::cout << "First punctuation character in " << S << " is "
          << *(std::find_first_of( S.begin(), S.end(), punctuation.begin(), punctuation.end() ))
          << std::endl;
    // 5.4  check that L and A3 contain the same elements in same order
    assert( std::equal( L.begin(), L.end(), A3 ) );
    // 5.5 fill A3 with -1
    std::fill(A3, A3 + 6, -1);
    // 5.6  replace every space in S by the underscore '_'
    std::replace( S.begin(), S.end(), ' ', '_' );
    // 5.7  check that S is a palindrom by reversing S3
    std::string S2( "amanaplanacanalpanama" );
    std::string S3( S2 );
    std::reverse( S3.begin(), S3.end());
    assert( std::equal( S2.begin(), S2.end(), S3.begin()) );
    // 5.8  copy every element of A2 into A3, check the result
    std::copy( A2, A2 + 6, A3 );
    assert( std::equal( A2, A2+6, A3 ) );
    // 5.9  sort A3, check that it gives the same as A1
    std::sort( A3, A3 + 6 );
    assert( std::equal( A1, A1+6, A3 ) );
    // 5.10 find the smallest element in V
//    assert( std::min_element( V.begin(), V.end(), comp) == &V[5] );
    // 5.11 find the 3rd smaller element in V
    std::nth_element( V.begin(), V.begin()+2, V.end() );
    assert( V[0] < 2 && V[1] < 2 && V[2] == 2 );

    char ch[5] = {'a', 'b', 'c', 'd', 'c'};
    char target = 'c';
    char* c = ch;
    cout << findOccurrences(c, target);
}

