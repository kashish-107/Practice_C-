#include<iostream>
#include<memory>
using namespace std;

class base
{
public:
	virtual void fun() { cout << "In Base" << endl; }
};

class derived : public base
{
public:
	// void fun(int) override { cout << "In derived" << endl; } --> Error at compile time no function to override
	void fun() override { cout << "In derived" << endl; }
};

int main()
{
	unique_ptr<base> p = make_unique<derived>();
	p->fun();
	return 0;
}
