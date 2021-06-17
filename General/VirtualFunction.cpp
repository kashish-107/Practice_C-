/*
- In C++, virtual functions can be private and can be overridden by the derived class
- Why error in case of private inheritance of base class - To check?
*/

#include<iostream>
using namespace std;

class A {
public:
	
	void func() {
		cout << "Func A" << endl;
	}
};

class B :public A {
public:
	void func() {
		cout << "Func B" << endl;
	}
};

class C :public B {
public:
	void func() {
		cout << "Func C" << endl;
	}
};

class Base
{
public:
	Base() = default;
	virtual ~Base() = default;
	virtual void print()
	{
		std::cout << "print() called on base class\n";
	}
};

class Derived : public Base
{
private:
	void print() override {
		cout << "print() called on derived class\n";
	}
};


int main() {
	unique_ptr<A> pB= make_unique<B>();
	pB->func();

	unique_ptr<A> pC = make_unique<C>();
	pC->func();

	unique_ptr<B> bb(static_cast<B*>(pB.release()));
	bb->func();

	cout << "Size of " << sizeof(A) << endl;
	cout << "Size of " << sizeof(B) << endl;
	cout << "Size of " << sizeof(C) << endl;

	//Without virtual -> TypeCasting
	A* pB1 = new B();
	B* b = static_cast<B*>(pB1);
	b->func();

	unique_ptr<Base> bptr = make_unique<Derived>();

	// call virtual print in base class but it is overridden
	// in derived class also note that print() is private
	// member in derived class, still the contents of derived
	// class are printed this code works because base class
	// defines a public interface and drived class overrides
	// it in its implementation
	bptr->print();

	unique_ptr<Derived> bptr2 = make_unique<Derived>();
	bptr2->print(); //Error

	return 0;
}
