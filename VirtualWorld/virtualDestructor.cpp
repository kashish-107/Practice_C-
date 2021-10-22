/*
Virtual dtor:
	1. any time you have a virtual function in a class, you should immediately add a virtual destructor (even if it does nothing)
	2. Making base class destructor virtual guarantees that the object of derived class is destructed properly, i.e., both base class and derived class destructors are called
*/

#include<iostream>
#include<memory>
using namespace std;

class base
{
public:
	virtual void show() {
		cout<<"Base show()"<<endl;
	}
	virtual ~base() {
		cout<<"Base dtor"<<endl;
	}
};

class derived : public base
{
public:
	void show() override {
		cout<<"Derived show()"<<endl;
	}
	~derived() {
		cout<<"Derived dtor"<<endl;
	}
};

int main()
{
	unique_ptr<base> pD = make_unique<derived>();
	pD->show();
	return 0;
}
