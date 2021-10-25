/*
- Yes, it is possible to have pure virtual destructor.
- One of the most important things to remember is that if a class contains a pure virtual destructor, it must provide a function body for the pure virtual destructor
	->  The reason is because destructors (unlike other functions) are not actually ‘overridden’, 
		rather they are always called in the reverse order of the class derivation. 
		This means that a derived class’ destructor will be invoked first, then base class destructor will be called. 
		If the definition of the pure virtual destructor is not provided, then what function body will be called during object destruction? 
		Therefore the compiler and linker enforce the existence of a function body for pure virtual destructors.
- Class becomes abstract class when it contains a pure virtual destructor.
*/

#include<iostream>
using namespace std;

class base
{
public:
	virtual void print() = 0;
	virtual ~base() = 0;
};

base::~base() {
	cout<<"Base dtor"<<endl;
}

class derived : public base
{
public:
	void print() {
		cout<<"I am derived"<<endl;
	}
};

class base2
{
public:
	virtual ~base2() = 0;
};

int main()
{
	base* ptr = new derived();
	ptr->print();
	delete ptr;

	//base2 obj;
	
	return 0;
}
