/*
- It is possible in C++ to get a special behavior for a particular data type. This is called template specialization.
*/

#include<iostream>
#include <cmath> //abs
using namespace std;

template<typename T>
bool is_equal(const T& a, const T& b)
{
	return a==b;
}

template<>
bool is_equal(const double& a, const double& b)
{
	return abs(a-b)<0.00001;
}

int main()
{
	cout<<is_equal(1,2)<<endl;
	cout<<is_equal(10.1,10.1)<<endl;

	return 0;
}
