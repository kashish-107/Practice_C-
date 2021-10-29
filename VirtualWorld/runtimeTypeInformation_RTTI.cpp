/*
In C++, RTTI (Run-time type information) is a mechanism that exposes information about an object’s data type at runtime and 
is available only for the classes which have at least one virtual function. It allows the type of an object to be determined during program execution
*/

#include<iostream>
#include<memory>
using namespace std;

class animal
{
public:
	virtual void print() {
		cout<<"show"<<endl;
	}
};

class dog : public animal
{
public:
	void print() override {
		cout<<"I am dog"<<endl;
	}
};

class cat : public animal
{
public:
	void print() override {
		cout<<"I am cat"<<endl;
	}
};

int main()
{
	
	unique_ptr<animal> pCat = make_unique<cat>();
	unique_ptr<animal> pCat2 = make_unique<cat>();

	dog* pDog = static_cast<dog*>(pCat.release());
	dog* pDog2 = dynamic_cast<dog*>(pCat2.release());

	pDog->print();
	if(pDog2) pDog2->print();
	else cout<<"Dynamic cast failed"<<endl;

	return 0;
}
