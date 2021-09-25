#include<iostream>
using namespace std;
class test
{
	
	int x, y;
public:
	test():test(0,0) {}
	test(int x) :test(x, 0) {}
	test(int x, int y): x{x}, y{y}
	{
		test t;
		cout << "Param ctor" << endl;
	}
	void print()
	{
		cout << x << " " << y << endl;
	}
};

int main()
{
	test t(9, 90);
	test t2(t);
	t2.print();
	return 0;
}
