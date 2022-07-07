//
//  testFile.cpp
//
//

int main(){
    Measurement m1;
    Measurement m2(24);
    Measurement m3(-12);
    
    cout << "m1: " << m1;
    cout << "m2: " << m2;
    cout << "m3: " << m3;
    
    cout << endl;
    
    cout << "m1++: " << m1++;
    cout << "m1: " << m1;
    cout << "++m1: " << ++m1;
    cout << "m1: " << m1;
    
    
    cout << endl;
    
    cout << "m1: " << m1;
    cout << "m2: " << m2;
    cout << "m3: " << m3;
    
    cout << endl;
    
    cout << "m1 + m2: " << (m1 + m2);
    cout << "m2 + m3: " << (m2 + m3);
    cout << "m2 - m1: " << (m2 - m1);
    cout << "m1 - m2: " << (m1 - m2);
    
    cout << endl;
    
    cout << "m1 == m2: " << boolalpha << (m1 == m2) << endl;
    cout << "m1 != m2: " << boolalpha << (m1 != m2)<< endl;
    
    cout << endl;
    
    cout << "m2 == m2: " << boolalpha << (m2 == m2) << endl;
    cout << "m2 != m2: " << boolalpha << (m2 != m2) << endl;
}
