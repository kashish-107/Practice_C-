#include <iostream>
using namespace std;

class foo {
	int i;
	bool flag;
	float f;
public:
	foo() = default;
	foo(int i, bool iflag, float f) :i{ i }, flag{ iflag }, f{ f } {

	}
	foo(const foo& rhs) :i{ rhs.i }, flag{ rhs.flag }, f{ rhs.f } {
		cout << "Copy ctor" << endl;
	}
	foo(const foo&& rhs) :i{ rhs.i }, flag{ rhs.flag }, f{ rhs.f } {
		cout << "Move ctor" << endl;
	}
	void print() {
		cout << i << "," << flag << "," << f << endl;
	}
};

template<typename T>
void fun(T&& ifoo)
{
	foo f = forward<T>(ifoo);
}

void func2(foo f)
{
	foo obj = f;
}

int main()
{
	foo(1, true, 2.f).print();
	foo f(1, true, 3.f);
	fun(move(f)); //Perfect forwarding
	fun(f);       //Perfect forwarding - lvalue
	func2(f);     
	return 0;
}
