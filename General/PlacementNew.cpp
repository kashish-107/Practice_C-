#include<iostream>
using namespace std;

class base
{
	int x;
public:
	base() { cout << "Default ctor" << endl; }
	base(int x) :x{ x } { cout << "Param ctor" << endl; }
	~base() { cout << "Default dtor" << endl; }
};

int main()
{
	//Normal case
	base* p = new base(10);

}
