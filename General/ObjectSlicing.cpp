#include<iostream>
using namespace std;

class base
{
protected:
	int i;
public:
	base(){}
	base(int i) :i{ i }
	{

	}
	virtual void display()
	{
		cout << "i " << i << endl;
	}
};

class derived :public base
{
	int j;
public:
	derived(){}
	derived(int x, int y) :base(x), j{ y }
	{

	}
	void display() override
	{
		cout << "i " << i  << ",j " << j << endl;
	}
};

int main()
{
	base b(3);
	derived d(6, 7);
	b.display();
	d.display();
	base b2 = d; //Object slicing j value is sliced off
	b2.display();

	//To avoid Object slicing we can use pointer and references 
	base* p = &d;
	p->display();
	return 0;
}

