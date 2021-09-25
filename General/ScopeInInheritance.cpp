#include<iostream>
using namespace std;

class base
{
	int x;
public:
	base() {}
	base(int x) :x{ x } 
	{ cout << "Base ctor"; }
	double add(double i) { return i + 0.1; }
};

class derived : public base
{
	int y;
public:
	derived() {}
	derived(int x, int y) :base(x), y{ y } {cout << "Derived ctor"; }
	using base::add;
	int add(int i) { return i + 1; }
};

int main()
{
	derived x;
	derived obj(3,5);
	cout << obj.add(10) << " " << obj.add(10.5) << endl;
	return 0;
}
