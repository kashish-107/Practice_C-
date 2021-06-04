/*
1. Creational design pattern
2. Ensures that only one object of its kind exists and 
provides a single point of access to it for any other code
*/

#include<iostream>
using namespace std;

class singleton {
public:
	static singleton* getInstance() {
		static singleton* _inst = nullptr;
		if (!_inst) {
			cout << "Create instance" << endl;
			_inst = new singleton();
		}
		cout << "Instance" << endl;
		return _inst;
	}

	void print() {
		cout << __FUNCTION__ << endl;
	}

	singleton(const singleton&) = delete;
	void operator=(const singleton&) = delete;

private:
	//static singleton* _inst = nullptr;
	singleton() = default;

	~singleton() {
		cout << "In dtor" << endl;
	}
};

//singleton* singleton::_inst;

int main() {
	singleton* p = singleton::getInstance();
	singleton* p1 = singleton::getInstance();
	p->print();

	//singleton p2 = *p1; //Deleted copy ctor
	//p1 = p;             //Deleted assignment operator
	//delete p1;          //Private dtor
	return 0;
}
