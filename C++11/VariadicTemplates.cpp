/*
1. Variadic templates are template that take a variable number of arguments
2. Syntax:
	- template<typename T, typename... args>
	- T function_name(T first, args... param){}
*/

#include<iostream>
#include<string>
using namespace std;

#if !defined(__PRETTY_FUNCTION__)
#define __PRETTY_FUNCTION__ __FUNCSIG__
#endif

template<typename T>
T adder(const T& i) {
	cout << __PRETTY_FUNCTION__ << endl;
	return i;
}

template<typename T, typename... Args>
T adder(T first, const Args&... arg)
{
	cout << __PRETTY_FUNCTION__ << endl;
	return first + adder(arg...);
}

int main() {
	cout << adder(1, 2, 3, 4, 5) << endl;
	cout << adder(1.5, 2.5, 3, 4, 5) << endl;
	cout << adder(string("Variadic "), string("Templates")) << endl;

	return 0;
}
