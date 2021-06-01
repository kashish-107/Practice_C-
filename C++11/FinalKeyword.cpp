/*
1. Specifies that a virtual function cannot be overridden in a derived class or that a class cannot be inherited from.
*/

#include <iostream>
using namespace std;

class base {
public:
	virtual void abc() final {

	}
};

class derived final :public base {
public:
	void abc() override {

	}
};

class derived2 :public derived {
public:
	void abc() override {

	}
};
int main() {
	return 0;
}
