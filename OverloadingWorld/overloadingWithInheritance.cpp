/*
- In C++, if a derived class redefines base class member method then all the base class methods with same name become hidden in derived class.
- If we want to overload a function of a base class, it is possible to unhide it by using the ‘using’ keyword.
*/

#include<iostream>
using namespace std;

class base
{
public:
	void fun(int i) { 
		cout<<i+3<<endl; 
	}

	void fun2(int i) { 
		cout<<i+3<<endl; 
	}
};

class derived : public base
{
public:
	using base::fun;
	void fun() {
		cout<<"Derived"<<endl;
	}

	void fun2(double d) {
		cout<<d+3.3<<endl;
	}
};

int main()
{
	derived d;
	d.fun(1);
	d.fun2(1);
	return 0;
}
