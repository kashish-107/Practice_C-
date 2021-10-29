/*
Whenever virtual function is called using base class reference or pointer it cannot be inlined (because call is resolved at runtime), 
but whenever called using the object (without reference or pointer) of that class, can be inlined because compiler knows the exact class of the object at compile time
*/
#include<iostream>
using namespace std;

class base
{
public:
	~base() {
		cout<<"Base dtor"<<endl;
	}
	
	inline virtual void show() {
		cout<<"Base show"<<endl;
	}
};

class derived : public base
{
public:
	inline void show() {
		cout<<"derived show"<<endl;
	}
};

int main()
{
	base* ptr = new derived();
	ptr->show();
	
	derived* dPtr = new derived();
	dPtr->show();

	base* bptr = new base();
	bptr->show();

	derived d;
	d.show();

	delete ptr;
	delete dPtr;
	delete bptr;
	return 0;
}
