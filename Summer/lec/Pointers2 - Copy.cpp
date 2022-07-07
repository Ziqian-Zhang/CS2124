#include <iostream>
#include <vector>

using namespace std;
class IndexOutOfBounds {}; //Only used for the Exception
template <class T>
class DynArray {
	int currentCapacity; //Maximum number of items we COULD store
	int currentSize; //number of items we are storing
	T* data; //pointer to our data array
	void resize(int newCapacity); //Theta(N)
public:
	DynArray();
	DynArray(const DynArray& rhs) :data(nullptr) { *this = rhs; }
	DynArray(DynArray&& rhs);
	DynArray& operator=(const DynArray& rhs);
	DynArray& operator=(DynArray&& rhs);
	void push_back(T value); //Amortized Theta(1)
	T pop_back(); //Theta(1)
	int size()const { return currentSize; } //Theta(1)
	int capacity() const { return currentCapacity; } //Theta(1)

	//T getAt(int position) const;  //Theta(1)
	void setAt(int position, T value); //Theta(1); fails if position>currentCapacity
	void clear(); //Theta(1)
	bool isEmpty() const { return size() == 0; }
	~DynArray() { delete[] data; } 
	T operator[](int index) const { return data[index]; }
	T& operator[](int index) { return data[index]; }
};
template <class T>
DynArray<T>::DynArray(DynArray<T>&& rhs) {
	currentSize = rhs.currentSize;
	currentCapacity = rhs.currentCapacity;
	data = rhs.data;
	rhs.currentCapacity = 5;
	rhs.currentSize = 0;
	rhs.data = new T[rhs.currentCapacity];
}
template <class T>
DynArray<T>& DynArray<T>::operator=(DynArray<T>&& rhs) {
	if (this != &rhs) {
		delete[] data;
		currentSize = rhs.currentSize;
		currentCapacity = rhs.currentCapacity;
		data = rhs.data;
		//Make RHS look more "Default"
		rhs.currentCapacity = 5;
		rhs.currentSize = 0;
		rhs.data = new T[rhs.currentCapacity];
	}
	return *this;
}
template <class T>
DynArray<T>& DynArray<T>::operator=(const DynArray<T>& rhs) {
	if (this != &rhs) {
		delete[] data;
		currentSize = rhs.currentSize;
		currentCapacity = rhs.currentCapacity; //could be currentCapacity=rhs.currentSize
		data = new int[currentCapacity];
		for (int i = 0; i < currentSize; i++)
			data[i] = rhs.data[i];
	}
	return *this;
}
template <class T>
void DynArray<T>::resize(int newCapacity) {
	T* temp = new int[newCapacity];
	int copyLimit;
	if (newCapacity <= currentSize) {
		copyLimit = newCapacity;
		currentSize = newCapacity;
	}
	else
		copyLimit = currentSize;
	for (int i = 0; i < copyLimit; i++)
		temp[i] = data[i];
	delete[] data;
	data = temp;
	currentCapacity = newCapacity;
}
/*template <class T>
T DynArray<T>::getAt(int position) const {
	if (position>=currentSize || position<0)
		throw IndexOutOfBounds(); //create  new IndexOutOfBounds object and throw it to indicate a problem
	return data[position];
}
*/
template <class T>
void DynArray<T>::setAt(int position, T value) {
	if (position >= currentCapacity || position < 0)
		throw IndexOutOfBounds(); //create  new IndexOutOfBounds object and throw it to indicate a problem
	else if (position >= currentSize) {
		push_back(value);
		return;
	}
	data[position] = value;
}
template <class T>
void DynArray<T>::clear() {
	delete[] data;
	currentCapacity = 5;
	currentSize = 0;
	data = new T[currentCapacity];

}

template <class T>
DynArray<T>::DynArray() {
	currentCapacity = 5;
	currentSize = 0;
	data = new T[currentCapacity];
}
template <class T>
T DynArray<T>::pop_back() {
	if (currentSize == 0)
		throw IndexOutOfBounds(); //create  new IndexOutOfBounds object and throw it to indicate a problem
	return data[--currentSize];

	/*int temp = data[currentSize - 1];
	currentSize -= 1;
	return temp;*/
}
template <class T>
void DynArray<T>::push_back(T value) {
	if (currentSize == currentCapacity)
		resize(currentCapacity * 2);
	data[currentSize++] = value;
}

