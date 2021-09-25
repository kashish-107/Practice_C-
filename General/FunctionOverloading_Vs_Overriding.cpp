/*
1. Inheritance: Overriding of functions occurs when one class is inherited from another class.Overloading can occur without inheritance.
2. Function Signature : Overloaded functions must differ in function signature ie either number of parameters or type of parameters should differ.
						In overriding, function signatures must be same.
3. Scope of functions : Overridden functions are in different scopes; whereas overloaded functions are in same scope.
4. Behavior of functions : Overriding is needed when derived class function has to do some added or different job than the base class function.
							Overloading is used to have same name functions which behave differently depending upon parameters passed to them.

How  Function Overloading works?
	Exact match:- (Function name and Parameter)

	If a not exact match is found:–
				   ->Char, Unsigned char, and short are promoted to an int.
				   ->Float is promoted to double
	
	If no match found:
				   ->C++ tries to find a match through the standard conversion.
	
	ELSE ERROR

- Can main() be overloaded in C++? -> No
	To overload main() function in C++, it is necessary to use class and declare the main as member function

- Does overloading work with Inheritance? -> No
	- If we want to overload a function of a base class, it is possible to unhide it by using the ‘using’ keyword

- Function overloading and const keyword
	- C++ allows member methods to be overloaded on the basis of const type
	- What about parameters?
		- C++ allows functions to be overloaded on the basis of const-ness of parameters only if the const parameter is a reference or a pointer

-  Functions can not be overloaded if they differ only in the return type.
*/

#include<iostream>
using namespace std;

class Test
{
protected:
	int x;
public:
	Test(int i) :x(i) { }
	void fun() const
	{
		cout << "fun() const called " << endl;
	}
	void fun()
	{
		cout << "fun() called " << endl;
	}
};

// (Fails in compilation)
void fun(const int i)
{
	cout << "fun(const int) called ";
}
void fun(int i)
{
	cout << "fun(int ) called ";
}

// (Compiles and runs fine)
void fun(char* a)
{
	cout << "non-const fun() " << a;
}

void fun(const char* a)
{
	cout << "const fun() " << a;
}

int main()
{
	Test t1(10);
	const Test t2(20);
	t1.fun();
	t2.fun();

	const int i = 10;
	fun(i);
	
	const char* ptr = "GeeksforGeeks";
	fun(ptr);

	return 0;
}