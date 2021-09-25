#include<iostream>
#include<memory>

using namespace std;

class A {
	int x;
public:
	A() = default;

	A(int x) :x{ x } { 
		cout << "A ctor" << endl; 
	}

	int getX() { 
		return x; 
	}

	~A() {
		cout << "A dtor" << endl;
	}
};

auto lambdaCustomDeleter = [](A* iP) {
	cout << __FUNCTION__ << endl;
	delete iP;
};

void functionCustomDeleter(A* iP) {
	cout << __FUNCTION__ << endl;
	delete iP;
}

class functorCustomDeleter {
public:
	void operator()(A * iP) {
		cout << __FUNCTION__ << endl;
		delete iP;
	}
};

int main()
{
	shared_ptr<A>p (new A(10), lambdaCustomDeleter);
	shared_ptr<A>pFun (new A(10), functionCustomDeleter);
	shared_ptr<A>pFuntor (new A(10), functorCustomDeleter());

	shared_ptr<A>p7 = make_shared<A>(20);
	cout << p.use_count() << endl;  //1
	
	//By value
	shared_ptr<A>p1 = p;
	cout << p.use_count() << endl;  //2
	
	//By reference
	shared_ptr<A>&p2 = p;           //2
	cout << p.use_count() << endl;

	//shared_ptr<A[]> arr (new A[3]);

	cout << sizeof(p) << endl;

	return 0;
}
