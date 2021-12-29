#include<iostream>
using namespace std;

class base
{
public:
	virtual ~base() {
		cout<<"Base dtor"<<endl;
	}
	
	virtual void show() {
		cout<<"I am base"<<endl;
	}
};

class derived1 : public base
{
public:
	void show() {
		cout<<"I am derived1"<<endl;
	}
};

class derived2 : public base
{
public:
	void show() {
		cout<<"I am derived2"<<endl;
	}
	void print() {
		cout<<"I am derived2"<<endl;
	}
};

int main()
{
	base* pDerived1 = new(nothrow) derived1();
	if(pDerived1)	
	{
		pDerived1->show();

		derived2* pDerived2 = (derived2*)pDerived1;
		pDerived2->print();
		
		delete pDerived2;
	}

	return 0;
}
