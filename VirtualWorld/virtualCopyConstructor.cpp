#include<iostream>
using namespace std;

class base {
public:
	virtual ~base() {
		cout<<"base dtor"<<endl;
	}
	
	virtual void changeAttribute() = 0;
	virtual base* clone() = 0;
	static base* create(int id);
};

class derived1 : public base {
public:
	~derived1() {
		cout<<"derived dtor"<<endl;
	}
	
	derived1() {
		cout<<"derived1 ctor"<<endl;
	}

	derived1(const derived1& rhs) {
		cout<<"Virtual copy ctor"<<endl;
	}
	
	void changeAttribute() override {
		cout<<"derived1 changeAtrribute()"<<endl;
	}

	base* clone() override {
		return new derived1(*this);
	}
};

base* base::create(int id)
{
	if(id == 1)
		return new derived1;
	return nullptr;
}

int main()
{
	base* bPtr = base::create(1);
	base* copiedObject = bPtr->clone();
	copiedObject->changeAttribute();
	
	delete bPtr;
	delete copiedObject;
	return 0;
}
