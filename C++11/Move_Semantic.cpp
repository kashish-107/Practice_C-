/*
Notes:
	1. Move semantic is implemeneted for all STL containers
	2. The most useful place for rvalue reference is overloading 
	copy & copy assignment operator, to achieve move semantics
	3. Conveniently avoid costly and unnecessary deep copying.
*/

#include <iostream>
using namespace std;

class xyz {
public:
	xyz() { cout << "Default ctor" << endl; }
	xyz(const xyz& rhs) { cout << "Copy ctor" << endl; }
	xyz(const xyz&& rhs) { cout << "Move ctor" << endl; }
	xyz& operator = (const xyz& rhs) { 
		cout << "Copy assignment" << endl; 
		return *this;
	}
	xyz& operator = (const xyz&& rhs) noexcept {
		if(this != &rhs)
			cout << "Move assignement" << endl;
		return *this;
	}
};

class DynClass {
	int* p;
	int size;
public:
	DynClass() :p(nullptr) { cout << "Default ctor" << endl; }

	DynClass(int iSize) : size{ iSize } {
		cout << "Param ctor" << endl;
		p = new int[size];
		for (int i = 0; i < size; ++i)
			p[i] = i;
	}

	DynClass(const DynClass& rhs) :size{ rhs.size } {
		cout << "Copy ctor" << endl;
		p = new int[size];
		for (int i = 0; i < size; ++i)
			p[i] = rhs.p[i] + 1;
	}

	DynClass(DynClass&& rhs) :size{ rhs.size } {
		cout << "Move ctor" << endl;
		p = rhs.p;
		rhs.p = nullptr;
	}

	DynClass& operator=(DynClass& rhs)
	{
		cout << "Copy assignement" << endl;
		if (this != &rhs) {
			size = rhs.size;
			p = new int[size];
			for (int i = 0; i < size; ++i)
				p[i] = rhs.p[i] + 1;
		}
		return *this;
	}

	DynClass& operator=(DynClass&& rhs) noexcept
	{
		cout << "Move assignement" << endl;
		if (this != &rhs) {
			delete[] p;
			p = rhs.p;
			size = rhs.size;
			rhs.p = nullptr;
		}
		return *this;
	}

	void printData() {
		cout << "Data :";
		for (int i = 0; i < size; ++i)
			cout << p[i] << " ";
		cout << endl;
	}

	~DynClass() {
		cout << "dtor" << endl;
		delete [] p;
	}
};

void fun(DynClass abc)
{
	cout << "In fun" << endl;
	DynClass obj = move(abc);
}

void funByRef(DynClass& abj)
{
	cout << "In fun" << endl;
}

DynClass createClass()
{
	return DynClass(7);
}

int main()
{
	//xyz obj1;
	//xyz obj3 = obj1;       //Copy ctor
	//xyz obj4 = static_cast<xyz&&>(obj1); //Move ctor
	//xyz obj2 = move(obj1); //Move ctor
	//obj2 = obj3;           //Copy assignment
	//obj1 = move(obj2);     //Move assignment

	//DynClass arr(10);
	//arr.printData();

	//DynClass arr2 = arr;  //Copy ctor
	//arr2.printData();

	//DynClass arr3(5);
	//arr3.printData();

	//arr3 = move(arr2);
	//arr3.printData();

	//DynClass arr3 = DynClass(5);  //Param ctor
	//arr3.printData();
	//
	//fun(arr2);          //Copy ctor
	//fun(move(arr3));    //Move ctor 
	//funByRef(arr2);     //No constructor

	//fun(DynClass(5));

	fun(createClass()); //Move ctor
	return 0;
}
