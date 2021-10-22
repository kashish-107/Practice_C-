/*
How does the compiler perform runtime resolution?
The compiler maintains two things to serve this purpose:
	vtable: A table of function pointers, maintained per class. 
	vptr: A pointer to vtable, maintained per object instance.i

Important: Irrespective of object is created or not, a static array of function pointer called VTABLE where each cell contains the address of each virtual function contained in that class.


Compiler adds additional code at two places to maintain and use vptr.
	1) Code in every constructor. This code sets the vptr of the object being created. This code sets vptr to point to the vtable of the class. 
	2) wherever a polymorphic call is made, the compiler inserts code to first look for vptr. Once vptr is fetched, vtable of derived class can be accessed. Using vtable, address of derived class function show() is accessed and called. 


Rules for Virtual Functions:
	- Virtual functions cannot be static.
	- A virtual function can be a friend function of another class.
	- Virtual functions should be accessed using pointer or reference of base class type to achieve run time polymorphism.
	- The prototype of virtual functions should be the same in the base as well as derived class.
	- They are always defined in the base class and overridden in a derived class. It is not mandatory for the derived class to override (or re-define the virtual function), in that case, the base class version of the function is used.
	- A class may have virtual destructor but it cannot have a virtual constructor.
*/

#include<iostream>
#include<memory>
using namespace std;

class shape
{
public:
	shape(int l, int w):length(l), width(w) {
	}
	
	virtual void get_Area() {
		cout<<"Parent class Shape"<<endl;
	}

	virtual ~shape() {
		cout<<"Shape dtor"<<endl;
	}
protected:
	int length, width;
};

class square : public shape
{
public:
	square(int l=0, int w=0):shape(l,w) {}
	void get_Area() override {
		cout<<"Area of square "<<length*width<<endl;
	}
};

class rectangle : public shape
{
public:
	rectangle(int l=0, int w=0):shape(l,w) {}
	void get_Area() override {
		cout<<"Area pf rectangle "<<length*width<<endl;
	}
};

int main()
{
	unique_ptr<shape> pSquare = make_unique<square>(5, 5);
	pSquare->get_Area();
	return 0;
}
