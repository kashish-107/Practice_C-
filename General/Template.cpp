/*
1. Each instance of a template contains its own static variable
2. Template specialization allows us to have different code for a particular data type
*/

#include<iostream>
using namespace std;

void print() {
	cout << endl;
}

template<typename T, typename... Args>
void print(T first, Args... args) {
	cout << first << " ";
	print(args...);
}

template<typename T>
T Max(T x, T y) {
	return x > y ? x : y;
}

template<typename T>
void func_staticVar(T x)
{
	static int i = 10;
	print(x, " ", i++);
}

template<typename T>
class A_staticVar {
	T x;
	static int i;
public:
	A_staticVar(T j) :x{ j } {
		print(__FUNCTION__, x, i++);
	}
};

template<typename T>
int A_staticVar<T>::i = 15;

template<typename T>
class Array {
	T* p;
	int size;
public:
	Array(T arr[], int iSize) :size{ iSize } {
		p = new T[size];
		for (int i = 0; i < size; ++i)
			p[i] = arr[i];
	}

	void print() {
		for (int i = 0; i < size; ++i) 
			cout << p[i] << " ";
		cout << endl;
	}

	~Array() {
		cout << "Dtor" << endl;
		delete[] p;
	}
};

template<typename T, typename U = char>
class A {
	T x;
	U Y;
public:
	A(T i, U j) {
		cout << i << j << endl;
		cout << "A Ctor" << endl;
	}
};

int main() {
	cout << Max(12, 3) << endl;
	cout << Max<float>(12.5, 6.7) << endl;

	int arr[5] = { 1,2,3,4,5 };
	Array<int> obj = Array<int>(arr, 5);

	obj.print();

	float arrf[5] = { 1.2f,2.4f,3.5f,4.0f,5.7f };
	Array<float> objf = Array<float>(arrf, 5);

	objf.print();

	A<int, float> a(1,5.5f);

	func_staticVar(15);
	func_staticVar(17);
	func_staticVar(17.5);

	A_staticVar<int> objS(77);
	A_staticVar<int> objS2(78);
	A_staticVar<float> objS3(78.7);

	return 0;
}