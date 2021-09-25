#include<iostream>
using namespace std;

class A
{
	int x;
public:
	A(){}
	explicit A(int x) :x{ x } { cout << "In param ctor" << endl; }
	bool operator == (const A& rhs)
	{
		return x == rhs.x;
	}
};

int main()
{
	A obj = (A)10; //Implicit call to ctor
	obj == 10 ? cout << "same" << endl : cout << "not same" << endl;
	return 0;
}
