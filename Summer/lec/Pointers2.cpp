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
	void push_back(T value); //Amortized Theta(1)
	T pop_back(); //Theta(1)
	int size()const { return currentSize; } //Theta(1)
	int capacity() const { return currentCapacity; } //Theta(1)

	T getAt(int position) const;  //Theta(1)
	void setAt(int position, T value); //Theta(1); fails if position>currentCapacity
	void clear(); //Theta(1)
	bool isEmpty() const { return size() == 0; }
	void destroy() { delete[] data; } //Temporary solution, NOT A GOOD IDEA
};
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
template <class T>
T DynArray<T>::getAt(int position) const {
	if (position>=currentSize || position<0)
		throw IndexOutOfBounds(); //create  new IndexOutOfBounds object and throw it to indicate a problem
	return data[position];
}
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


void func() {
	DynArray<int> d1;
	d1.destroy();
}

int main() {
	Thing<int> t1;
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