/*
The reason behind the ambiguity in above code is that the floating literals 3.5 and 5.6 are actually treated as double by the compiler. As per C++ standard, floating point literals (compile time constants) are treated as double unless explicitly specified by a suffix [See 2.14.4 of C+++ standard here). Since compiler could not find a function with double argument and got confused if the value should be converted from double to int or float.
*/

#include<iostream>
using namespace std;

void fun(int i)
{
}

void fun(float f)
{
}

int main()
{
	//fun(4.5);
	fun(4.5f);
	return 0;
}