/*void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void swap(string& a, string& b) {
	string temp = a;
	a = b;
	b = temp;
}*/
template <class CS2124Type> // could also be template <typename T> ; T could be anything you like
void mySwap(CS2124Type& a, CS2124Type& b) {
	CS2124Type temp = a;
	a = b;
	b = temp;
}

template <class T>
class Thing {
public:
	Thing(T newVal = T()); //I don't know what a new value should be for this, so I'll use default
	T x;
};

template <class T>
Thing<T>::Thing(T newval) {
	x = newval;
}




class HeapMem {
	int* data;
public:
	HeapMem(int newval = 0) :data(new int(newval)) { cout << "Constructing a HeamMem object" << endl; }
	~HeapMem(); //The Destructor! Invoked when the object falls out of scope
	HeapMem(const HeapMem& rhs); //copy constructor
	HeapMem(HeapMem&& rhs); //Move constructor
	int getVal() const { return *data; }
	void setVal(int newval) { *data = newval; }
	HeapMem& operator=(const HeapMem& rhs); //Assignment operator
	HeapMem& operator=(HeapMem&& rhs); //Move operator
	HeapMem operator+(const HeapMem& rhs)const;
};
HeapMem operator+(const HeapMem& lhs, const HeapMem& rhs) {
	cout << "NON-Member" << endl;
	HeapMem temp(lhs.getVal() + rhs.getVal());
	return temp;

}
HeapMem HeapMem::operator+(const HeapMem& rhs)const {
	cout << "Member" << endl;
	HeapMem temp(*data + *rhs.data);
	return temp;
}
HeapMem::HeapMem(const HeapMem& rhs) {
	/*data = new int(*rhs.data);
	cout << "Copy-constructing a HeapMem object!" << endl;
	*/
	data = nullptr;
	*this = rhs;
}
HeapMem::HeapMem(HeapMem&& rhs) { //move constructor
	/*data = new int(*rhs.data);
	cout << "Copy-constructing a HeapMem object!" << endl;
	*/
	data = rhs.data;
	rhs.data = nullptr;
}


HeapMem& HeapMem::operator=(const HeapMem& rhs) {
	if (this != &rhs) { //test for self-assignment
		delete data;
		data = new int(*rhs.data);
	}
	return *this;
}

HeapMem& HeapMem::operator=(HeapMem&& rhs) { //Move Operator
	if (this != &rhs) { //test for self-assignment
		data = rhs.data;
		rhs.data = nullptr;
	}
	return *this;
}

HeapMem::~HeapMem() {

	delete data;
	cout << "Destructing a HeapMem Object" << endl;
}

void func() {
	HeapMem m1;
}

struct Oldie {
	int x;
	int y;
	int z;
};
void demo1() {
	HeapMem m1(100);
	HeapMem m2(200);
	HeapMem m3 = m2; //call to copy-constructor
	m1 = m2; //m1.operator=(m2)
	m1 = m1; //Really?????????????


}

int main() {
	HeapMem m1(100);
	HeapMem m2(200);
	//HeapMem m3 = m1 + m2;


	/*HeapMem m1(10); //one argument constructor
	HeapMem m2 = 20; //one argument constructor
	HeapMem m3;
	HeapMem m4(m1);
	HeapMem m5 = m1;	
	int x(100);
	m3 = m2;


	for (int i = 0; i < 2; i++)
		func();
*/
/*	Thing<int> t1;
	Thing<string> t2;
	Thing<double> t3;

	vector<int> v1;

	int x=5;
	int y=10;
	mySwap(x, y);
	double q = 5.5;
	double r = 10.5;
	mySwap(q, r);

	for (int i = 0; i < 100000000; i++)
		func();
		*/
/*	DynArray<int> d1;
	for (int i = 0; i < 100; i++)
		d1.push_back(i * 10);
	for (int i = 0; i < d1.size(); i++)
		cout << d1.getAt(i) << endl;
	cout << "****************************************" << endl;
	while (!d1.isEmpty()) {
		cout << d1.pop_back() << endl;
	}
	*/

	/*	vector<int> v;
	v[0] = 100;

	int size = 100;
	const int CONST_SIZE = 100;
	cout << "What size? ";
	cin >> size;
	//int arr[size]; // Stack-Dynamic array, size must be knwn at compile time!
	int arr[CONST_SIZE];
	int* dynarr = new int[size]; //Heap-Dynamic array, size can be dynamic.

	delete[] dynarr; //delete an array
*/}