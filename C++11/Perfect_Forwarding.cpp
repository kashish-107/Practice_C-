/*
1. rvalue is forwarded as rvalue, and lvalue is forwarded as lvalue
2. reference collapsing rules (C++11)
	a) T& &   ==> T&
	b) T& &&  ==> T&
	c) T&& &  ==> T&
	d) T&& && ==> T&&
3. type&& is rvalue reference? No. Its a universal reference (forwarding reference)
	- fun(9) -> T = int && -> T&& = int&& && = int&&
	- fun(i) -> T = int & -> T& = int& && = int&
4. type&& is a universal reference if
	a) type is tempelate type
	b) type deduction (reference collapsing) happens to type
*/

#include <iostream>
#include <vector>
using namespace std;

class foo {
	int i;
	bool flag;
	float f;
	vector<int> v;
public:
	foo() = default;

	foo(int i, bool iflag, float f, vector<int> const& iVec) 
		:i{ i }
		,flag{ iflag }
		,f{ f }
		,v{iVec}
	{
		cout << "Param ctor" << endl;
	}

	foo(int i, bool iflag, float f, vector<int>&& iVec)
		:i{ i }
		, flag{ iflag }
		, f{ f }
		, v{move(iVec)}
	{
		cout << "Rvalue Param ctor" << endl;
	}

	foo(int i) :i{ i }{
		cout << "One Param ctor" << endl;
	}

	foo(const foo& rhs) :foo(rhs.i , rhs.flag, rhs.f, rhs.v) {
		cout << "Copy ctor" << endl;
	}

	foo(const foo&& rhs) :foo(rhs.i, rhs.flag, rhs.f, rhs.v) {
		cout << "Move ctor" << endl;
	}

	void print() {
		cout << i << "," << flag << "," << f << endl;
	}
};

class bar {
public:
	void addFoo(foo const& f)
	{
		v.push_back(f);
	}

	//Variadic template
	template<typename ... Args>                //Any number of arguments and any type  
	void addFoo_emplaceBack(Args&& ... args)   //Forwarding reference  (Universal reference)
	{
		v.emplace_back(forward<Args>(args)...);
	}
private:
	vector<foo> v;
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
	//foo(1, true, 2.f).print();
	//foo f(1, true, 3.f);
	//fun(move(f)); //Perfect forwarding - rvalue - move ctor
	//fun(f);       //Perfect forwarding - lvalue - copy ctor
	//func2(f);

	//vector<foo> v1;
	//{
	//	foo f1(1, false, 5.f);
	//	v1.push_back(f1);                  //make a copy of foo
	//	v1.push_back(move(f1));            //move foo
	//	v1.push_back(foo(1, true, 3.f));   //move foo - rvalue

	//	v1.emplace_back(3, true, 7.f);
	//}

	cout << "***** Bar *****" << endl;

	bar b;
//	foo f(1, false, 5.f);
//	b.addFoo(f);                           //Copy ctor 
//	b.addFoo_emplaceBack(3, true, 7.f);

	vector<int> vv{ 1,2,3,4,5 };
	//b.addFoo_emplaceBack(3, true, 7.f, vv); //param ctor - lvalue
	b.addFoo_emplaceBack(3, true, 7.f, move(vv));
	return 0;
}
