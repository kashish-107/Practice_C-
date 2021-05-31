/*
Notes:
Default:
	1. The =default; part instructs the compiler to generate the default implementation for the function
	2. Default ctor (generated only if no constructor is declared by user)
	3. Copy constructor & Copy assignment operator (generated only if move ctor & move assignment operator is not decalred by user
Delete:
	1.Deleted functions are useful for preventing object copying, among the rest.
	Recall that C++ automatically declares a copy constructor and an assignment operator for classes. 
	To disable copying, declare these two special member functions =delete:
	2. must be deleted on the first declaration.
*/

#include <iostream>
using namespace std;

class defaultFun {
	int i;
public:
	defaultFun() = default;
	defaultFun(float i) = delete;
	defaultFun(int i)
		:i{ i } {
		cout << "Param ctor" << endl;
	}
	defaultFun(const defaultFun& rhs) = delete;
	defaultFun& operator =(const defaultFun& rhs) = default;
	defaultFun(defaultFun&& rhs) {

	}

	void print() {
		cout << i << endl;
	}

	void abc();

	~defaultFun() {
		cout << "Dtor" << endl;
	}
};

void defaultFun::abc() = delete; // error: must be deleted on the first declaration

int main() {
	defaultFun d(10);
	defaultFun d2 = d;
	d = d2;

	defaultFun(2.3f).print();
	return 0;
}
